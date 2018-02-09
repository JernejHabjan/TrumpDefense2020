// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSMinimapVolume.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSMinimapVolume() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSMinimapVolume_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSMinimapVolume();
	ENGINE_API UClass* Z_Construct_UClass_AVolume();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
// End Cross Module References
	void ARTSMinimapVolume::StaticRegisterNativesARTSMinimapVolume()
	{
	}
	UClass* Z_Construct_UClass_ARTSMinimapVolume_NoRegister()
	{
		return ARTSMinimapVolume::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSMinimapVolume()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AVolume,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "HideCategories", "Brush Physics Object Display Rendering Physics Input Blueprint" },
				{ "IncludePath", "RTSMinimapVolume.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Classes/RTSMinimapVolume.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
				{ "ToolTip", "Volume that defines the size and resolution of the minimap." },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSMinimapVolume>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSMinimapVolume::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
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
	IMPLEMENT_CLASS(ARTSMinimapVolume, 1891156115);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSMinimapVolume(Z_Construct_UClass_ARTSMinimapVolume, &ARTSMinimapVolume::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSMinimapVolume"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSMinimapVolume);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
