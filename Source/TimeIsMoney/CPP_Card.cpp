// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Card.h"

// Sets default values
ACPP_Card::ACPP_Card()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Other vars will be set in BeginPlay
}

// Pseudo-constructor: Initializes the card with a suit and number
/*
* This changes the internal values of the card suit and number to the argued params.
* It also updates the static mesh and text components
* 
* Does not create or construct a new Card. It just changes the values of this Card.
*/
void ACPP_Card::InitializeCard(ECardSuit Suit, int Number)
{
	SetCardSuit(Suit);
	SetCardNumber(Number);
}

// Called when the game starts or when spawned
void ACPP_Card::BeginPlay()
{
	Super::BeginPlay();

	CardMesh = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
	CardNumberText = Cast<UTextRenderComponent>(GetComponentByClass(UTextRenderComponent::StaticClass()));
	if (CardMesh && CardNumberText)
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
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No material found on CardMesh"));
		}

		SetCardSuit(CardSuit);
		SetCardNumber(CardNumber);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CardMesh or CardNumberText is NULL"));
	}
}

// Called every frame
void ACPP_Card::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Card::SetCardTexture(UTexture2D* NewTexture)
{
	if (CardMesh && DynMaterial && NewTexture) {
		DynMaterial->SetTextureParameterValue("CardTexture", NewTexture);	// "CardTexture" needs to match the param name exactly
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CardMesh, CardMeshMaterial, or NewTexture is NULL"));
	}
}

void ACPP_Card::SetCardNumber(int Number)
{
	CardNumber = Number;
	// Update the text on the CardNumberText
	if (CardNumberText)
	{
		// Convert the number to a string and then to FText
		FText NewText = FText::FromString(FString::Printf(TEXT("%d"), CardNumber));

		// Set the new text
		CardNumberText->SetText(NewText);
	}
}


void ACPP_Card::SetCardSuit(ECardSuit Suit)
{
	CardSuit = Suit;
	switch (CardSuit)
	{
	case ECardSuit::Blood:
		SetCardTexture(BloodTexture);
		break;
	case ECardSuit::Time:
		SetCardTexture(TimeTexture);
		break;
	case ECardSuit::Money:
		SetCardTexture(MoneyTexture);
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("Invalid Card Suit"));
		break;
	}
}