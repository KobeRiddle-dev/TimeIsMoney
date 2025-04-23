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

ACPP_Card* ACPP_NPC_Opp_TimeIsMoney::PlayCard()
{
	// TODO logic to determine which card to play
	return Deck->OpponentHeldHand.Pop();
}
