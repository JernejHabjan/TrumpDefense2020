// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSCheatManager.h"
#include "Classes/GameFramework/PlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSCheatManager() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSCheatManager_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSCheatManager();
	ENGINE_API UClass* Z_Construct_UClass_UCheatManager();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSCheatManager_Boost();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSCheatManager_God();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSCheatManager_Money();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSCheatManager_Victory();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceType_NoRegister();
// End Cross Module References
	void URTSCheatManager::StaticRegisterNativesURTSCheatManager()
	{
		UClass* Class = URTSCheatManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Boost", (Native)&URTSCheatManager::execBoost },
			{ "God", (Native)&URTSCheatManager::execGod },
			{ "Money", (Native)&URTSCheatManager::execMoney },
			{ "Victory", (Native)&URTSCheatManager::execVictory },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URTSCheatManager_Boost()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Cheat Manager" },
				{ "ModuleRelativePath", "Classes/RTSCheatManager.h" },
				{ "ToolTip", "Increases construction and production speed." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSCheatManager, "Boost", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020600, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSCheatManager_God()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Cheat Manager" },
				{ "ModuleRelativePath", "Classes/RTSCheatManager.h" },
				{ "ToolTip", "Invulnerability cheat." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSCheatManager, "God", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020600, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSCheatManager_Money()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Cheat Manager" },
				{ "ModuleRelativePath", "Classes/RTSCheatManager.h" },
				{ "ToolTip", "Adds resources." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSCheatManager, "Money", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020600, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSCheatManager_Victory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Cheat Manager" },
				{ "ModuleRelativePath", "Classes/RTSCheatManager.h" },
				{ "ToolTip", "Defeat all other players." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSCheatManager, "Victory", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020600, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URTSCheatManager_NoRegister()
	{
		return URTSCheatManager::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSCheatManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UCheatManager,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URTSCheatManager_Boost, "Boost" }, // 328042832
				{ &Z_Construct_UFunction_URTSCheatManager_God, "God" }, // 3147217821
				{ &Z_Construct_UFunction_URTSCheatManager_Money, "Money" }, // 1244632998
				{ &Z_Construct_UFunction_URTSCheatManager_Victory, "Victory" }, // 3875386799
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "IncludePath", "RTSCheatManager.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Classes/RTSCheatManager.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpeedBoostFactor_MetaData[] = {
				{ "Category", "Cheat Manager" },
				{ "ModuleRelativePath", "Classes/RTSCheatManager.h" },
				{ "ToolTip", "Factor to multiply all construction and production speed with." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SpeedBoostFactor = { UE4CodeGen_Private::EPropertyClass::Float, "SpeedBoostFactor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSCheatManager, SpeedBoostFactor), METADATA_PARAMS(NewProp_SpeedBoostFactor_MetaData, ARRAY_COUNT(NewProp_SpeedBoostFactor_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResourceTypes_MetaData[] = {
				{ "Category", "Cheat Manager" },
				{ "ModuleRelativePath", "Classes/RTSCheatManager.h" },
				{ "ToolTip", "Types of resources to grant with the Money cheat." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ResourceTypes = { UE4CodeGen_Private::EPropertyClass::Array, "ResourceTypes", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000005, 1, nullptr, STRUCT_OFFSET(URTSCheatManager, ResourceTypes), METADATA_PARAMS(NewProp_ResourceTypes_MetaData, ARRAY_COUNT(NewProp_ResourceTypes_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ResourceTypes_Inner = { UE4CodeGen_Private::EPropertyClass::Class, "ResourceTypes", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000000, 1, nullptr, 0, Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResourceAmount_MetaData[] = {
				{ "Category", "Cheat Manager" },
				{ "ModuleRelativePath", "Classes/RTSCheatManager.h" },
				{ "ToolTip", "Amount of resources to grant with the Money cheat." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ResourceAmount = { UE4CodeGen_Private::EPropertyClass::Float, "ResourceAmount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSCheatManager, ResourceAmount), METADATA_PARAMS(NewProp_ResourceAmount_MetaData, ARRAY_COUNT(NewProp_ResourceAmount_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SpeedBoostFactor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceTypes,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceTypes_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceAmount,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSCheatManager>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSCheatManager::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100080u,
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
	IMPLEMENT_CLASS(URTSCheatManager, 2394366914);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSCheatManager(Z_Construct_UClass_URTSCheatManager, &URTSCheatManager::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSCheatManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSCheatManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
