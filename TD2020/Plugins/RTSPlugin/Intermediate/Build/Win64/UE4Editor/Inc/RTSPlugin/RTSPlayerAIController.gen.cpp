// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSPlayerAIController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSPlayerAIController() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSPlayerAIController_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSPlayerAIController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSPlayerAIController_CanPayFor();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSPlayerAIController_GetNextPawnToProduce();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSPlayerAIController_GetPrimaryResourceDrain();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSPlayerAIController_GetPrimaryResourceSource();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSPlayerAIController_MeetsAllRequirementsFor();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSPlayerAIController_StartProduction();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSPlayerResourcesComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceType_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBlackboardData_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
// End Cross Module References
	void ARTSPlayerAIController::StaticRegisterNativesARTSPlayerAIController()
	{
		UClass* Class = ARTSPlayerAIController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CanPayFor", (Native)&ARTSPlayerAIController::execCanPayFor },
			{ "GetNextPawnToProduce", (Native)&ARTSPlayerAIController::execGetNextPawnToProduce },
			{ "GetPrimaryResourceDrain", (Native)&ARTSPlayerAIController::execGetPrimaryResourceDrain },
			{ "GetPrimaryResourceSource", (Native)&ARTSPlayerAIController::execGetPrimaryResourceSource },
			{ "MeetsAllRequirementsFor", (Native)&ARTSPlayerAIController::execMeetsAllRequirementsFor },
			{ "StartProduction", (Native)&ARTSPlayerAIController::execStartProduction },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ARTSPlayerAIController_CanPayFor()
	{
		struct RTSPlayerAIController_eventCanPayFor_Parms
		{
			TSubclassOf<APawn>  PawnClass;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSPlayerAIController_eventCanPayFor_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSPlayerAIController_eventCanPayFor_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_PawnClass = { UE4CodeGen_Private::EPropertyClass::Class, "PawnClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSPlayerAIController_eventCanPayFor_Parms, PawnClass), Z_Construct_UClass_APawn_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PawnClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "Checks the available resources for the AI and whether it can pay for a pawn of the specified class." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSPlayerAIController, "CanPayFor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSPlayerAIController_eventCanPayFor_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSPlayerAIController_GetNextPawnToProduce()
	{
		struct RTSPlayerAIController_eventGetNextPawnToProduce_Parms
		{
			TSubclassOf<APawn>  ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Class, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000580, 1, nullptr, STRUCT_OFFSET(RTSPlayerAIController_eventGetNextPawnToProduce_Parms, ReturnValue), Z_Construct_UClass_APawn_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "Checks the build order and returns the class of the next pawn to produce, or the Pawn class if nothing needs to be produced." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSPlayerAIController, "GetNextPawnToProduce", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSPlayerAIController_eventGetNextPawnToProduce_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSPlayerAIController_GetPrimaryResourceDrain()
	{
		struct RTSPlayerAIController_eventGetPrimaryResourceDrain_Parms
		{
			AActor* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSPlayerAIController_eventGetPrimaryResourceDrain_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "Gets the primary resource drain of the AI." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSPlayerAIController, "GetPrimaryResourceDrain", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020400, sizeof(RTSPlayerAIController_eventGetPrimaryResourceDrain_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSPlayerAIController_GetPrimaryResourceSource()
	{
		struct RTSPlayerAIController_eventGetPrimaryResourceSource_Parms
		{
			AActor* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSPlayerAIController_eventGetPrimaryResourceSource_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "Gets the closest resource source of the primary resource type around the first resource drain of the AI." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSPlayerAIController, "GetPrimaryResourceSource", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020400, sizeof(RTSPlayerAIController_eventGetPrimaryResourceSource_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSPlayerAIController_MeetsAllRequirementsFor()
	{
		struct RTSPlayerAIController_eventMeetsAllRequirementsFor_Parms
		{
			TSubclassOf<APawn>  PawnClass;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSPlayerAIController_eventMeetsAllRequirementsFor_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSPlayerAIController_eventMeetsAllRequirementsFor_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_PawnClass = { UE4CodeGen_Private::EPropertyClass::Class, "PawnClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSPlayerAIController_eventMeetsAllRequirementsFor_Parms, PawnClass), Z_Construct_UClass_APawn_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PawnClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "Checks whether the AI meets all tech tree requirements for a pawn of the specified class." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSPlayerAIController, "MeetsAllRequirementsFor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54020401, sizeof(RTSPlayerAIController_eventMeetsAllRequirementsFor_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSPlayerAIController_StartProduction()
	{
		struct RTSPlayerAIController_eventStartProduction_Parms
		{
			TSubclassOf<APawn>  PawnClass;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSPlayerAIController_eventStartProduction_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSPlayerAIController_eventStartProduction_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_PawnClass = { UE4CodeGen_Private::EPropertyClass::Class, "PawnClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSPlayerAIController_eventStartProduction_Parms, PawnClass), Z_Construct_UClass_APawn_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PawnClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "Selects an arbitrary production actor for producing a pawn of the specified class and starts production." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSPlayerAIController, "StartProduction", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSPlayerAIController_eventStartProduction_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARTSPlayerAIController_NoRegister()
	{
		return ARTSPlayerAIController::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSPlayerAIController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AAIController,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ARTSPlayerAIController_CanPayFor, "CanPayFor" }, // 3297470257
				{ &Z_Construct_UFunction_ARTSPlayerAIController_GetNextPawnToProduce, "GetNextPawnToProduce" }, // 1204477011
				{ &Z_Construct_UFunction_ARTSPlayerAIController_GetPrimaryResourceDrain, "GetPrimaryResourceDrain" }, // 1404155256
				{ &Z_Construct_UFunction_ARTSPlayerAIController_GetPrimaryResourceSource, "GetPrimaryResourceSource" }, // 1842622890
				{ &Z_Construct_UFunction_ARTSPlayerAIController_MeetsAllRequirementsFor, "MeetsAllRequirementsFor" }, // 550773801
				{ &Z_Construct_UFunction_ARTSPlayerAIController_StartProduction, "StartProduction" }, // 1459761821
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "RTSPlayerAIController.h" },
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "AI controller that drives strategic RTS player AI." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerResourcesComponent_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "RTSPlayerAIController" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "Stores the resources available for this player." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerResourcesComponent = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerResourcesComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(ARTSPlayerAIController, PlayerResourcesComponent), Z_Construct_UClass_URTSPlayerResourcesComponent_NoRegister, METADATA_PARAMS(NewProp_PlayerResourcesComponent_MetaData, ARRAY_COUNT(NewProp_PlayerResourcesComponent_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrimaryResourceType_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "Type of the primary resource for the AI to gather (e.g. used for placing resource drains)." },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_PrimaryResourceType = { UE4CodeGen_Private::EPropertyClass::Class, "PrimaryResourceType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000010015, 1, nullptr, STRUCT_OFFSET(ARTSPlayerAIController, PrimaryResourceType), Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_PrimaryResourceType_MetaData, ARRAY_COUNT(NewProp_PrimaryResourceType_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaximumBaseBuildingDistance_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "Maximum distance of a new building to an existing one, in cm." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaximumBaseBuildingDistance = { UE4CodeGen_Private::EPropertyClass::Float, "MaximumBaseBuildingDistance", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010015, 1, nullptr, STRUCT_OFFSET(ARTSPlayerAIController, MaximumBaseBuildingDistance), METADATA_PARAMS(NewProp_MaximumBaseBuildingDistance_MetaData, ARRAY_COUNT(NewProp_MaximumBaseBuildingDistance_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BuildOrder_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "Units and buildings the AI should produce, in order." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_BuildOrder = { UE4CodeGen_Private::EPropertyClass::Array, "BuildOrder", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000010015, 1, nullptr, STRUCT_OFFSET(ARTSPlayerAIController, BuildOrder), METADATA_PARAMS(NewProp_BuildOrder_MetaData, ARRAY_COUNT(NewProp_BuildOrder_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_BuildOrder_Inner = { UE4CodeGen_Private::EPropertyClass::Class, "BuildOrder", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000000, 1, nullptr, 0, Z_Construct_UClass_APawn_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerBlackboardAsset_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "Blackboard to use for holding all data relevant to the player AI." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerBlackboardAsset = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerBlackboardAsset", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010015, 1, nullptr, STRUCT_OFFSET(ARTSPlayerAIController, PlayerBlackboardAsset), Z_Construct_UClass_UBlackboardData_NoRegister, METADATA_PARAMS(NewProp_PlayerBlackboardAsset_MetaData, ARRAY_COUNT(NewProp_PlayerBlackboardAsset_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerBehaviorTreeAsset_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSPlayerAIController.h" },
				{ "ToolTip", "Behavior tree to use for driving the player AI." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerBehaviorTreeAsset = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerBehaviorTreeAsset", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010015, 1, nullptr, STRUCT_OFFSET(ARTSPlayerAIController, PlayerBehaviorTreeAsset), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(NewProp_PlayerBehaviorTreeAsset_MetaData, ARRAY_COUNT(NewProp_PlayerBehaviorTreeAsset_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PlayerResourcesComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PrimaryResourceType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaximumBaseBuildingDistance,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BuildOrder,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BuildOrder_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PlayerBlackboardAsset,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PlayerBehaviorTreeAsset,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSPlayerAIController>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSPlayerAIController::StaticClass,
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
	IMPLEMENT_CLASS(ARTSPlayerAIController, 1235460303);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSPlayerAIController(Z_Construct_UClass_ARTSPlayerAIController, &ARTSPlayerAIController::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSPlayerAIController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSPlayerAIController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
