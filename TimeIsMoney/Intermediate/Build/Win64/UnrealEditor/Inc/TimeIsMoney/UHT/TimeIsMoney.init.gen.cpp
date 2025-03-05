// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTimeIsMoney_init() {}
	TIMEISMONEY_API UFunction* Z_Construct_UDelegateFunction_TimeIsMoney__CardDrawnEventDispatcher__DelegateSignature();
	TIMEISMONEY_API UFunction* Z_Construct_UDelegateFunction_TimeIsMoney__HandDiscardedEventDispatcher__DelegateSignature();
	TIMEISMONEY_API UFunction* Z_Construct_UDelegateFunction_TimeIsMoney_OnHandStartEventDispatcher__DelegateSignature();
	TIMEISMONEY_API UFunction* Z_Construct_UDelegateFunction_TimeIsMoney_OnOppCardPlayedEventDispatcher__DelegateSignature();
	TIMEISMONEY_API UFunction* Z_Construct_UDelegateFunction_TimeIsMoney_OnPlayerCardPlayedEventDispatcher__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_TimeIsMoney;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_TimeIsMoney()
	{
		if (!Z_Registration_Info_UPackage__Script_TimeIsMoney.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_TimeIsMoney__CardDrawnEventDispatcher__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_TimeIsMoney__HandDiscardedEventDispatcher__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_TimeIsMoney_OnHandStartEventDispatcher__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_TimeIsMoney_OnOppCardPlayedEventDispatcher__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_TimeIsMoney_OnPlayerCardPlayedEventDispatcher__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/TimeIsMoney",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x1A502582,
				0x9653843F,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_TimeIsMoney.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_TimeIsMoney.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_TimeIsMoney(Z_Construct_UPackage__Script_TimeIsMoney, TEXT("/Script/TimeIsMoney"), Z_Registration_Info_UPackage__Script_TimeIsMoney, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x1A502582, 0x9653843F));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
