// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_NPC_Opp_TimeIsMoney.h"

// Sets default values
ACPP_NPC_Opp_TimeIsMoney::ACPP_NPC_Opp_TimeIsMoney()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_NPC_Opp_TimeIsMoney::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_NPC_Opp_TimeIsMoney::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// TODO: make AI smarter
ACPP_Card_EffectCard* ACPP_NPC_Opp_TimeIsMoney::PlayCard()
{
    if (Deck->Hand.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Opponent has no cards to play!"));
        return nullptr;
    }

    // Reference right-most card
    return Deck->Hand.Last().CardActor;
}
