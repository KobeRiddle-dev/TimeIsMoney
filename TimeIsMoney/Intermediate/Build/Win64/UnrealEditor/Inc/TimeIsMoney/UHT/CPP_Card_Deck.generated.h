// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CPP_Card_Deck.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ACPP_Card;
#ifdef TIMEISMONEY_CPP_Card_Deck_generated_h
#error "CPP_Card_Deck.generated.h already included, missing '#pragma once' in CPP_Card_Deck.h"
#endif
#define TIMEISMONEY_CPP_Card_Deck_generated_h

<<<<<<< Updated upstream
#define FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
=======
#define FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_9_DELEGATE \
TIMEISMONEY_API void F_CardDrawnEventDispatcher_DelegateWrapper(const FMulticastScriptDelegate& _CardDrawnEventDispatcher, ACPP_Card* DrawnCard);


#define FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_10_DELEGATE \
TIMEISMONEY_API void F_HandDiscardedEventDispatcher_DelegateWrapper(const FMulticastScriptDelegate& _HandDiscardedEventDispatcher);


#define FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
>>>>>>> Stashed changes
	DECLARE_FUNCTION(execDiscardHands); \
	DECLARE_FUNCTION(execDrawRandom);


<<<<<<< Updated upstream
#define FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_12_INCLASS_NO_PURE_DECLS \
=======
#define FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_15_INCLASS_NO_PURE_DECLS \
>>>>>>> Stashed changes
private: \
	static void StaticRegisterNativesACPP_Card_Deck(); \
	friend struct Z_Construct_UClass_ACPP_Card_Deck_Statics; \
public: \
	DECLARE_CLASS(ACPP_Card_Deck, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TimeIsMoney"), NO_API) \
	DECLARE_SERIALIZER(ACPP_Card_Deck)


<<<<<<< Updated upstream
#define FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_12_ENHANCED_CONSTRUCTORS \
=======
#define FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_15_ENHANCED_CONSTRUCTORS \
>>>>>>> Stashed changes
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACPP_Card_Deck(ACPP_Card_Deck&&); \
	ACPP_Card_Deck(const ACPP_Card_Deck&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACPP_Card_Deck); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACPP_Card_Deck); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACPP_Card_Deck) \
	NO_API virtual ~ACPP_Card_Deck();


<<<<<<< Updated upstream
#define FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_9_PROLOG
#define FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_12_INCLASS_NO_PURE_DECLS \
	FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_12_ENHANCED_CONSTRUCTORS \
=======
#define FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_12_PROLOG
#define FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_15_INCLASS_NO_PURE_DECLS \
	FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_15_ENHANCED_CONSTRUCTORS \
>>>>>>> Stashed changes
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TIMEISMONEY_API UClass* StaticClass<class ACPP_Card_Deck>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
