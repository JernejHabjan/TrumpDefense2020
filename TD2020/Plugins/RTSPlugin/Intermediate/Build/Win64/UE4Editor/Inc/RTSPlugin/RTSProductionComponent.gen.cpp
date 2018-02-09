// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSProductionComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSProductionComponent() {}
// Cross Module References
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductionCostRefundedSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceType_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductionCanceledSignature__DelegateSignature();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductionFinishedSignature__DelegateSignature();
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductionStartedSignature__DelegateSignature();
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductQueuedSignature__DelegateSignature();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSProductionComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSProductionComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSProductionComponent_CanAssignProduction();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSProductionComponent_CancelProduction();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSProductionComponent_FindQueueForProduct();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSProductionComponent_FinishProduction();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSProductionComponent_GetCurrentProduction();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSProductionComponent_GetProductionTime();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSProductionComponent_GetProductionTimeForProduct();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSProductionComponent_GetProgressPercentage();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSProductionComponent_GetRemainingProductionTime();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSProductionComponent_IsProducing();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSProductionComponent_StartProduction();
	RTSPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FRTSProductionQueue();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductionCostRefundedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSProductionComponentProductionCostRefundedSignature_Parms
		{
			TSubclassOf<URTSResourceType>  ResourceType;
			float ResourceAmount;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ResourceAmount = { UE4CodeGen_Private::EPropertyClass::Float, "ResourceAmount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSProductionComponentProductionCostRefundedSignature_Parms, ResourceAmount), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ResourceType = { UE4CodeGen_Private::EPropertyClass::Class, "ResourceType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSProductionComponentProductionCostRefundedSignature_Parms, ResourceType), Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceAmount,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceType,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSProductionComponentProductionCostRefundedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSProductionComponentProductionCostRefundedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductionCanceledSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSProductionComponentProductionCanceledSignature_Parms
		{
			TSubclassOf<AActor>  ProductClass;
			int32 QueueIndex;
			float ElapsedProductionTime;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ElapsedProductionTime = { UE4CodeGen_Private::EPropertyClass::Float, "ElapsedProductionTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSProductionComponentProductionCanceledSignature_Parms, ElapsedProductionTime), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_QueueIndex = { UE4CodeGen_Private::EPropertyClass::Int, "QueueIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSProductionComponentProductionCanceledSignature_Parms, QueueIndex), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProductClass = { UE4CodeGen_Private::EPropertyClass::Class, "ProductClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSProductionComponentProductionCanceledSignature_Parms, ProductClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ElapsedProductionTime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_QueueIndex,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSProductionComponentProductionCanceledSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSProductionComponentProductionCanceledSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductionFinishedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSProductionComponentProductionFinishedSignature_Parms
		{
			AActor* Product;
			int32 QueueIndex;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_QueueIndex = { UE4CodeGen_Private::EPropertyClass::Int, "QueueIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSProductionComponentProductionFinishedSignature_Parms, QueueIndex), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Product = { UE4CodeGen_Private::EPropertyClass::Object, "Product", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSProductionComponentProductionFinishedSignature_Parms, Product), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_QueueIndex,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Product,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSProductionComponentProductionFinishedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSProductionComponentProductionFinishedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductionStartedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSProductionComponentProductionStartedSignature_Parms
		{
			TSubclassOf<AActor>  ProductClass;
			int32 QueueIndex;
			float TotalProductionTime;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TotalProductionTime = { UE4CodeGen_Private::EPropertyClass::Float, "TotalProductionTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSProductionComponentProductionStartedSignature_Parms, TotalProductionTime), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_QueueIndex = { UE4CodeGen_Private::EPropertyClass::Int, "QueueIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSProductionComponentProductionStartedSignature_Parms, QueueIndex), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProductClass = { UE4CodeGen_Private::EPropertyClass::Class, "ProductClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSProductionComponentProductionStartedSignature_Parms, ProductClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TotalProductionTime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_QueueIndex,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSProductionComponentProductionStartedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSProductionComponentProductionStartedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductQueuedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSProductionComponentProductQueuedSignature_Parms
		{
			TSubclassOf<AActor>  ProductClass;
			int32 QueueIndex;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_QueueIndex = { UE4CodeGen_Private::EPropertyClass::Int, "QueueIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSProductionComponentProductQueuedSignature_Parms, QueueIndex), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProductClass = { UE4CodeGen_Private::EPropertyClass::Class, "ProductClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSProductionComponentProductQueuedSignature_Parms, ProductClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_QueueIndex,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSProductionComponentProductQueuedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSProductionComponentProductQueuedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	void URTSProductionComponent::StaticRegisterNativesURTSProductionComponent()
	{
		UClass* Class = URTSProductionComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CanAssignProduction", (Native)&URTSProductionComponent::execCanAssignProduction },
			{ "CancelProduction", (Native)&URTSProductionComponent::execCancelProduction },
			{ "FindQueueForProduct", (Native)&URTSProductionComponent::execFindQueueForProduct },
			{ "FinishProduction", (Native)&URTSProductionComponent::execFinishProduction },
			{ "GetCurrentProduction", (Native)&URTSProductionComponent::execGetCurrentProduction },
			{ "GetProductionTime", (Native)&URTSProductionComponent::execGetProductionTime },
			{ "GetProductionTimeForProduct", (Native)&URTSProductionComponent::execGetProductionTimeForProduct },
			{ "GetProgressPercentage", (Native)&URTSProductionComponent::execGetProgressPercentage },
			{ "GetRemainingProductionTime", (Native)&URTSProductionComponent::execGetRemainingProductionTime },
			{ "IsProducing", (Native)&URTSProductionComponent::execIsProducing },
			{ "StartProduction", (Native)&URTSProductionComponent::execStartProduction },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URTSProductionComponent_CanAssignProduction()
	{
		struct RTSProductionComponent_eventCanAssignProduction_Parms
		{
			TSubclassOf<AActor>  ProductClass;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSProductionComponent_eventCanAssignProduction_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSProductionComponent_eventCanAssignProduction_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProductClass = { UE4CodeGen_Private::EPropertyClass::Class, "ProductClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventCanAssignProduction_Parms, ProductClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Checks whether the actor can start producing the specified product." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSProductionComponent, "CanAssignProduction", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020400, sizeof(RTSProductionComponent_eventCanAssignProduction_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSProductionComponent_CancelProduction()
	{
		struct RTSProductionComponent_eventCancelProduction_Parms
		{
			int32 QueueIndex;
			int32 ProductIndex;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_ProductIndex = { UE4CodeGen_Private::EPropertyClass::Int, "ProductIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventCancelProduction_Parms, ProductIndex), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_QueueIndex = { UE4CodeGen_Private::EPropertyClass::Int, "QueueIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventCancelProduction_Parms, QueueIndex), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductIndex,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_QueueIndex,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "CPP_Default_ProductIndex", "0" },
				{ "CPP_Default_QueueIndex", "0" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Cancels producing the product in the specified queue." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSProductionComponent, "CancelProduction", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, sizeof(RTSProductionComponent_eventCancelProduction_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSProductionComponent_FindQueueForProduct()
	{
		struct RTSProductionComponent_eventFindQueueForProduct_Parms
		{
			TSubclassOf<AActor>  ProductClass;
			int32 ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Int, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventFindQueueForProduct_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProductClass = { UE4CodeGen_Private::EPropertyClass::Class, "ProductClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventFindQueueForProduct_Parms, ProductClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Gets the index of the queue the specified product would be assigned to, or -1 all queues are at the capacity limit." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSProductionComponent, "FindQueueForProduct", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020400, sizeof(RTSProductionComponent_eventFindQueueForProduct_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSProductionComponent_FinishProduction()
	{
		struct RTSProductionComponent_eventFinishProduction_Parms
		{
			int32 QueueIndex;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_QueueIndex = { UE4CodeGen_Private::EPropertyClass::Int, "QueueIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventFinishProduction_Parms, QueueIndex), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_QueueIndex,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "CPP_Default_QueueIndex", "0" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Finishes producing the product in the specified queue." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSProductionComponent, "FinishProduction", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, sizeof(RTSProductionComponent_eventFinishProduction_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSProductionComponent_GetCurrentProduction()
	{
		struct RTSProductionComponent_eventGetCurrentProduction_Parms
		{
			int32 QueueIndex;
			TSubclassOf<AActor>  ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Class, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000580, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventGetCurrentProduction_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_QueueIndex = { UE4CodeGen_Private::EPropertyClass::Int, "QueueIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventGetCurrentProduction_Parms, QueueIndex), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_QueueIndex,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "CPP_Default_QueueIndex", "0" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Gets the product currently being produced in the specified queue." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSProductionComponent, "GetCurrentProduction", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSProductionComponent_eventGetCurrentProduction_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSProductionComponent_GetProductionTime()
	{
		struct RTSProductionComponent_eventGetProductionTime_Parms
		{
			int32 QueueIndex;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventGetProductionTime_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_QueueIndex = { UE4CodeGen_Private::EPropertyClass::Int, "QueueIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventGetProductionTime_Parms, QueueIndex), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_QueueIndex,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "CPP_Default_QueueIndex", "0" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Gets the required time for producing the current product in the specified queue." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSProductionComponent, "GetProductionTime", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSProductionComponent_eventGetProductionTime_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSProductionComponent_GetProductionTimeForProduct()
	{
		struct RTSProductionComponent_eventGetProductionTimeForProduct_Parms
		{
			TSubclassOf<AActor>  ProductClass;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventGetProductionTimeForProduct_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProductClass = { UE4CodeGen_Private::EPropertyClass::Class, "ProductClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventGetProductionTimeForProduct_Parms, ProductClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Gets the required time for producing the specified product." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSProductionComponent, "GetProductionTimeForProduct", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020400, sizeof(RTSProductionComponent_eventGetProductionTimeForProduct_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSProductionComponent_GetProgressPercentage()
	{
		struct RTSProductionComponent_eventGetProgressPercentage_Parms
		{
			int32 QueueIndex;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventGetProgressPercentage_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_QueueIndex = { UE4CodeGen_Private::EPropertyClass::Int, "QueueIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventGetProgressPercentage_Parms, QueueIndex), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_QueueIndex,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "CPP_Default_QueueIndex", "0" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Gets the current production progress [0..1] for the specified queue." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSProductionComponent, "GetProgressPercentage", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSProductionComponent_eventGetProgressPercentage_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSProductionComponent_GetRemainingProductionTime()
	{
		struct RTSProductionComponent_eventGetRemainingProductionTime_Parms
		{
			int32 QueueIndex;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventGetRemainingProductionTime_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_QueueIndex = { UE4CodeGen_Private::EPropertyClass::Int, "QueueIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventGetRemainingProductionTime_Parms, QueueIndex), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_QueueIndex,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "CPP_Default_QueueIndex", "0" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Gets the time before producing the current product in the specified queue has finished." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSProductionComponent, "GetRemainingProductionTime", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSProductionComponent_eventGetRemainingProductionTime_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSProductionComponent_IsProducing()
	{
		struct RTSProductionComponent_eventIsProducing_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSProductionComponent_eventIsProducing_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSProductionComponent_eventIsProducing_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Whether any queue production timer is currently being ticked, or not." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSProductionComponent, "IsProducing", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSProductionComponent_eventIsProducing_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSProductionComponent_StartProduction()
	{
		struct RTSProductionComponent_eventStartProduction_Parms
		{
			TSubclassOf<AActor>  ProductClass;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProductClass = { UE4CodeGen_Private::EPropertyClass::Class, "ProductClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSProductionComponent_eventStartProduction_Parms, ProductClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Starts producing the specified product, setting the timer." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSProductionComponent, "StartProduction", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, sizeof(RTSProductionComponent_eventStartProduction_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URTSProductionComponent_NoRegister()
	{
		return URTSProductionComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSProductionComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URTSProductionComponent_CanAssignProduction, "CanAssignProduction" }, // 1270337585
				{ &Z_Construct_UFunction_URTSProductionComponent_CancelProduction, "CancelProduction" }, // 140223465
				{ &Z_Construct_UFunction_URTSProductionComponent_FindQueueForProduct, "FindQueueForProduct" }, // 2012042015
				{ &Z_Construct_UFunction_URTSProductionComponent_FinishProduction, "FinishProduction" }, // 3658445947
				{ &Z_Construct_UFunction_URTSProductionComponent_GetCurrentProduction, "GetCurrentProduction" }, // 1511702875
				{ &Z_Construct_UFunction_URTSProductionComponent_GetProductionTime, "GetProductionTime" }, // 1768768012
				{ &Z_Construct_UFunction_URTSProductionComponent_GetProductionTimeForProduct, "GetProductionTimeForProduct" }, // 1766408435
				{ &Z_Construct_UFunction_URTSProductionComponent_GetProgressPercentage, "GetProgressPercentage" }, // 1780668854
				{ &Z_Construct_UFunction_URTSProductionComponent_GetRemainingProductionTime, "GetRemainingProductionTime" }, // 2883275681
				{ &Z_Construct_UFunction_URTSProductionComponent_IsProducing, "IsProducing" }, // 2815224374
				{ &Z_Construct_UFunction_URTSProductionComponent_StartProduction, "StartProduction" }, // 3178690792
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "IncludePath", "RTSProductionComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Allows producing actors over time." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnProductionCostRefunded_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Event when any production costs have been refunded." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnProductionCostRefunded = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnProductionCostRefunded", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSProductionComponent, OnProductionCostRefunded), Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductionCostRefundedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnProductionCostRefunded_MetaData, ARRAY_COUNT(NewProp_OnProductionCostRefunded_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnProductionCanceled_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Event when the production has been canceled." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnProductionCanceled = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnProductionCanceled", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSProductionComponent, OnProductionCanceled), Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductionCanceledSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnProductionCanceled_MetaData, ARRAY_COUNT(NewProp_OnProductionCanceled_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnProductionFinished_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Event when the production timer has expired." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnProductionFinished = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnProductionFinished", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSProductionComponent, OnProductionFinished), Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductionFinishedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnProductionFinished_MetaData, ARRAY_COUNT(NewProp_OnProductionFinished_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnProductionStarted_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Event when the production timer has been started." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnProductionStarted = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnProductionStarted", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSProductionComponent, OnProductionStarted), Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductionStartedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnProductionStarted_MetaData, ARRAY_COUNT(NewProp_OnProductionStarted_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnProductQueued_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Event when a product has been queued for production." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnProductQueued = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnProductQueued", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSProductionComponent, OnProductQueued), Z_Construct_UDelegateFunction_RTSPlugin_RTSProductionComponentProductQueuedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnProductQueued_MetaData, ARRAY_COUNT(NewProp_OnProductQueued_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_QueueCount_MetaData[] = {
				{ "Category", "RTS" },
				{ "ClampMin", "1" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "How many products can be produced simultaneously." },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_QueueCount = { UE4CodeGen_Private::EPropertyClass::Int, "QueueCount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSProductionComponent, QueueCount), METADATA_PARAMS(NewProp_QueueCount_MetaData, ARRAY_COUNT(NewProp_QueueCount_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProductionQueues_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Products queued for production." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ProductionQueues = { UE4CodeGen_Private::EPropertyClass::Array, "ProductionQueues", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000034, 1, nullptr, STRUCT_OFFSET(URTSProductionComponent, ProductionQueues), METADATA_PARAMS(NewProp_ProductionQueues_MetaData, ARRAY_COUNT(NewProp_ProductionQueues_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ProductionQueues_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ProductionQueues", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FRTSProductionQueue, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CapacityPerQueue_MetaData[] = {
				{ "Category", "RTS" },
				{ "ClampMin", "1" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "How many products may be queued per queue." },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_CapacityPerQueue = { UE4CodeGen_Private::EPropertyClass::Int, "CapacityPerQueue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSProductionComponent, CapacityPerQueue), METADATA_PARAMS(NewProp_CapacityPerQueue_MetaData, ARRAY_COUNT(NewProp_CapacityPerQueue_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AvailableProducts_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionComponent.h" },
				{ "ToolTip", "Types of actors the actor can produce." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AvailableProducts = { UE4CodeGen_Private::EPropertyClass::Array, "AvailableProducts", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000005, 1, nullptr, STRUCT_OFFSET(URTSProductionComponent, AvailableProducts), METADATA_PARAMS(NewProp_AvailableProducts_MetaData, ARRAY_COUNT(NewProp_AvailableProducts_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_AvailableProducts_Inner = { UE4CodeGen_Private::EPropertyClass::Class, "AvailableProducts", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000000, 1, nullptr, 0, Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnProductionCostRefunded,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnProductionCanceled,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnProductionFinished,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnProductionStarted,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnProductQueued,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_QueueCount,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductionQueues,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductionQueues_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CapacityPerQueue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AvailableProducts,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AvailableProducts_Inner,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSProductionComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSProductionComponent::StaticClass,
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
	IMPLEMENT_CLASS(URTSProductionComponent, 1303260656);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSProductionComponent(Z_Construct_UClass_URTSProductionComponent, &URTSProductionComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSProductionComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSProductionComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
