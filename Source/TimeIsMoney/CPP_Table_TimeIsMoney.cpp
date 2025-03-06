// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "CPP_Table_TimeIsMoney.h"

// Sets default values
ACPP_Table_TimeIsMoney::ACPP_Table_TimeIsMoney()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACPP_Table_TimeIsMoney::BeginPlay()
{
	Super::BeginPlay();

	// Initialize PlayerHands and OpponentHands with default values (0 wins)
	PlayerHands.Add(ECardSuit::Blood, 0);
	PlayerHands.Add(ECardSuit::Time, 0);
	PlayerHands.Add(ECardSuit::Money, 0);

	OppHand.Add(ECardSuit::Blood, 0);
	OppHand.Add(ECardSuit::Time, 0);
	OppHand.Add(ECardSuit::Money, 0);

	GameIsActive = false;
}

// Called every frame
void ACPP_Table_TimeIsMoney::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Table_TimeIsMoney::StartGame()
{
	// Reset player hand wins
	PlayerHands[ECardSuit::Blood] = 0;
	PlayerHands[ECardSuit::Time] = 0;
	PlayerHands[ECardSuit::Money] = 0;

	// Reset opponent hand wins
	OppHand[ECardSuit::Blood] = 0;
	OppHand[ECardSuit::Time] = 0;
	OppHand[ECardSuit::Money] = 0;

	GameIsActive = true;
	OnHandStart.Broadcast();
	StartHand();
}

bool ACPP_Table_TimeIsMoney::StartHand()
{
	UE_LOG(LogTemp, Log, TEXT("Starting Hand"));
	if (!GameIsActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("Game is not active. Cannot start hand."));
		return false;
	}

	// Discard old hand
	if (Deck->PlayersHeldHand.Num() > 0)
	{
		Deck->DiscardHands();
	}

	// Draw new hand
	int drawPower = 3;
	int maxHandSize = 3;
	while (Deck->PlayersHeldHand.Num() < drawPower && Deck->PlayersHeldHand.Num() < maxHandSize)
	{
		Deck->DrawRandom();
	}
	OppCard = Opponent->PlayCard();
	UE_LOG(LogTemp, Log, TEXT("Opponent Card is: %d of %s"),
		OppCard->CardNumber,
		*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(OppCard->CardSuit))
	);
	return true;
}

void ACPP_Table_TimeIsMoney::CheckForEndGame()
{
	if (CheckIfWin(PlayerHands))
	{
		UE_LOG(LogTemp, Log, TEXT("Player Wins The Game"));
		// TODO: emit result to listeners and/or cleanup game
		GameIsActive = false;
	}
	else if (CheckIfWin(OppHand))
	{
		UE_LOG(LogTemp, Log, TEXT("Opponent Wins The Game"));
		// TODO: emit result to listeners and/or cleanup game
		GameIsActive = false;
	}

	if (!GameIsActive)
	{
		Deck->DiscardHands();
	}
}

bool ACPP_Table_TimeIsMoney::CheckIfWin(TMap<ECardSuit, int> PlayerBeingChecked)
{
	// Check if player has 3 wins in any suit
	for (const auto& suit : PlayerBeingChecked)
	{
		if (suit.Value >= 3)
		{
			return true;
		}
	}
	// Check if player has 1 or more wins in every suit
	bool playerIsWin = true;
	for (const auto& suit : PlayerBeingChecked)
	{
		if (suit.Value <= 0)
		{
			playerIsWin = false;
		}
	}
	return playerIsWin;
}

bool ACPP_Table_TimeIsMoney::DetermineWinner(ACPP_Card* Player, ACPP_Card* Opp)
{
	OnHandStart.Broadcast();
	// Check if Player or Opponent is null to prevent crashes
	if (!Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("DetermineWinner: Player null!"));
		return false;
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("Player played: %d of %s"),
			Player->CardNumber,
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(Player->CardSuit))
		);
		OnPlayerCardPlayed.Broadcast(Player);
	}
	if (!Opp) {
		UE_LOG(LogTemp, Warning, TEXT("DetermineWinner: Opponent is null!"));
		return false;
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("Opponent played: %d of %s"),
			Opp->CardNumber,
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(Opp->CardSuit))
		);
		OnOppCardPlayed.Broadcast(Opp);
	}

	// Find game result
	bool playerIsWin = false;
	if (Player->CardSuit == ECardSuit::Blood && Opp->CardSuit == ECardSuit::Time)
	{
		playerIsWin = true;
	}
	else if (Player->CardSuit == ECardSuit::Time && Opp->CardSuit == ECardSuit::Money)
	{
		playerIsWin = true;
	}
	else if (Player->CardSuit == ECardSuit::Money && Opp->CardSuit == ECardSuit::Blood)
	{
		playerIsWin = true;
	}
	else if (Player->CardSuit == Opp->CardSuit)
	{
		if (Player->CardNumber > Opp->CardNumber)
		{
			playerIsWin = true;
		}
		else if (Player->CardNumber == Opp->CardNumber)
		{
			UE_LOG(LogTemp, Log, TEXT("Tie"));
			playerIsWin = true;
		}
	}

	// Store the result of the game
	if (playerIsWin)
	{
		UE_LOG(LogTemp, Log, TEXT("Player Wins"));
		PlayerHands[Player->CardSuit]++;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Player Loses"));
		OppHand[Opp->CardSuit]++;
	}

	// Check if the game is over
	CheckForEndGame();
	if (GameIsActive)
	{
		StartHand();
	}

	return playerIsWin;
}
