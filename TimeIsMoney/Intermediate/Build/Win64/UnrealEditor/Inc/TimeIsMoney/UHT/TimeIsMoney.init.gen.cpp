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
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_TimeIsMoney;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_TimeIsMoney()
	{
		if (!Z_Registration_Info_UPackage__Script_TimeIsMoney.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_TimeIsMoney__CardDrawnEventDispatcher__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_TimeIsMoney__HandDiscardedEventDispatcher__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/TimeIsMoney",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xF6285B97,
				0x9B3B5D52,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_TimeIsMoney.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_TimeIsMoney.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_TimeIsMoney(Z_Construct_UPackage__Script_TimeIsMoney, TEXT("/Script/TimeIsMoney"), Z_Registration_Info_UPackage__Script_TimeIsMoney, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xF6285B97, 0x9B3B5D52));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
