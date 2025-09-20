#include "GameTimerComponent.h"

// Sets default values
UGameTimerComponent::UGameTimerComponent()
{
	CurrentTime = FTimespan::Zero();
	MaxTime = FTimespan::Zero();
	StartingHours = 72.0f;
	bAutoInitializeOnBeginPlay = true;
}
void UGameTimerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (bAutoInitializeOnBeginPlay)
	{
		InitializeTimer(StartingHours);
	}
}
// Initialize timer with starting time (in hours)
/*
* This sets the current time and max time to the specified hours.
* It also broadcasts the time changed event to update UI or other systems.
*
* StartingHours: The initial time in hours (default 72 hours = 3 days)
*/
void UGameTimerComponent::InitializeTimer(float Hours)
{
	CurrentTime = FTimespan::FromHours(Hours);
	MaxTime = CurrentTime;
	StartingHours = Hours;
	BroadcastTimeChanged();
}

bool UGameTimerComponent::SpendTime(const FTimespan& TimeToSpend)
{
	if (TimeToSpend.GetTotalSeconds() <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameTimerComponent: Cannot spend negative or zero time"));
		return false;
	}

	if (!HasEnoughTime(TimeToSpend))
	{
		UE_LOG(LogTemp, Warning, TEXT("GameTimerComponent: Not enough time to spend %s"),
			*TimeToSpend.ToString());
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

	UE_LOG(LogTemp, Log, TEXT("GameTimerComponent: Spent %s, remaining: %s"),
		*TimeToSpend.ToString(), *GetTimeAsString());

	return true;
}

void UGameTimerComponent::AddTime(const FTimespan& TimeToAdd)
{
	if (TimeToAdd.GetTotalSeconds() <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameTimerComponent: Cannot add negative or zero time"));
		return;
	}

	CurrentTime += TimeToAdd;
	BroadcastTimeChanged();

	UE_LOG(LogTemp, Log, TEXT("GameTimerComponent: Added %s, current: %s"),
		*TimeToAdd.ToString(), *GetTimeAsString());
}

bool UGameTimerComponent::HasEnoughTime(const FTimespan& RequiredTime) const
{
	return CurrentTime >= RequiredTime;
}

FTimespan UGameTimerComponent::GetRemainingTime() const
{
	return CurrentTime;
}

FString UGameTimerComponent::GetTimeAsString() const
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

float UGameTimerComponent::GetTimeInHours() const
{
	return static_cast<float>(CurrentTime.GetTotalHours());
}

int32 UGameTimerComponent::GetDays() const
{
	return CurrentTime.GetDays();
}

int32 UGameTimerComponent::GetHours() const
{
	return CurrentTime.GetHours();
}

int32 UGameTimerComponent::GetMinutes() const
{
	return CurrentTime.GetMinutes();
}

bool UGameTimerComponent::IsTimeExpired() const
{
	return CurrentTime.GetTotalSeconds() <= 0;
}

bool UGameTimerComponent::SpendMinutes(int32 Minutes)
{
	return SpendTime(FTimespan::FromMinutes(Minutes));
}

bool UGameTimerComponent::SpendHours(int32 Hours)
{
	return SpendTime(FTimespan::FromHours(Hours));
}

void UGameTimerComponent::AddMinutes(int32 Minutes)
{
	AddTime(FTimespan::FromMinutes(Minutes));
}

void UGameTimerComponent::AddHours(int32 Hours)
{
	AddTime(FTimespan::FromHours(Hours));
}

void UGameTimerComponent::BroadcastTimeChanged()
{
	OnTimeChanged.Broadcast(CurrentTime);
}

void UGameTimerComponent::CheckTimeExpired()
{
	if (IsTimeExpired())
	{
		OnTimeExpired.Broadcast();
		UE_LOG(LogTemp, Warning, TEXT("GameTimerComponent: Time has expired!"));
	}
}