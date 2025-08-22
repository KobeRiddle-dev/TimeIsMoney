// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Card.h"
#include "CPP_CardTypes.h"
#include "CPP_Card_EffectCard.h"
#include "CPP_Card_Deck.h"

class ACPP_Table_TimeIsMoney;

/**
 * 
 */
class TIMEISMONEY_API CPP_CardEffectEvaluator
{
private:
	static void SetCardNumberRelative(bool IsTargetingOpp, int32 RelativeNumber, ACPP_Table_TimeIsMoney* GameState);
	static void SetCardSuit(bool IsTargetingOpp, ECardSuit Suit, ACPP_Table_TimeIsMoney* GameState);
	static void IgnoreRevealedEffectOfCard(ACPP_Table_TimeIsMoney* GameState);
	static void DrawCards(int NumOfDraws);
	static void RevealHiddenEffectOfCard(ACPP_Table_TimeIsMoney* GameState);
	static void RevealStartingSuit(bool IsTargetingOpp, ACPP_Table_TimeIsMoney* GameState);

	static bool EvaluateCondition(const FCardEffect& CardPlayed, ACPP_Table_TimeIsMoney* GameState);

public:
	CPP_CardEffectEvaluator();
	~CPP_CardEffectEvaluator();

	static void ApplyEffect(const FCardEffect& Effect, ACPP_Table_TimeIsMoney* GameState);
};
