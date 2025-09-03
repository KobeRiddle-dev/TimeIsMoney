// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Card_EffectCard.h"
#include "CPP_Data_EffectCards.h"

// Sets default values
ACPP_Card_EffectCard::ACPP_Card_EffectCard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Card_EffectCard::BeginPlay()
{
	Super::BeginPlay();
	
	CardMesh = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
	if (CardMesh)
	{
		UMaterialInterface* Material = CardMesh->GetMaterial(0);
		if (Material)
		{
			DynMaterial = UMaterialInstanceDynamic::Create(Material, this);
			if (DynMaterial)
			{
				UE_LOG(LogTemp, Log, TEXT("Dynamic Material Created Successfully"));
				CardMesh->SetMaterial(0, DynMaterial);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed to create dynamic material"));
			}
			if (CardTexture)
			{
				SetCardTexture(CardTexture);	// Set the initial texture if provided
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No material found on CardMesh"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CardMesh is NULL!"));
	}
}

// Called every frame
void ACPP_Card_EffectCard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Card_EffectCard::SetCardTexture(UTexture2D* NewTexture)
{
	if (CardMesh && DynMaterial && NewTexture)
	{
		DynMaterial->SetTextureParameterValue("CardTexture", NewTexture);	// "CardTexture" needs to match the param name exactly
		CardTexture = NewTexture; 
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Dynamic Material is NULL!"));
	}
}

void ACPP_Card_EffectCard::InitializeCard(UCPP_Data_EffectCards* Card)
{
	if(Card)
	{
		CardData = Card;
		SetCardTexture(CardData->CardTexture);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("There was a problem with Effect Card Data"));
	}
}

void ACPP_Card_EffectCard::PlayEffectAnimationWithCallback(
	ECardEffectType EffectType,
	std::function<void()> OnFinished
)
{
	AnimationFinishedCallback = OnFinished;
	PlayEffectAnimation(EffectType);
}


void ACPP_Card_EffectCard::CallAnimationFinished()
{
	if (AnimationFinishedCallback)
	{
		AnimationFinishedCallback();
		AnimationFinishedCallback = nullptr; // clear after execution
	}
}