// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject2/GM_Casino.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGM_Casino() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
MYPROJECT2_API UClass* Z_Construct_UClass_AGM_Casino();
MYPROJECT2_API UClass* Z_Construct_UClass_AGM_Casino_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProject2();
// End Cross Module References

// Begin Class AGM_Casino
void AGM_Casino::StaticRegisterNativesAGM_Casino()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGM_Casino);
UClass* Z_Construct_UClass_AGM_Casino_NoRegister()
{
	return AGM_Casino::StaticClass();
}
struct Z_Construct_UClass_AGM_Casino_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GM_Casino.h" },
		{ "ModuleRelativePath", "GM_Casino.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGM_Casino>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AGM_Casino_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject2,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGM_Casino_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGM_Casino_Statics::ClassParams = {
	&AGM_Casino::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGM_Casino_Statics::Class_MetaDataParams), Z_Construct_UClass_AGM_Casino_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGM_Casino()
{
	if (!Z_Registration_Info_UClass_AGM_Casino.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGM_Casino.OuterSingleton, Z_Construct_UClass_AGM_Casino_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGM_Casino.OuterSingleton;
}
template<> MYPROJECT2_API UClass* StaticClass<AGM_Casino>()
{
	return AGM_Casino::StaticClass();
}
AGM_Casino::AGM_Casino(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGM_Casino);
AGM_Casino::~AGM_Casino() {}
// End Class AGM_Casino

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_Unreal_Projects_MyProject2_Source_MyProject2_GM_Casino_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGM_Casino, AGM_Casino::StaticClass, TEXT("AGM_Casino"), &Z_Registration_Info_UClass_AGM_Casino, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGM_Casino), 3474545290U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_Unreal_Projects_MyProject2_Source_MyProject2_GM_Casino_h_3167003448(TEXT("/Script/MyProject2"),
	Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_Unreal_Projects_MyProject2_Source_MyProject2_GM_Casino_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_Unreal_Projects_MyProject2_Source_MyProject2_GM_Casino_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
