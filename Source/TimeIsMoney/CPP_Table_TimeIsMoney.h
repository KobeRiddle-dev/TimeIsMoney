// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Card.h"
#include "CPP_Card_Deck.h"
#include "GameFramework/Actor.h"
#include "CPP_NPC_Opp_TimeIsMoney.h"
#include "CPP_Table_TimeIsMoney.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerCardPlayedEventDispatcher, ACPP_Card*, CardPlayed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOppCardPlayedEventDispatcher, ACPP_Card*, CardPlayed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHandStartEventDispatcher);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWinnerDeterminedEventDispatcher);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameEndedEventDispatcher, bool, PlayerIsWin);

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
	void ResetHands();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney_Setup")
	ACPP_NPC_Opp_TimeIsMoney* Opponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney_Setup")
	ACPP_Card_Deck* Deck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	ACPP_Card* PublicPlayerCard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	TArray<ACPP_Card*> PlayerCards;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	ACPP_Card* PublicOppCard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	TMap<ECardSuit, int> PlayerHands;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	TMap<ECardSuit, int> OppHands;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	TArray<ACPP_Card*> OppCards;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	bool GameIsActive;

	UPROPERTY(BlueprintAssignable, Category = "Table_TimeIsMoney_Events")
	FOnPlayerCardPlayedEventDispatcher OnPlayerCardPlayed;
	UPROPERTY(BlueprintAssignable, Category = "Table_TimeIsMoney_Events")
	FOnOppCardPlayedEventDispatcher OnOppCardPlayed;
	UPROPERTY(BlueprintAssignable, Category = "Table_TimeIsMoney_Events")
	FOnHandStartEventDispatcher OnHandStart;
	UPROPERTY(BlueprintAssignable, Category = "Table_TimeIsMoney_Events")
	FOnWinnerDeterminedEventDispatcher OnWinnerDetermined;
	UPROPERTY(BlueprintAssignable, Category = "Table_TimeIsMoney_Events")
	FOnGameEndedEventDispatcher OnGameEnded;

	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	bool DetermineWinner();
	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	void PlayCard(ACPP_Card* PlayerCard);
	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	void StartGame();
	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	bool CheckForEndGame();
	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	bool StartHand();

};
