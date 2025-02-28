// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeIsMoney/CPP_Card_Deck.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPP_Card_Deck() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_Card_Deck();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_Card_Deck_NoRegister();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_Card_NoRegister();
UPackage* Z_Construct_UPackage__Script_TimeIsMoney();
// End Cross Module References

// Begin Class ACPP_Card_Deck Function DiscardHands
struct Z_Construct_UFunction_ACPP_Card_Deck_DiscardHands_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Card_Deck" },
		{ "ModuleRelativePath", "CPP_Card_Deck.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Card_Deck_DiscardHands_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Card_Deck, nullptr, "DiscardHands", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_Deck_DiscardHands_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Card_Deck_DiscardHands_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ACPP_Card_Deck_DiscardHands()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Card_Deck_DiscardHands_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Card_Deck::execDiscardHands)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DiscardHands();
	P_NATIVE_END;
}
// End Class ACPP_Card_Deck Function DiscardHands

// Begin Class ACPP_Card_Deck Function DrawRandom
struct Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics
{
	struct CPP_Card_Deck_eventDrawRandom_Parms
	{
		ACPP_Card* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Card_Deck" },
		{ "ModuleRelativePath", "CPP_Card_Deck.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Card_Deck_eventDrawRandom_Parms, ReturnValue), Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Card_Deck, nullptr, "DrawRandom", nullptr, nullptr, Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics::CPP_Card_Deck_eventDrawRandom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics::CPP_Card_Deck_eventDrawRandom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Card_Deck::execDrawRandom)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ACPP_Card**)Z_Param__Result=P_THIS->DrawRandom();
	P_NATIVE_END;
}
// End Class ACPP_Card_Deck Function DrawRandom

// Begin Class ACPP_Card_Deck
void ACPP_Card_Deck::StaticRegisterNativesACPP_Card_Deck()
{
	UClass* Class = ACPP_Card_Deck::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DiscardHands", &ACPP_Card_Deck::execDiscardHands },
		{ "DrawRandom", &ACPP_Card_Deck::execDrawRandom },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACPP_Card_Deck);
UClass* Z_Construct_UClass_ACPP_Card_Deck_NoRegister()
{
	return ACPP_Card_Deck::StaticClass();
}
struct Z_Construct_UClass_ACPP_Card_Deck_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "CPP_Card_Deck.h" },
		{ "ModuleRelativePath", "CPP_Card_Deck.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerDeck_MetaData[] = {
		{ "Category", "Card_Deck" },
		{ "ModuleRelativePath", "CPP_Card_Deck.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpponentDeck_MetaData[] = {
		{ "Category", "Card_Deck" },
		{ "ModuleRelativePath", "CPP_Card_Deck.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayersHeldHand_MetaData[] = {
		{ "Category", "Card_Deck" },
		{ "ModuleRelativePath", "CPP_Card_Deck.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpponentHeldHand_MetaData[] = {
		{ "Category", "Card_Deck" },
		{ "ModuleRelativePath", "CPP_Card_Deck.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerDeck_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PlayerDeck;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OpponentDeck_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OpponentDeck;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayersHeldHand_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PlayersHeldHand;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OpponentHeldHand_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OpponentHeldHand;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACPP_Card_Deck_DiscardHands, "DiscardHands" }, // 1384432899
		{ &Z_Construct_UFunction_ACPP_Card_Deck_DrawRandom, "DrawRandom" }, // 3276155464
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_Card_Deck>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_PlayerDeck_Inner = { "PlayerDeck", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_PlayerDeck = { "PlayerDeck", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Card_Deck, PlayerDeck), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerDeck_MetaData), NewProp_PlayerDeck_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_OpponentDeck_Inner = { "OpponentDeck", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_OpponentDeck = { "OpponentDeck", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Card_Deck, OpponentDeck), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpponentDeck_MetaData), NewProp_OpponentDeck_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_PlayersHeldHand_Inner = { "PlayersHeldHand", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_PlayersHeldHand = { "PlayersHeldHand", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Card_Deck, PlayersHeldHand), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayersHeldHand_MetaData), NewProp_PlayersHeldHand_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_OpponentHeldHand_Inner = { "OpponentHeldHand", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_OpponentHeldHand = { "OpponentHeldHand", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Card_Deck, OpponentHeldHand), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpponentHeldHand_MetaData), NewProp_OpponentHeldHand_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPP_Card_Deck_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_PlayerDeck_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_PlayerDeck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_OpponentDeck_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_OpponentDeck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_PlayersHeldHand_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_PlayersHeldHand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_OpponentHeldHand_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Deck_Statics::NewProp_OpponentHeldHand,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Card_Deck_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACPP_Card_Deck_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_TimeIsMoney,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Card_Deck_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPP_Card_Deck_Statics::ClassParams = {
	&ACPP_Card_Deck::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACPP_Card_Deck_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Card_Deck_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Card_Deck_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPP_Card_Deck_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACPP_Card_Deck()
{
	if (!Z_Registration_Info_UClass_ACPP_Card_Deck.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPP_Card_Deck.OuterSingleton, Z_Construct_UClass_ACPP_Card_Deck_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACPP_Card_Deck.OuterSingleton;
}
template<> TIMEISMONEY_API UClass* StaticClass<ACPP_Card_Deck>()
{
	return ACPP_Card_Deck::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_Card_Deck);
ACPP_Card_Deck::~ACPP_Card_Deck() {}
// End Class ACPP_Card_Deck

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_GitHub_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_Card_Deck, ACPP_Card_Deck::StaticClass, TEXT("ACPP_Card_Deck"), &Z_Registration_Info_UClass_ACPP_Card_Deck, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_Card_Deck), 1037104899U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_GitHub_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_3720373540(TEXT("/Script/TimeIsMoney"),
	Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_GitHub_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_GitHub_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_Deck_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
