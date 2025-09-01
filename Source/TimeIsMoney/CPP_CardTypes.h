// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EVariable : uint8
{
	PLAYER_CARD_0_SUIT,
	PLAYER_CARD_0_VALUE,
	PLAYER_CARD_1_SUIT,
	PLAYER_CARD_1_VALUE,
	PLAYER_CARD_2_SUIT,
	PLAYER_CARD_2_VALUE,
	PLAYER_STARTING_SUIT,
	PLAYER_CURRENT_SUIT,
	PLAYER_CURRENT_VALUE,
	PLAYER_FINAL_VALUE,
	PLAYER_FINAL_SUIT,

	OPPONENT_CARD_0_SUIT,
	OPPONENT_CARD_0_VALUE,
	OPPONENT_CARD_1_SUIT,
	OPPONENT_CARD_1_VALUE,
	OPPONENT_CARD_2_SUIT,
	OPPONENT_CARD_2_VALUE,
	OPPONENT_STARTING_SUIT,
	OPPONENT_CURRENT_SUIT,
	OPPONENT_CURRENT_VALUE,
	OPPONENT_FINAL_VALUE,
	OPPONENT_FINAL_SUIT,

	THIS_CARD_POSITION,
	THIS_CARD_SUIT,
	THIS_CARD_VALUE
};

UENUM(BlueprintType)
enum class ERelation : uint8
{
	EQUALS,
	LESS_THAN,
	GREATER_THAN,
	LESS_THAN_OR_EQUAL,
	GREATER_THAN_OR_EQUAL
};

UENUM(BlueprintType)
enum class EBooleanOperator : uint8
{
	OR,
	AND,
	NOT
};

UENUM(BlueprintType)
enum class ECardSuit : uint8
{
	Time,
	Money,
	Blood,
	Unknown
};

UENUM(BlueprintType)
enum class ECardConditionType : uint8
{
	None,
	SuitEquals,
	PlayedPositionEquals
	// SuitAtPosition
};

UENUM(BlueprintType)
enum class ECardEffectType : uint8
{
	SetCardNumberRelative,
	SetCardSuit,
	IgnoreRevealedEffectOfCard,
	DrawCards,
	RevealHiddenEffectOfCard,
	RevealStartingSuit
};

