// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Card_Deck.h"
#include "CPP_Card_EffectCard.h"
#include "CPP_NPC_Opp_TimeIsMoney.generated.h"

UCLASS()
class TIMEISMONEY_API ACPP_NPC_Opp_TimeIsMoney : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_NPC_Opp_TimeIsMoney();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NPC_TimeIsMoney")
	ACPP_Card_Deck* Deck;

	UFUNCTION(BlueprintCallable, Category = "NPC_TimeIsMoney")
	ACPP_Card_EffectCard* PlayCard();
};
