// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSCharacter() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSCharacter_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	ENGINE_API UClass* Z_Construct_UClass_UDecalComponent_NoRegister();
// End Cross Module References
	void ARTSCharacter::StaticRegisterNativesARTSCharacter()
	{
	}
	UClass* Z_Construct_UClass_ARTSCharacter_NoRegister()
	{
		return ARTSCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ACharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "RTSCharacter.h" },
				{ "ModuleRelativePath", "Classes/RTSCharacter.h" },
				{ "ToolTip", "Character with RTS features, such as taking damage." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelectionCircleDecalComponent_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "RTSCharacter" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Classes/RTSCharacter.h" },
				{ "ToolTip", "Decal used for rendering the selection circle of this character." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SelectionCircleDecalComponent = { UE4CodeGen_Private::EPropertyClass::Object, "SelectionCircleDecalComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(ARTSCharacter, SelectionCircleDecalComponent), Z_Construct_UClass_UDecalComponent_NoRegister, METADATA_PARAMS(NewProp_SelectionCircleDecalComponent_MetaData, ARRAY_COUNT(NewProp_SelectionCircleDecalComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SelectionCircleDecalComponent,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSCharacter>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSCharacter::StaticClass,
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
	IMPLEMENT_CLASS(ARTSCharacter, 2784921987);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSCharacter(Z_Construct_UClass_ARTSCharacter, &ARTSCharacter::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
