// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeIsMoneyGameUserSettings.h"

void UTimeIsMoneyGameUserSettings::SetPixellationResolution(float NewValue)
{
	float newValue8ified = FMath::RoundToFloat(FMath::RoundToFloat(NewValue / 8.0f) * 8.0f);
	PixellationResolution = FMath::Clamp(newValue8ified, 128.0f, 2048.0f);
}

float UTimeIsMoneyGameUserSettings::GetPixellationResolution() const
{
	return PixellationResolution;
}