// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ECardSuit : uint8 
{
    Time, 
    Money, 
    Blood 
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