// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject2/Table_TimeBloodMoney.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTable_TimeBloodMoney() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
MYPROJECT2_API UClass* Z_Construct_UClass_ACPP_Card_NoRegister();
MYPROJECT2_API UClass* Z_Construct_UClass_ATable_TimeBloodMoney();
MYPROJECT2_API UClass* Z_Construct_UClass_ATable_TimeBloodMoney_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProject2();
// End Cross Module References

// Begin Class ATable_TimeBloodMoney Function DetermineWinner
struct Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics
{
	struct Table_TimeBloodMoney_eventDetermineWinner_Parms
	{
		ACPP_Card* Player;
		ACPP_Card* Opponent;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Table_TimeBloodMoney" },
		{ "ModuleRelativePath", "Table_TimeBloodMoney.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Player;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Opponent;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Table_TimeBloodMoney_eventDetermineWinner_Parms, Player), Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::NewProp_Opponent = { "Opponent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Table_TimeBloodMoney_eventDetermineWinner_Parms, Opponent), Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((Table_TimeBloodMoney_eventDetermineWinner_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Table_TimeBloodMoney_eventDetermineWinner_Parms), &Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::NewProp_Player,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::NewProp_Opponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATable_TimeBloodMoney, nullptr, "DetermineWinner", nullptr, nullptr, Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::PropPointers), sizeof(Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::Table_TimeBloodMoney_eventDetermineWinner_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::Table_TimeBloodMoney_eventDetermineWinner_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ATable_TimeBloodMoney::execDetermineWinner)
{
	P_GET_OBJECT(ACPP_Card,Z_Param_Player);
	P_GET_OBJECT(ACPP_Card,Z_Param_Opponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->DetermineWinner(Z_Param_Player,Z_Param_Opponent);
	P_NATIVE_END;
}
// End Class ATable_TimeBloodMoney Function DetermineWinner

// Begin Class ATable_TimeBloodMoney
void ATable_TimeBloodMoney::StaticRegisterNativesATable_TimeBloodMoney()
{
	UClass* Class = ATable_TimeBloodMoney::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DetermineWinner", &ATable_TimeBloodMoney::execDetermineWinner },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATable_TimeBloodMoney);
UClass* Z_Construct_UClass_ATable_TimeBloodMoney_NoRegister()
{
	return ATable_TimeBloodMoney::StaticClass();
}
struct Z_Construct_UClass_ATable_TimeBloodMoney_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Table_TimeBloodMoney.h" },
		{ "ModuleRelativePath", "Table_TimeBloodMoney.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCard_MetaData[] = {
		{ "Category", "Table_TimeBloodMoney" },
		{ "ModuleRelativePath", "Table_TimeBloodMoney.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpponentCard_MetaData[] = {
		{ "Category", "Table_TimeBloodMoney" },
		{ "ModuleRelativePath", "Table_TimeBloodMoney.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerCard;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OpponentCard;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ATable_TimeBloodMoney_DetermineWinner, "DetermineWinner" }, // 1828590111
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATable_TimeBloodMoney>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATable_TimeBloodMoney_Statics::NewProp_PlayerCard = { "PlayerCard", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATable_TimeBloodMoney, PlayerCard), Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerCard_MetaData), NewProp_PlayerCard_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATable_TimeBloodMoney_Statics::NewProp_OpponentCard = { "OpponentCard", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATable_TimeBloodMoney, OpponentCard), Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpponentCard_MetaData), NewProp_OpponentCard_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATable_TimeBloodMoney_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATable_TimeBloodMoney_Statics::NewProp_PlayerCard,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATable_TimeBloodMoney_Statics::NewProp_OpponentCard,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATable_TimeBloodMoney_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATable_TimeBloodMoney_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject2,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATable_TimeBloodMoney_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATable_TimeBloodMoney_Statics::ClassParams = {
	&ATable_TimeBloodMoney::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ATable_TimeBloodMoney_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ATable_TimeBloodMoney_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATable_TimeBloodMoney_Statics::Class_MetaDataParams), Z_Construct_UClass_ATable_TimeBloodMoney_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATable_TimeBloodMoney()
{
	if (!Z_Registration_Info_UClass_ATable_TimeBloodMoney.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATable_TimeBloodMoney.OuterSingleton, Z_Construct_UClass_ATable_TimeBloodMoney_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATable_TimeBloodMoney.OuterSingleton;
}
template<> MYPROJECT2_API UClass* StaticClass<ATable_TimeBloodMoney>()
{
	return ATable_TimeBloodMoney::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATable_TimeBloodMoney);
ATable_TimeBloodMoney::~ATable_TimeBloodMoney() {}
// End Class ATable_TimeBloodMoney

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_Unreal_Projects_MyProject2_Source_MyProject2_Table_TimeBloodMoney_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATable_TimeBloodMoney, ATable_TimeBloodMoney::StaticClass, TEXT("ATable_TimeBloodMoney"), &Z_Registration_Info_UClass_ATable_TimeBloodMoney, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATable_TimeBloodMoney), 2149457696U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_Unreal_Projects_MyProject2_Source_MyProject2_Table_TimeBloodMoney_h_4127428403(TEXT("/Script/MyProject2"),
	Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_Unreal_Projects_MyProject2_Source_MyProject2_Table_TimeBloodMoney_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_Unreal_Projects_MyProject2_Source_MyProject2_Table_TimeBloodMoney_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
