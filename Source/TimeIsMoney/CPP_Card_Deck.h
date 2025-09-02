
#pragma once

#include "CoreMinimal.h"
#include "CPP_Card_EffectCard.h"
#include "CPP_Data_EffectCards.h"
#include "GameFramework/Actor.h"
#include "CPP_Card_Deck.generated.h"

/// <summary>
/// Lightweight instance of an effect card for deck/hand management
/// </summary>
USTRUCT(BlueprintType)
struct FCardInstance
{
	GENERATED_BODY()

	UPROPERTY()
	UCPP_Data_EffectCards* CardData = nullptr;

	// Only not null if the card actor is spawned in play (hand/board)
	UPROPERTY()
	TObjectPtr<ACPP_Card_EffectCard> CardActor = nullptr;

	bool operator==(const FCardInstance& Other) const
	{
		return CardData == Other.CardData;
	}
};

// Delegates should take a const reference, not a pointer
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(F_CardDrawnEventDispatcher, const FCardInstance&, DrawnCard);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(F_CardDiscardedEventDispatcher, const FCardInstance&, DiscardedCard);

UCLASS()
class TIMEISMONEY_API ACPP_Card_Deck : public AActor
{
	GENERATED_BODY()

public:
	ACPP_Card_Deck();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// The editor-only template deck
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card_Deck_Setup")
	TArray<UCPP_Data_EffectCards*> StartingDeck;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Card_Deck")
	TArray<FCardInstance> Drawpile;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Card_Deck")
	TArray<FCardInstance> Hand;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Card_Deck")
	TArray<FCardInstance> InPlay;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Card_Deck")
	TArray<FCardInstance> DiscardPile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card_Deck_Setup")
	TArray<FTransform> BoardSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card_Deck_Setup")
	TArray<FTransform> HandSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card_Deck_Setup")
	FTransform DiscardPileSlot;

	UPROPERTY(BlueprintAssignable, Category = "Card_Deck")
	F_CardDrawnEventDispatcher OnCardDrawn;

	UPROPERTY(BlueprintAssignable, Category = "Card_Deck")
	F_CardDiscardedEventDispatcher OnCardDiscarded;

	// The card actor Blueprint to spawn when drawing cards
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card_Deck_Setup")
	TSubclassOf<ACPP_Card_EffectCard> CardActorClass;

	UFUNCTION(BlueprintCallable, Category = "Card_Deck")
	void DiscardHand();

	UFUNCTION(BlueprintCallable, Category = "Card_Deck")
	void ShuffleDeck();

	UFUNCTION(BlueprintCallable, Category = "Card_Deck")
	void DrawRandom();

	UFUNCTION(BlueprintCallable, Category = "Card_Deck")
	void DiscardInPlayCards();

	UFUNCTION(BlueprintCallable, Category = "Card_Deck")
	void PlayCardFromHand(ACPP_Card_EffectCard* CardToPlay);

	UFUNCTION(BlueprintCallable, Category = "Card_Deck")
	int GetCardFromHandIndex(ACPP_Card_EffectCard* CardToFind);
};