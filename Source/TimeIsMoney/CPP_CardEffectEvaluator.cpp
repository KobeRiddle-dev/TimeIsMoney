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
	bool IsPublicEffect,
	bool IsPlayedByPlayer)
{
	if (!IsPlayedByPlayer)
	{
		IsTargetingOpp = !IsTargetingOpp;
	}
	if (IsTargetingOpp)
	{
		if (ConditionResult->Private)
		{
			UE_LOG(LogTemp, Log, TEXT("Setting Private Opp Card Number Relative by %d"), RelativeNumber);
			GameState->PrivateOppCard->SetCardNumber(GameState->PrivateOppCard->CardNumber + RelativeNumber);
		}
		if (IsPublicEffect)
		{
			if (ConditionResult->Public)
			{
				UE_LOG(LogTemp, Log, TEXT("Setting Public Opp Card Number Relative by %d"), RelativeNumber);
				GameState->PublicOppCard->SetCardNumber(GameState->PublicOppCard->CardNumber + RelativeNumber);
			}
		}
		if (ConditionResult->True)
		{
			UE_LOG(LogTemp, Log, TEXT("Setting True Opp Card Number Relative by %d"), RelativeNumber);
			GameState->TrueOppCard->SetCardNumber(GameState->TrueOppCard->CardNumber + RelativeNumber);
		}
	}
	else
	{
		if (ConditionResult->Private)
		{
			UE_LOG(LogTemp, Log, TEXT("Setting Private Player Card Number Relative by %d"), RelativeNumber);
			GameState->PrivatePlayerCard->SetCardNumber(GameState->PrivatePlayerCard->CardNumber + RelativeNumber);
		}
		if (IsPublicEffect)
		{
			if (ConditionResult->Public)
			{
				UE_LOG(LogTemp, Log, TEXT("Setting Public Player Card Number Relative by %d"), RelativeNumber);
				GameState->PublicPlayerCard->SetCardNumber(GameState->PublicPlayerCard->CardNumber + RelativeNumber);
			}
		}
		if (ConditionResult->True)
		{
			UE_LOG(LogTemp, Log, TEXT("Setting True Player Card Number Relative by %d"), RelativeNumber);
			GameState->TruePlayerCard->SetCardNumber(GameState->TruePlayerCard->CardNumber + RelativeNumber);
		}
	}
}

void CPP_CardEffectEvaluator::SetCardSuit(
	bool IsTargetingOpp,
	ECardSuit Suit,
	ACPP_Table_TimeIsMoney* GameState,
	UConditionStateResults* ConditionResult,
	bool IsPublicEffect,
	bool IsPlayedByPlayer)
{
	if (!IsPlayedByPlayer)
	{
		IsTargetingOpp = !IsTargetingOpp;
	}
	if (IsTargetingOpp)
	{
		if (ConditionResult->Private)
		{
			GameState->PrivateOppCard->SetCardSuit(Suit);
		}
		if (IsPublicEffect)
		{
			if (ConditionResult->Public)
			{
				GameState->PublicOppCard->SetCardSuit(Suit);
			}
		}
		if (ConditionResult->True)
		{
			UE_LOG(LogTemp, Log, TEXT("Setting True Opp Card Suit to %d"), static_cast<int>(Suit));
			GameState->TrueOppCard->SetCardSuit(Suit);
		}
	}
	else
	{
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
			UE_LOG(LogTemp, Log, TEXT("Setting True Player Card Suit to %d"), static_cast<int>(Suit));
			GameState->TruePlayerCard->SetCardSuit(Suit);
		}
	}
}

