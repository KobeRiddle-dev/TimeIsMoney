#include "CPP_Card_Deck.h"

// Sets default values
ACPP_Card_Deck::ACPP_Card_Deck()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Card_Deck::BeginPlay()
{
	Super::BeginPlay();

	// Create Drawpile from StartingDeck
	for (UCPP_Data_EffectCards* CardData : StartingDeck)
	{
		if (CardData)
		{
			FCardInstance NewCard;
			NewCard.CardData = CardData;
			NewCard.CardActor = nullptr; // Not spawned yet
			Drawpile.Add(NewCard);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("StartingDeck contains a NULL card!"));
		}
	}

	// Initial Shuffle
	ShuffleDeck();
}

void ACPP_Card_Deck::ShuffleDeck()
{
	Drawpile.Sort([](const FCardInstance& A, const FCardInstance& B) {
		return FMath::RandBool();
		});
}

void ACPP_Card_Deck::DrawRandom()
{
	// If we reached the end of the deck shuffle discard into deck
	if (Drawpile.Num() == 0)
	{
		if (!DiscardPile.IsEmpty())
		{
			Drawpile = DiscardPile;
			DiscardPile.Empty();
			ShuffleDeck();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No cards left to draw!"));
			return;
		}
	}

	// Pop card from drawpile and add to hand
	FCardInstance RandomCard = Drawpile.Pop();
	Hand.Add(RandomCard);
	int32 HandIndex = Hand.Num() - 1;

	// Compute target positions for the whole hand (this uses the updated Hand.Num())
	TArray<FVector> Positions = CalculateHandPositions();
	FVector SpawnLocation = GetActorLocation(); // fallback
	FRotator SpawnRotation = FRotator::ZeroRotator;
	if (HandSlots.Num() > 0)
	{
		SpawnRotation = HandSlots[0].GetRotation().Rotator();
	}
	if (Positions.IsValidIndex(HandIndex))
	{
		SpawnLocation = Positions[HandIndex];
	}
	else if (HandSlots.Num() >= 2)
	{
		// Fallback to center between the two hand slots if index missing
		SpawnLocation = (HandSlots[0].GetLocation() + HandSlots[1].GetLocation()) * 0.5f;
	}

	// Spawn world actor IF we don't already have one
	if (!IsValid(Hand[HandIndex].CardActor))
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		UWorld* World = GetWorld();
		if (World && CardActorClass)
		{
			ACPP_Card_EffectCard* Spawned = World->SpawnActor<ACPP_Card_EffectCard>(
				CardActorClass,
				SpawnLocation,
				SpawnRotation,
				SpawnParams
			);
			if (IsValid(Spawned))
			{
				// Initialize it with its data
				Spawned->InitializeCard(RandomCard.CardData);
				Spawned->SetCardText();
				// store reference
				Hand[HandIndex].CardActor = Spawned;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("DrawRandom: spawn failed for index %d"), HandIndex);
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("DrawRandom: CardActorClass not set! Assign BP_EffectCard in Deck settings."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DrawRandom: CardActor already exists for drawn card!"));
	}

	// notify listeners
	OnCardDrawn.Broadcast(Hand[HandIndex]);
	// Update layout for all cards (positions & fixed rotation)
	UpdateHandLayout();
}

TArray<FVector> ACPP_Card_Deck::CalculateHandPositions() const
{
	TArray<FVector> OutPositions;
	int32 NumCards = Hand.Num();
	OutPositions.SetNumZeroed(NumCards);

	if (NumCards == 0)
	{
		return OutPositions;
	}

	// Need two hand slot endpoints
	if (HandSlots.Num() < 2)
	{
		// fallback: put everything at actor location
		FVector Fallback = GetActorLocation();
		for (int32 i = 0; i < NumCards; ++i)
		{
			OutPositions[i] = Fallback;
		}
		return OutPositions;
	}

	const FVector Start = HandSlots[0].GetLocation();
	const FVector End = HandSlots[1].GetLocation();
	const FVector Center = (Start + End) * 0.5f;
	const FVector Dir = End - Start;
	const float TotalWidth = Dir.Size();

	// If the two points coincide, put all cards at center.
	if (TotalWidth <= KINDA_SMALL_NUMBER)
	{
		for (int32 i = 0; i < NumCards; ++i)
			OutPositions[i] = Center;
		return OutPositions;
	}

	const FVector DirUnit = Dir / TotalWidth;

	// Compute spacing:
	// - PreferredCardSpacing is the spacing we'd like if there's enough room.
	// - If (NumCards - 1) * PreferredCardSpacing > TotalWidth, shrink spacing so cluster fits.
	float spacing = 0.0f;
	if (NumCards == 1)
	{
		spacing = 0.0f;
	}
	else
	{
		// maximum spacing that still fits between endpoints
		const float maxFitSpacing = TotalWidth / float(NumCards - 1);
		spacing = FMath::Min(PreferredCardSpacing, maxFitSpacing);
	}

	// Compute left-most start so cluster is centered at Center.
	const float halfSpan = spacing * float(NumCards - 1) * 0.5f;
	const FVector clusterStart = Center - DirUnit * halfSpan;

	for (int32 i = 0; i < NumCards; ++i)
	{
		OutPositions[i] = clusterStart + DirUnit * (spacing * float(i));
	}

	return OutPositions;
}

// Helper: move any already-spawned card actors into their computed positions
void ACPP_Card_Deck::UpdateHandLayout()
{
	if (Hand.Num() == 0) return;
	TArray<FVector> Positions = CalculateHandPositions();
	FRotator CardRotation = FRotator::ZeroRotator;
	// Use the first hand slot's rotation if available
	if (HandSlots.Num() > 0)
	{
		CardRotation = HandSlots[0].GetRotation().Rotator();
	}
	int32 Count = FMath::Min<int32>(Hand.Num(), Positions.Num());
	for (int32 i = 0; i < Count; ++i)
	{
		if (IsValid(Hand[i].CardActor))
		{
			Hand[i].CardActor->SetActorLocation(Positions[i]);
			Hand[i].CardActor->SetActorRotation(CardRotation);
		}
	}
}

void ACPP_Card_Deck::DiscardHand()
{
	//UE_LOG(LogTemp, Log, TEXT("Discarding hand"));
	while (Hand.Num() > 0)
	{
		FCardInstance DiscardedCard = Hand.Pop();
		if (DiscardedCard.CardActor)
		{
			DiscardedCard.CardActor->Destroy();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("DiscardHand: CardActor or DiscardPileSlot is NULL!"));
		}
		DiscardPile.Add(DiscardedCard);
		OnCardDiscarded.Broadcast(DiscardedCard);
	}
}

