// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSProductionCostType.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSProductionCostType() {}
// Cross Module References
	RTSPLUGIN_API UEnum* Z_Construct_UEnum_RTSPlugin_ERTSProductionCostType();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
// End Cross Module References
	static UEnum* ERTSProductionCostType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_RTSPlugin_ERTSProductionCostType, Z_Construct_UPackage__Script_RTSPlugin(), TEXT("ERTSProductionCostType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERTSProductionCostType(ERTSProductionCostType_StaticEnum, TEXT("/Script/RTSPlugin"), TEXT("ERTSProductionCostType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_RTSPlugin_ERTSProductionCostType_CRC() { return 1088327932U; }
	UEnum* Z_Construct_UEnum_RTSPlugin_ERTSProductionCostType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_RTSPlugin();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERTSProductionCostType"), 0, Get_Z_Construct_UEnum_RTSPlugin_ERTSProductionCostType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERTSProductionCostType::COST_PayImmediately", (int64)ERTSProductionCostType::COST_PayImmediately },
				{ "ERTSProductionCostType::COST_PayOverTime", (int64)ERTSProductionCostType::COST_PayOverTime },
				{ "ERTSProductionCostType::COST_PayCustom", (int64)ERTSProductionCostType::COST_PayCustom },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "COST_PayCustom.ToolTip", "Don't pay production costs automatically." },
				{ "COST_PayImmediately.ToolTip", "Pay whole production cost as soon as production starts." },
				{ "COST_PayOverTime.ToolTip", "Pay production costs every tick while production proceeds." },
				{ "ModuleRelativePath", "Classes/RTSProductionCostType.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ERTSProductionCostType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ERTSProductionCostType",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
