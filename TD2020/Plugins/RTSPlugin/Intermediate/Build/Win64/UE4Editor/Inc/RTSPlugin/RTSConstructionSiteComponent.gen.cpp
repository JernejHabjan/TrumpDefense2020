// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSConstructionSiteComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSConstructionSiteComponent() {}
// Cross Module References
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentConstructionCostRefundedSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceType_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentBuilderConsumedSignature__DelegateSignature();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentConstructionCanceledSignature__DelegateSignature();
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentConstructionFinishedSignature__DelegateSignature();
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentConstructionStartedSignature__DelegateSignature();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSConstructionSiteComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSConstructionSiteComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_CanAssignBuilder();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_CancelConstruction();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_FinishConstruction();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_GetProgressPercentage();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_IsConstructing();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_IsFinished();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_StartConstruction();
	RTSPLUGIN_API UEnum* Z_Construct_UEnum_RTSPlugin_ERTSProductionCostType();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentConstructionCostRefundedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSConstructionSiteComponentConstructionCostRefundedSignature_Parms
		{
			TSubclassOf<URTSResourceType>  ResourceType;
			float ResourceAmount;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ResourceAmount = { UE4CodeGen_Private::EPropertyClass::Float, "ResourceAmount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSConstructionSiteComponentConstructionCostRefundedSignature_Parms, ResourceAmount), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ResourceType = { UE4CodeGen_Private::EPropertyClass::Class, "ResourceType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSConstructionSiteComponentConstructionCostRefundedSignature_Parms, ResourceType), Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceAmount,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceType,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSConstructionSiteComponentConstructionCostRefundedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSConstructionSiteComponentConstructionCostRefundedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentBuilderConsumedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSConstructionSiteComponentBuilderConsumedSignature_Parms
		{
			AActor* Builder;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Builder = { UE4CodeGen_Private::EPropertyClass::Object, "Builder", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSConstructionSiteComponentBuilderConsumedSignature_Parms, Builder), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Builder,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSConstructionSiteComponentBuilderConsumedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSConstructionSiteComponentBuilderConsumedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentConstructionCanceledSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSConstructionSiteComponentConstructionCanceledSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentConstructionFinishedSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSConstructionSiteComponentConstructionFinishedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentConstructionStartedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSConstructionSiteComponentConstructionStartedSignature_Parms
		{
			float TotalConstructionTime;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TotalConstructionTime = { UE4CodeGen_Private::EPropertyClass::Float, "TotalConstructionTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSConstructionSiteComponentConstructionStartedSignature_Parms, TotalConstructionTime), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TotalConstructionTime,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSConstructionSiteComponentConstructionStartedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSConstructionSiteComponentConstructionStartedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	void URTSConstructionSiteComponent::StaticRegisterNativesURTSConstructionSiteComponent()
	{
		UClass* Class = URTSConstructionSiteComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CanAssignBuilder", (Native)&URTSConstructionSiteComponent::execCanAssignBuilder },
			{ "CancelConstruction", (Native)&URTSConstructionSiteComponent::execCancelConstruction },
			{ "FinishConstruction", (Native)&URTSConstructionSiteComponent::execFinishConstruction },
			{ "GetProgressPercentage", (Native)&URTSConstructionSiteComponent::execGetProgressPercentage },
			{ "IsConstructing", (Native)&URTSConstructionSiteComponent::execIsConstructing },
			{ "IsFinished", (Native)&URTSConstructionSiteComponent::execIsFinished },
			{ "StartConstruction", (Native)&URTSConstructionSiteComponent::execStartConstruction },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_CanAssignBuilder()
	{
		struct RTSConstructionSiteComponent_eventCanAssignBuilder_Parms
		{
			AActor* Builder;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSConstructionSiteComponent_eventCanAssignBuilder_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSConstructionSiteComponent_eventCanAssignBuilder_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Builder = { UE4CodeGen_Private::EPropertyClass::Object, "Builder", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSConstructionSiteComponent_eventCanAssignBuilder_Parms, Builder), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Builder,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Whether the specified builder can be assigned to this construction site." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSConstructionSiteComponent, "CanAssignBuilder", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020400, sizeof(RTSConstructionSiteComponent_eventCanAssignBuilder_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_CancelConstruction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Cancels constructing the actor, destroying it." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSConstructionSiteComponent, "CancelConstruction", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_FinishConstruction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Finishes constructing the actor." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSConstructionSiteComponent, "FinishConstruction", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_GetProgressPercentage()
	{
		struct RTSConstructionSiteComponent_eventGetProgressPercentage_Parms
		{
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSConstructionSiteComponent_eventGetProgressPercentage_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Gets the current construction progress [0..1]." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSConstructionSiteComponent, "GetProgressPercentage", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSConstructionSiteComponent_eventGetProgressPercentage_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_IsConstructing()
	{
		struct RTSConstructionSiteComponent_eventIsConstructing_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSConstructionSiteComponent_eventIsConstructing_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSConstructionSiteComponent_eventIsConstructing_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Whether the construction timer is currently being ticked, or not." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSConstructionSiteComponent, "IsConstructing", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSConstructionSiteComponent_eventIsConstructing_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_IsFinished()
	{
		struct RTSConstructionSiteComponent_eventIsFinished_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSConstructionSiteComponent_eventIsFinished_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSConstructionSiteComponent_eventIsFinished_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Whether the construction is finished and the actor ready to use." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSConstructionSiteComponent, "IsFinished", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSConstructionSiteComponent_eventIsFinished_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSConstructionSiteComponent_StartConstruction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Starts constructing the actor, setting the timer." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSConstructionSiteComponent, "StartConstruction", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URTSConstructionSiteComponent_NoRegister()
	{
		return URTSConstructionSiteComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSConstructionSiteComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URTSConstructionSiteComponent_CanAssignBuilder, "CanAssignBuilder" }, // 287128430
				{ &Z_Construct_UFunction_URTSConstructionSiteComponent_CancelConstruction, "CancelConstruction" }, // 3779113842
				{ &Z_Construct_UFunction_URTSConstructionSiteComponent_FinishConstruction, "FinishConstruction" }, // 3572495515
				{ &Z_Construct_UFunction_URTSConstructionSiteComponent_GetProgressPercentage, "GetProgressPercentage" }, // 431306016
				{ &Z_Construct_UFunction_URTSConstructionSiteComponent_IsConstructing, "IsConstructing" }, // 524561328
				{ &Z_Construct_UFunction_URTSConstructionSiteComponent_IsFinished, "IsFinished" }, // 4089974088
				{ &Z_Construct_UFunction_URTSConstructionSiteComponent_StartConstruction, "StartConstruction" }, // 1621276037
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "IncludePath", "RTSConstructionSiteComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Allows constructing the actor over time." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnConstructionCostRefunded_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Event when any construction costs have been refunded." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConstructionCostRefunded = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnConstructionCostRefunded", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, OnConstructionCostRefunded), Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentConstructionCostRefundedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnConstructionCostRefunded_MetaData, ARRAY_COUNT(NewProp_OnConstructionCostRefunded_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnBuilderConsumed_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Event when a builder working at this construction site has been destroyed." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnBuilderConsumed = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnBuilderConsumed", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, OnBuilderConsumed), Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentBuilderConsumedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnBuilderConsumed_MetaData, ARRAY_COUNT(NewProp_OnBuilderConsumed_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnConstructionCanceled_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Event when the construction has been canceled and the construction site destroyed." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConstructionCanceled = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnConstructionCanceled", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, OnConstructionCanceled), Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentConstructionCanceledSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnConstructionCanceled_MetaData, ARRAY_COUNT(NewProp_OnConstructionCanceled_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnConstructionFinished_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Event when the construction timer has been expired." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConstructionFinished = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnConstructionFinished", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, OnConstructionFinished), Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentConstructionFinishedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnConstructionFinished_MetaData, ARRAY_COUNT(NewProp_OnConstructionFinished_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnConstructionStarted_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Event when the construction timer has been started." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConstructionStarted = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnConstructionStarted", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, OnConstructionStarted), Z_Construct_UDelegateFunction_RTSPlugin_RTSConstructionSiteComponentConstructionStartedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnConstructionStarted_MetaData, ARRAY_COUNT(NewProp_OnConstructionStarted_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bStartImmediately_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Whether to start construction immediately after spawn, or not." },
			};
#endif
			auto NewProp_bStartImmediately_SetBit = [](void* Obj){ ((URTSConstructionSiteComponent*)Obj)->bStartImmediately = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bStartImmediately = { UE4CodeGen_Private::EPropertyClass::Bool, "bStartImmediately", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(URTSConstructionSiteComponent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bStartImmediately_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bStartImmediately_MetaData, ARRAY_COUNT(NewProp_bStartImmediately_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RefundFactor_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Resources to refund when canceling construction." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RefundFactor = { UE4CodeGen_Private::EPropertyClass::Float, "RefundFactor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, RefundFactor), METADATA_PARAMS(NewProp_RefundFactor_MetaData, ARRAY_COUNT(NewProp_RefundFactor_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RemainingConstructionTime_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Time before the actor is constructed, in seconds." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RemainingConstructionTime = { UE4CodeGen_Private::EPropertyClass::Float, "RemainingConstructionTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000025, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, RemainingConstructionTime), METADATA_PARAMS(NewProp_RemainingConstructionTime_MetaData, ARRAY_COUNT(NewProp_RemainingConstructionTime_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProgressMadePerBuilder_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Factor to multiply all passed construction time with, multiplied with the number of currently assigned builders." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ProgressMadePerBuilder = { UE4CodeGen_Private::EPropertyClass::Float, "ProgressMadePerBuilder", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, ProgressMadePerBuilder), METADATA_PARAMS(NewProp_ProgressMadePerBuilder_MetaData, ARRAY_COUNT(NewProp_ProgressMadePerBuilder_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProgressMadeAutomatically_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Factor to multiply all passed construction time with, independent of any currently assigned builders." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ProgressMadeAutomatically = { UE4CodeGen_Private::EPropertyClass::Float, "ProgressMadeAutomatically", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, ProgressMadeAutomatically), METADATA_PARAMS(NewProp_ProgressMadeAutomatically_MetaData, ARRAY_COUNT(NewProp_ProgressMadeAutomatically_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxAssignedBuilders_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "How many builders may be assigned to this construction site at the same time." },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxAssignedBuilders = { UE4CodeGen_Private::EPropertyClass::Int, "MaxAssignedBuilders", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, MaxAssignedBuilders), METADATA_PARAMS(NewProp_MaxAssignedBuilders_MetaData, ARRAY_COUNT(NewProp_MaxAssignedBuilders_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bConsumesBuilders_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Whether any builders working at this construction site are destroyed when finished." },
			};
#endif
			auto NewProp_bConsumesBuilders_SetBit = [](void* Obj){ ((URTSConstructionSiteComponent*)Obj)->bConsumesBuilders = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bConsumesBuilders = { UE4CodeGen_Private::EPropertyClass::Bool, "bConsumesBuilders", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(URTSConstructionSiteComponent), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bConsumesBuilders_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bConsumesBuilders_MetaData, ARRAY_COUNT(NewProp_bConsumesBuilders_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConstructionTime_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Time for constructing the actor, in seconds." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ConstructionTime = { UE4CodeGen_Private::EPropertyClass::Float, "ConstructionTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, ConstructionTime), METADATA_PARAMS(NewProp_ConstructionTime_MetaData, ARRAY_COUNT(NewProp_ConstructionTime_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConstructionCosts_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "Resources to pay for constructing the actor." },
			};
#endif
			static const UE4CodeGen_Private::FMapPropertyParams NewProp_ConstructionCosts = { UE4CodeGen_Private::EPropertyClass::Map, "ConstructionCosts", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, ConstructionCosts), METADATA_PARAMS(NewProp_ConstructionCosts_MetaData, ARRAY_COUNT(NewProp_ConstructionCosts_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ConstructionCosts_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Class, "ConstructionCosts_Key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000001, 1, nullptr, 0, Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ConstructionCosts_ValueProp = { UE4CodeGen_Private::EPropertyClass::Float, "ConstructionCosts", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000001, 1, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConstructionCostType_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSConstructionSiteComponent.h" },
				{ "ToolTip", "When to pay resources for construction." },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ConstructionCostType = { UE4CodeGen_Private::EPropertyClass::Enum, "ConstructionCostType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSConstructionSiteComponent, ConstructionCostType), Z_Construct_UEnum_RTSPlugin_ERTSProductionCostType, METADATA_PARAMS(NewProp_ConstructionCostType_MetaData, ARRAY_COUNT(NewProp_ConstructionCostType_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_ConstructionCostType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnConstructionCostRefunded,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnBuilderConsumed,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnConstructionCanceled,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnConstructionFinished,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnConstructionStarted,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bStartImmediately,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RefundFactor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RemainingConstructionTime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProgressMadePerBuilder,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProgressMadeAutomatically,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaxAssignedBuilders,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bConsumesBuilders,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ConstructionTime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ConstructionCosts,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ConstructionCosts_Key_KeyProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ConstructionCosts_ValueProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ConstructionCostType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ConstructionCostType_Underlying,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSConstructionSiteComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSConstructionSiteComponent::StaticClass,
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
	IMPLEMENT_CLASS(URTSConstructionSiteComponent, 1905005269);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSConstructionSiteComponent(Z_Construct_UClass_URTSConstructionSiteComponent, &URTSConstructionSiteComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSConstructionSiteComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSConstructionSiteComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
