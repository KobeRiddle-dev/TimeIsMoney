// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Card.h"
#include "CPP_CardTypes.h"
#include "CPP_Card_Deck.h"
#include "GameFramework/Actor.h"
#include "CPP_NPC_Opp_TimeIsMoney.h"
#include "CPP_CardEffectEvaluator.h"
#include "CPP_Card_EffectCard.h"
#include "CPP_Table_TimeIsMoney.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerCardPlayedEventDispatcher, ACPP_Card_EffectCard*, CardPlayed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOppCardPlayedEventDispatcher, ACPP_Card_EffectCard*, CardPlayed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHandStartEventDispatcher);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWinnerDeterminedEventDispatcher);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartGameEventDispatcher);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBeginEffectReveal);
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
	ECardSuit GetRandomSuit();
	int GetCardPlayedPosition(ACPP_Card_EffectCard* PlayedCard, bool IsPlayer);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney_Setup")
	ACPP_NPC_Opp_TimeIsMoney* OpponentAI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney_Setup")
	ACPP_Card_Deck* PlayerDeck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	TArray<bool> PlayerCards_IgnoreRevealedEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	TArray<bool> PlayerCards_IgnoreHiddenEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney_Setup")
	ACPP_Card* PublicPlayerCard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney_Setup")
	ACPP_Card* PrivatePlayerCard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney_Setup")
	ACPP_Card* TruePlayerCard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	ECardSuit PlayerStartingSuit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney_Setup")
	ACPP_Card_Deck* OpponentDeck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	TArray<bool> OppCards_IgnoreRevealedEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	TArray<bool> OppCards_IgnoreHiddenEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney_Setup")
	ACPP_Card* PublicOppCard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney_Setup")
	ACPP_Card* PrivateOppCard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney_Setup")
	ACPP_Card* TrueOppCard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	ECardSuit OppStartingSuit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	TMap<ECardSuit, int> PlayerHands;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	TMap<ECardSuit, int> OppHands;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	bool GameIsActive;

	UPROPERTY(BlueprintAssignable, Category = "Table_TimeIsMoney_Events")
	FOnStartGameEventDispatcher OnGameStarted;

	UPROPERTY(BlueprintAssignable, Category = "Table_TimeIsMoney_Events")
	FOnPlayerCardPlayedEventDispatcher OnPlayerCardPlayed;

	UPROPERTY(BlueprintAssignable, Category = "Table_TimeIsMoney_Events")
	FOnOppCardPlayedEventDispatcher OnOppCardPlayed;

	UPROPERTY(BlueprintAssignable, Category = "Table_TimeIsMoney_Events")
	FOnHandStartEventDispatcher OnHandStart;

	UPROPERTY(BlueprintAssignable, Category = "Table_TimeIsMoney_Events")
	FBeginEffectReveal OnBeginEffectReveal;

	UPROPERTY(BlueprintAssignable, Category = "Table_TimeIsMoney_Events")
	FOnWinnerDeterminedEventDispatcher OnWinnerDetermined;

	UPROPERTY(BlueprintAssignable, Category = "Table_TimeIsMoney_Events")
	FOnGameEndedEventDispatcher OnGameEnded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	bool IsPlayerTurn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	bool IsAnimationPlaying;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeIsMoney")
	bool PlayerGoesFirst;

	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	bool DetermineWinner();

	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	void RevealAllCardEffects();

	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	void PlayCard(ACPP_Card_EffectCard* PlayedCard);

	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	void StartGame();

	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	bool CheckForEndGame();

	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	bool StartHand();

	UFUNCTION(BlueprintImplementableEvent, Category = "Table_TimeIsMoney Animations")
	void PlayEffectRevealAnimation();

	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	void EvaluateEffect_AnimationFinished(FCardInstance Card);

	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	void RandomizeStartSettings();

	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	void GameSetup();

	UFUNCTION(BlueprintCallable, Category = "Table_TimeIsMoney")
	void BossDefeated();

};
