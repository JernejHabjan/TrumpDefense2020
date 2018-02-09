// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSCameraBoundsVolume.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSCameraBoundsVolume() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSCameraBoundsVolume_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSCameraBoundsVolume();
	ENGINE_API UClass* Z_Construct_UClass_AVolume();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
// End Cross Module References
	void ARTSCameraBoundsVolume::StaticRegisterNativesARTSCameraBoundsVolume()
	{
	}
	UClass* Z_Construct_UClass_ARTSCameraBoundsVolume_NoRegister()
	{
		return ARTSCameraBoundsVolume::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSCameraBoundsVolume()
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
				{ "HideCategories", "Brush Physics Object Display Rendering Physics Input Blueprint" },
				{ "IncludePath", "RTSCameraBoundsVolume.h" },
				{ "ModuleRelativePath", "Classes/RTSCameraBoundsVolume.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
				{ "ToolTip", "Volume that restricts RTS camera movement.\nRTS cameras are not allowed to move outside of this volume.\nThere should never be more than one camera bounds volume per level." },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSCameraBoundsVolume>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSCameraBoundsVolume::StaticClass,
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
	IMPLEMENT_CLASS(ARTSCameraBoundsVolume, 1906681558);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSCameraBoundsVolume(Z_Construct_UClass_ARTSCameraBoundsVolume, &ARTSCameraBoundsVolume::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSCameraBoundsVolume"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSCameraBoundsVolume);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
