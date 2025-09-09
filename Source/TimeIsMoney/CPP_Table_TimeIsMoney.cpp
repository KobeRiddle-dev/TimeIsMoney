// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Table_TimeIsMoney.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACPP_Table_TimeIsMoney::ACPP_Table_TimeIsMoney()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACPP_Table_TimeIsMoney::BeginPlay()
{
	Super::BeginPlay();
	ResetHands();
	GameIsActive = false;
}

// Called every frame
void ACPP_Table_TimeIsMoney::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPP_Table_TimeIsMoney::StartGame()
{
	ResetHands();
	GameIsActive = true;
	PlayerGoesFirst = FMath::RandBool();	// this will alternate each hand
	OnHandStart.Broadcast();

	StartHand();
}

void  ACPP_Table_TimeIsMoney::RandomizeStartSettings()
{
	// Randomize who goes first
	PlayerGoesFirst = FMath::RandBool();

	// Randomize the starting suits
	PlayerStartingSuit = GetRandomSuit();
	OppStartingSuit = GetRandomSuit();

	UE_LOG(LogTemp, Log, TEXT("Randomized Start Settings -> PlayerGoesFirst: %s, PlayerSuit: %s, OppSuit: %s"),
		PlayerGoesFirst ? TEXT("True") : TEXT("False"),
		*StaticEnum<ECardSuit>()->GetNameStringByValue((int64)PlayerStartingSuit),
		*StaticEnum<ECardSuit>()->GetNameStringByValue((int64)OppStartingSuit));
}

void ACPP_Table_TimeIsMoney::ResetHands()
{
	// Reset player hand wins
	PlayerHands.FindOrAdd(ECardSuit::Blood) = 0;
	PlayerHands.FindOrAdd(ECardSuit::Time) = 0;
	PlayerHands.FindOrAdd(ECardSuit::Money) = 0;

	OppHands.FindOrAdd(ECardSuit::Blood) = 0;
	OppHands.FindOrAdd(ECardSuit::Time) = 0;
	OppHands.FindOrAdd(ECardSuit::Money) = 0;
}

bool ACPP_Table_TimeIsMoney::StartHand()
{
	UE_LOG(LogTemp, Log, TEXT("Starting Hand"));
	if (!GameIsActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("Game is not active. Cannot start hand."));
		return false;
	}
	// Null Check for `Deck` FIRST
	if (!IsValid(PlayerDeck) || !IsValid(OpponentDeck))
	{
		UE_LOG(LogTemp, Error, TEXT("StartHand: PlayerDeck or OpponentDeck is NULL/invalid!"));
		return false;
	}

	// Set who goes first
	PlayerGoesFirst = !PlayerGoesFirst;
	IsPlayerTurn = PlayerGoesFirst;
	// Empty the board
	PlayerDeck->DiscardInPlayCards();
	OpponentDeck->DiscardInPlayCards();
	// Discard old hand
	PlayerDeck->DiscardHand();
	OpponentDeck->DiscardHand();
	// Draw 5 cards to hand
	for (int i = 0; i < 5; i++)
	{
		PlayerDeck->DrawRandom();
		OpponentDeck->DrawRandom();
	}
	// Determine starting suits and reset number value
	PlayerStartingSuit = GetRandomSuit();
	PublicPlayerCard->InitializeCard(ECardSuit::Unknown, 0);
	PrivatePlayerCard->InitializeCard(PlayerStartingSuit, 0);
	TruePlayerCard->InitializeCard(PlayerStartingSuit, 0);
	OppStartingSuit = GetRandomSuit();
	PublicOppCard->InitializeCard(ECardSuit::Unknown, 0);
	PrivateOppCard->InitializeCard(OppStartingSuit, 0);
	TrueOppCard->InitializeCard(OppStartingSuit, 0);

	// Notify listeners
	OnHandStart.Broadcast();
	IsAnimationPlaying = false;
	return true;
}


bool ACPP_Table_TimeIsMoney::CheckForEndGame()
{
	if (CheckIfWin(PlayerHands))
	{
		UE_LOG(LogTemp, Log, TEXT("Player Wins The Game"));
		GameIsActive = false;
		OnGameEnded.Broadcast(true);
	}
	else if (CheckIfWin(OppHands))
	{
		UE_LOG(LogTemp, Log, TEXT("Opponent Wins The Game"));
		GameIsActive = false;
		OnGameEnded.Broadcast(false);
	}

	if (!GameIsActive)
	{
		PlayerDeck->DiscardHand();
	}

	return GameIsActive;
}

bool ACPP_Table_TimeIsMoney::CheckIfWin(TMap<ECardSuit, int> PlayerBeingChecked)
{
	bool hasThreeWins = false;
	bool hasOneWinInEachSuit = true;

	for (const auto& suit : PlayerBeingChecked)
	{
		if (suit.Value >= 3)
		{
			hasThreeWins = true;
		}
		if (suit.Value <= 0)
		{
			hasOneWinInEachSuit = false;
		}
	}

	return hasThreeWins || hasOneWinInEachSuit;
}

void ACPP_Table_TimeIsMoney::EvaluateEffect_AnimationFinished(FCardInstance Card)
{

	Card.CardActor->PlayEffectAnimation(ECardEffectType::None);	// TODO: animations for every effect type
	CPP_CardEffectEvaluator::ApplyEffect(
		Card.CardData->RevealedEffects,
		this,
		Card.CardActor,
		true,
		IsPlayerTurn
	);
	CPP_CardEffectEvaluator::ApplyEffect(
		Card.CardData->HiddenEffects,
		this,
		Card.CardActor,
		false,
		IsPlayerTurn
	);
	IsPlayerTurn = !IsPlayerTurn;
}

