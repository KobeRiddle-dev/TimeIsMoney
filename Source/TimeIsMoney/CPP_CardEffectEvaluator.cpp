// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_CardEffectEvaluator.h"
#include "CPP_Table_TimeIsMoney.h"

CPP_CardEffectEvaluator::CPP_CardEffectEvaluator()
{
}

CPP_CardEffectEvaluator::~CPP_CardEffectEvaluator()
{
}

void CPP_CardEffectEvaluator::SetCardNumberRelative(
	bool IsTargetingOpp, 
	int32 RelativeNumber, 
	ACPP_Table_TimeIsMoney* GameState,
	UConditionStateResults* ConditionResult,
	bool IsPublicEffect)
{
	if (IsTargetingOpp)
	{
		// Set the opponent's number relative
		if (IsPublicEffect) 
		{
			if (ConditionResult->Private)
			{
				GameState->PrivateOppCard->SetCardNumber(GameState->PrivateOppCard->CardNumber + RelativeNumber);
			}
			if (ConditionResult->Public)
			{
				GameState->PublicOppCard->SetCardNumber(GameState->PublicOppCard->CardNumber + RelativeNumber);
			}
		}
		if (ConditionResult->True)
		{
			GameState->TrueOppCard->SetCardNumber(GameState->TrueOppCard->CardNumber + RelativeNumber);
		}
	}
	else
	{
		// Set the player's number relative
		if (ConditionResult->Private)
		{
			GameState->PrivatePlayerCard->SetCardNumber(GameState->PrivatePlayerCard->CardNumber + RelativeNumber);
		}
		if (IsPublicEffect)
		{
			if (ConditionResult->Public)
			{
				GameState->PublicPlayerCard->SetCardNumber(GameState->PublicPlayerCard->CardNumber + RelativeNumber);
			}
		}
		if (ConditionResult->True)
		{
			GameState->TruePlayerCard->SetCardNumber(GameState->TruePlayerCard->CardNumber + RelativeNumber);
		}
	}
}

