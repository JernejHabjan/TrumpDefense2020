// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSGatherData.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSGatherData() {}
// Cross Module References
	RTSPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FRTSGatherData();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceType_NoRegister();
// End Cross Module References
class UScriptStruct* FRTSGatherData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RTSPLUGIN_API uint32 Get_Z_Construct_UScriptStruct_FRTSGatherData_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FRTSGatherData, Z_Construct_UPackage__Script_RTSPlugin(), TEXT("RTSGatherData"), sizeof(FRTSGatherData), Get_Z_Construct_UScriptStruct_FRTSGatherData_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FRTSGatherData(FRTSGatherData::StaticStruct, TEXT("/Script/RTSPlugin"), TEXT("RTSGatherData"), false, nullptr, nullptr);
static struct FScriptStruct_RTSPlugin_StaticRegisterNativesFRTSGatherData
{
	FScriptStruct_RTSPlugin_StaticRegisterNativesFRTSGatherData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("RTSGatherData")),new UScriptStruct::TCppStructOps<FRTSGatherData>);
	}
} ScriptStruct_RTSPlugin_StaticRegisterNativesFRTSGatherData;
	UScriptStruct* Z_Construct_UScriptStruct_FRTSGatherData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FRTSGatherData_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_RTSPlugin();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("RTSGatherData"), sizeof(FRTSGatherData), Get_Z_Construct_UScriptStruct_FRTSGatherData_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/RTSGatherData.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRTSGatherData>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Range_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGatherData.h" },
				{ "ToolTip", "Range in which resources can be gathered, in cm." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Range = { UE4CodeGen_Private::EPropertyClass::Float, "Range", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRTSGatherData, Range), METADATA_PARAMS(NewProp_Range_MetaData, ARRAY_COUNT(NewProp_Range_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bNeedsReturnToDrain_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGatherData.h" },
				{ "ToolTip", "Whether the actor needs to return to the drain in order to drop resources." },
			};
#endif
			auto NewProp_bNeedsReturnToDrain_SetBit = [](void* Obj){ ((FRTSGatherData*)Obj)->bNeedsReturnToDrain = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNeedsReturnToDrain = { UE4CodeGen_Private::EPropertyClass::Bool, "bNeedsReturnToDrain", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FRTSGatherData), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bNeedsReturnToDrain_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bNeedsReturnToDrain_MetaData, ARRAY_COUNT(NewProp_bNeedsReturnToDrain_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Cooldown_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGatherData.h" },
				{ "ToolTip", "Time between two gatherings, in seconds." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Cooldown = { UE4CodeGen_Private::EPropertyClass::Float, "Cooldown", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRTSGatherData, Cooldown), METADATA_PARAMS(NewProp_Cooldown_MetaData, ARRAY_COUNT(NewProp_Cooldown_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Capacity_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGatherData.h" },
				{ "ToolTip", "Maximum amount of resources that can be carried." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Capacity = { UE4CodeGen_Private::EPropertyClass::Float, "Capacity", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRTSGatherData, Capacity), METADATA_PARAMS(NewProp_Capacity_MetaData, ARRAY_COUNT(NewProp_Capacity_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AmountPerGathering_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGatherData.h" },
				{ "ToolTip", "Amount of resources gathered after each cooldown." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AmountPerGathering = { UE4CodeGen_Private::EPropertyClass::Float, "AmountPerGathering", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRTSGatherData, AmountPerGathering), METADATA_PARAMS(NewProp_AmountPerGathering_MetaData, ARRAY_COUNT(NewProp_AmountPerGathering_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResourceType_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGatherData.h" },
				{ "ToolTip", "Type of resources that can be gathered." },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ResourceType = { UE4CodeGen_Private::EPropertyClass::Class, "ResourceType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000005, 1, nullptr, STRUCT_OFFSET(FRTSGatherData, ResourceType), Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_ResourceType_MetaData, ARRAY_COUNT(NewProp_ResourceType_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Range,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bNeedsReturnToDrain,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Cooldown,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Capacity,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AmountPerGathering,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceType,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"RTSGatherData",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000201),
				sizeof(FRTSGatherData),
				alignof(FRTSGatherData),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FRTSGatherData_CRC() { return 1184908007U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
