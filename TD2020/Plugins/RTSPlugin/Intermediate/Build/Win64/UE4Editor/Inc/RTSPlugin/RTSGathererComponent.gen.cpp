// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSGathererComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSGathererComponent() {}
// Cross Module References
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSGathererComponentResourcesReturnedSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceType_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSGathererComponentResourcesGatheredSignature__DelegateSignature();
	RTSPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FRTSGatherData();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSGathererComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSGathererComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSGathererComponent_CanGatherFrom();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSGathererComponent_FindClosestResourceDrain();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSGathererComponent_GatherResources();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSGathererComponent_GetClosestResourceSource();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSGathererComponent_GetGatherRange();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSGathererComponent_GetPreferredResourceSource();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSGathererComponent_IsCarryingResources();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSGathererComponent_IsGathering();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSGathererComponent_ReturnResources();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSGathererComponent_StartGatheringResources();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSGathererComponentResourcesReturnedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSGathererComponentResourcesReturnedSignature_Parms
		{
			AActor* ResourceDrain;
			TSubclassOf<URTSResourceType>  ResourceType;
			float ReturnedAmount;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnedAmount = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnedAmount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSGathererComponentResourcesReturnedSignature_Parms, ReturnedAmount), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ResourceType = { UE4CodeGen_Private::EPropertyClass::Class, "ResourceType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSGathererComponentResourcesReturnedSignature_Parms, ResourceType), Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ResourceDrain = { UE4CodeGen_Private::EPropertyClass::Object, "ResourceDrain", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSGathererComponentResourcesReturnedSignature_Parms, ResourceDrain), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnedAmount,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceDrain,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSGathererComponentResourcesReturnedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSGathererComponentResourcesReturnedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSGathererComponentResourcesGatheredSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSGathererComponentResourcesGatheredSignature_Parms
		{
			AActor* ResourceSource;
			FRTSGatherData GatherData;
			float GatheredAmount;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GatheredAmount = { UE4CodeGen_Private::EPropertyClass::Float, "GatheredAmount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSGathererComponentResourcesGatheredSignature_Parms, GatheredAmount), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GatherData_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_GatherData = { UE4CodeGen_Private::EPropertyClass::Struct, "GatherData", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSGathererComponentResourcesGatheredSignature_Parms, GatherData), Z_Construct_UScriptStruct_FRTSGatherData, METADATA_PARAMS(NewProp_GatherData_MetaData, ARRAY_COUNT(NewProp_GatherData_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ResourceSource = { UE4CodeGen_Private::EPropertyClass::Object, "ResourceSource", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSGathererComponentResourcesGatheredSignature_Parms, ResourceSource), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GatheredAmount,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GatherData,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceSource,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSGathererComponentResourcesGatheredSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSGathererComponentResourcesGatheredSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	void URTSGathererComponent::StaticRegisterNativesURTSGathererComponent()
	{
		UClass* Class = URTSGathererComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CanGatherFrom", (Native)&URTSGathererComponent::execCanGatherFrom },
			{ "FindClosestResourceDrain", (Native)&URTSGathererComponent::execFindClosestResourceDrain },
			{ "GatherResources", (Native)&URTSGathererComponent::execGatherResources },
			{ "GetClosestResourceSource", (Native)&URTSGathererComponent::execGetClosestResourceSource },
			{ "GetGatherRange", (Native)&URTSGathererComponent::execGetGatherRange },
			{ "GetPreferredResourceSource", (Native)&URTSGathererComponent::execGetPreferredResourceSource },
			{ "IsCarryingResources", (Native)&URTSGathererComponent::execIsCarryingResources },
			{ "IsGathering", (Native)&URTSGathererComponent::execIsGathering },
			{ "ReturnResources", (Native)&URTSGathererComponent::execReturnResources },
			{ "StartGatheringResources", (Native)&URTSGathererComponent::execStartGatheringResources },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URTSGathererComponent_CanGatherFrom()
	{
		struct RTSGathererComponent_eventCanGatherFrom_Parms
		{
			AActor* ResourceSource;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSGathererComponent_eventCanGatherFrom_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSGathererComponent_eventCanGatherFrom_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ResourceSource = { UE4CodeGen_Private::EPropertyClass::Object, "ResourceSource", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventCanGatherFrom_Parms, ResourceSource), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceSource,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Checks whether the actor can gather from the specified source, e.g. is allowed to gather, and is not at capacity limit." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSGathererComponent, "CanGatherFrom", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, sizeof(RTSGathererComponent_eventCanGatherFrom_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSGathererComponent_FindClosestResourceDrain()
	{
		struct RTSGathererComponent_eventFindClosestResourceDrain_Parms
		{
			AActor* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventFindClosestResourceDrain_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Finds the closest resource drain for returning currently carried resources." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSGathererComponent, "FindClosestResourceDrain", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020400, sizeof(RTSGathererComponent_eventFindClosestResourceDrain_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSGathererComponent_GatherResources()
	{
		struct RTSGathererComponent_eventGatherResources_Parms
		{
			AActor* ResourceSource;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventGatherResources_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ResourceSource = { UE4CodeGen_Private::EPropertyClass::Object, "ResourceSource", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventGatherResources_Parms, ResourceSource), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceSource,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Gathers resources from the specified source and starts the cooldown timer." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSGathererComponent, "GatherResources", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, sizeof(RTSGathererComponent_eventGatherResources_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSGathererComponent_GetClosestResourceSource()
	{
		struct RTSGathererComponent_eventGetClosestResourceSource_Parms
		{
			TSubclassOf<URTSResourceType>  DesiredResourceType;
			float MaxDistance;
			AActor* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventGetClosestResourceSource_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxDistance = { UE4CodeGen_Private::EPropertyClass::Float, "MaxDistance", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventGetClosestResourceSource_Parms, MaxDistance), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_DesiredResourceType = { UE4CodeGen_Private::EPropertyClass::Class, "DesiredResourceType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventGetClosestResourceSource_Parms, DesiredResourceType), Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaxDistance,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DesiredResourceType,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Gets the closest resource source of the specified type within the passed maximum distance around the actor (0 means anywhere)." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSGathererComponent, "GetClosestResourceSource", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020400, sizeof(RTSGathererComponent_eventGetClosestResourceSource_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSGathererComponent_GetGatherRange()
	{
		struct RTSGathererComponent_eventGetGatherRange_Parms
		{
			AActor* ResourceSource;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventGetGatherRange_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ResourceSource = { UE4CodeGen_Private::EPropertyClass::Object, "ResourceSource", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventGetGatherRange_Parms, ResourceSource), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceSource,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Gets the maximum distance for gathering resources from the specified source." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSGathererComponent, "GetGatherRange", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, sizeof(RTSGathererComponent_eventGetGatherRange_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSGathererComponent_GetPreferredResourceSource()
	{
		struct RTSGathererComponent_eventGetPreferredResourceSource_Parms
		{
			AActor* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventGetPreferredResourceSource_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Gets the resource source the actor has recently been gathering from, if available, or a similar one within its sweep radius." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSGathererComponent, "GetPreferredResourceSource", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020400, sizeof(RTSGathererComponent_eventGetPreferredResourceSource_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSGathererComponent_IsCarryingResources()
	{
		struct RTSGathererComponent_eventIsCarryingResources_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSGathererComponent_eventIsCarryingResources_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSGathererComponent_eventIsCarryingResources_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Whether the gatherer is currently carrying any resources that could be returned." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSGathererComponent, "IsCarryingResources", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSGathererComponent_eventIsCarryingResources_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSGathererComponent_IsGathering()
	{
		struct RTSGathererComponent_eventIsGathering_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSGathererComponent_eventIsGathering_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSGathererComponent_eventIsGathering_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Whether this gatherer is currently gathering resources." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSGathererComponent, "IsGathering", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSGathererComponent_eventIsGathering_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSGathererComponent_ReturnResources()
	{
		struct RTSGathererComponent_eventReturnResources_Parms
		{
			AActor* ResourceDrain;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventReturnResources_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ResourceDrain = { UE4CodeGen_Private::EPropertyClass::Object, "ResourceDrain", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventReturnResources_Parms, ResourceDrain), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceDrain,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Returns resources to the specified drain." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSGathererComponent, "ReturnResources", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, sizeof(RTSGathererComponent_eventReturnResources_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSGathererComponent_StartGatheringResources()
	{
		struct RTSGathererComponent_eventStartGatheringResources_Parms
		{
			AActor* ResourceSource;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ResourceSource = { UE4CodeGen_Private::EPropertyClass::Object, "ResourceSource", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSGathererComponent_eventStartGatheringResources_Parms, ResourceSource), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceSource,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Starts the cooldown timer for gathering resources from the specified source." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSGathererComponent, "StartGatheringResources", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, sizeof(RTSGathererComponent_eventStartGatheringResources_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URTSGathererComponent_NoRegister()
	{
		return URTSGathererComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSGathererComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URTSGathererComponent_CanGatherFrom, "CanGatherFrom" }, // 25569741
				{ &Z_Construct_UFunction_URTSGathererComponent_FindClosestResourceDrain, "FindClosestResourceDrain" }, // 2332879006
				{ &Z_Construct_UFunction_URTSGathererComponent_GatherResources, "GatherResources" }, // 103864827
				{ &Z_Construct_UFunction_URTSGathererComponent_GetClosestResourceSource, "GetClosestResourceSource" }, // 3494064193
				{ &Z_Construct_UFunction_URTSGathererComponent_GetGatherRange, "GetGatherRange" }, // 27780939
				{ &Z_Construct_UFunction_URTSGathererComponent_GetPreferredResourceSource, "GetPreferredResourceSource" }, // 852529899
				{ &Z_Construct_UFunction_URTSGathererComponent_IsCarryingResources, "IsCarryingResources" }, // 2604825223
				{ &Z_Construct_UFunction_URTSGathererComponent_IsGathering, "IsGathering" }, // 1821924665
				{ &Z_Construct_UFunction_URTSGathererComponent_ReturnResources, "ReturnResources" }, // 3047210398
				{ &Z_Construct_UFunction_URTSGathererComponent_StartGatheringResources, "StartGatheringResources" }, // 2310557612
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "IncludePath", "RTSGathererComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Allows the actor to gather resources." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnResourcesReturned_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Event when the actor has returned resources to a drain." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnResourcesReturned = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnResourcesReturned", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSGathererComponent, OnResourcesReturned), Z_Construct_UDelegateFunction_RTSPlugin_RTSGathererComponentResourcesReturnedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnResourcesReturned_MetaData, ARRAY_COUNT(NewProp_OnResourcesReturned_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnResourcesGathered_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Event when the actor has gathered resources from a source." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnResourcesGathered = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnResourcesGathered", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSGathererComponent, OnResourcesGathered), Z_Construct_UDelegateFunction_RTSPlugin_RTSGathererComponentResourcesGatheredSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnResourcesGathered_MetaData, ARRAY_COUNT(NewProp_OnResourcesGathered_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResourceSweepRadius_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Radius in which the actor will automatically gather resources from, in cm." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ResourceSweepRadius = { UE4CodeGen_Private::EPropertyClass::Float, "ResourceSweepRadius", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSGathererComponent, ResourceSweepRadius), METADATA_PARAMS(NewProp_ResourceSweepRadius_MetaData, ARRAY_COUNT(NewProp_ResourceSweepRadius_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResourceSourceActorClasses_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Types of actors the gatherer can gather resources from." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ResourceSourceActorClasses = { UE4CodeGen_Private::EPropertyClass::Array, "ResourceSourceActorClasses", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000005, 1, nullptr, STRUCT_OFFSET(URTSGathererComponent, ResourceSourceActorClasses), METADATA_PARAMS(NewProp_ResourceSourceActorClasses_MetaData, ARRAY_COUNT(NewProp_ResourceSourceActorClasses_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ResourceSourceActorClasses_Inner = { UE4CodeGen_Private::EPropertyClass::Class, "ResourceSourceActorClasses", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000000, 1, nullptr, 0, Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RemainingCooldown_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Time before the next resources are gathered, in seconds." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RemainingCooldown = { UE4CodeGen_Private::EPropertyClass::Float, "RemainingCooldown", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSGathererComponent, RemainingCooldown), METADATA_PARAMS(NewProp_RemainingCooldown_MetaData, ARRAY_COUNT(NewProp_RemainingCooldown_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GatheredResources_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Resources that can be gathered by the actor." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_GatheredResources = { UE4CodeGen_Private::EPropertyClass::Array, "GatheredResources", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSGathererComponent, GatheredResources), METADATA_PARAMS(NewProp_GatheredResources_MetaData, ARRAY_COUNT(NewProp_GatheredResources_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_GatheredResources_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "GatheredResources", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FRTSGatherData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CarriedResourceType_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Type of resource the actor is carrying." },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_CarriedResourceType = { UE4CodeGen_Private::EPropertyClass::Class, "CarriedResourceType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000025, 1, nullptr, STRUCT_OFFSET(URTSGathererComponent, CarriedResourceType), Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_CarriedResourceType_MetaData, ARRAY_COUNT(NewProp_CarriedResourceType_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CarriedResourceAmount_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGathererComponent.h" },
				{ "ToolTip", "Amount of resources the actor is carrying." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CarriedResourceAmount = { UE4CodeGen_Private::EPropertyClass::Float, "CarriedResourceAmount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000025, 1, nullptr, STRUCT_OFFSET(URTSGathererComponent, CarriedResourceAmount), METADATA_PARAMS(NewProp_CarriedResourceAmount_MetaData, ARRAY_COUNT(NewProp_CarriedResourceAmount_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnResourcesReturned,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnResourcesGathered,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceSweepRadius,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceSourceActorClasses,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceSourceActorClasses_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RemainingCooldown,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GatheredResources,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GatheredResources_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CarriedResourceType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CarriedResourceAmount,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSGathererComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSGathererComponent::StaticClass,
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
	IMPLEMENT_CLASS(URTSGathererComponent, 1028239721);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSGathererComponent(Z_Construct_UClass_URTSGathererComponent, &URTSGathererComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSGathererComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSGathererComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
