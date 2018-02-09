// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSCharacterAIController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSCharacterAIController() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSCharacterAIController_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSCharacterAIController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSCharacterAIController_FindTargetInAcquisitionRadius();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSCharacterAIController_HasOrder();
	RTSPLUGIN_API UEnum* Z_Construct_UEnum_RTSPlugin_ERTSOrderType();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IsIdle();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueAttackOrder();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueBeginConstructionOrder();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueContinueConstructionOrder();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueGatherOrder();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueMoveOrder();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueReturnResourcesOrder();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueStopOrder();
	AIMODULE_API UClass* Z_Construct_UClass_UBlackboardData_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
// End Cross Module References
	void ARTSCharacterAIController::StaticRegisterNativesARTSCharacterAIController()
	{
		UClass* Class = ARTSCharacterAIController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FindTargetInAcquisitionRadius", (Native)&ARTSCharacterAIController::execFindTargetInAcquisitionRadius },
			{ "HasOrder", (Native)&ARTSCharacterAIController::execHasOrder },
			{ "IsIdle", (Native)&ARTSCharacterAIController::execIsIdle },
			{ "IssueAttackOrder", (Native)&ARTSCharacterAIController::execIssueAttackOrder },
			{ "IssueBeginConstructionOrder", (Native)&ARTSCharacterAIController::execIssueBeginConstructionOrder },
			{ "IssueContinueConstructionOrder", (Native)&ARTSCharacterAIController::execIssueContinueConstructionOrder },
			{ "IssueGatherOrder", (Native)&ARTSCharacterAIController::execIssueGatherOrder },
			{ "IssueMoveOrder", (Native)&ARTSCharacterAIController::execIssueMoveOrder },
			{ "IssueReturnResourcesOrder", (Native)&ARTSCharacterAIController::execIssueReturnResourcesOrder },
			{ "IssueStopOrder", (Native)&ARTSCharacterAIController::execIssueStopOrder },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ARTSCharacterAIController_FindTargetInAcquisitionRadius()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "Makes the pawn look for a feasible target in its acquisition radius." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSCharacterAIController, "FindTargetInAcquisitionRadius", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSCharacterAIController_HasOrder()
	{
		struct RTSCharacterAIController_eventHasOrder_Parms
		{
			ERTSOrderType OrderType;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSCharacterAIController_eventHasOrder_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSCharacterAIController_eventHasOrder_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_OrderType = { UE4CodeGen_Private::EPropertyClass::Enum, "OrderType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSCharacterAIController_eventHasOrder_Parms, OrderType), Z_Construct_UEnum_RTSPlugin_ERTSOrderType, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_OrderType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OrderType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OrderType_Underlying,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "Checks whether the pawn has an order of the specified type." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSCharacterAIController, "HasOrder", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSCharacterAIController_eventHasOrder_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IsIdle()
	{
		struct RTSCharacterAIController_eventIsIdle_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSCharacterAIController_eventIsIdle_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSCharacterAIController_eventIsIdle_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "Checks whether the pawn is idle, or has any orders." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSCharacterAIController, "IsIdle", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSCharacterAIController_eventIsIdle_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueAttackOrder()
	{
		struct RTSCharacterAIController_eventIssueAttackOrder_Parms
		{
			AActor* Target;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Target = { UE4CodeGen_Private::EPropertyClass::Object, "Target", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSCharacterAIController_eventIssueAttackOrder_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Target,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "Makes the pawn attack the specified target." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSCharacterAIController, "IssueAttackOrder", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSCharacterAIController_eventIssueAttackOrder_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueBeginConstructionOrder()
	{
		struct RTSCharacterAIController_eventIssueBeginConstructionOrder_Parms
		{
			TSubclassOf<AActor>  BuildingClass;
			FVector TargetLocation;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetLocation_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_TargetLocation = { UE4CodeGen_Private::EPropertyClass::Struct, "TargetLocation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(RTSCharacterAIController_eventIssueBeginConstructionOrder_Parms, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(NewProp_TargetLocation_MetaData, ARRAY_COUNT(NewProp_TargetLocation_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_BuildingClass = { UE4CodeGen_Private::EPropertyClass::Class, "BuildingClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSCharacterAIController_eventIssueBeginConstructionOrder_Parms, BuildingClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TargetLocation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BuildingClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "Makes the pawn construct the specified building at the passed location." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSCharacterAIController, "IssueBeginConstructionOrder", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C20401, sizeof(RTSCharacterAIController_eventIssueBeginConstructionOrder_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueContinueConstructionOrder()
	{
		struct RTSCharacterAIController_eventIssueContinueConstructionOrder_Parms
		{
			AActor* ConstructionSite;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ConstructionSite = { UE4CodeGen_Private::EPropertyClass::Object, "ConstructionSite", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSCharacterAIController_eventIssueContinueConstructionOrder_Parms, ConstructionSite), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ConstructionSite,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "Makes the pawn continue constructing the specified building." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSCharacterAIController, "IssueContinueConstructionOrder", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSCharacterAIController_eventIssueContinueConstructionOrder_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueGatherOrder()
	{
		struct RTSCharacterAIController_eventIssueGatherOrder_Parms
		{
			AActor* ResourceSource;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ResourceSource = { UE4CodeGen_Private::EPropertyClass::Object, "ResourceSource", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSCharacterAIController_eventIssueGatherOrder_Parms, ResourceSource), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceSource,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "Makes the pawn gather resources from the specified source." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSCharacterAIController, "IssueGatherOrder", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSCharacterAIController_eventIssueGatherOrder_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueMoveOrder()
	{
		struct RTSCharacterAIController_eventIssueMoveOrder_Parms
		{
			FVector Location;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location = { UE4CodeGen_Private::EPropertyClass::Struct, "Location", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(RTSCharacterAIController_eventIssueMoveOrder_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(NewProp_Location_MetaData, ARRAY_COUNT(NewProp_Location_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Location,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "Makes the pawn move towards the specified location." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSCharacterAIController, "IssueMoveOrder", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C20401, sizeof(RTSCharacterAIController_eventIssueMoveOrder_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueReturnResourcesOrder()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "Makes the pawn move towards the closest resource drain and return all carried resources." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSCharacterAIController, "IssueReturnResourcesOrder", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSCharacterAIController_IssueStopOrder()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "Makes the pawn stop all actions immediately." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSCharacterAIController, "IssueStopOrder", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARTSCharacterAIController_NoRegister()
	{
		return ARTSCharacterAIController::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSCharacterAIController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AAIController,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ARTSCharacterAIController_FindTargetInAcquisitionRadius, "FindTargetInAcquisitionRadius" }, // 12880675
				{ &Z_Construct_UFunction_ARTSCharacterAIController_HasOrder, "HasOrder" }, // 1758917210
				{ &Z_Construct_UFunction_ARTSCharacterAIController_IsIdle, "IsIdle" }, // 1091178514
				{ &Z_Construct_UFunction_ARTSCharacterAIController_IssueAttackOrder, "IssueAttackOrder" }, // 3268189071
				{ &Z_Construct_UFunction_ARTSCharacterAIController_IssueBeginConstructionOrder, "IssueBeginConstructionOrder" }, // 2320792563
				{ &Z_Construct_UFunction_ARTSCharacterAIController_IssueContinueConstructionOrder, "IssueContinueConstructionOrder" }, // 3366513838
				{ &Z_Construct_UFunction_ARTSCharacterAIController_IssueGatherOrder, "IssueGatherOrder" }, // 3520465560
				{ &Z_Construct_UFunction_ARTSCharacterAIController_IssueMoveOrder, "IssueMoveOrder" }, // 2706412314
				{ &Z_Construct_UFunction_ARTSCharacterAIController_IssueReturnResourcesOrder, "IssueReturnResourcesOrder" }, // 1018388280
				{ &Z_Construct_UFunction_ARTSCharacterAIController_IssueStopOrder, "IssueStopOrder" }, // 599523270
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "RTSCharacterAIController.h" },
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "AI controller that drives RTS unit movement and orders." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterBlackboardAsset_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "Blackboard to use for holding all data relevant to the character AI." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CharacterBlackboardAsset = { UE4CodeGen_Private::EPropertyClass::Object, "CharacterBlackboardAsset", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010015, 1, nullptr, STRUCT_OFFSET(ARTSCharacterAIController, CharacterBlackboardAsset), Z_Construct_UClass_UBlackboardData_NoRegister, METADATA_PARAMS(NewProp_CharacterBlackboardAsset_MetaData, ARRAY_COUNT(NewProp_CharacterBlackboardAsset_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterBehaviorTreeAsset_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSCharacterAIController.h" },
				{ "ToolTip", "Behavior tree to use for driving the character AI." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CharacterBehaviorTreeAsset = { UE4CodeGen_Private::EPropertyClass::Object, "CharacterBehaviorTreeAsset", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010015, 1, nullptr, STRUCT_OFFSET(ARTSCharacterAIController, CharacterBehaviorTreeAsset), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(NewProp_CharacterBehaviorTreeAsset_MetaData, ARRAY_COUNT(NewProp_CharacterBehaviorTreeAsset_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CharacterBlackboardAsset,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CharacterBehaviorTreeAsset,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSCharacterAIController>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSCharacterAIController::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900280u,
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
	IMPLEMENT_CLASS(ARTSCharacterAIController, 54088599);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSCharacterAIController(Z_Construct_UClass_ARTSCharacterAIController, &ARTSCharacterAIController::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSCharacterAIController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSCharacterAIController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
