// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSOrderType.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSOrderType() {}
// Cross Module References
	RTSPLUGIN_API UEnum* Z_Construct_UEnum_RTSPlugin_ERTSOrderType();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
// End Cross Module References
	static UEnum* ERTSOrderType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_RTSPlugin_ERTSOrderType, Z_Construct_UPackage__Script_RTSPlugin(), TEXT("ERTSOrderType"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERTSOrderType(ERTSOrderType_StaticEnum, TEXT("/Script/RTSPlugin"), TEXT("ERTSOrderType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_RTSPlugin_ERTSOrderType_CRC() { return 2767666106U; }
	UEnum* Z_Construct_UEnum_RTSPlugin_ERTSOrderType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_RTSPlugin();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERTSOrderType"), 0, Get_Z_Construct_UEnum_RTSPlugin_ERTSOrderType_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERTSOrderType::ORDER_None", (int64)ERTSOrderType::ORDER_None },
				{ "ERTSOrderType::ORDER_Move", (int64)ERTSOrderType::ORDER_Move },
				{ "ERTSOrderType::ORDER_Attack", (int64)ERTSOrderType::ORDER_Attack },
				{ "ERTSOrderType::ORDER_BeginConstruction", (int64)ERTSOrderType::ORDER_BeginConstruction },
				{ "ERTSOrderType::ORDER_ContinueConstruction", (int64)ERTSOrderType::ORDER_ContinueConstruction },
				{ "ERTSOrderType::ORDER_Gather", (int64)ERTSOrderType::ORDER_Gather },
				{ "ERTSOrderType::ORDER_ReturnResources", (int64)ERTSOrderType::ORDER_ReturnResources },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/RTSOrderType.h" },
				{ "ORDER_Attack.ToolTip", "Attack another actor." },
				{ "ORDER_BeginConstruction.ToolTip", "Create a new construction site." },
				{ "ORDER_ContinueConstruction.ToolTip", "Finish a building construction." },
				{ "ORDER_Gather.ToolTip", "Gather resources." },
				{ "ORDER_Move.ToolTip", "Move to a destination in the world." },
				{ "ORDER_None.ToolTip", "Idle." },
				{ "ORDER_ReturnResources.ToolTip", "Return carried resources." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ERTSOrderType",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ERTSOrderType",
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
