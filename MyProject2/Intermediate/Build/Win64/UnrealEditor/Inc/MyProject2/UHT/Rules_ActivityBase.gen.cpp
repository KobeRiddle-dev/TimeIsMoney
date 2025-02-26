// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject2/Rules_ActivityBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRules_ActivityBase() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
MYPROJECT2_API UClass* Z_Construct_UClass_URules_ActivityBase();
MYPROJECT2_API UClass* Z_Construct_UClass_URules_ActivityBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProject2();
// End Cross Module References

// Begin Class URules_ActivityBase
void URules_ActivityBase::StaticRegisterNativesURules_ActivityBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URules_ActivityBase);
UClass* Z_Construct_UClass_URules_ActivityBase_NoRegister()
{
	return URules_ActivityBase::StaticClass();
}
struct Z_Construct_UClass_URules_ActivityBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Rules_ActivityBase.h" },
		{ "ModuleRelativePath", "Rules_ActivityBase.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URules_ActivityBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_URules_ActivityBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject2,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URules_ActivityBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_URules_ActivityBase_Statics::ClassParams = {
	&URules_ActivityBase::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URules_ActivityBase_Statics::Class_MetaDataParams), Z_Construct_UClass_URules_ActivityBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_URules_ActivityBase()
{
	if (!Z_Registration_Info_UClass_URules_ActivityBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URules_ActivityBase.OuterSingleton, Z_Construct_UClass_URules_ActivityBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_URules_ActivityBase.OuterSingleton;
}
template<> MYPROJECT2_API UClass* StaticClass<URules_ActivityBase>()
{
	return URules_ActivityBase::StaticClass();
}
URules_ActivityBase::URules_ActivityBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(URules_ActivityBase);
URules_ActivityBase::~URules_ActivityBase() {}
// End Class URules_ActivityBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_Unreal_Projects_MyProject2_Source_MyProject2_Rules_ActivityBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_URules_ActivityBase, URules_ActivityBase::StaticClass, TEXT("URules_ActivityBase"), &Z_Registration_Info_UClass_URules_ActivityBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URules_ActivityBase), 314603677U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_Unreal_Projects_MyProject2_Source_MyProject2_Rules_ActivityBase_h_1433125064(TEXT("/Script/MyProject2"),
	Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_Unreal_Projects_MyProject2_Source_MyProject2_Rules_ActivityBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_gronaldo44_Documents_Unreal_Projects_MyProject2_Source_MyProject2_Rules_ActivityBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
