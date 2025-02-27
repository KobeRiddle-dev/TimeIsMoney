
#pragma once

#include "CoreMinimal.h"
#include "CPP_Card.h"
#include "GameFramework/Actor.h"
#include "CPP_Card_Deck.generated.h"

UCLASS()
class TIMEISMONEY_API ACPP_Card_Deck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Card_Deck();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card_Deck")
	TArray<ACPP_Card*> PlayerDeck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card_Deck")
	TArray<ACPP_Card*> OpponentDeck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card_Deck")
	TArray<ACPP_Card*> PlayersHeldHand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card_Deck")
	TArray<ACPP_Card*> OpponentHeldHand;


	UFUNCTION(BlueprintCallable, Category = "Card_Deck")
	void DrawRandom();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
