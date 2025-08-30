// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CPP_CardTypes.h"
#include "CPP_Card_EffectCard.h"
#include "CPP_Data_EffectCards.generated.h"

/**
 * 
 */
UCLASS()
class TIMEISMONEY_API UCPP_Data_EffectCards : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect Cards Data")
	UTexture2D* CardTexture;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect Cards Data")
	TArray<FCardEffect> RevealedEffects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect Cards Data")
	TArray<FCardEffect> HiddenEffects;
};
