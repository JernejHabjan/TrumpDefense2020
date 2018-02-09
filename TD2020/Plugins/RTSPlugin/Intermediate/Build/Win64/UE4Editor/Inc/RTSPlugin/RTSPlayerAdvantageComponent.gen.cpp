// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSPlayerAdvantageComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSPlayerAdvantageComponent() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSPlayerAdvantageComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSPlayerAdvantageComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
// End Cross Module References
	void URTSPlayerAdvantageComponent::StaticRegisterNativesURTSPlayerAdvantageComponent()
	{
	}
	UClass* Z_Construct_UClass_URTSPlayerAdvantageComponent_NoRegister()
	{
		return URTSPlayerAdvantageComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSPlayerAdvantageComponent()
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
				{ "IncludePath", "RTSPlayerAdvantageComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSPlayerAdvantageComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Attach to player or AI controllers. Provides bonuses for various gameplay elements." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpeedBoostFactor_MetaData[] = {
				{ "Category", "RTS|Advantage" },
				{ "ModuleRelativePath", "Classes/RTSPlayerAdvantageComponent.h" },
				{ "ToolTip", "Factor to multiply all construction and production speed with." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SpeedBoostFactor = { UE4CodeGen_Private::EPropertyClass::Float, "SpeedBoostFactor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSPlayerAdvantageComponent, SpeedBoostFactor), METADATA_PARAMS(NewProp_SpeedBoostFactor_MetaData, ARRAY_COUNT(NewProp_SpeedBoostFactor_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bGodModeEnabled_MetaData[] = {
				{ "Category", "RTS|Advantage" },
				{ "ModuleRelativePath", "Classes/RTSPlayerAdvantageComponent.h" },
				{ "ToolTip", "Whether units controlled by the player are invulnerable, or not." },
			};
#endif
			auto NewProp_bGodModeEnabled_SetBit = [](void* Obj){ ((URTSPlayerAdvantageComponent*)Obj)->bGodModeEnabled = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bGodModeEnabled = { UE4CodeGen_Private::EPropertyClass::Bool, "bGodModeEnabled", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(URTSPlayerAdvantageComponent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bGodModeEnabled_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bGodModeEnabled_MetaData, ARRAY_COUNT(NewProp_bGodModeEnabled_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SpeedBoostFactor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bGodModeEnabled,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSPlayerAdvantageComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSPlayerAdvantageComponent::StaticClass,
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
	IMPLEMENT_CLASS(URTSPlayerAdvantageComponent, 783264183);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSPlayerAdvantageComponent(Z_Construct_UClass_URTSPlayerAdvantageComponent, &URTSPlayerAdvantageComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSPlayerAdvantageComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSPlayerAdvantageComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
