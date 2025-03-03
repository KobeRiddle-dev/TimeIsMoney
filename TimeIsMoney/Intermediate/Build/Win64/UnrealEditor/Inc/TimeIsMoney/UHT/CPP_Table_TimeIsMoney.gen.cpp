// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TimeIsMoney/CPP_Table_TimeIsMoney.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPP_Table_TimeIsMoney() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_Card_Deck_NoRegister();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_Card_NoRegister();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_NoRegister();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_Table_TimeIsMoney();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_Table_TimeIsMoney_NoRegister();
TIMEISMONEY_API UEnum* Z_Construct_UEnum_TimeIsMoney_ECardSuit();
UPackage* Z_Construct_UPackage__Script_TimeIsMoney();
// End Cross Module References

// Begin Class ACPP_Table_TimeIsMoney Function CheckForEndGame
struct Z_Construct_UFunction_ACPP_Table_TimeIsMoney_CheckForEndGame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Table_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_Table_TimeIsMoney.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Table_TimeIsMoney_CheckForEndGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Table_TimeIsMoney, nullptr, "CheckForEndGame", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Table_TimeIsMoney_CheckForEndGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Table_TimeIsMoney_CheckForEndGame_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ACPP_Table_TimeIsMoney_CheckForEndGame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Table_TimeIsMoney_CheckForEndGame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Table_TimeIsMoney::execCheckForEndGame)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CheckForEndGame();
	P_NATIVE_END;
}
// End Class ACPP_Table_TimeIsMoney Function CheckForEndGame

// Begin Class ACPP_Table_TimeIsMoney Function DetermineWinner
struct Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics
{
	struct CPP_Table_TimeIsMoney_eventDetermineWinner_Parms
	{
		ACPP_Card* Player;
		ACPP_Card* Opp;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Table_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_Table_TimeIsMoney.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Player;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Opp;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Table_TimeIsMoney_eventDetermineWinner_Parms, Player), Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::NewProp_Opp = { "Opp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Table_TimeIsMoney_eventDetermineWinner_Parms, Opp), Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CPP_Table_TimeIsMoney_eventDetermineWinner_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CPP_Table_TimeIsMoney_eventDetermineWinner_Parms), &Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::NewProp_Player,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::NewProp_Opp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Table_TimeIsMoney, nullptr, "DetermineWinner", nullptr, nullptr, Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::CPP_Table_TimeIsMoney_eventDetermineWinner_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::CPP_Table_TimeIsMoney_eventDetermineWinner_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Table_TimeIsMoney::execDetermineWinner)
{
	P_GET_OBJECT(ACPP_Card,Z_Param_Player);
	P_GET_OBJECT(ACPP_Card,Z_Param_Opp);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->DetermineWinner(Z_Param_Player,Z_Param_Opp);
	P_NATIVE_END;
}
// End Class ACPP_Table_TimeIsMoney Function DetermineWinner

// Begin Class ACPP_Table_TimeIsMoney Function StartGame
struct Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartGame_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Table_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_Table_TimeIsMoney.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartGame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Table_TimeIsMoney, nullptr, "StartGame", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartGame_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartGame_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartGame()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartGame_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Table_TimeIsMoney::execStartGame)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartGame();
	P_NATIVE_END;
}
// End Class ACPP_Table_TimeIsMoney Function StartGame

// Begin Class ACPP_Table_TimeIsMoney Function StartHand
struct Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics
{
	struct CPP_Table_TimeIsMoney_eventStartHand_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Table_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_Table_TimeIsMoney.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CPP_Table_TimeIsMoney_eventStartHand_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CPP_Table_TimeIsMoney_eventStartHand_Parms), &Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Table_TimeIsMoney, nullptr, "StartHand", nullptr, nullptr, Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::CPP_Table_TimeIsMoney_eventStartHand_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::CPP_Table_TimeIsMoney_eventStartHand_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACPP_Table_TimeIsMoney::execStartHand)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->StartHand();
	P_NATIVE_END;
}
// End Class ACPP_Table_TimeIsMoney Function StartHand

// Begin Class ACPP_Table_TimeIsMoney
void ACPP_Table_TimeIsMoney::StaticRegisterNativesACPP_Table_TimeIsMoney()
{
	UClass* Class = ACPP_Table_TimeIsMoney::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CheckForEndGame", &ACPP_Table_TimeIsMoney::execCheckForEndGame },
		{ "DetermineWinner", &ACPP_Table_TimeIsMoney::execDetermineWinner },
		{ "StartGame", &ACPP_Table_TimeIsMoney::execStartGame },
		{ "StartHand", &ACPP_Table_TimeIsMoney::execStartHand },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACPP_Table_TimeIsMoney);
