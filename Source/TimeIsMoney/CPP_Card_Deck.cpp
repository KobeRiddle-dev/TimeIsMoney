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

	// Spawn world actor IF we don't already have one
	if (!IsValid(Hand[HandIndex].CardActor))
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		UWorld* World = GetWorld();
		if (World && CardActorClass)
		{
			// Pick a slot transform if available, otherwise fallback
			FTransform SpawnTransform = FTransform::Identity;
			if (HandSlots.IsValidIndex(HandIndex))
			{
				SpawnTransform = HandSlots[HandIndex];
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("HandSlots does not have an entry for HandIndex %d, using identity transform"), HandIndex);
			}

			ACPP_Card_EffectCard* Spawned = World->SpawnActor<ACPP_Card_EffectCard>(
				CardActorClass,
				SpawnTransform.GetLocation(),
				SpawnTransform.GetRotation().Rotator(),
				SpawnParams
			);

			if (IsValid(Spawned))
			{
				// Initialize with card data
				Spawned->InitializeCard(RandomCard.CardData);

				// Store reference
				Hand[HandIndex].CardActor = Spawned;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("DrawRandom: spawn failed"));
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
}

void ACPP_Card_Deck::DiscardHand()
{
	//UE_LOG(LogTemp, Log, TEXT("Discarding hand"));
	while (Hand.Num() > 0)
	{
		FCardInstance DiscardedCard = Hand.Pop();
		DiscardPile.Add(DiscardedCard);
		OnCardDiscarded.Broadcast(DiscardedCard);
	}
}

void ACPP_Card_Deck::DiscardInPlayCards()
{
	while (InPlay.Num() > 0)
	{
		FCardInstance DiscardedCard = InPlay.Pop();
		DiscardPile.Add(DiscardedCard);
		if (DiscardedCard.CardActor)
		{
			DiscardedCard.CardActor->SetActorLocation(DiscardPileSlot.GetLocation());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("DiscardInPlayCards: CardActor or DiscardPileSlot is NULL!"));
		}
		OnCardDiscarded.Broadcast(DiscardedCard);
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

	// Add to InPlay
	FCardInstance PlayedCard = Hand[Index];
	Hand.RemoveAt(Index);
	InPlay.Add(PlayedCard);

	// Move the actor in the world if it exists
	if (PlayedCard.CardActor)
	{

		if (InPlay.Num() > 0) {
			PlayedCard.CardActor->SetActorLocation(BoardSlots[InPlay.Num() - 1].GetLocation());
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("PlayCardFromHand: BoardSlots index out of range! Make sure BoardSlots are set in Card Deck Setup."));
		}

	}
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

// Called every frame
void ACPP_Card_Deck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


