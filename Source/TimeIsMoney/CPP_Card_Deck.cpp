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
    ACPP_Card* card = NewObject<ACPP_Card>(this, ACPP_Card::StaticClass());

    playerCardIndex = 0;
    opponentCardIndex = 0;

    // There are 13 cards per suit so loop through the 13 cards
    for (int i = 0; i < 13; i++)
    {
        /// Initialize the Player Deck
        card->InitializeCard(ECardSuit::Blood, i);
        PlayerDeck.Add(card);
        card->InitializeCard(ECardSuit::Time, i);
        PlayerDeck.Add(card);
        card->InitializeCard(ECardSuit::Money, i);
        PlayerDeck.Add(card);

        // Initialize the Opponent Deck
        card->InitializeCard(ECardSuit::Blood, i);
        OpponentDeck.Add(card);
        card->InitializeCard(ECardSuit::Time, i);
        OpponentDeck.Add(card);
        card->InitializeCard(ECardSuit::Money, i);
        OpponentDeck.Add(card);
    }

    ShuffleDeck(PlayerDeck);
    ShuffleDeck(OpponentDeck);

	Super::BeginPlay();
}

ACPP_Card* ACPP_Card_Deck::DrawRandom()
{
    // If we reached the end of the deck shuffle
    if (playerCardIndex == PlayerDeck.Num())
    {
        ShuffleDeck(PlayerDeck);
    }

    if (opponentCardIndex == OpponentDeck.Num())
    {
        ShuffleDeck(OpponentDeck);
    }

    ACPP_Card* randomPlayerCard = PlayerDeck[playerCardIndex];
    // Add to the Opponent's hand (assuming this is an array of pointers)
    PlayersHeldHand.Add(randomPlayerCard);
    UE_LOG(LogTemp, Log, TEXT("Player Drew: %d of %d"), randomPlayerCard->CardNumber, randomPlayerCard->CardSuit);


    ACPP_Card* randomOpponentCard = OpponentDeck[opponentCardIndex];
    // Add to the player's hand (assuming this is an array of pointers)
    OpponentHeldHand.Add(randomOpponentCard);
    UE_LOG(LogTemp, Log, TEXT("Opponent Drew: %d of %d"), randomOpponentCard->CardNumber, randomOpponentCard->CardSuit);

    // Increment index values for Decks
    playerCardIndex++;
    opponentCardIndex++;

    // Return the player's randomly drawn card and notify listeners
    OnCardDrawn.Broadcast(randomPlayerCard);
    return randomPlayerCard;
}

void ACPP_Card_Deck::ShuffleDeck(TArray<ACPP_Card*> deck)
{
    // Shuffle algorithm grabbed from: https://forums.unrealengine.com/t/equivalent-of-bp-shuffle-array-for-c-tarrays/349431/2
    if (deck.Num() > 0)
    {
        int32 lastIndex = deck.Num() - 1;
        for (int32 i = 0; i <= lastIndex; ++i)
        {
            int32 index = FMath::RandRange(i, lastIndex);
            if (i != index)
            {
                deck.Swap(i, index);
            }
        }
    }
}

void ACPP_Card_Deck::DiscardHands()
{
	UE_LOG(LogTemp, Log, TEXT("Discarding hands"));

	// Clear the player's hand
	PlayersHeldHand.Empty();

	// Clear the opponent's hand
	OpponentHeldHand.Empty();

	// Notify listeners that the hands have been discarded
	OnHandDiscarded.Broadcast();
}

 
// Called every frame
void ACPP_Card_Deck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

