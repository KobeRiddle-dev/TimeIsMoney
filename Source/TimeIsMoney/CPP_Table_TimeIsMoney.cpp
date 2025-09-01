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
	OnHandStart.Broadcast();

	StartHand();
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

	// Null Check for `Opponent`
	if (!IsValid(OpponentAI))
	{
		UE_LOG(LogTemp, Error, TEXT("StartHand: OpponentAI is NULL/invalid!"));
		return false;
	}
	// Opponent plays a card
	ACPP_Card_EffectCard* OppCard = OpponentAI->PlayCard();
	if (!IsValid(OppCard))
	{
		UE_LOG(LogTemp, Error, TEXT("StartHand: OpponentAI returned null card!"));
		return false;
	}
	// Safely play the card and apply effects
	OpponentDeck->PlayCardFromHand(OppCard);
	// CardData check: never assume it exists
	if (!IsValid(OppCard->CardData))
	{
		UE_LOG(LogTemp, Error, TEXT("StartHand: OppCard has no CardData!"));
	}
	else
	{
		CPP_CardEffectEvaluator::ApplyEffect(OppCard->CardData->RevealedEffects, this, true, false);
		CPP_CardEffectEvaluator::ApplyEffect(OppCard->CardData->HiddenEffects, this, false, false);
	}
	OnOppCardPlayed.Broadcast(OppCard);

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

bool ACPP_Table_TimeIsMoney::DetermineWinner()
{
	// TODO: need to make this more robust, currently assumes opp always goes first
	// Apply the Hidden and Revealed effects of the cards
	OnBeginEffectReveal.Broadcast();
	PublicPlayerCard->InitializeCard(PlayerStartingSuit, 0);
	PublicOppCard->InitializeCard(OppStartingSuit, 0);
	for (int i = 0; i < PlayerDeck->InPlay.Num(); i++)
	{
		CPP_CardEffectEvaluator::ApplyEffect(
			OpponentDeck->InPlay[i].CardData->RevealedEffects, 
			this, 
			true,
			false
		);
		CPP_CardEffectEvaluator::ApplyEffect(
			OpponentDeck->InPlay[i].CardData->HiddenEffects, 
			this, 
			false,
			false
		);

		CPP_CardEffectEvaluator::ApplyEffect(
			PlayerDeck->InPlay[i].CardData->RevealedEffects, 
			this, 
			true,
			true
		);
		CPP_CardEffectEvaluator::ApplyEffect(
			PlayerDeck->InPlay[i].CardData->HiddenEffects, 
			this, 
			false,
			true
		);
	}

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

// TODO: This function should just play a card agnostic of player or opponent
void ACPP_Table_TimeIsMoney::PlayCard(ACPP_Card_EffectCard* PlayerCard)
{
	// Add the card to the player's board
	PlayerDeck->PlayCardFromHand(PlayerCard);
	CPP_CardEffectEvaluator::ApplyEffect(PlayerCard->CardData->RevealedEffects, this, true, true);
	CPP_CardEffectEvaluator::ApplyEffect(PlayerCard->CardData->HiddenEffects, this, false, true);
	OnPlayerCardPlayed.Broadcast(PlayerCard);

	// Play a card from the opponent's hand in response
	ACPP_Card_EffectCard* OppCard = OpponentAI->PlayCard();
	OpponentDeck->PlayCardFromHand(OppCard);
	CPP_CardEffectEvaluator::ApplyEffect(OppCard->CardData->RevealedEffects, this, true, false);
	CPP_CardEffectEvaluator::ApplyEffect(OppCard->CardData->HiddenEffects, this, false, false);
	OnOppCardPlayed.Broadcast(OppCard);

	// If this is the 6th card, determine the winner
	if (PlayerDeck->InPlay.Num() >= 3) {
		DetermineWinner();
	}
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
