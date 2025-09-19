#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Engine.h"
#include "CPP_GameTimer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimeChanged, const FTimespan&, NewTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimeExpired);

UCLASS(BlueprintType, Blueprintable)
class TIMEISMONEY_API UGameTimer : public UObject
{
	GENERATED_BODY()

public:
	// Sets default values
	UGameTimer();

protected:
	// Called when the timer is initialized or when spawned
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Timer")
	FTimespan CurrentTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Timer")
	FTimespan MaxTime;

public:
	// Initialize timer with starting time (in hours)
	UFUNCTION(BlueprintCallable, Category = "Game Timer")
	void InitializeTimer(float StartingHours = 72.0f);

	// Spend time (subtract from current time)
	UFUNCTION(BlueprintCallable, Category = "Game Timer")
	bool SpendTime(const FTimespan& TimeToSpend);

	// Add time (reward player with more time)
	UFUNCTION(BlueprintCallable, Category = "Game Timer")
	void AddTime(const FTimespan& TimeToAdd);

	// Check if player has enough time for an action
	UFUNCTION(BlueprintCallable, Category = "Game Timer", BlueprintPure)
	bool HasEnoughTime(const FTimespan& RequiredTime) const;

	// Get current remaining time
	UFUNCTION(BlueprintCallable, Category = "Game Timer", BlueprintPure)
	FTimespan GetRemainingTime() const;

	// Get current time in various formats
	UFUNCTION(BlueprintCallable, Category = "Game Timer", BlueprintPure)
	FString GetTimeAsString() const;

	UFUNCTION(BlueprintCallable, Category = "Game Timer", BlueprintPure)
	float GetTimeInHours() const;

	UFUNCTION(BlueprintCallable, Category = "Game Timer", BlueprintPure)
	int32 GetDays() const;

	UFUNCTION(BlueprintCallable, Category = "Game Timer", BlueprintPure)
	int32 GetHours() const;

	UFUNCTION(BlueprintCallable, Category = "Game Timer", BlueprintPure)
	int32 GetMinutes() const;

	// Check if time has expired
	UFUNCTION(BlueprintCallable, Category = "Game Timer", BlueprintPure)
	bool IsTimeExpired() const;

	// Convenience functions for common time costs
	UFUNCTION(BlueprintCallable, Category = "Game Timer")
	bool SpendMinutes(int32 Minutes);

	UFUNCTION(BlueprintCallable, Category = "Game Timer")
	bool SpendHours(int32 Hours);

	UFUNCTION(BlueprintCallable, Category = "Game Timer")
	void AddMinutes(int32 Minutes);

	UFUNCTION(BlueprintCallable, Category = "Game Timer")
	void AddHours(int32 Hours);

	// Events
	UPROPERTY(BlueprintAssignable, Category = "Game Timer")
	FOnTimeChanged OnTimeChanged;

	UPROPERTY(BlueprintAssignable, Category = "Game Timer")
	FOnTimeExpired OnTimeExpired;

private:
	void BroadcastTimeChanged();
	void CheckTimeExpired();
};