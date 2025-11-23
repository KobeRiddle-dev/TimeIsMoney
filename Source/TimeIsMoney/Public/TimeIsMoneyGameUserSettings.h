// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "TimeIsMoneyGameUserSettings.generated.h"

/**
 *
 */
UCLASS(BlueprintType, Blueprintable)
class TIMEISMONEY_API UTimeIsMoneyGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(Config, BlueprintReadWrite, Category = "Settings")
	float PixellationResolution = 360.0f;

	UFUNCTION(BlueprintCallable, Category = "Settings")
	void SetPixellationResolution(float NewValue);

	UFUNCTION(BlueprintCallable, Category = "Settings")
	float GetPixellationResolution() const;
};
