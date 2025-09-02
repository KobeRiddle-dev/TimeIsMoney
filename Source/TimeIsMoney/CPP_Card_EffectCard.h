// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_CardTypes.h"
#include "CPP_Data_EffectCards.h"
#include "CPP_Card_EffectCard.generated.h"

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
	UCPP_Data_EffectCards* CardData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EffectCard")
	UTexture2D* CardTexture;

	UFUNCTION(BlueprintCallable, Category = "EffectCard")
	void SetCardTexture(UTexture2D* NewTexture);

	UFUNCTION(BlueprintCallable, Category = "EffectCard")
	void InitializeCard(UCPP_Data_EffectCards* card);

	UFUNCTION(BlueprintImplementableEvent, Category = "Cards")
	void PlayEffectAnimation(
		ACPP_Card_EffectCard* CardActor,
		const FVector& TargetLocation,
		const FRotator& TargetRotation,
		const float AnimationDuration = 0.5f
	);
};
