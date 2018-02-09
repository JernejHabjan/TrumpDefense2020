// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSVisionComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSVisionComponent() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSVisionComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSVisionComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
// End Cross Module References
	void URTSVisionComponent::StaticRegisterNativesURTSVisionComponent()
	{
	}
	UClass* Z_Construct_UClass_URTSVisionComponent_NoRegister()
	{
		return URTSVisionComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSVisionComponent()
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
				{ "IncludePath", "RTSVisionComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSVisionComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Allows the actor to reveal areas covered by fog of war." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SightRadius_MetaData[] = {
				{ "Category", "RTS" },
				{ "ClampMin", "0" },
				{ "ModuleRelativePath", "Classes/RTSVisionComponent.h" },
				{ "ToolTip", "Radius in which the actor reveals areas covered by fog of war, in cm." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SightRadius = { UE4CodeGen_Private::EPropertyClass::Float, "SightRadius", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000025, 1, nullptr, STRUCT_OFFSET(URTSVisionComponent, SightRadius), METADATA_PARAMS(NewProp_SightRadius_MetaData, ARRAY_COUNT(NewProp_SightRadius_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SightRadius,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSVisionComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSVisionComponent::StaticClass,
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
	IMPLEMENT_CLASS(URTSVisionComponent, 1290426081);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSVisionComponent(Z_Construct_UClass_URTSVisionComponent, &URTSVisionComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSVisionComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSVisionComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
