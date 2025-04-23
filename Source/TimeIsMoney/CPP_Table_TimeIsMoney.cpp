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

	// Tmp while we only play 1 card
	Deck->DrawRandom();
	PublicOppCard = Opponent->PlayCard();
	OnOppCardPlayed.Broadcast(PublicOppCard);
	// Tmp while we only play 1 card

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

	// Null Check for `Opponent`
	if (!Opponent)
	{
		UE_LOG(LogTemp, Error, TEXT("StartHand: Opponent is NULL!"));
		return false;
	}
	// Opponenet play their first card
	OppCards.Add(Opponent->PlayCard());
	PublicOppCard = OppCards.Last();
	// Null Check for `OppCard`
	if (!PublicOppCard)
	{
		UE_LOG(LogTemp, Error, TEXT("StartHand: Opponent played a NULL card!"));
		return false;
	}
	UE_LOG(LogTemp, Log, TEXT("Opponent Card is: %d of %s"),
		PublicOppCard->CardNumber,
		*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(PublicOppCard->CardSuit))
	);
	//OnOppCardPlayed.Broadcast(PublicOppCard);		Disabled while we only play 1 card

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
	// Null check the cards values being compared
	if (!PublicPlayerCard)
	{
		UE_LOG(LogTemp, Error, TEXT("DetermineWinner: Player null!"));
		return false;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Player played: %d of %s"),
			PublicPlayerCard->CardNumber,
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(PublicPlayerCard->CardSuit))
		);
		
	}
	if (!PublicOppCard)
	{
		UE_LOG(LogTemp, Error, TEXT("DetermineWinner: Opponent is null!"));
		return false;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Opponent played: %d of %s"),
			PublicOppCard->CardNumber,
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(PublicOppCard->CardSuit))
		);
	}

	// Determine winner based on suit and number
	bool playerIsWin = false;
	if ((PublicPlayerCard->CardSuit == ECardSuit::Blood && PublicOppCard->CardSuit == ECardSuit::Time) ||	// blood beats time
		(PublicPlayerCard->CardSuit == ECardSuit::Time && PublicOppCard->CardSuit == ECardSuit::Money) ||	// time beats money
		(PublicPlayerCard->CardSuit == ECardSuit::Money && PublicOppCard->CardSuit == ECardSuit::Blood) ||	// money beats blood
		(PublicPlayerCard->CardSuit == PublicOppCard->CardSuit && PublicPlayerCard->CardNumber >= PublicOppCard->CardNumber))	// same suit, higher number wins
	{
		playerIsWin = true;
	}

	// Store the winner of the hand
	if (playerIsWin)
	{
		UE_LOG(LogTemp, Log, TEXT("Player Wins %s"),
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(PublicPlayerCard->CardSuit))
		);
		PlayerHands[PublicPlayerCard->CardSuit]++;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Opponent Wins %s"),
			*StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(PublicOppCard->CardSuit))
		);
		OppHands[PublicOppCard->CardSuit]++;
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

void ACPP_Table_TimeIsMoney::PlayCard(ACPP_Card* PlayerCard)
{
	// Add the card to the player's board
	PlayerCards.Add(PlayerCard);
	PublicPlayerCard = PlayerCards.Last();
	OnPlayerCardPlayed.Broadcast(PublicPlayerCard);

	// TEMPORARY: Only play one card
	if (PlayerCards.Num() >= 1)
	{
		DetermineWinner();
		return;
	}

	// TODO:
	//// Add a card from the opponenet's hand to their board
	//if (Deck->OpponentHeldHand.Num() > 0)
	//{
	//	OppCards.Add(Opponent->PlayCard());
	//	PublicOppCard = OppCards.Last();
	//	OnOppCardPlayed.Broadcast(PublicOppCard);
	//}

	//// If this is the 6th card, determine the winner
	//if (PlayerCards.Num() >= 3) {
	//	DetermineWinner();
	//}
}