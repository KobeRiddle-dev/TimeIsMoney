#include "CPP_GameTimer.h"

// Sets default values
UGameTimer::UGameTimer()
{
	CurrentTime = FTimespan::Zero();
	MaxTime = FTimespan::Zero();
}

// Initialize timer with starting time (in hours)
/*
* This sets the current time and max time to the specified hours.
* It also broadcasts the time changed event to update UI or other systems.
*
* StartingHours: The initial time in hours (default 72 hours = 3 days)
*/
void UGameTimer::InitializeTimer(float StartingHours)
{
	CurrentTime = FTimespan::FromHours(StartingHours);
	MaxTime = CurrentTime;
	BroadcastTimeChanged();
}

bool UGameTimer::SpendTime(const FTimespan& TimeToSpend)
{
	if (TimeToSpend.GetTotalSeconds() <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameTimer: Cannot spend negative or zero time"));
		return false;
	}

	if (!HasEnoughTime(TimeToSpend))
	{
		UE_LOG(LogTemp, Warning, TEXT("GameTimer: Not enough time to spend %s"), *TimeToSpend.ToString());
		return false;
	}

	CurrentTime -= TimeToSpend;

	// Ensure we don't go below zero
	if (CurrentTime.GetTotalSeconds() < 0)
	{
		CurrentTime = FTimespan::Zero();
	}

	BroadcastTimeChanged();
	CheckTimeExpired();

	UE_LOG(LogTemp, Log, TEXT("GameTimer: Spent %s, remaining: %s"),
		*TimeToSpend.ToString(), *GetTimeAsString());

	return true;
}

void UGameTimer::AddTime(const FTimespan& TimeToAdd)
{
	if (TimeToAdd.GetTotalSeconds() <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameTimer: Cannot add negative or zero time"));
		return;
	}

	CurrentTime += TimeToAdd;
	BroadcastTimeChanged();

	UE_LOG(LogTemp, Log, TEXT("GameTimer: Added %s, current: %s"),
		*TimeToAdd.ToString(), *GetTimeAsString());
}

bool UGameTimer::HasEnoughTime(const FTimespan& RequiredTime) const
{
	return CurrentTime >= RequiredTime;
}

FTimespan UGameTimer::GetRemainingTime() const
{
	return CurrentTime;
}

FString UGameTimer::GetTimeAsString() const
{
	int32 Days = CurrentTime.GetDays();
	int32 Hours = CurrentTime.GetHours();
	int32 Minutes = CurrentTime.GetMinutes();

	if (Days > 0)
	{
		return FString::Printf(TEXT("%d days, %d hours, %d minutes"), Days, Hours, Minutes);
	}
	else if (Hours > 0)
	{
		return FString::Printf(TEXT("%d hours, %d minutes"), Hours, Minutes);
	}
	else
	{
		return FString::Printf(TEXT("%d minutes"), Minutes);
	}
}

float UGameTimer::GetTimeInHours() const
{
	return static_cast<float>(CurrentTime.GetTotalHours());
}

int32 UGameTimer::GetDays() const
{
	return CurrentTime.GetDays();
}

int32 UGameTimer::GetHours() const
{
	return CurrentTime.GetHours();
}

int32 UGameTimer::GetMinutes() const
{
	return CurrentTime.GetMinutes();
}

bool UGameTimer::IsTimeExpired() const
{
	return CurrentTime.GetTotalSeconds() <= 0;
}

bool UGameTimer::SpendMinutes(int32 Minutes)
{
	return SpendTime(FTimespan::FromMinutes(Minutes));
}

bool UGameTimer::SpendHours(int32 Hours)
{
	return SpendTime(FTimespan::FromHours(Hours));
}

void UGameTimer::AddMinutes(int32 Minutes)
{
	AddTime(FTimespan::FromMinutes(Minutes));
}

void UGameTimer::AddHours(int32 Hours)
{
	AddTime(FTimespan::FromHours(Hours));
}

void UGameTimer::BroadcastTimeChanged()
{
	OnTimeChanged.Broadcast(CurrentTime);
}

void UGameTimer::CheckTimeExpired()
{
	if (IsTimeExpired())
	{
		OnTimeExpired.Broadcast();
		UE_LOG(LogTemp, Warning, TEXT("GameTimer: Time has expired!"));
	}
}