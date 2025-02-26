// Fill out your copyright notice in the Description page of Project Settings.


#include "Table_TimeBloodMoney.h"

// Sets default values
ATable_TimeBloodMoney::ATable_TimeBloodMoney()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATable_TimeBloodMoney::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATable_TimeBloodMoney::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATable_TimeBloodMoney::DetermineWinner(ACPP_Card* Player, ACPP_Card* Opponent)
{
    // Check if Player or Opponent is null to prevent crashes
    if (!Player || !Opponent)
    {
        UE_LOG(LogTemp, Error, TEXT("DetermineWinner: Player or Opponent is null!"));
        return false;
    }

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

    if (playerIsWin)
    {
        UE_LOG(LogTemp, Warning, TEXT("Player Wins"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Player Loses"));
    }
    return playerIsWin;
}

