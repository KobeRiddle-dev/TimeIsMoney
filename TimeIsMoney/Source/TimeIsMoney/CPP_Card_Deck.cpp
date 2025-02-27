

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

void ACPP_Card_Deck::DrawRandom() 
{
	ACPP_Card randomCard =  ACPP_Card();
	switch (rand() % 3) {
	case 0:
		randomCard.InitializeCard(ECardSuit::Blood, (rand() % 13) + 1);
	case 1:
		randomCard.InitializeCard(ECardSuit::Time, (rand() % 13) + 1);
	case 2:
		randomCard.InitializeCard(ECardSuit::Money, (rand() % 13) + 1);
	}

	PlayersHeldHand.Add(&randomCard);
}
 
// Called every frame
void ACPP_Card_Deck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

