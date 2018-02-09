// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSBuildingCursor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSBuildingCursor() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSBuildingCursor_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSBuildingCursor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
// End Cross Module References
	void ARTSBuildingCursor::StaticRegisterNativesARTSBuildingCursor()
	{
	}
	UClass* Z_Construct_UClass_ARTSBuildingCursor_NoRegister()
	{
		return ARTSBuildingCursor::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSBuildingCursor()
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
				{ "IncludePath", "RTSBuildingCursor.h" },
				{ "ModuleRelativePath", "Classes/RTSBuildingCursor.h" },
				{ "ToolTip", "3D cursor for selecting a location for a building." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "RTSBuildingCursor" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Classes/RTSBuildingCursor.h" },
				{ "ToolTip", "Current preview mesh of this cursor." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh = { UE4CodeGen_Private::EPropertyClass::Object, "Mesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(ARTSBuildingCursor, Mesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(NewProp_Mesh_MetaData, ARRAY_COUNT(NewProp_Mesh_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InvalidLocationMaterial_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSBuildingCursor.h" },
				{ "ToolTip", "Material to apply while the current location is invalid." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InvalidLocationMaterial = { UE4CodeGen_Private::EPropertyClass::Object, "InvalidLocationMaterial", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ARTSBuildingCursor, InvalidLocationMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(NewProp_InvalidLocationMaterial_MetaData, ARRAY_COUNT(NewProp_InvalidLocationMaterial_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ValidLocationMaterial_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSBuildingCursor.h" },
				{ "ToolTip", "Material to apply while the current location is valid." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ValidLocationMaterial = { UE4CodeGen_Private::EPropertyClass::Object, "ValidLocationMaterial", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ARTSBuildingCursor, ValidLocationMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(NewProp_ValidLocationMaterial_MetaData, ARRAY_COUNT(NewProp_ValidLocationMaterial_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Mesh,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InvalidLocationMaterial,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ValidLocationMaterial,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSBuildingCursor>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSBuildingCursor::StaticClass,
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
	IMPLEMENT_CLASS(ARTSBuildingCursor, 1414337285);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSBuildingCursor(Z_Construct_UClass_ARTSBuildingCursor, &ARTSBuildingCursor::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSBuildingCursor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSBuildingCursor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
