// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSVisionVolume.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSVisionVolume() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSVisionVolume_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSVisionVolume();
	ENGINE_API UClass* Z_Construct_UClass_AVolume();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
// End Cross Module References
	void ARTSVisionVolume::StaticRegisterNativesARTSVisionVolume()
	{
	}
	UClass* Z_Construct_UClass_ARTSVisionVolume_NoRegister()
	{
		return ARTSVisionVolume::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSVisionVolume()
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
				{ "IncludePath", "RTSVisionVolume.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Classes/RTSVisionVolume.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
				{ "ToolTip", "Volume that defines the size and resolution of vision provided by units." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSVisionVolume.h" },
			};
#endif
			auto NewProp_Enable_SetBit = [](void* Obj){ ((ARTSVisionVolume*)Obj)->Enable = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Enable = { UE4CodeGen_Private::EPropertyClass::Bool, "Enable", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSVisionVolume), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_Enable_SetBit)>::SetBit, METADATA_PARAMS(NewProp_Enable_MetaData, ARRAY_COUNT(NewProp_Enable_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SizePerTile_MetaData[] = {
				{ "Category", "RTS" },
				{ "ClampMin", "0" },
				{ "ModuleRelativePath", "Classes/RTSVisionVolume.h" },
				{ "ToolTip", "Size of a single tile of the vision grid imposed on the world." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SizePerTile = { UE4CodeGen_Private::EPropertyClass::Float, "SizePerTile", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ARTSVisionVolume, SizePerTile), METADATA_PARAMS(NewProp_SizePerTile_MetaData, ARRAY_COUNT(NewProp_SizePerTile_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Enable,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SizePerTile,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSVisionVolume>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSVisionVolume::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARTSVisionVolume, 252968733);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSVisionVolume(Z_Construct_UClass_ARTSVisionVolume, &ARTSVisionVolume::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSVisionVolume"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSVisionVolume);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
