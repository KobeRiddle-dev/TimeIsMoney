// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_CardTypes.h"
#include "CPP_Card_EffectCard.generated.h"

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
	TArray<FCardEffect> HiddenEffects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EffectCard")
	TArray<FCardEffect> RevealedEffects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EffectCard")
	UTexture2D* CardTexture;

	UFUNCTION(BlueprintCallable, Category = "EffectCard")
	void SetCardTexture(UTexture2D* NewTexture);

	UFUNCTION(BlueprintCallable, Category = "EffectCard")
	void InitializeCard(UCPP_Data_EffectCards* CardData);

};
