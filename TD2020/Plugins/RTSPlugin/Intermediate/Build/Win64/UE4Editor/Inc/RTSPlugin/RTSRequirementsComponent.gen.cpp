// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSRequirementsComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSRequirementsComponent() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSRequirementsComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSRequirementsComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	void URTSRequirementsComponent::StaticRegisterNativesURTSRequirementsComponent()
	{
	}
	UClass* Z_Construct_UClass_URTSRequirementsComponent_NoRegister()
	{
		return URTSRequirementsComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSRequirementsComponent()
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
				{ "IncludePath", "RTSRequirementsComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSRequirementsComponent.h" },
				{ "ToolTip", "Adds tech tree requirements to the actor." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RequiredActors_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSRequirementsComponent.h" },
				{ "ToolTip", "Types of actors the player needs to own in order to create this actor." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_RequiredActors = { UE4CodeGen_Private::EPropertyClass::Array, "RequiredActors", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000005, 1, nullptr, STRUCT_OFFSET(URTSRequirementsComponent, RequiredActors), METADATA_PARAMS(NewProp_RequiredActors_MetaData, ARRAY_COUNT(NewProp_RequiredActors_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_RequiredActors_Inner = { UE4CodeGen_Private::EPropertyClass::Class, "RequiredActors", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000000, 1, nullptr, 0, Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RequiredActors,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RequiredActors_Inner,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSRequirementsComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSRequirementsComponent::StaticClass,
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
	IMPLEMENT_CLASS(URTSRequirementsComponent, 828719321);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSRequirementsComponent(Z_Construct_UClass_URTSRequirementsComponent, &URTSRequirementsComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSRequirementsComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSRequirementsComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