// TODO: We need to queue up effect animations and play them all
// sequentially, then determine winner after all of the effects are done.
// The camera should follow the card whose effect is being played.
void ACPP_Table_TimeIsMoney::RevealAllCardEffects()
{
	// Apply the Hidden and Revealed effects of the cards
	UE_LOG(LogTemp, Log, TEXT("Revealing All Card Effects"));
	IsAnimationPlaying = true;
	OnBeginEffectReveal.Broadcast();
	IsPlayerTurn = PlayerGoesFirst; 
	PublicPlayerCard->InitializeCard(PlayerStartingSuit, 0);
	TruePlayerCard->InitializeCard(PlayerStartingSuit, 0);
	PrivatePlayerCard->InitializeCard(PlayerStartingSuit, 0);
	PublicOppCard->InitializeCard(OppStartingSuit, 0);
	TrueOppCard->InitializeCard(OppStartingSuit, 0);
	PrivateOppCard->InitializeCard(OppStartingSuit, 0);
	PlayEffectRevealAnimation();
}

bool ACPP_Table_TimeIsMoney::DetermineWinner()
{
	// Determine winner based on suit and number
	bool playerIsWin = false;
	if ((TruePlayerCard->CardSuit == ECardSuit::Blood && TrueOppCard->CardSuit == ECardSuit::Time) ||	// blood beats time
		(TruePlayerCard->CardSuit == ECardSuit::Time && TrueOppCard->CardSuit == ECardSuit::Money) ||	// time beats money
		(TruePlayerCard->CardSuit == ECardSuit::Money && TrueOppCard->CardSuit == ECardSuit::Blood) ||	// money beats blood
		(TruePlayerCard->CardSuit == TrueOppCard->CardSuit && TruePlayerCard->CardNumber > TrueOppCard->CardNumber))	// same suit, higher number wins
	{
		playerIsWin = true;
	}

	// Store the winner of the hand
	if (playerIsWin)
	{
		UE_LOG(LogTemp, Log, TEXT("Player Wins %s"),
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(TruePlayerCard->CardSuit))
		);
		PlayerHands[TruePlayerCard->CardSuit]++;
	}
	else if (TruePlayerCard->CardSuit == TrueOppCard->CardSuit && TruePlayerCard->CardNumber == TrueOppCard->CardNumber)
	{
		// Absolute tie, both win
		UE_LOG(LogTemp, Log, TEXT("Absolute Tie, Both Win %s"),
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(TruePlayerCard->CardSuit))
		);
		PlayerHands[TruePlayerCard->CardSuit]++;
		OppHands[TrueOppCard->CardSuit]++;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Opponent Wins %s"),
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(TrueOppCard->CardSuit))
		);
		OppHands[TrueOppCard->CardSuit]++;
	}

	// Check if the game is over
	CheckForEndGame();
	if (GameIsActive)
	{
		StartHand();
	}

	// Notify listeners that the winner has been determined
	OnWinnerDetermined.Broadcast();
	return playerIsWin;
}

void ACPP_Table_TimeIsMoney::PlayCard(ACPP_Card_EffectCard* PlayedCard)
{
	// Safety checks
	if (!GameIsActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("Game is not active. Cannot play a card."));
		return;
	}
	if (IsAnimationPlaying)
	{
		UE_LOG(LogTemp, Warning, TEXT("Card animation in progress. Cannot play card yet."));
		return;
	}
	if (!PlayedCard)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayedCard is nullptr."));
		return;
	}
	if (!IsValid(PlayerDeck) || !IsValid(OpponentDeck))
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerDeck or OpponentDeck is nullptr or invalid."));
		return;
	}
	if (PlayerDeck->InPlay.Num() >= 3 && OpponentDeck->InPlay.Num() >= 3)
	{
		UE_LOG(LogTemp, Warning, TEXT("Both players have 3 cards in play. Cannot play more cards."));
		return;
	}

	IsAnimationPlaying = true; // Will be reset when animation finishes by Card_Deck::PlayCardAnimation

	ACPP_Card_Deck* ActiveDeck = IsPlayerTurn ? PlayerDeck : OpponentDeck;
	if (!IsValid(ActiveDeck))
	{
		UE_LOG(LogTemp, Error, TEXT("ActiveDeck is invalid."));
		IsAnimationPlaying = false;
		return;
	}
	ActiveDeck->PlayCardFromHand(PlayedCard);
	if (PlayedCard->CardData)
	{
		CPP_CardEffectEvaluator::ApplyEffect(
			PlayedCard->CardData->RevealedEffects, 
			this,
			PlayedCard,
			true, 
			IsPlayerTurn
		);
		CPP_CardEffectEvaluator::ApplyEffect(
			PlayedCard->CardData->HiddenEffects, 
			this, 
			PlayedCard,
			false, 
			IsPlayerTurn
		);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("PlayedCard->CardData is nullptr. Skipping effects."));
	}

	if (IsPlayerTurn)
	{
		OnPlayerCardPlayed.Broadcast(PlayedCard);
	}
	else
	{
		OnOppCardPlayed.Broadcast(PlayedCard);
	}
	if (PlayerDeck->InPlay.Num() >= 3 && OpponentDeck->InPlay.Num() >= 3)
	{
		RevealAllCardEffects();
		return;
	}
	IsPlayerTurn = !IsPlayerTurn;
}

ECardSuit ACPP_Table_TimeIsMoney::GetRandomSuit()
{
	TArray<ECardSuit> Suits;
	Suits.Add(ECardSuit::Blood);
	Suits.Add(ECardSuit::Time);
	Suits.Add(ECardSuit::Money);
	int32 RandomIndex = FMath::RandRange(0, Suits.Num() - 1);
	return Suits[RandomIndex];
}

