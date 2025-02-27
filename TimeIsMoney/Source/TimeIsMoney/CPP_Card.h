// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "CPP_Card.generated.h"

UENUM(BlueprintType)
enum class ECardSuit : uint8
{
	Blood UMETA(DisplayName = "Blood"),
	Time UMETA(DisplayName = "Time"),
	Money UMETA(DisplayName = "Money")
};

UCLASS()
class TIMEISMONEY_API ACPP_Card : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_Card();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent* CardMesh;
	UMaterialInstanceDynamic* DynMaterial;
	UTextRenderComponent* CardNumberText;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
	int CardNumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
	ECardSuit CardSuit;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
	UTexture2D* BloodTexture;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
	UTexture2D* TimeTexture;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card")
	UTexture2D* MoneyTexture;

	UFUNCTION(BlueprintCallable, Category = "Card")
	void SetCardTexture(UTexture2D* NewTexture);
	UFUNCTION(BlueprintCallable, Category = "Card")
	void SetCardNumber(int Number);
	UFUNCTION(BlueprintCallable, Category = "Card")
	void SetCardSuit(ECardSuit Suit);
	UFUNCTION(BlueprintCallable, Category = "Card")
	void InitializeCard(ECardSuit Suit, int Number);
};