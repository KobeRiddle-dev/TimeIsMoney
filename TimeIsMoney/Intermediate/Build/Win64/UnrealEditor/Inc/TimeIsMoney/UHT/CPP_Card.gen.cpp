// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeIsMoney/CPP_Card.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPP_Card() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_Card();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_Card_NoRegister();
TIMEISMONEY_API UEnum* Z_Construct_UEnum_TimeIsMoney_ECardSuit();
UPackage* Z_Construct_UPackage__Script_TimeIsMoney();
// End Cross Module References

// Begin Enum ECardSuit
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECardSuit;
static UEnum* ECardSuit_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECardSuit.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECardSuit.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_TimeIsMoney_ECardSuit, (UObject*)Z_Construct_UPackage__Script_TimeIsMoney(), TEXT("ECardSuit"));
	}
	return Z_Registration_Info_UEnum_ECardSuit.OuterSingleton;
}
template<> TIMEISMONEY_API UEnum* StaticEnum<ECardSuit>()
{
	return ECardSuit_StaticEnum();
}
struct Z_Construct_UEnum_TimeIsMoney_ECardSuit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Blood.DisplayName", "Blood" },
		{ "Blood.Name", "ECardSuit::Blood" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "CPP_Card.h" },
		{ "Money.DisplayName", "Money" },
		{ "Money.Name", "ECardSuit::Money" },
		{ "Time.DisplayName", "Time" },
		{ "Time.Name", "ECardSuit::Time" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECardSuit::Blood", (int64)ECardSuit::Blood },
		{ "ECardSuit::Time", (int64)ECardSuit::Time },
		{ "ECardSuit::Money", (int64)ECardSuit::Money },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_TimeIsMoney_ECardSuit_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_TimeIsMoney,
	nullptr,
	"ECardSuit",
	"ECardSuit",
	Z_Construct_UEnum_TimeIsMoney_ECardSuit_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_TimeIsMoney_ECardSuit_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_TimeIsMoney_ECardSuit_Statics::Enum_MetaDataParams), Z_Construct_UEnum_TimeIsMoney_ECardSuit_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_TimeIsMoney_ECardSuit()
{
	if (!Z_Registration_Info_UEnum_ECardSuit.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECardSuit.InnerSingleton, Z_Construct_UEnum_TimeIsMoney_ECardSuit_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECardSuit.InnerSingleton;
}
// End Enum ECardSuit

// Begin Class ACPP_Card Function InitializeCard
struct Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics
{
	struct CPP_Card_eventInitializeCard_Parms
	{
		ECardSuit Suit;
		int32 Number;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Card" },
		{ "ModuleRelativePath", "CPP_Card.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Suit_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Suit;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Number;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::NewProp_Suit_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::NewProp_Suit = { "Suit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Card_eventInitializeCard_Parms, Suit), Z_Construct_UEnum_TimeIsMoney_ECardSuit, METADATA_PARAMS(0, nullptr) }; // 1292650111
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::NewProp_Number = { "Number", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Card_eventInitializeCard_Parms, Number), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::NewProp_Suit_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::NewProp_Suit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::NewProp_Number,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Card, nullptr, "InitializeCard", nullptr, nullptr, Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::CPP_Card_eventInitializeCard_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::CPP_Card_eventInitializeCard_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACPP_Card_InitializeCard()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Card_InitializeCard_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Card::execInitializeCard)
{
	P_GET_ENUM(ECardSuit,Z_Param_Suit);
	P_GET_PROPERTY(FIntProperty,Z_Param_Number);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeCard(ECardSuit(Z_Param_Suit),Z_Param_Number);
	P_NATIVE_END;
}
// End Class ACPP_Card Function InitializeCard

// Begin Class ACPP_Card Function SetCardNumber
struct Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics
{
	struct CPP_Card_eventSetCardNumber_Parms
	{
		int32 Number;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Card" },
		{ "ModuleRelativePath", "CPP_Card.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Number;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics::NewProp_Number = { "Number", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Card_eventSetCardNumber_Parms, Number), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics::NewProp_Number,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Card, nullptr, "SetCardNumber", nullptr, nullptr, Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics::CPP_Card_eventSetCardNumber_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics::CPP_Card_eventSetCardNumber_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACPP_Card_SetCardNumber()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Card_SetCardNumber_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Card::execSetCardNumber)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Number);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCardNumber(Z_Param_Number);
	P_NATIVE_END;
}
// End Class ACPP_Card Function SetCardNumber

// Begin Class ACPP_Card Function SetCardSuit
struct Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics
{
	struct CPP_Card_eventSetCardSuit_Parms
	{
		ECardSuit Suit;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Card" },
		{ "ModuleRelativePath", "CPP_Card.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Suit_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Suit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::NewProp_Suit_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::NewProp_Suit = { "Suit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Card_eventSetCardSuit_Parms, Suit), Z_Construct_UEnum_TimeIsMoney_ECardSuit, METADATA_PARAMS(0, nullptr) }; // 1292650111
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::NewProp_Suit_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::NewProp_Suit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Card, nullptr, "SetCardSuit", nullptr, nullptr, Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::CPP_Card_eventSetCardSuit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::CPP_Card_eventSetCardSuit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACPP_Card_SetCardSuit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Card_SetCardSuit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Card::execSetCardSuit)
{
	P_GET_ENUM(ECardSuit,Z_Param_Suit);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCardSuit(ECardSuit(Z_Param_Suit));
	P_NATIVE_END;
}
// End Class ACPP_Card Function SetCardSuit

// Begin Class ACPP_Card Function SetCardTexture
struct Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics
{
	struct CPP_Card_eventSetCardTexture_Parms
	{
		UTexture2D* NewTexture;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Card" },
		{ "ModuleRelativePath", "CPP_Card.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewTexture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics::NewProp_NewTexture = { "NewTexture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Card_eventSetCardTexture_Parms, NewTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics::NewProp_NewTexture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Card, nullptr, "SetCardTexture", nullptr, nullptr, Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics::CPP_Card_eventSetCardTexture_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics::CPP_Card_eventSetCardTexture_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACPP_Card_SetCardTexture()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Card_SetCardTexture_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Card::execSetCardTexture)
{
	P_GET_OBJECT(UTexture2D,Z_Param_NewTexture);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCardTexture(Z_Param_NewTexture);
	P_NATIVE_END;
}
// End Class ACPP_Card Function SetCardTexture

// Begin Class ACPP_Card
void ACPP_Card::StaticRegisterNativesACPP_Card()
{
	UClass* Class = ACPP_Card::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "InitializeCard", &ACPP_Card::execInitializeCard },
		{ "SetCardNumber", &ACPP_Card::execSetCardNumber },
		{ "SetCardSuit", &ACPP_Card::execSetCardSuit },
		{ "SetCardTexture", &ACPP_Card::execSetCardTexture },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACPP_Card);
UClass* Z_Construct_UClass_ACPP_Card_NoRegister()
{
	return ACPP_Card::StaticClass();
}
struct Z_Construct_UClass_ACPP_Card_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "CPP_Card.h" },
		{ "ModuleRelativePath", "CPP_Card.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CardNumber_MetaData[] = {
		{ "Category", "Card" },
		{ "ModuleRelativePath", "CPP_Card.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CardSuit_MetaData[] = {
		{ "Category", "Card" },
		{ "ModuleRelativePath", "CPP_Card.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BloodTexture_MetaData[] = {
		{ "Category", "Card" },
		{ "ModuleRelativePath", "CPP_Card.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeTexture_MetaData[] = {
		{ "Category", "Card" },
		{ "ModuleRelativePath", "CPP_Card.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoneyTexture_MetaData[] = {
		{ "Category", "Card" },
		{ "ModuleRelativePath", "CPP_Card.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_CardNumber;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CardSuit_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CardSuit;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BloodTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TimeTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoneyTexture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACPP_Card_InitializeCard, "InitializeCard" }, // 3262099678
		{ &Z_Construct_UFunction_ACPP_Card_SetCardNumber, "SetCardNumber" }, // 753032696
		{ &Z_Construct_UFunction_ACPP_Card_SetCardSuit, "SetCardSuit" }, // 30691008
		{ &Z_Construct_UFunction_ACPP_Card_SetCardTexture, "SetCardTexture" }, // 844928754
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_Card>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ACPP_Card_Statics::NewProp_CardNumber = { "CardNumber", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Card, CardNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CardNumber_MetaData), NewProp_CardNumber_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ACPP_Card_Statics::NewProp_CardSuit_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ACPP_Card_Statics::NewProp_CardSuit = { "CardSuit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Card, CardSuit), Z_Construct_UEnum_TimeIsMoney_ECardSuit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CardSuit_MetaData), NewProp_CardSuit_MetaData) }; // 1292650111
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Card_Statics::NewProp_BloodTexture = { "BloodTexture", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Card, BloodTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BloodTexture_MetaData), NewProp_BloodTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Card_Statics::NewProp_TimeTexture = { "TimeTexture", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Card, TimeTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeTexture_MetaData), NewProp_TimeTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Card_Statics::NewProp_MoneyTexture = { "MoneyTexture", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Card, MoneyTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoneyTexture_MetaData), NewProp_MoneyTexture_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPP_Card_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Statics::NewProp_CardNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Statics::NewProp_CardSuit_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Statics::NewProp_CardSuit,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Statics::NewProp_BloodTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Statics::NewProp_TimeTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Card_Statics::NewProp_MoneyTexture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Card_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACPP_Card_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_TimeIsMoney,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Card_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPP_Card_Statics::ClassParams = {
	&ACPP_Card::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACPP_Card_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Card_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Card_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPP_Card_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACPP_Card()
{
	if (!Z_Registration_Info_UClass_ACPP_Card.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPP_Card.OuterSingleton, Z_Construct_UClass_ACPP_Card_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACPP_Card.OuterSingleton;
}
template<> TIMEISMONEY_API UClass* StaticClass<ACPP_Card>()
{
	return ACPP_Card::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_Card);
ACPP_Card::~ACPP_Card() {}
// End Class ACPP_Card

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Tyler_Kendall_Documents_Unreal_Projects_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ECardSuit_StaticEnum, TEXT("ECardSuit"), &Z_Registration_Info_UEnum_ECardSuit, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1292650111U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_Card, ACPP_Card::StaticClass, TEXT("ACPP_Card"), &Z_Registration_Info_UClass_ACPP_Card, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_Card), 1257717102U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Tyler_Kendall_Documents_Unreal_Projects_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_1640356819(TEXT("/Script/TimeIsMoney"),
	Z_CompiledInDeferFile_FID_Users_Tyler_Kendall_Documents_Unreal_Projects_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Tyler_Kendall_Documents_Unreal_Projects_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_Tyler_Kendall_Documents_Unreal_Projects_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Tyler_Kendall_Documents_Unreal_Projects_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Card_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
