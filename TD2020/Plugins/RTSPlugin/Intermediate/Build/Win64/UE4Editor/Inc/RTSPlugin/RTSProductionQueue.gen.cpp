// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSProductionQueue.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSProductionQueue() {}
// Cross Module References
	RTSPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FRTSProductionQueue();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
class UScriptStruct* FRTSProductionQueue::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RTSPLUGIN_API uint32 Get_Z_Construct_UScriptStruct_FRTSProductionQueue_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FRTSProductionQueue, Z_Construct_UPackage__Script_RTSPlugin(), TEXT("RTSProductionQueue"), sizeof(FRTSProductionQueue), Get_Z_Construct_UScriptStruct_FRTSProductionQueue_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FRTSProductionQueue(FRTSProductionQueue::StaticStruct, TEXT("/Script/RTSPlugin"), TEXT("RTSProductionQueue"), false, nullptr, nullptr);
static struct FScriptStruct_RTSPlugin_StaticRegisterNativesFRTSProductionQueue
{
	FScriptStruct_RTSPlugin_StaticRegisterNativesFRTSProductionQueue()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("RTSProductionQueue")),new UScriptStruct::TCppStructOps<FRTSProductionQueue>);
	}
} ScriptStruct_RTSPlugin_StaticRegisterNativesFRTSProductionQueue;
	UScriptStruct* Z_Construct_UScriptStruct_FRTSProductionQueue()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FRTSProductionQueue_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_RTSPlugin();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("RTSProductionQueue"), sizeof(FRTSProductionQueue), Get_Z_Construct_UScriptStruct_FRTSProductionQueue_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/RTSProductionQueue.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRTSProductionQueue>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RemainingProductionTime_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionQueue.h" },
				{ "ToolTip", "Time before the current actor in the queue is produced, in seconds." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RemainingProductionTime = { UE4CodeGen_Private::EPropertyClass::Float, "RemainingProductionTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRTSProductionQueue, RemainingProductionTime), METADATA_PARAMS(NewProp_RemainingProductionTime_MetaData, ARRAY_COUNT(NewProp_RemainingProductionTime_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Queue_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSProductionQueue.h" },
				{ "ToolTip", "Products queued for production." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Queue = { UE4CodeGen_Private::EPropertyClass::Array, "Queue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000005, 1, nullptr, STRUCT_OFFSET(FRTSProductionQueue, Queue), METADATA_PARAMS(NewProp_Queue_MetaData, ARRAY_COUNT(NewProp_Queue_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_Queue_Inner = { UE4CodeGen_Private::EPropertyClass::Class, "Queue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000000, 1, nullptr, 0, Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RemainingProductionTime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Queue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Queue_Inner,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"RTSProductionQueue",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000201),
				sizeof(FRTSProductionQueue),
				alignof(FRTSProductionQueue),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FRTSProductionQueue_CRC() { return 1871187722U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
