// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CPP_CardTypes.h"
#include "CPP_Data_EffectCards.generated.h"

/// <summary>
/// Tree structure of AND, OR, NOT conditions.
/// 
/// Every Leaf node will have their conditions evaluated.
/// 
/// Non-leaf nodes will evaluate their children based on their Operator 
/// until reaching their leaf children at the end of the tree.
/// </summary>
USTRUCT(BlueprintType)
struct FCardConditionNode
{
	GENERATED_BODY()

	// Index of the parent node in the array. -1 for root.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Condition")
	int32 ParentIndex = -1;

	// Operator used if this node has children
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Condition")
	EBooleanOperator Operator = EBooleanOperator::OR;

	// Is this node a leaf (has no children)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Condition")
	bool IsLeaf = true;

	// Leaf data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Condition")
	ECardConditionType LeafConditionType = ECardConditionType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Condition")
	bool IsTargetingOpponent = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Condition")
	int32 IntParam = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Condition")
	ECardSuit SuitParam = ECardSuit::Time;
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

	// Flat array of all nodes in the tree
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCardConditionNode> ConditionNodes;
};

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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect Cards Data")
	ECardSuit CardSuit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect Cards Data")
	FString tooltip;
};
