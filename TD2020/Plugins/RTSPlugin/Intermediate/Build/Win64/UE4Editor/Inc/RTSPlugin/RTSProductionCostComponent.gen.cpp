// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSProductionCostComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSProductionCostComponent() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSProductionCostComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSProductionCostComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceType_NoRegister();
	RTSPLUGIN_API UEnum* Z_Construct_UEnum_RTSPlugin_ERTSProductionCostType();
// End Cross Module References
	void URTSProductionCostComponent::StaticRegisterNativesURTSProductionCostComponent()
	{
	}
	UClass* Z_Construct_UClass_URTSProductionCostComponent_NoRegister()
	{
		return URTSProductionCostComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSProductionCostComponent()
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
				{ "IncludePath", "RTSProductionCostComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSProductionCostComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Specifies the time and resources required to construct the actor." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RefundFactor_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionCostComponent.h" },
				{ "ToolTip", "Resources to refund when canceling production." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RefundFactor = { UE4CodeGen_Private::EPropertyClass::Float, "RefundFactor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSProductionCostComponent, RefundFactor), METADATA_PARAMS(NewProp_RefundFactor_MetaData, ARRAY_COUNT(NewProp_RefundFactor_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Resources_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionCostComponent.h" },
				{ "ToolTip", "Resources to pay for producing the actor." },
			};
#endif
			static const UE4CodeGen_Private::FMapPropertyParams NewProp_Resources = { UE4CodeGen_Private::EPropertyClass::Map, "Resources", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSProductionCostComponent, Resources), METADATA_PARAMS(NewProp_Resources_MetaData, ARRAY_COUNT(NewProp_Resources_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_Resources_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Class, "Resources_Key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000001, 1, nullptr, 0, Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Resources_ValueProp = { UE4CodeGen_Private::EPropertyClass::Float, "Resources", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000001, 1, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProductionTime_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionCostComponent.h" },
				{ "ToolTip", "Time for producing the actor, in seconds." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ProductionTime = { UE4CodeGen_Private::EPropertyClass::Float, "ProductionTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSProductionCostComponent, ProductionTime), METADATA_PARAMS(NewProp_ProductionTime_MetaData, ARRAY_COUNT(NewProp_ProductionTime_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProductionCostType_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionCostComponent.h" },
				{ "ToolTip", "When to pay resources for production." },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ProductionCostType = { UE4CodeGen_Private::EPropertyClass::Enum, "ProductionCostType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSProductionCostComponent, ProductionCostType), Z_Construct_UEnum_RTSPlugin_ERTSProductionCostType, METADATA_PARAMS(NewProp_ProductionCostType_MetaData, ARRAY_COUNT(NewProp_ProductionCostType_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_ProductionCostType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RefundFactor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Resources,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Resources_Key_KeyProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Resources_ValueProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductionTime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductionCostType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductionCostType_Underlying,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSProductionCostComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSProductionCostComponent::StaticClass,
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
	IMPLEMENT_CLASS(URTSProductionCostComponent, 1123015413);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSProductionCostComponent(Z_Construct_UClass_URTSProductionCostComponent, &URTSProductionCostComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSProductionCostComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSProductionCostComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
