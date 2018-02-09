// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSResourceType.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSResourceType() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceType_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceType();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
// End Cross Module References
	void URTSResourceType::StaticRegisterNativesURTSResourceType()
	{
	}
	UClass* Z_Construct_UClass_URTSResourceType_NoRegister()
	{
		return URTSResourceType::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSResourceType()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UObject,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "IncludePath", "RTSResourceType.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Classes/RTSResourceType.h" },
				{ "ToolTip", "Resource that can be gathered and spent for construction, production and research." },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSResourceType>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSResourceType::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100080u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URTSResourceType, 1345453981);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSResourceType(Z_Construct_UClass_URTSResourceType, &URTSResourceType::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSResourceType"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSResourceType);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
