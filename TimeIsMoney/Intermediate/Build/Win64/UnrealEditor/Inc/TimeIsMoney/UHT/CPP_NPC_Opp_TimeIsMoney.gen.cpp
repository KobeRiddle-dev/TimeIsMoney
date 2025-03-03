// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeIsMoney/CPP_NPC_Opp_TimeIsMoney.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPP_NPC_Opp_TimeIsMoney() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_Card_Deck_NoRegister();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_Card_NoRegister();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_NoRegister();
UPackage* Z_Construct_UPackage__Script_TimeIsMoney();
// End Cross Module References

// Begin Class ACPP_NPC_Opp_TimeIsMoney Function PlayCard
struct Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics
{
	struct CPP_NPC_Opp_TimeIsMoney_eventPlayCard_Parms
	{
		ACPP_Card* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "NPC_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_NPC_Opp_TimeIsMoney.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_NPC_Opp_TimeIsMoney_eventPlayCard_Parms, ReturnValue), Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney, nullptr, "PlayCard", nullptr, nullptr, Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics::CPP_NPC_Opp_TimeIsMoney_eventPlayCard_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics::CPP_NPC_Opp_TimeIsMoney_eventPlayCard_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_NPC_Opp_TimeIsMoney::execPlayCard)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ACPP_Card**)Z_Param__Result=P_THIS->PlayCard();
	P_NATIVE_END;
}
// End Class ACPP_NPC_Opp_TimeIsMoney Function PlayCard

// Begin Class ACPP_NPC_Opp_TimeIsMoney
void ACPP_NPC_Opp_TimeIsMoney::StaticRegisterNativesACPP_NPC_Opp_TimeIsMoney()
{
	UClass* Class = ACPP_NPC_Opp_TimeIsMoney::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "PlayCard", &ACPP_NPC_Opp_TimeIsMoney::execPlayCard },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACPP_NPC_Opp_TimeIsMoney);
UClass* Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_NoRegister()
{
	return ACPP_NPC_Opp_TimeIsMoney::StaticClass();
}
struct Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "CPP_NPC_Opp_TimeIsMoney.h" },
		{ "ModuleRelativePath", "CPP_NPC_Opp_TimeIsMoney.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Deck_MetaData[] = {
		{ "Category", "NPC_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_NPC_Opp_TimeIsMoney.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CardPlayed_MetaData[] = {
		{ "Category", "NPC_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_NPC_Opp_TimeIsMoney.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Deck;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CardPlayed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACPP_NPC_Opp_TimeIsMoney_PlayCard, "PlayCard" }, // 2236577090
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_NPC_Opp_TimeIsMoney>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::NewProp_Deck = { "Deck", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_NPC_Opp_TimeIsMoney, Deck), Z_Construct_UClass_ACPP_Card_Deck_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Deck_MetaData), NewProp_Deck_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::NewProp_CardPlayed = { "CardPlayed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_NPC_Opp_TimeIsMoney, CardPlayed), Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CardPlayed_MetaData), NewProp_CardPlayed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::NewProp_Deck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::NewProp_CardPlayed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_TimeIsMoney,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::ClassParams = {
	&ACPP_NPC_Opp_TimeIsMoney::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney()
{
	if (!Z_Registration_Info_UClass_ACPP_NPC_Opp_TimeIsMoney.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPP_NPC_Opp_TimeIsMoney.OuterSingleton, Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACPP_NPC_Opp_TimeIsMoney.OuterSingleton;
}
template<> TIMEISMONEY_API UClass* StaticClass<ACPP_NPC_Opp_TimeIsMoney>()
{
	return ACPP_NPC_Opp_TimeIsMoney::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_NPC_Opp_TimeIsMoney);
ACPP_NPC_Opp_TimeIsMoney::~ACPP_NPC_Opp_TimeIsMoney() {}
// End Class ACPP_NPC_Opp_TimeIsMoney

// Begin Registration
struct Z_CompiledInDeferFile_FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_NPC_Opp_TimeIsMoney_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney, ACPP_NPC_Opp_TimeIsMoney::StaticClass, TEXT("ACPP_NPC_Opp_TimeIsMoney"), &Z_Registration_Info_UClass_ACPP_NPC_Opp_TimeIsMoney, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_NPC_Opp_TimeIsMoney), 1079971997U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_NPC_Opp_TimeIsMoney_h_2186904825(TEXT("/Script/TimeIsMoney"),
	Z_CompiledInDeferFile_FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_NPC_Opp_TimeIsMoney_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_NPC_Opp_TimeIsMoney_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
