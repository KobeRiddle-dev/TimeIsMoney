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
    for (int i = 1; i <= 13; i++)
    {
        // Create a new card instance for each card added
        ACPP_Card* bloodCard = NewObject<ACPP_Card>(this, ACPP_Card::StaticClass());
        bloodCard->InitializeCard(ECardSuit::Blood, i);
        PlayerDeck.Add(bloodCard);

        ACPP_Card* timeCard = NewObject<ACPP_Card>(this, ACPP_Card::StaticClass());
        timeCard->InitializeCard(ECardSuit::Time, i);
        PlayerDeck.Add(timeCard);

        ACPP_Card* moneyCard = NewObject<ACPP_Card>(this, ACPP_Card::StaticClass());
        moneyCard->InitializeCard(ECardSuit::Money, i);
        PlayerDeck.Add(moneyCard);

        // Opponent's deck
        ACPP_Card* bloodCardOpponent = NewObject<ACPP_Card>(this, ACPP_Card::StaticClass());
        bloodCardOpponent->InitializeCard(ECardSuit::Blood, i);
        OpponentDeck.Add(bloodCardOpponent);

        ACPP_Card* timeCardOpponent = NewObject<ACPP_Card>(this, ACPP_Card::StaticClass());
        timeCardOpponent->InitializeCard(ECardSuit::Time, i);
        OpponentDeck.Add(timeCardOpponent);

        ACPP_Card* moneyCardOpponent = NewObject<ACPP_Card>(this, ACPP_Card::StaticClass());
        moneyCardOpponent->InitializeCard(ECardSuit::Money, i);
        OpponentDeck.Add(moneyCardOpponent);
    }

    // Initial Shuffle
    PlayerDeck.Sort([this](const ACPP_Card& Item1, const ACPP_Card& Item2) {
        return FMath::RandBool();
        });
    OpponentDeck.Sort([this](const ACPP_Card& Item1, const ACPP_Card& Item2) {
        return FMath::RandBool();
        });

	Super::BeginPlay();
}

ACPP_Card* ACPP_Card_Deck::DrawRandom()
{
    //// Log all cards in PlayerDeck before drawing
    //UE_LOG(LogTemp, Log, TEXT("Current PlayerDeck:"));
    //for (const ACPP_Card* Card : PlayerDeck)
    //{
    //    UE_LOG(LogTemp, Log, TEXT("%d of %s"),
    //        Card->CardNumber,
    //        *StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(Card->CardSuit))
    //    );
    //}

    // If we reached the end of the deck shuffle
    if (playerCardIndex == PlayerDeck.Num())
    {
        PlayerDeck.Sort([this](const ACPP_Card& Item1, const ACPP_Card& Item2) {
            return FMath::RandBool();
            });
    }

    if (opponentCardIndex == OpponentDeck.Num())
    {
        OpponentDeck.Sort([this](const ACPP_Card& Item1, const ACPP_Card& Item2) {
            return FMath::RandBool();
            });
    }

    ACPP_Card* randomPlayerCard = PlayerDeck[playerCardIndex];
    // Add to the Opponent's hand (assuming this is an array of pointers)
    PlayersHeldHand.Add(randomPlayerCard);
    UE_LOG(LogTemp, Log, TEXT("Player Card is: %d of %s"),
        randomPlayerCard->CardNumber,
        *StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(randomPlayerCard->CardSuit))
    );


    ACPP_Card* randomOpponentCard = OpponentDeck[opponentCardIndex];
    // Add to the player's hand (assuming this is an array of pointers)
    OpponentHeldHand.Add(randomOpponentCard);
    UE_LOG(LogTemp, Log, TEXT("Opponent Card is: %d of %s"),
        randomOpponentCard->CardNumber,
        *StaticEnum<ECardSuit>()->GetNameStringByValue(static_cast<int64>(randomOpponentCard->CardSuit))
    );

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

