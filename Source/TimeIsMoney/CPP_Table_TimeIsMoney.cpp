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

bool ACPP_Table_TimeIsMoney::DetermineWinner(ACPP_Card* Player, ACPP_Card* Opp)
{
	OnHandStart.Broadcast();

	if (!Player)
	{
		UE_LOG(LogTemp, Error, TEXT("DetermineWinner: Player null!"));
		return false;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Player played: %d of %s"),
			Player->CardNumber,
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(Player->CardSuit))
		);
		OnPlayerCardPlayed.Broadcast(Player);
	}

	if (!Opp)
	{
		UE_LOG(LogTemp, Error, TEXT("DetermineWinner: Opponent is null!"));
		return false;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Opponent played: %d of %s"),
			Opp->CardNumber,
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(Opp->CardSuit))
		);
		OnOppCardPlayed.Broadcast(Opp);
	}

	bool playerIsWin = false;
	if ((Player->CardSuit == ECardSuit::Blood && Opp->CardSuit == ECardSuit::Time) ||	// blood beats time
		(Player->CardSuit == ECardSuit::Time && Opp->CardSuit == ECardSuit::Money) ||	// time beats money
		(Player->CardSuit == ECardSuit::Money && Opp->CardSuit == ECardSuit::Blood) ||	// money beats blood
		(Player->CardSuit == Opp->CardSuit && Player->CardNumber >= Opp->CardNumber))	// same suit, higher number wins
	{
		playerIsWin = true;
	}

	if (playerIsWin)
	{
		UE_LOG(LogTemp, Log, TEXT("Player Wins %s"),
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(Player->CardSuit))
		);
		PlayerHands[Player->CardSuit]++;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Opponent Wins %s"),
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(Opp->CardSuit))
		);
		OppHands[Opp->CardSuit]++;
	}

	CheckForEndGame();
	if (GameIsActive)
	{
		StartHand();
	}

	OnWinnerDetermined.Broadcast();
	return playerIsWin;
}