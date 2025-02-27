// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Table_TimeIsMoney.h"

// Sets default values
ACPP_Table_TimeIsMoney::ACPP_Table_TimeIsMoney()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Table_TimeIsMoney::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACPP_Table_TimeIsMoney::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Table_TimeIsMoney::StartGame(ACPP_NPC_Opp_TimeIsMoney* Opp)
{
	// reset player hand wins
	PlayerHands[ECardSuit::Blood] = 0;
	PlayerHands[ECardSuit::Time] = 0;
	PlayerHands[ECardSuit::Money] = 0;
	// reset opponent hand wins
	OpponentHands[ECardSuit::Blood] = 0;
	OpponentHands[ECardSuit::Time] = 0;
	OpponentHands[ECardSuit::Money] = 0;
	// reset opponent
	Opponent = Opp;
}

void ACPP_Table_TimeIsMoney::StartHand()
{
	Opponent->PlayCard();
}

void ACPP_Table_TimeIsMoney::CheckForEndGame()
{
	if (CheckIfWin(PlayerHands))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Wins"));
		// TODO: emit result to listeners and/or cleanup game
	}
	else if (CheckIfWin(OpponentHands))
	{
		UE_LOG(LogTemp, Warning, TEXT("Opponent Wins"));
		// TODO: emit result to listeners and/or cleanup game
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

bool ACPP_Table_TimeIsMoney::DetermineWinner(ACPP_Card* Player, ACPP_Card* Opponent)
{
	// Check if Player or Opponent is null to prevent crashes
	if (!Player || !Opponent)
	{
		UE_LOG(LogTemp, Error, TEXT("DetermineWinner: Player or Opponent is null!"));
		return false;
	}

	// Find game result
	bool playerIsWin = false;
	if (Player->CardSuit == ECardSuit::Blood && Opponent->CardSuit == ECardSuit::Time)
	{
		playerIsWin = true;
	}
	else if (Player->CardSuit == ECardSuit::Time && Opponent->CardSuit == ECardSuit::Money)
	{
		playerIsWin = true;
	}
	else if (Player->CardSuit == ECardSuit::Money && Opponent->CardSuit == ECardSuit::Blood)
	{
		playerIsWin = true;
	}
	else if (Player->CardSuit == Opponent->CardSuit)
	{
		if (Player->CardNumber > Opponent->CardNumber)
		{
			playerIsWin = true;
		}
		else if (Player->CardNumber == Opponent->CardNumber)
		{
			UE_LOG(LogTemp, Warning, TEXT("Tie"));
			return true;
		}
	}
	// Store the result of the game
	if (playerIsWin)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Wins"));
		PlayerHands[Player->CardSuit]++;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Loses"));
		OpponentHands[Opponent->CardSuit]++;
	}
	CheckForEndGame();
	return playerIsWin;
}