void CPP_CardEffectEvaluator::SetCardSuit(
	bool IsTargetingOpp, 
	ECardSuit Suit, 
	ACPP_Table_TimeIsMoney* GameState, 
	UConditionStateResults* ConditionResult,
	bool IsPublicEffect)
{
	if (IsTargetingOpp)
	{
		// Set the opponent's suit
		if (IsPublicEffect)
		{
			if (ConditionResult->Private)
			{
				GameState->PrivateOppCard->SetCardSuit(Suit);
			}
			if (ConditionResult->Public)
			{
				GameState->PublicOppCard->SetCardSuit(Suit);
			}
		}
		if (ConditionResult->True)
		{
			GameState->TrueOppCard->SetCardSuit(Suit);
		}
	}
	else
	{
		// Set the player's suit
		if (ConditionResult->Private)
		{
			GameState->PrivatePlayerCard->SetCardSuit(Suit);
		}
		if (IsPublicEffect) 
		{
			if (ConditionResult->Public)
			{
				GameState->PublicPlayerCard->SetCardSuit(Suit);
			}
		}
		if (ConditionResult->True)
		{
			GameState->TruePlayerCard->SetCardSuit(Suit);
		}
	}
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

UConditionStateResults* CPP_CardEffectEvaluator::EvaluateConditionSuitEquals(
	bool IsTargetingOpp, 
	ECardSuit Suit, 
	ACPP_Table_TimeIsMoney* GameState)
{
	UConditionStateResults* Result = NewObject<UConditionStateResults>();
	if (IsTargetingOpp)
	{
		// Check opponent's suit
		Result->Public = GameState->PublicOppCard->CardSuit == Suit;
		Result->Private = GameState->PrivateOppCard->CardSuit == Suit;
		Result->True = GameState->TrueOppCard->CardSuit == Suit;
	}
	else
	{
		// Check player's suit
		Result->Public = GameState->PublicPlayerCard->CardSuit == Suit;
		Result->Private = GameState->PrivatePlayerCard->CardSuit == Suit;
		Result->True = GameState->TruePlayerCard->CardSuit == Suit;
	}
	return Result;
}

UConditionStateResults* CPP_CardEffectEvaluator::EvaluateConditionPlayedPositionEquals(
	int PlayedPosition,
	ACPP_Table_TimeIsMoney* GameState)
{
	UConditionStateResults* Result = NewObject<UConditionStateResults>();
	Result->Initialize(false, false, false);
	return Result;
}

UConditionStateResults* CPP_CardEffectEvaluator::EvaluateConditionNode(
	const TArray<FCardConditionNode>& Nodes,
	int32 NodeIndex,
	ACPP_Table_TimeIsMoney* GameState)
{
	if (!Nodes.IsValidIndex(NodeIndex))
	{
		UConditionStateResults* Result = NewObject<UConditionStateResults>();
		Result->Initialize(false, false, false);
		return Result;
	}

	const FCardConditionNode& Node = Nodes[NodeIndex];

	if (Node.IsLeaf)
	{
		// Evaluate this condition
		switch (Node.LeafConditionType)
		{
		case ECardConditionType::SuitEquals:
			EvaluateConditionSuitEquals(Node.IsTargetingOpponent, Node.SuitParam, GameState);
			break;
		case ECardConditionType::PlayedPositionEquals:
			// TODO: playedpositionequals method
			break;
		default:
			// Unknown condition type
			UConditionStateResults* Result = NewObject<UConditionStateResults>();
			Result->Initialize(false, false, false);
			return Result;
		}
	}

	// Get Children of this node
	TArray<int32> ChildIndices;
	for (int32 i = 0; i < Nodes.Num(); ++i)
	{
		if (Nodes[i].ParentIndex == NodeIndex)
		{
			ChildIndices.Add(i);
		}
	}
	if (ChildIndices.Num() == 0)
	{
		// Node is not a leaf but has no children; card data is faulty
		UConditionStateResults* Result = NewObject<UConditionStateResults>();
		Result->Initialize(false, false, false);
		return Result;
	}

	// Evaluate starting with first child
	UConditionStateResults* Result = EvaluateConditionNode(Nodes, ChildIndices[0], GameState);

	// Combine remaining children based on Operator
	for (int32 i = 1; i < ChildIndices.Num(); ++i)
	{
		UConditionStateResults* ChildResult = EvaluateConditionNode(Nodes, ChildIndices[i], GameState);
		switch (Node.Operator)
		{
		case EBooleanOperator::AND:
			Result->Private = Result->Private && ChildResult->Private;
			Result->Public = Result->Public && ChildResult->Public;
			Result->True = Result->True && ChildResult->True;
			break;

		case EBooleanOperator::OR:
			Result->Private = Result->Private || ChildResult->Private;
			Result->Public = Result->Public || ChildResult->Public;
			Result->True = Result->True || ChildResult->True;
			break;

		case EBooleanOperator::NOT:
			Result->Private = !ChildResult->Private;
			Result->Public = !ChildResult->Public;
			Result->True = !ChildResult->True;
			break;

		default:
			UConditionStateResults* DefaultResult = NewObject<UConditionStateResults>();
			DefaultResult->Initialize(false, false, false);
			return DefaultResult;
		}
	}

	return Result;
}

void CPP_CardEffectEvaluator::ApplyEffect(
	const TArray<FCardEffect>& Effects, 
	ACPP_Table_TimeIsMoney* GameState,
	bool IsPublicEffect)
{
	for (const FCardEffect& Effect : Effects)
	{
		UConditionStateResults* ConditionResult = EvaluateConditionNode(Effect.ConditionNodes, 0, GameState);

		switch (Effect.EffectType)
		{
		case ECardEffectType::SetCardNumberRelative:
			SetCardNumberRelative(Effect.IsTargetingOpponent, Effect.IntParam, GameState, ConditionResult, IsPublicEffect);
			break;
		case ECardEffectType::SetCardSuit:
			SetCardSuit(Effect.IsTargetingOpponent, Effect.SuitParam, GameState, ConditionResult, IsPublicEffect);
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
}
