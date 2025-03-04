// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CPP_Card.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTexture2D;
enum class ECardSuit : uint8;
#ifdef TIMEISMONEY_CPP_Card_generated_h
#error "CPP_Card.generated.h already included, missing '#pragma once' in CPP_Card.h"
#endif
#define TIMEISMONEY_CPP_Card_generated_h

#define FID_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execInitializeCard); \
	DECLARE_FUNCTION(execSetCardSuit); \
	DECLARE_FUNCTION(execSetCardNumber); \
	DECLARE_FUNCTION(execSetCardTexture);


#define FID_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACPP_Card(); \
	friend struct Z_Construct_UClass_ACPP_Card_Statics; \
public: \
	DECLARE_CLASS(ACPP_Card, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TimeIsMoney"), NO_API) \
	DECLARE_SERIALIZER(ACPP_Card)


#define FID_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACPP_Card(ACPP_Card&&); \
	ACPP_Card(const ACPP_Card&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACPP_Card); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACPP_Card); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACPP_Card) \
	NO_API virtual ~ACPP_Card();


#define FID_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_18_PROLOG
#define FID_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_21_INCLASS_NO_PURE_DECLS \
	FID_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TIMEISMONEY_API UClass* StaticClass<class ACPP_Card>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h


#define FOREACH_ENUM_ECARDSUIT(op) \
	op(ECardSuit::Blood) \
	op(ECardSuit::Time) \
	op(ECardSuit::Money) 

enum class ECardSuit : uint8;
template<> struct TIsUEnumClass<ECardSuit> { enum { Value = true }; };
template<> TIMEISMONEY_API UEnum* StaticEnum<ECardSuit>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