void ACPP_Card_Deck::DiscardInPlayCards()
{
	while (InPlay.Num() > 0)
	{
		FCardInstance DiscardedCard = InPlay.Pop();
		if (DiscardedCard.CardActor)
		{
			DiscardedCard.CardActor->Destroy();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("DiscardInPlayCards: CardActor or DiscardPileSlot is NULL!"));
		}
		DiscardPile.Add(DiscardedCard);
		OnCardDiscarded.Broadcast(DiscardedCard);
		UE_LOG(LogTemp, Log, TEXT("Discarded a card to DiscardPile. DiscardPile now has %d cards."), DiscardPile.Num());
	}
}

void ACPP_Card_Deck::PlayCardFromHand(ACPP_Card_EffectCard* CardToPlay)
{
	if (!CardToPlay)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayCardFromHand: CardToPlay is NULL!"));
		return;
	}

	// Find card in Hand
	int32 Index = GetCardFromHandIndex(CardToPlay);
	if (Index == INDEX_NONE)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayCardFromHand: Could not find card in Hand!"));
		return;
	}

	// Add to InPlay
	FCardInstance PlayedCard = Hand[Index];
	Hand.RemoveAt(Index);
	InPlay.Add(PlayedCard);

	// Move the actor in the world if it exists
	if (PlayedCard.CardActor)
	{
		int32 SlotIndex = InPlay.Num() - 1;
		if (BoardSlots.IsValidIndex(SlotIndex))
		{
			FVector TargetLocation = BoardSlots[SlotIndex].GetLocation();
			FRotator TargetRotation = FRotator::ZeroRotator;

			// Trigger Blueprint animation. Animation callback is Table_TimeIsMoney::PlayCard(...)
			PlayCardAnimation(PlayedCard.CardActor, TargetLocation, TargetRotation);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("PlayCardFromHand: BoardSlots index %d is out of range! BoardSlots.Num=%d, InPlay.Num=%d"),
				SlotIndex, BoardSlots.Num(), InPlay.Num());
		}
	}
	UpdateHandLayout();
}

// Returns -1 if the card is not found in hand
int ACPP_Card_Deck::GetCardFromHandIndex(ACPP_Card_EffectCard* CardToFind)
{
	if (!CardToFind)
	{
		UE_LOG(LogTemp, Error, TEXT("GetCardFromHandIndex: CardToFind is NULL!"));
		return INDEX_NONE;
	}
	int32 Index = Hand.IndexOfByPredicate([CardToFind](const FCardInstance& Card) {
		return Card.CardActor == CardToFind;
		});
	if (Index == INDEX_NONE)
	{
		UE_LOG(LogTemp, Warning, TEXT("GetCardFromHandIndex: Card not found in hand!"));
	}
	return Index;
}

// Returns -1 if the card is not found in play
int ACPP_Card_Deck::GetCardFromInPlayIndex(ACPP_Card_EffectCard* CardToFind)
{
	if (!CardToFind)
	{
		UE_LOG(LogTemp, Error, TEXT("GetCardFromInPlayIndex: CardToFind is NULL!"));
		return INDEX_NONE;
	}
	int32 Index = InPlay.IndexOfByPredicate([CardToFind](const FCardInstance& Card) {
		return Card.CardActor == CardToFind;
		});
	if (Index == INDEX_NONE)
	{
		UE_LOG(LogTemp, Warning, TEXT("GetCardFromInPlayIndex: Card not found in play!"));
	}
	return Index;
}

// Called every frame
void ACPP_Card_Deck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


