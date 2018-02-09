// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSFogOfWarActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSFogOfWarActor() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSFogOfWarActor_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSFogOfWarActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	ENGINE_API UClass* Z_Construct_UClass_APostProcessVolume_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
// End Cross Module References
	void ARTSFogOfWarActor::StaticRegisterNativesARTSFogOfWarActor()
	{
	}
	UClass* Z_Construct_UClass_ARTSFogOfWarActor_NoRegister()
	{
		return ARTSFogOfWarActor::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSFogOfWarActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "RTSFogOfWarActor.h" },
				{ "ModuleRelativePath", "Classes/RTSFogOfWarActor.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Renders fog of war in 3D space." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FogOfWarVolume_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "RTSFogOfWarActor" },
				{ "ModuleRelativePath", "Classes/RTSFogOfWarActor.h" },
				{ "ToolTip", "Renders the fog of war." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FogOfWarVolume = { UE4CodeGen_Private::EPropertyClass::Object, "FogOfWarVolume", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000015, 1, nullptr, STRUCT_OFFSET(ARTSFogOfWarActor, FogOfWarVolume), Z_Construct_UClass_APostProcessVolume_NoRegister, METADATA_PARAMS(NewProp_FogOfWarVolume_MetaData, ARRAY_COUNT(NewProp_FogOfWarVolume_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FogOfWarMaterial_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "RTSFogOfWarActor" },
				{ "ModuleRelativePath", "Classes/RTSFogOfWarActor.h" },
				{ "ToolTip", "Material to instance for rendering the fog of war effect." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FogOfWarMaterial = { UE4CodeGen_Private::EPropertyClass::Object, "FogOfWarMaterial", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000015, 1, nullptr, STRUCT_OFFSET(ARTSFogOfWarActor, FogOfWarMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(NewProp_FogOfWarMaterial_MetaData, ARRAY_COUNT(NewProp_FogOfWarMaterial_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Enable_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSFogOfWarActor.h" },
			};
#endif
			auto NewProp_Enable_SetBit = [](void* Obj){ ((ARTSFogOfWarActor*)Obj)->Enable = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Enable = { UE4CodeGen_Private::EPropertyClass::Bool, "Enable", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSFogOfWarActor), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_Enable_SetBit)>::SetBit, METADATA_PARAMS(NewProp_Enable_MetaData, ARRAY_COUNT(NewProp_Enable_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FogOfWarVolume,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FogOfWarMaterial,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Enable,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSFogOfWarActor>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSFogOfWarActor::StaticClass,
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
	IMPLEMENT_CLASS(ARTSFogOfWarActor, 2860261386);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSFogOfWarActor(Z_Construct_UClass_ARTSFogOfWarActor, &ARTSFogOfWarActor::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSFogOfWarActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSFogOfWarActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
