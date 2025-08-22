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
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Dynamic Material is NULL!"));
	}
}

void ACPP_Card_EffectCard::InitializeCard(UCPP_Data_EffectCards* CardData)
{
	if (CardData)
	{
		RevealedEffect.Condition.ConditionType = CardData->Revealed_Condition_Type;
		RevealedEffect.Condition.IntParam = CardData->Revealed_Condition_IntParam;
		RevealedEffect.Condition.IsTargetingOpponent = CardData->Revealed_Condtion_IsTargetingOpponent;
		RevealedEffect.Condition.SuitParam = CardData->Revealed_Condition_SuitParam;
		RevealedEffect.EffectType = CardData->Revealed_Effect_Type;
		RevealedEffect.IntParam = CardData->Revealed_Effect_IntParam;
		RevealedEffect.SuitParam = CardData->Revealed_Effect_SuitParam;
		RevealedEffect.IsTargetingOpponent = CardData->Revealed_Effect_IsTargetingOpponent;
		HiddenEffect.Condition.ConditionType = CardData->Hidden_Condition_Type;
		HiddenEffect.Condition.IntParam = CardData->Hidden_Condition_IntParam;
		HiddenEffect.Condition.IsTargetingOpponent = CardData->Hidden_Condition_IsTargetingOpponent;
		HiddenEffect.Condition.SuitParam = CardData->Hidden_Condition_SuitParam;
		HiddenEffect.EffectType = CardData->Hidden_Effect_Type;
		HiddenEffect.IntParam = CardData->Hidden_Effect_IntParam;
		HiddenEffect.SuitParam = CardData->Hidden_Effect_SuitParam;
		HiddenEffect.IsTargetingOpponent = CardData->Hidden_Effect_IsTargetingOpponent;
		CardTexture = CardData->CardTexture;
		if (DynMaterial && CardTexture)
		{
			SetCardTexture(CardTexture);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CardData is NULL!"));
	}
}
