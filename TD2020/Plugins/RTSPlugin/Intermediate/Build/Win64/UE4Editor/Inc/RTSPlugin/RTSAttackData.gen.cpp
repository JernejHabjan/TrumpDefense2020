// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSAttackData.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSAttackData() {}
// Cross Module References
	RTSPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FRTSAttackData();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSProjectile_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
// End Cross Module References
class UScriptStruct* FRTSAttackData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern RTSPLUGIN_API uint32 Get_Z_Construct_UScriptStruct_FRTSAttackData_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FRTSAttackData, Z_Construct_UPackage__Script_RTSPlugin(), TEXT("RTSAttackData"), sizeof(FRTSAttackData), Get_Z_Construct_UScriptStruct_FRTSAttackData_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FRTSAttackData(FRTSAttackData::StaticStruct, TEXT("/Script/RTSPlugin"), TEXT("RTSAttackData"), false, nullptr, nullptr);
static struct FScriptStruct_RTSPlugin_StaticRegisterNativesFRTSAttackData
{
	FScriptStruct_RTSPlugin_StaticRegisterNativesFRTSAttackData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("RTSAttackData")),new UScriptStruct::TCppStructOps<FRTSAttackData>);
	}
} ScriptStruct_RTSPlugin_StaticRegisterNativesFRTSAttackData;
	UScriptStruct* Z_Construct_UScriptStruct_FRTSAttackData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FRTSAttackData_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_RTSPlugin();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("RTSAttackData"), sizeof(FRTSAttackData), Get_Z_Construct_UScriptStruct_FRTSAttackData_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/RTSAttackData.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRTSAttackData>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSAttackData.h" },
				{ "ToolTip", "Type of the projectile to spawn. If not set, damage will be dealt instantly." },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProjectileClass = { UE4CodeGen_Private::EPropertyClass::Class, "ProjectileClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000005, 1, nullptr, STRUCT_OFFSET(FRTSAttackData, ProjectileClass), Z_Construct_UClass_ARTSProjectile_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_ProjectileClass_MetaData, ARRAY_COUNT(NewProp_ProjectileClass_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Range_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSAttackData.h" },
				{ "ToolTip", "Range of this attack, in cm." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Range = { UE4CodeGen_Private::EPropertyClass::Float, "Range", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRTSAttackData, Range), METADATA_PARAMS(NewProp_Range_MetaData, ARRAY_COUNT(NewProp_Range_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageType_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSAttackData.h" },
				{ "ToolTip", "Type of the damage caused by this attack." },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_DamageType = { UE4CodeGen_Private::EPropertyClass::Class, "DamageType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000005, 1, nullptr, STRUCT_OFFSET(FRTSAttackData, DamageType), Z_Construct_UClass_UDamageType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_DamageType_MetaData, ARRAY_COUNT(NewProp_DamageType_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSAttackData.h" },
				{ "ToolTip", "Damage dealt by this attack. Negative values could mean healing, depending on the game." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Damage = { UE4CodeGen_Private::EPropertyClass::Float, "Damage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRTSAttackData, Damage), METADATA_PARAMS(NewProp_Damage_MetaData, ARRAY_COUNT(NewProp_Damage_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Cooldown_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSAttackData.h" },
				{ "ToolTip", "Time before this attack can be used again, in seconds." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Cooldown = { UE4CodeGen_Private::EPropertyClass::Float, "Cooldown", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FRTSAttackData, Cooldown), METADATA_PARAMS(NewProp_Cooldown_MetaData, ARRAY_COUNT(NewProp_Cooldown_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileClass,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Range,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DamageType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Damage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Cooldown,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"RTSAttackData",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000201),
				sizeof(FRTSAttackData),
				alignof(FRTSAttackData),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FRTSAttackData_CRC() { return 4227075392U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
