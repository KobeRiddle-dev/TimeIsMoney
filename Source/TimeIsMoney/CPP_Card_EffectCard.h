// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_CardTypes.h"
#include <functional>
#include "CPP_Data_EffectCards.h"
#include "CPP_Card_EffectCard.generated.h"

class ACPP_Card_Deck;
DECLARE_DELEGATE(FOnEffectAnimationFinished);

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EffectCard")
	int32 HandIndex = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EffectCard")
	ACPP_Card_Deck* OwningDeck;

	UFUNCTION(BlueprintCallable, Category = "EffectCard")
	void SetCardTexture(UTexture2D* NewTexture);

	UFUNCTION(BlueprintImplementableEvent, Category = "EffectCard")
	void SetCardText();

	UFUNCTION(BlueprintCallable, Category = "EffectCard")
	FString ParseTooltip(FString Text);

	UFUNCTION(BlueprintCallable, Category = "EffectCard")
	void InitializeCard(UCPP_Data_EffectCards* card);

	UFUNCTION(BlueprintImplementableEvent, Category = "Card Animation")
	void PlayEffectAnimation(
		ECardEffectType EffectType
	);

	void PlayEffectAnimationWithCallback(
		ECardEffectType EffectType,
		std::function<void()> OnFinished
	);

	UFUNCTION(BlueprintCallable, Category = "Card Animation")
	void CallAnimationFinished();

	std::function<void()> AnimationFinishedCallback;
};
