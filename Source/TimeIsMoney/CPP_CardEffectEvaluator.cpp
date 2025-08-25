// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_CardEffectEvaluator.h"
#include "CPP_Table_TimeIsMoney.h"

CPP_CardEffectEvaluator::CPP_CardEffectEvaluator()
{
}

CPP_CardEffectEvaluator::~CPP_CardEffectEvaluator()
{
}

void CPP_CardEffectEvaluator::SetCardNumberRelative(bool IsTargetingOpp, int32 RelativeNumber, ACPP_Table_TimeIsMoney* GameState)
{

}

void CPP_CardEffectEvaluator::SetCardSuit(bool IsTargetingOpp, ECardSuit Suit, ACPP_Table_TimeIsMoney* GameState)
{
	//if (IsTargetingOpp)
	//{
	//	GameState.opponent->PublicOppCard->SetCardSuit(Suit);
	//}
	//else
	//{
	//	GameState->PublicPlayerCard->SetCardSuit(Suit);
	//}
}

// TODO
void CPP_CardEffectEvaluator::IgnoreRevealedEffectOfCard(ACPP_Table_TimeIsMoney* GameState)
{

}

void CPP_CardEffectEvaluator::DrawCards(int NumOfDraws)
{
}

// TODO
void CPP_CardEffectEvaluator::RevealHiddenEffectOfCard(ACPP_Table_TimeIsMoney* GameState)
{

}

void CPP_CardEffectEvaluator::RevealStartingSuit(bool IsTargetingOpp, ACPP_Table_TimeIsMoney* GameState)
{

}

bool CPP_CardEffectEvaluator::EvaluateCondition(const FCardEffect& CardPlayed, ACPP_Table_TimeIsMoney* GameState)
{
	switch (CardPlayed.Condition.ConditionType)
	{
		case ECardConditionType::None:
			return true; // No condition, always true
		case ECardConditionType::SuitEquals:
			if (CardPlayed.Condition.IsTargetingOpponent) {
				return CardPlayed.Condition.SuitParam == GameState->PublicOppCard->CardSuit;
			}
			else
			{
				return CardPlayed.Condition.SuitParam == GameState->PublicPlayerCard->CardSuit;
			}
		case ECardConditionType::PlayedPositionEquals:
			if (CardPlayed.Condition.IsTargetingOpponent) 
			{
				return CardPlayed.Condition.IntParam == GameState->OppCards.Num();
			} 
			else 
			{
				return CardPlayed.Condition.IntParam == GameState->PlayerCards.Num();
			}
		default:
			return false; // Unknown condition type
	}
}

// TODO: ApplyEffect(s)
void CPP_CardEffectEvaluator::ApplyEffect(const FCardEffect& Effect, ACPP_Table_TimeIsMoney* GameState)
{
	if (!EvaluateCondition(Effect, GameState))
	{
		return; // Condition not met, do not apply effect
	}

	switch (Effect.EffectType) 
	{
		case ECardEffectType::SetCardNumberRelative:
			SetCardNumberRelative(Effect.IsTargetingOpponent, Effect.IntParam, GameState);
			break;
		case ECardEffectType::SetCardSuit:
			SetCardSuit(Effect.IsTargetingOpponent, Effect.SuitParam, GameState);
			break;
		case ECardEffectType::IgnoreRevealedEffectOfCard:
			IgnoreRevealedEffectOfCard(GameState);
			break;
		case ECardEffectType::DrawCards:
			DrawCards(Effect.IntParam);
			break;
		case ECardEffectType::RevealHiddenEffectOfCard:
			RevealHiddenEffectOfCard(GameState);
			break;
		case ECardEffectType::RevealStartingSuit:
			RevealStartingSuit(Effect.IsTargetingOpponent, GameState);
			break;
		default:
			break; // Unknown effect type
	}
}
