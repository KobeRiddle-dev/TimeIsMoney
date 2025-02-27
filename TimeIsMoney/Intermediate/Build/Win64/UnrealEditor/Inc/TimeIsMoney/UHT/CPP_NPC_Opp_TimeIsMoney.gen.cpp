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
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney();
TIMEISMONEY_API UClass* Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney_NoRegister();
UPackage* Z_Construct_UPackage__Script_TimeIsMoney();
// End Cross Module References

// Begin Class ACPP_NPC_Opp_TimeIsMoney
void ACPP_NPC_Opp_TimeIsMoney::StaticRegisterNativesACPP_NPC_Opp_TimeIsMoney()
{
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
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_NPC_Opp_TimeIsMoney>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
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
struct Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_GitHub_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_NPC_Opp_TimeIsMoney_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_NPC_Opp_TimeIsMoney, ACPP_NPC_Opp_TimeIsMoney::StaticClass, TEXT("ACPP_NPC_Opp_TimeIsMoney"), &Z_Registration_Info_UClass_ACPP_NPC_Opp_TimeIsMoney, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_NPC_Opp_TimeIsMoney), 266147123U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_GitHub_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_NPC_Opp_TimeIsMoney_h_1169366418(TEXT("/Script/TimeIsMoney"),
	Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_GitHub_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_NPC_Opp_TimeIsMoney_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_GitHub_TimeIsMoney_TimeIsMoney_Source_TimeIsMoney_CPP_NPC_Opp_TimeIsMoney_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
