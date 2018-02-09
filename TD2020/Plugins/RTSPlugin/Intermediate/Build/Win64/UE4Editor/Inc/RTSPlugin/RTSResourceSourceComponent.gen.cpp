// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSResourceSourceComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSResourceSourceComponent() {}
// Cross Module References
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSResourceSourceComponentDepletedSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSResourceSourceComponentResourcesChangedSignature__DelegateSignature();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceSourceComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceSourceComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSResourceSourceComponent_CanGathererEnter();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSResourceSourceComponent_ExtractResources();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceType_NoRegister();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSResourceSourceComponentDepletedSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSResourceSourceComponentDepletedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSResourceSourceComponentResourcesChangedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSResourceSourceComponentResourcesChangedSignature_Parms
		{
			float OldResources;
			float NewResources;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewResources = { UE4CodeGen_Private::EPropertyClass::Float, "NewResources", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSResourceSourceComponentResourcesChangedSignature_Parms, NewResources), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OldResources = { UE4CodeGen_Private::EPropertyClass::Float, "OldResources", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSResourceSourceComponentResourcesChangedSignature_Parms, OldResources), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewResources,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OldResources,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSResourceSourceComponentResourcesChangedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSResourceSourceComponentResourcesChangedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	void URTSResourceSourceComponent::StaticRegisterNativesURTSResourceSourceComponent()
	{
		UClass* Class = URTSResourceSourceComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CanGathererEnter", (Native)&URTSResourceSourceComponent::execCanGathererEnter },
			{ "ExtractResources", (Native)&URTSResourceSourceComponent::execExtractResources },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URTSResourceSourceComponent_CanGathererEnter()
	{
		struct RTSResourceSourceComponent_eventCanGathererEnter_Parms
		{
			AActor* Gatherer;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSResourceSourceComponent_eventCanGathererEnter_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSResourceSourceComponent_eventCanGathererEnter_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Gatherer = { UE4CodeGen_Private::EPropertyClass::Object, "Gatherer", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSResourceSourceComponent_eventCanGathererEnter_Parms, Gatherer), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Gatherer,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
				{ "ToolTip", "Checks whether the specified gatherer can enter the resource source right now." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSResourceSourceComponent, "CanGathererEnter", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020400, sizeof(RTSResourceSourceComponent_eventCanGathererEnter_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSResourceSourceComponent_ExtractResources()
	{
		struct RTSResourceSourceComponent_eventExtractResources_Parms
		{
			AActor* Gatherer;
			float ResourceAmount;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSResourceSourceComponent_eventExtractResources_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ResourceAmount = { UE4CodeGen_Private::EPropertyClass::Float, "ResourceAmount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSResourceSourceComponent_eventExtractResources_Parms, ResourceAmount), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Gatherer = { UE4CodeGen_Private::EPropertyClass::Object, "Gatherer", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSResourceSourceComponent_eventExtractResources_Parms, Gatherer), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceAmount,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Gatherer,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
				{ "ToolTip", "Extracts resources from this actor, applying gathering factor and checking remaining amount." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSResourceSourceComponent, "ExtractResources", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, sizeof(RTSResourceSourceComponent_eventExtractResources_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URTSResourceSourceComponent_NoRegister()
	{
		return URTSResourceSourceComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSResourceSourceComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URTSResourceSourceComponent_CanGathererEnter, "CanGathererEnter" }, // 2406833686
				{ &Z_Construct_UFunction_URTSResourceSourceComponent_ExtractResources, "ExtractResources" }, // 233861084
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "IncludePath", "RTSResourceSourceComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Adds resources to be gathered from the actor." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnDepleted_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
				{ "ToolTip", "Event when the actor has been depleted." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDepleted = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnDepleted", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSResourceSourceComponent, OnDepleted), Z_Construct_UDelegateFunction_RTSPlugin_RTSResourceSourceComponentDepletedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnDepleted_MetaData, ARRAY_COUNT(NewProp_OnDepleted_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnResourcesChanged_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
				{ "ToolTip", "Event when the amount of available resources has changed." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnResourcesChanged = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnResourcesChanged", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSResourceSourceComponent, OnResourcesChanged), Z_Construct_UDelegateFunction_RTSPlugin_RTSResourceSourceComponentResourcesChangedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnResourcesChanged_MetaData, ARRAY_COUNT(NewProp_OnResourcesChanged_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GathererCapacity_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
				{ "ToolTip", "How many gatherers may enter at the same time." },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_GathererCapacity = { UE4CodeGen_Private::EPropertyClass::Int, "GathererCapacity", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSResourceSourceComponent, GathererCapacity), METADATA_PARAMS(NewProp_GathererCapacity_MetaData, ARRAY_COUNT(NewProp_GathererCapacity_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bGathererMustEnter_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
				{ "ToolTip", "Whether gatherers must enter the resource source for gathering." },
			};
#endif
			auto NewProp_bGathererMustEnter_SetBit = [](void* Obj){ ((URTSResourceSourceComponent*)Obj)->bGathererMustEnter = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bGathererMustEnter = { UE4CodeGen_Private::EPropertyClass::Bool, "bGathererMustEnter", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(URTSResourceSourceComponent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bGathererMustEnter_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bGathererMustEnter_MetaData, ARRAY_COUNT(NewProp_bGathererMustEnter_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GatheringFactor_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
				{ "ToolTip", "Factor to multiply all gathered resources with (e.g. very abundant resource nodes." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GatheringFactor = { UE4CodeGen_Private::EPropertyClass::Float, "GatheringFactor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSResourceSourceComponent, GatheringFactor), METADATA_PARAMS(NewProp_GatheringFactor_MetaData, ARRAY_COUNT(NewProp_GatheringFactor_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaximumResources_MetaData[] = {
				{ "Category", "RTS" },
				{ "ClampMin", "0" },
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
				{ "ToolTip", "Maximum resources available at the actor." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaximumResources = { UE4CodeGen_Private::EPropertyClass::Float, "MaximumResources", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSResourceSourceComponent, MaximumResources), METADATA_PARAMS(NewProp_MaximumResources_MetaData, ARRAY_COUNT(NewProp_MaximumResources_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentResources_MetaData[] = {
				{ "Category", "RTS" },
				{ "ClampMin", "0" },
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
				{ "ToolTip", "Current resources available at the actor." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentResources = { UE4CodeGen_Private::EPropertyClass::Float, "CurrentResources", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000025, 1, nullptr, STRUCT_OFFSET(URTSResourceSourceComponent, CurrentResources), METADATA_PARAMS(NewProp_CurrentResources_MetaData, ARRAY_COUNT(NewProp_CurrentResources_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResourceType_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSResourceSourceComponent.h" },
				{ "ToolTip", "Type of resources to be gathered from the actor." },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ResourceType = { UE4CodeGen_Private::EPropertyClass::Class, "ResourceType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000005, 1, nullptr, STRUCT_OFFSET(URTSResourceSourceComponent, ResourceType), Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_ResourceType_MetaData, ARRAY_COUNT(NewProp_ResourceType_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnDepleted,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnResourcesChanged,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GathererCapacity,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bGathererMustEnter,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GatheringFactor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaximumResources,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentResources,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceType,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSResourceSourceComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSResourceSourceComponent::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(URTSResourceSourceComponent, 657160704);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSResourceSourceComponent(Z_Construct_UClass_URTSResourceSourceComponent, &URTSResourceSourceComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSResourceSourceComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSResourceSourceComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
