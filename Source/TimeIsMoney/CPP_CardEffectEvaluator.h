// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Card.h"
#include "CPP_CardTypes.h"
#include "CPP_Card_EffectCard.h"
#include "CPP_Card_Deck.h"
#include "CPP_CardEffectEvaluator.generated.h"

class ACPP_Table_TimeIsMoney;

UCLASS(BlueprintType)
/// <summary>
/// Condition State Results for Private, Public, and True 
/// states of the game.
/// </summary>
class TIMEISMONEY_API UConditionStateResults : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite)
    bool Private;

    UPROPERTY(BlueprintReadWrite)
    bool Public;

    UPROPERTY(BlueprintReadWrite)
    bool True;

    // Optional: helper initializer
    void Initialize(bool InPrivate, bool InPublic, bool InTrue)
    {
        Private = InPrivate;
        Public = InPublic;
        True = InTrue;
    }
};

/**
 * 
 */
class TIMEISMONEY_API CPP_CardEffectEvaluator
{
private:
	static void EvaluateEffect(
		const FCardEffect& Effect,
		ACPP_Table_TimeIsMoney* GameState,
		bool IsPublicEffect,
		bool IsPlayedByPlayer,
        UConditionStateResults*);

	static void SetCardNumberRelative(
        bool IsTargetingOpp, 
        int32 RelativeNumber, 
        ACPP_Table_TimeIsMoney* GameState,
		UConditionStateResults* ConditionResult,
        bool IsPublicEffect,
        bool IsPlayedByPlayer);

	static void SetCardSuit(
        bool IsTargetingOpp, 
        ECardSuit Suit, 
        ACPP_Table_TimeIsMoney* GameState,  
        UConditionStateResults* ConditionResult,
        bool IsPublicEffect,
        bool IsPlayedByPlayer);

	static void IgnoreRevealedEffectOfCard(
        ACPP_Table_TimeIsMoney* GameState);

	static void DrawCards(
        int NumOfDraws);

	static void RevealHiddenEffectOfCard(
        ACPP_Table_TimeIsMoney* GameState);

	static void RevealStartingSuit(
        bool IsTargetingOpp, 
        ACPP_Table_TimeIsMoney* GameState);

	static UConditionStateResults* EvaluateConditionNode(
        const TArray<FCardConditionNode>& Nodes,
        int32 NodeIndex, 
        ACPP_Table_TimeIsMoney* GameState,
        bool IsPlayedByPlayer);

	static UConditionStateResults* EvaluateConditionSuitEquals(
        bool IsTargetingOpp, 
        ECardSuit Suit, 
        ACPP_Table_TimeIsMoney* GameState,
        bool IsPlayedByPlayer);

	static UConditionStateResults* EvaluateConditionPlayedPositionEquals(
        int PlayedPosition, 
        ACPP_Table_TimeIsMoney* GameState,
        bool IsPlayedByPlayer);

public:
	CPP_CardEffectEvaluator();
	~CPP_CardEffectEvaluator();

	static void ApplyEffect(
        const TArray<FCardEffect>& Effects, 
        ACPP_Table_TimeIsMoney* GameState,
		ACPP_Card_EffectCard* SourceCard,
        bool IsPublicEffect,
        bool IsPlayedByPlayer);
};
