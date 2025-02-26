// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Card.h"
#include "Table_TimeBloodMoney.generated.h"

UCLASS()
class MYPROJECT2_API ATable_TimeBloodMoney : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATable_TimeBloodMoney();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Table_TimeBloodMoney")
	bool DetermineWinner(ACPP_Card* Player, ACPP_Card* Opponent);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeBloodMoney")
	ACPP_Card* PlayerCard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Table_TimeBloodMoney")
	ACPP_Card* OpponentCard;

};
