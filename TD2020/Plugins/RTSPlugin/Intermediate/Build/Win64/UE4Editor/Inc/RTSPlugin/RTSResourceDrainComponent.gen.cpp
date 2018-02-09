// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSResourceDrainComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSResourceDrainComponent() {}
// Cross Module References
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSResourceDrainComponentResourcesReturnedSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceType_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceDrainComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceDrainComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSResourceDrainComponentResourcesReturnedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSResourceDrainComponentResourcesReturnedSignature_Parms
		{
			AActor* Gatherer;
			TSubclassOf<URTSResourceType>  ResourceType;
			float ResourceAmount;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ResourceAmount = { UE4CodeGen_Private::EPropertyClass::Float, "ResourceAmount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSResourceDrainComponentResourcesReturnedSignature_Parms, ResourceAmount), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ResourceType = { UE4CodeGen_Private::EPropertyClass::Class, "ResourceType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSResourceDrainComponentResourcesReturnedSignature_Parms, ResourceType), Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Gatherer = { UE4CodeGen_Private::EPropertyClass::Object, "Gatherer", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSResourceDrainComponentResourcesReturnedSignature_Parms, Gatherer), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceAmount,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Gatherer,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSResourceDrainComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSResourceDrainComponentResourcesReturnedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSResourceDrainComponentResourcesReturnedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	void URTSResourceDrainComponent::StaticRegisterNativesURTSResourceDrainComponent()
	{
	}
	UClass* Z_Construct_UClass_URTSResourceDrainComponent_NoRegister()
	{
		return URTSResourceDrainComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSResourceDrainComponent()
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
				{ "IncludePath", "RTSResourceDrainComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSResourceDrainComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Allows resources to be returned to the actor." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnResourcesReturned_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSResourceDrainComponent.h" },
				{ "ToolTip", "Event when resources have been returned to the actor." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnResourcesReturned = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnResourcesReturned", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSResourceDrainComponent, OnResourcesReturned), Z_Construct_UDelegateFunction_RTSPlugin_RTSResourceDrainComponentResourcesReturnedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnResourcesReturned_MetaData, ARRAY_COUNT(NewProp_OnResourcesReturned_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GathererCapacity_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSResourceDrainComponent.h" },
				{ "ToolTip", "How many gatherers may enter at the same time." },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_GathererCapacity = { UE4CodeGen_Private::EPropertyClass::Int, "GathererCapacity", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSResourceDrainComponent, GathererCapacity), METADATA_PARAMS(NewProp_GathererCapacity_MetaData, ARRAY_COUNT(NewProp_GathererCapacity_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bGathererMustEnter_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSResourceDrainComponent.h" },
				{ "ToolTip", "Whether gatherers must enter the resource drain for returning resources." },
			};
#endif
			auto NewProp_bGathererMustEnter_SetBit = [](void* Obj){ ((URTSResourceDrainComponent*)Obj)->bGathererMustEnter = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bGathererMustEnter = { UE4CodeGen_Private::EPropertyClass::Bool, "bGathererMustEnter", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(URTSResourceDrainComponent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bGathererMustEnter_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bGathererMustEnter_MetaData, ARRAY_COUNT(NewProp_bGathererMustEnter_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResourceTypes_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSResourceDrainComponent.h" },
				{ "ToolTip", "Types of resources that can be returned to the actor." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ResourceTypes = { UE4CodeGen_Private::EPropertyClass::Array, "ResourceTypes", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000005, 1, nullptr, STRUCT_OFFSET(URTSResourceDrainComponent, ResourceTypes), METADATA_PARAMS(NewProp_ResourceTypes_MetaData, ARRAY_COUNT(NewProp_ResourceTypes_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ResourceTypes_Inner = { UE4CodeGen_Private::EPropertyClass::Class, "ResourceTypes", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000000, 1, nullptr, 0, Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnResourcesReturned,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GathererCapacity,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bGathererMustEnter,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceTypes,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceTypes_Inner,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSResourceDrainComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSResourceDrainComponent::StaticClass,
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
	IMPLEMENT_CLASS(URTSResourceDrainComponent, 1576396556);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSResourceDrainComponent(Z_Construct_UClass_URTSResourceDrainComponent, &URTSResourceDrainComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSResourceDrainComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSResourceDrainComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
