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
	OnHandStart.Broadcast();

	if (!GameIsActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("Game is not active. Cannot start hand."));
		return false;
	}

	// Empty the board
	OppCards.Empty();
	PlayerCards.Empty();

	// Null Check for `Deck`
	if (!Deck)
	{
		UE_LOG(LogTemp, Error, TEXT("StartHand: Deck is NULL!"));
		return false;
	}
	// Discard old hand
	if (Deck->PlayersHeldHand.Num() > 0)
	{
		Deck->DiscardHands();
	}
	// Draw new hand
	int drawPower = 5;
	int maxHandSize = 5;
	while (Deck->PlayersHeldHand.Num() < drawPower && Deck->PlayersHeldHand.Num() < maxHandSize)
	{
		Deck->DrawRandom();
	}

	// Determine starting suits and reset number value
	PublicPlayerCard->SetCardNumber(0);
	PlayerStartingSuit = GetRandomSuit();
	PrivatePlayerCard->InitializeCard(PlayerStartingSuit, 0);
	TruePlayerCard->InitializeCard(PlayerStartingSuit, 0);
	OppStartingSuit = GetRandomSuit();
	PublicOppCard->SetCardNumber(0);
	PrivateOppCard->InitializeCard(OppStartingSuit, 0);
	TrueOppCard->InitializeCard(OppStartingSuit, 0);

	// TODO: Determine who goes first. Right now opp always goes first.
	// Null Check for `Opponent`
	if (!Opponent)
	{
		UE_LOG(LogTemp, Error, TEXT("StartHand: Opponent is NULL!"));
		return false;
	}
	// Opponenet plays a card
	OppCards.Add(Opponent->PlayCard());
	CPP_CardEffectEvaluator::ApplyEffect(OppCards.Last()->RevealedEffects, this, true);
	CPP_CardEffectEvaluator::ApplyEffect(OppCards.Last()->HiddenEffects, this, false);
	OnOppCardPlayed.Broadcast(OppCards.Last());

	// for debugging
	UE_LOG(LogTemp, Log, TEXT("Opponent Card is: %d of %s"),
		PublicOppCard->CardNumber,
		*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(PublicOppCard->CardSuit))
	);
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
		Deck->DiscardHands();
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
	for (int i = 0; i < PlayerCards.Num(); i++)
	{
		CPP_CardEffectEvaluator::ApplyEffect(OppCards[i]->RevealedEffects, this, true);
		CPP_CardEffectEvaluator::ApplyEffect(OppCards[i]->HiddenEffects, this, false);

		CPP_CardEffectEvaluator::ApplyEffect(PlayerCards[i]->RevealedEffects, this, true);
		CPP_CardEffectEvaluator::ApplyEffect(PlayerCards[i]->HiddenEffects, this, false);
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

void ACPP_Table_TimeIsMoney::PlayCard(ACPP_Card_EffectCard* PlayerCard)
{
	// Add the card to the player's board
	PlayerCards.Add(PlayerCard);
	CPP_CardEffectEvaluator::ApplyEffect(PlayerCard->RevealedEffects, this, true);
	CPP_CardEffectEvaluator::ApplyEffect(PlayerCard->HiddenEffects, this, false);
	OnPlayerCardPlayed.Broadcast(PlayerCard);

	// Add a card from the opponenet's hand to their board
	if (Deck->OpponentHeldHand.Num() > 0)
	{
		OppCards.Add(Opponent->PlayCard());
		//CPP_CardEffectEvaluator::ApplyEffect(OppCards.Last()->RevealedEffects, this);
		OnOppCardPlayed.Broadcast(OppCards.Last());
	}

	// If this is the 6th card, determine the winner
	if (PlayerCards.Num() >= 3) {
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