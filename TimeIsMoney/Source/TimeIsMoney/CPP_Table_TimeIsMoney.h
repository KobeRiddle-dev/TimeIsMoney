// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Card.h"
#include "CPP_Card_Deck.h"
#include "GameFramework/Actor.h"
#include "CPP_Table_TimeIsMoney.generated.h"

UCLASS()
class TIMEISMONEY_API ACPP_Table_TimeIsMoney : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Table_TimeIsMoney();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool CheckIfWin(TMap<ECardSuit, int> PlayerBeingChecked);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	ACPP_Card* PlayerCard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	ACPP_Card* OpponentCard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	TMap<ECardSuit, int> PlayerHands;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	TMap<ECardSuit, int> OpponentHands;

	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	bool DetermineWinner(ACPP_Card* Player, ACPP_Card* Opponent);
	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	void StartGame();
	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	void CheckForEndGame();

};
