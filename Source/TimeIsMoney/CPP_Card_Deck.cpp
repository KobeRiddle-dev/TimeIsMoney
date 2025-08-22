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

	// TODO: initialize player and opponent decks with cards

	// Initial Shuffle
	ShufflePlayerDeck();
	ShuffleOpponentDeck();
}

void ACPP_Card_Deck::ShufflePlayerDeck()
{
	PlayerDeck.Sort([this](const ACPP_Card_EffectCard& Item1, const ACPP_Card_EffectCard& Item2) {
		return FMath::RandBool();
		});
	playerCardIndex = 0;

}

void ACPP_Card_Deck::ShuffleOpponentDeck()
{
	OpponentDeck.Sort([this](const ACPP_Card_EffectCard& Item1, const ACPP_Card_EffectCard& Item2) {
		return FMath::RandBool();
		});
	opponentCardIndex = 0;
}

ACPP_Card_EffectCard* ACPP_Card_Deck::DrawRandom()
{
    // If we reached the end of the deck shuffle
    if (playerCardIndex == PlayerDeck.Num())
    {
		ShufflePlayerDeck();
    }

    if (opponentCardIndex == OpponentDeck.Num())
    {
		ShuffleOpponentDeck();
    }

    ACPP_Card_EffectCard* randomPlayerCard = PlayerDeck[playerCardIndex];
	if (!randomPlayerCard){
		UE_LOG(LogTemp, Error, TEXT("Player Card is NULL!"));
	}
    PlayersHeldHand.Add(randomPlayerCard);

    ACPP_Card_EffectCard* randomOpponentCard = OpponentDeck[opponentCardIndex];
	if (!randomOpponentCard) {
		UE_LOG(LogTemp, Error, TEXT("Opponent Card is NULL!"));
	}
    OpponentHeldHand.Add(randomOpponentCard);

    // Increment index values for Decks
    playerCardIndex++;
    opponentCardIndex++;

    // Return the player's randomly drawn card and notify listeners
    OnCardDrawn.Broadcast(randomPlayerCard);
    return randomPlayerCard;
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

void ACPP_Card_Deck::SetPlayerDeck()
{
	// Initialize the player deck with cards
	// This should be done in the editor or through a data table
}

void ACPP_Card_Deck::AddCardToPlayerDeck(UCPP_Data_EffectCards* Card)
{
	// Create a new card instance and add it to the player deck
}

void ACPP_Card_Deck::SetOpponentDeck()
{
	// Initialize the opponent deck with cards
	// This should be done in the editor or through a data table
}

void ACPP_Card_Deck::AddCardToOpponentDeck(UCPP_Data_EffectCards* Card)
{
	// Create a new card instance and add it to the opponent deck
}

