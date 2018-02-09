// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSPortraitComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSPortraitComponent() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSPortraitComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSPortraitComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
	void URTSPortraitComponent::StaticRegisterNativesURTSPortraitComponent()
	{
	}
	UClass* Z_Construct_UClass_URTSPortraitComponent_NoRegister()
	{
		return URTSPortraitComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSPortraitComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "IncludePath", "RTSPortraitComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSPortraitComponent.h" },
				{ "ToolTip", "Adds a portrait to the actor that can be shown in the UI." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Portrait_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSPortraitComponent.h" },
				{ "ToolTip", "Portrait of the actor. Can be shown in the UI." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Portrait = { UE4CodeGen_Private::EPropertyClass::Object, "Portrait", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSPortraitComponent, Portrait), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_Portrait_MetaData, ARRAY_COUNT(NewProp_Portrait_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Portrait,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSPortraitComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSPortraitComponent::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
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
	IMPLEMENT_CLASS(URTSPortraitComponent, 4294117101);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSPortraitComponent(Z_Construct_UClass_URTSPortraitComponent, &URTSPortraitComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSPortraitComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSPortraitComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
