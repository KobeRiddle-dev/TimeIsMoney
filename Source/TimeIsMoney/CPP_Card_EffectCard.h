// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_CardTypes.h"
#include "CPP_Card_EffectCard.generated.h"

USTRUCT(BlueprintType)
struct FCardCondition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECardConditionType ConditionType = ECardConditionType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 IntParam = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsTargetingOpponent = false;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECardSuit SuitParam = ECardSuit::Time;	// tmp default value
};

USTRUCT(BlueprintType)
struct FCardEffect
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECardEffectType EffectType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 IntParam = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECardSuit SuitParam = ECardSuit::Time;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsTargetingOpponent = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCardCondition Condition;	// TODO: and or conditions; multiple conditions
};

UCLASS()
class TIMEISMONEY_API ACPP_Card_EffectCard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Card_EffectCard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent* CardMesh;
	UMaterialInstanceDynamic* DynMaterial;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EffectCard")
	FCardEffect HiddenEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EffectCard")
	FCardEffect RevealedEffect;;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EffectCard")
	UTexture2D* CardTexture;

	UFUNCTION(BlueprintCallable, Category = "EffectCard")
	void SetCardTexture(UTexture2D* NewTexture);

	UFUNCTION(BlueprintCallable, Category = "EffectCard")
	void InitializeCard(UCPP_Data_EffectCards* CardData);

};