void CPP_CardEffectEvaluator::IgnoreRevealedEffectOfCard(
	ACPP_Table_TimeIsMoney* GameState,
	bool IsTargetingOpp,
	int TargetCardPos,	// if not 1, 2, or 3, it targets the card opposite the current card
	bool IsPublicEffect,
	bool IsPlayedByPlayer,
	int ThisCardPos)
{
	if (!IsPlayedByPlayer)
	{
		IsTargetingOpp = !IsTargetingOpp;
	}
	if (TargetCardPos < 1 || TargetCardPos > 3)
	{
		TargetCardPos = ThisCardPos;
	}
	// TODO: Visually indicate that the card's revealed effect is ignored
	if (IsTargetingOpp)
	{
		GameState->OppCards_IgnoreHiddenEffect[TargetCardPos - 1] = true;
	}
	else
	{
		GameState->PlayerCards_IgnoreHiddenEffect[TargetCardPos - 1] = true;
	}
}

void CPP_CardEffectEvaluator::DrawCards(
	ACPP_Table_TimeIsMoney* GameState,
	int NumOfDraws,
	bool IsTargetingOpp,
	bool IsPlayedByPlayer)
{
	if (!IsPlayedByPlayer)
	{
		IsTargetingOpp = !IsTargetingOpp;
	}
	for (int i = 0; i < NumOfDraws; i++)
	{
		if (IsTargetingOpp) {
			GameState->OpponentDeck->DrawRandom();
		}
		else {
			GameState->PlayerDeck->DrawRandom();
		}
	}
}

// TODO
void CPP_CardEffectEvaluator::RevealHiddenEffectOfCard(ACPP_Table_TimeIsMoney* GameState)
{

}

void CPP_CardEffectEvaluator::RevealStartingSuit(
	ACPP_Table_TimeIsMoney* GameState,
	bool IsTargetingOpp,
	bool IsPlayedByPlayer)
{
	if (!IsPlayedByPlayer)
	{
		IsTargetingOpp = !IsTargetingOpp;
	}
	// TODO: Visually indicate the starting suit then step through public effects up to current cards
	if (IsTargetingOpp)
	{
		GameState->PublicOppCard->SetCardSuit(GameState->OppStartingSuit);
	}
	else
	{
		GameState->PublicPlayerCard->SetCardSuit(GameState->PlayerStartingSuit);
	}
}