UClass* Z_Construct_UClass_ACPP_Table_TimeIsMoney_NoRegister()
{
	return ACPP_Table_TimeIsMoney::StaticClass();
}
struct Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "CPP_Table_TimeIsMoney.h" },
		{ "ModuleRelativePath", "CPP_Table_TimeIsMoney.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Opponent_MetaData[] = {
		{ "Category", "Table_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_Table_TimeIsMoney.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCard_MetaData[] = {
		{ "Category", "Table_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_Table_TimeIsMoney.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpponentCard_MetaData[] = {
		{ "Category", "Table_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_Table_TimeIsMoney.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerHands_MetaData[] = {
		{ "Category", "Table_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_Table_TimeIsMoney.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpponentHands_MetaData[] = {
		{ "Category", "Table_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_Table_TimeIsMoney.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameIsActive_MetaData[] = {
		{ "Category", "Table_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_Table_TimeIsMoney.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Deck_MetaData[] = {
		{ "Category", "Table_TimeIsMoney" },
		{ "ModuleRelativePath", "CPP_Table_TimeIsMoney.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Opponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerCard;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OpponentCard;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PlayerHands_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PlayerHands_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PlayerHands_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_PlayerHands;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OpponentHands_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OpponentHands_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OpponentHands_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_OpponentHands;
	static void NewProp_GameIsActive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_GameIsActive;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Deck;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACPP_Table_TimeIsMoney_CheckForEndGame, "CheckForEndGame" }, // 2615763833
		{ &Z_Construct_UFunction_ACPP_Table_TimeIsMoney_DetermineWinner, "DetermineWinner" }, // 1921826931
		{ &Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartGame, "StartGame" }, // 2920465295
		{ &Z_Construct_UFunction_ACPP_Table_TimeIsMoney_StartHand, "StartHand" }, // 482080347
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_Table_TimeIsMoney>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_Opponent = { "Opponent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Table_TimeIsMoney, Opponent), Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Opponent_MetaData), NewProp_Opponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_PlayerCard = { "PlayerCard", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Table_TimeIsMoney, PlayerCard), Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerCard_MetaData), NewProp_PlayerCard_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_OpponentCard = { "OpponentCard", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Table_TimeIsMoney, OpponentCard), Z_Construct_UClass_ACPP_Card_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpponentCard_MetaData), NewProp_OpponentCard_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_PlayerHands_ValueProp = { "PlayerHands", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_PlayerHands_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_PlayerHands_Key_KeyProp = { "PlayerHands_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_TimeIsMoney_ECardSuit, METADATA_PARAMS(0, nullptr) }; // 1292650111
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_PlayerHands = { "PlayerHands", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Table_TimeIsMoney, PlayerHands), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerHands_MetaData), NewProp_PlayerHands_MetaData) }; // 1292650111
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_OpponentHands_ValueProp = { "OpponentHands", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_OpponentHands_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_OpponentHands_Key_KeyProp = { "OpponentHands_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_TimeIsMoney_ECardSuit, METADATA_PARAMS(0, nullptr) }; // 1292650111
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_OpponentHands = { "OpponentHands", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Table_TimeIsMoney, OpponentHands), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpponentHands_MetaData), NewProp_OpponentHands_MetaData) }; // 1292650111
void Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_GameIsActive_SetBit(void* Obj)
{
	((ACPP_Table_TimeIsMoney*)Obj)->GameIsActive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_GameIsActive = { "GameIsActive", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACPP_Table_TimeIsMoney), &Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_GameIsActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameIsActive_MetaData), NewProp_GameIsActive_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_Deck = { "Deck", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Table_TimeIsMoney, Deck), Z_Construct_UClass_ACPP_Card_Deck_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Deck_MetaData), NewProp_Deck_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_Opponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_PlayerCard,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_OpponentCard,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_PlayerHands_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_PlayerHands_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_PlayerHands_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_PlayerHands,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_OpponentHands_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_OpponentHands_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_OpponentHands_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_OpponentHands,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_GameIsActive,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::NewProp_Deck,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_TimeIsMoney,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::ClassParams = {
	&ACPP_Table_TimeIsMoney::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACPP_Table_TimeIsMoney()
{
	if (!Z_Registration_Info_UClass_ACPP_Table_TimeIsMoney.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPP_Table_TimeIsMoney.OuterSingleton, Z_Construct_UClass_ACPP_Table_TimeIsMoney_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACPP_Table_TimeIsMoney.OuterSingleton;
}
template<> TIMEISMONEY_API UClass* StaticClass<ACPP_Table_TimeIsMoney>()
{
	return ACPP_Table_TimeIsMoney::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_Table_TimeIsMoney);
ACPP_Table_TimeIsMoney::~ACPP_Table_TimeIsMoney() {}
// End Class ACPP_Table_TimeIsMoney

// Begin Registration
struct Z_CompiledInDeferFile_FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Table_TimeIsMoney_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_Table_TimeIsMoney, ACPP_Table_TimeIsMoney::StaticClass, TEXT("ACPP_Table_TimeIsMoney"), &Z_Registration_Info_UClass_ACPP_Table_TimeIsMoney, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_Table_TimeIsMoney), 704798054U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Table_TimeIsMoney_h_2860245663(TEXT("/Script/TimeIsMoney"),
	Z_CompiledInDeferFile_FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Table_TimeIsMoney_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Goode_4500_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_Table_TimeIsMoney_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
