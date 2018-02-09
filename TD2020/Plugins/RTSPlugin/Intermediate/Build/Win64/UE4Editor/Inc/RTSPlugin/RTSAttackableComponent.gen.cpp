// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSAttackableComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSAttackableComponent() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSAttackableComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSAttackableComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
// End Cross Module References
	void URTSAttackableComponent::StaticRegisterNativesURTSAttackableComponent()
	{
	}
	UClass* Z_Construct_UClass_URTSAttackableComponent_NoRegister()
	{
		return URTSAttackableComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSAttackableComponent()
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
				{ "IncludePath", "RTSAttackableComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSAttackableComponent.h" },
				{ "ToolTip", "Allows choosing the actor as target for an attack order." },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSAttackableComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSAttackableComponent::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
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
	IMPLEMENT_CLASS(URTSAttackableComponent, 3639537198);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSAttackableComponent(Z_Construct_UClass_URTSAttackableComponent, &URTSAttackableComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSAttackableComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSAttackableComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
