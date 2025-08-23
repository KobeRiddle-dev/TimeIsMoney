// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CPP_CardTypes.h"

#include "CPP_Data_Condition.generated.h"

UCLASS(Abstract, Blueprintable)
class UPredicate : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	EVariable leftSide;

	UPROPERTY(EditAnywhere)
	ERelation relation;
};

UCLASS(Blueprintable)
class UVariableAndVariablePredicate : public UPredicate
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	EVariable rightSide;
};

UENUM(BlueprintType)
enum class EValueType : uint8
{
	Int,
	CardSuit
};

UCLASS(Blueprintable)
class UVariableAndValuePredicate : public UPredicate
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	EValueType valueType;

	UPROPERTY(EditAnywhere)
	int intValue;

	UPROPERTY(EditAnywhere)
	ECardSuit cardSuitValue;

};

USTRUCT(BlueprintType)
struct FSubCondition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	EBooleanOperator booleanOperator;

	UPROPERTY(EditAnywhere, Instanced)
	UPredicate* predicate;
};

/**
 *
 */
UCLASS()
class TIMEISMONEY_API UCPP_Data_Condition : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FSubCondition> subConditions;
};
