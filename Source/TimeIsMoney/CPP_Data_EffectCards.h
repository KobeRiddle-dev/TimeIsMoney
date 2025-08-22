// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CPP_CardTypes.h"
#include "CPP_Data_EffectCards.generated.h"

/**
 * 
 */
UCLASS()
class TIMEISMONEY_API UCPP_Data_EffectCards : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	UTexture2D* CardTexture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	ECardConditionType Revealed_Condition_Type = ECardConditionType::None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	int Revealed_Condition_IntParam = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	bool Revealed_Condtion_IsTargetingOpponent = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	ECardSuit Revealed_Condition_SuitParam = ECardSuit::Time; // tmp default value

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	ECardEffectType Revealed_Effect_Type = ECardEffectType::SetCardNumberRelative;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	int Revealed_Effect_IntParam = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	ECardSuit Revealed_Effect_SuitParam = ECardSuit::Time; // tmp default value

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	bool Revealed_Effect_IsTargetingOpponent = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	ECardConditionType Hidden_Condition_Type = ECardConditionType::None;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	int Hidden_Condition_IntParam = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	bool Hidden_Condition_IsTargetingOpponent = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	ECardSuit Hidden_Condition_SuitParam = ECardSuit::Time; // tmp default value

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	ECardEffectType Hidden_Effect_Type = ECardEffectType::SetCardNumberRelative;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	int Hidden_Effect_IntParam = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	ECardSuit Hidden_Effect_SuitParam = ECardSuit::Time; // tmp default value

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	bool Hidden_Effect_IsTargetingOpponent = false;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effect Cards")
	//TArray<bool> TMP_multipleconditions;
};