UConditionStateResults* CPP_CardEffectEvaluator::EvaluateConditionSuitEquals(
	bool IsTargetingOpp,
	ECardSuit Suit,
	ACPP_Table_TimeIsMoney* GameState,
	bool IsPlayedByPlayer)
{
	UConditionStateResults* Result = NewObject<UConditionStateResults>();
	if (!IsPlayedByPlayer)
	{
		IsTargetingOpp = !IsTargetingOpp;
	}
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

// TODO
UConditionStateResults* CPP_CardEffectEvaluator::EvaluateConditionPlayedPositionEquals(
	ACPP_Table_TimeIsMoney* GameState,
	int PlayedPosition,
	int ThisCardPos)
{
	UConditionStateResults* Result = NewObject<UConditionStateResults>();
	Result->Public = ThisCardPos == PlayedPosition;
	Result->Private = ThisCardPos == PlayedPosition;
	Result->True = ThisCardPos == PlayedPosition;
	return Result;
}

UConditionStateResults* CPP_CardEffectEvaluator::EvaluateConditionNode(
	const TArray<FCardConditionNode>& Nodes,
	int32 NodeIndex,
	ACPP_Table_TimeIsMoney* GameState,
	bool IsPlayedByPlayer,
	int ThisCardPos)
{
	if (Nodes.Num() == 0)
	{
		UE_LOG(LogTemp, Log, TEXT("EvaluateConditionNode: No condition nodes, returning true"));
		UConditionStateResults* Result = NewObject<UConditionStateResults>();
		Result->Initialize(true, true, true);
		return Result;
	}
	if (!Nodes.IsValidIndex(NodeIndex))
	{
		UE_LOG(LogTemp, Warning, TEXT("EvaluateConditionNode: Invalid NodeIndex %d"), NodeIndex);
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
		{
			UConditionStateResults* Result = EvaluateConditionSuitEquals(
				Node.IsTargetingOpponent,
				Node.SuitParam,
				GameState,
				IsPlayedByPlayer
			);
			UE_LOG(LogTemp, Log, TEXT("EvaluateConditionNode: SuitEquals result - Private: %d, Public: %d, True: %d"),
				Result->Private ? 1 : 0,
				Result->Public ? 1 : 0,
				Result->True ? 1 : 0
			);
			return Result;
		}
		case ECardConditionType::PlayedPositionEquals:
		{
			// TODO: implement playedpositionequals method
			UConditionStateResults* Result = EvaluateConditionPlayedPositionEquals(
				GameState,
				Node.IntParam,
				ThisCardPos
			);
			return Result;
		}
		default:
		{
			UConditionStateResults* Result = NewObject<UConditionStateResults>();
			Result->Initialize(true, true, true);	// if uknown condition, consider the condition met
			UE_LOG(LogTemp, Warning, TEXT("EvaluateConditionNode: Unknown LeafConditionType, returning true"));
			return Result;
		}
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
	UConditionStateResults* Result = EvaluateConditionNode(
		Nodes,
		ChildIndices[0],
		GameState,
		IsPlayedByPlayer,
		ThisCardPos
	);

	// Combine remaining children based on Operator
	for (int32 i = 1; i < ChildIndices.Num(); ++i)
	{
		UConditionStateResults* ChildResult = EvaluateConditionNode(
			Nodes,
			ChildIndices[i],
			GameState,
			IsPlayedByPlayer,
			ThisCardPos
		);
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
	ACPP_Card_EffectCard* SourceCard,
	bool IsPublicEffect,
	bool IsPlayedByPlayer,
	int ThisCardPos)
{
	for (const FCardEffect& Effect : Effects)
	{
		UConditionStateResults* ConditionResult = EvaluateConditionNode(
			Effect.ConditionNodes,
			0,
			GameState,
			IsPlayedByPlayer,
			ThisCardPos
		);
		SourceCard->PlayEffectAnimationWithCallback(
			Effect.EffectType,
			[Effect, GameState, IsPublicEffect, IsPlayedByPlayer, ThisCardPos, ConditionResult]()
			{
				CPP_CardEffectEvaluator::EvaluateEffect(
					Effect, GameState, IsPublicEffect, IsPlayedByPlayer, ThisCardPos, ConditionResult
				);
			}
		);
	}
}

void CPP_CardEffectEvaluator::EvaluateEffect(
	const FCardEffect& Effect,
	ACPP_Table_TimeIsMoney* GameState,
	bool IsPublicEffect,
	bool IsPlayedByPlayer,
	int ThisCardPos,
	UConditionStateResults* ConditionResult)
{
	switch (Effect.EffectType)
	{
	case ECardEffectType::SetCardNumberRelative:
		SetCardNumberRelative(
			Effect.IsTargetingOpponent, 
			Effect.IntParam, 
			GameState, 
			ConditionResult, 
			IsPublicEffect, 
			IsPlayedByPlayer
		);
		break;
	case ECardEffectType::SetCardSuit:
		SetCardSuit(Effect.IsTargetingOpponent, 
			Effect.SuitParam, 
			GameState, 
			ConditionResult, 
			IsPublicEffect, 
			IsPlayedByPlayer
		);
		break;
	case ECardEffectType::IgnoreRevealedEffectOfCard:
		IgnoreRevealedEffectOfCard(
			GameState,
			Effect.IsTargetingOpponent,
			Effect.IntParam,
			IsPublicEffect,
			IsPlayedByPlayer,
			ThisCardPos
		);
		break;
	case ECardEffectType::DrawCards:
		DrawCards(
			GameState,
			Effect.IntParam,
			Effect.IsTargetingOpponent,
			IsPlayedByPlayer
		);
		break;
	case ECardEffectType::RevealHiddenEffectOfCard:
		RevealHiddenEffectOfCard(GameState);
		break;
	case ECardEffectType::RevealStartingSuit:
		RevealStartingSuit(
			GameState,
			Effect.IsTargetingOpponent,
			IsPlayedByPlayer
		);
		break;
	default:
		break; // Unknown effect type
	}
}

