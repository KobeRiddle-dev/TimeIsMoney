

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
}

ACPP_Card* ACPP_Card_Deck::DrawRandom()
{
    // Dynamically allocate memory for the card
    ACPP_Card* randomCard = NewObject<ACPP_Card>(this, ACPP_Card::StaticClass());

    if (randomCard)
    {
        switch (rand() % 3)
        {
        case 0:
            randomCard->InitializeCard(ECardSuit::Blood, (rand() % 13) + 1);
            break;  
        case 1:
            randomCard->InitializeCard(ECardSuit::Time, (rand() % 13) + 1);
            break;
        case 2:
            randomCard->InitializeCard(ECardSuit::Money, (rand() % 13) + 1);
            break;
        }
        // Add to the Opponent's hand (assuming this is an array of pointers)
        OpponentHeldHand.Add(randomCard);
        UE_LOG(LogTemp, Log, TEXT("Opponent Drew: %d of %d"), randomCard->CardNumber, randomCard->CardSuit);

        // Initialize the card with a random suit and rank
        switch (rand() % 3)
        {
        case 0:
            randomCard->InitializeCard(ECardSuit::Blood, (rand() % 13) + 1);
            break;  
        case 1:
            randomCard->InitializeCard(ECardSuit::Time, (rand() % 13) + 1);
            break;
        case 2:
            randomCard->InitializeCard(ECardSuit::Money, (rand() % 13) + 1);
            break;
        }
        // Add to the player's hand (assuming this is an array of pointers)
        PlayersHeldHand.Add(randomCard);
        UE_LOG(LogTemp, Log, TEXT("Player Drew: %d of %d"), randomCard->CardNumber, randomCard->CardSuit);

        // Return the player's randomly drawn card and notify listeners
		OnCardDrawn.Broadcast(randomCard);
        return randomCard;
    }

    return nullptr;  // In case something goes wrong
}

void ACPP_Card_Deck::DiscardHands()
{
	UE_LOG(LogTemp, Log, TEXT("Discarding hands"));
	// Clear the player's hand
	for (ACPP_Card* card : PlayersHeldHand)
	{
		card->Destroy();
	}
	PlayersHeldHand.Empty();
	// Clear the opponent's hand
	for (ACPP_Card* card : OpponentHeldHand)
	{
		card->Destroy();
	}
	OpponentHeldHand.Empty();

	// Notify listeners that the hands have been discarded
	OnHandDiscarded.Broadcast();
}

 
// Called every frame
void ACPP_Card_Deck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

