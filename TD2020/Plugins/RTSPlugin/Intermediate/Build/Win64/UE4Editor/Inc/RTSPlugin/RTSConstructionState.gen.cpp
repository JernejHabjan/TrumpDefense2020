// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSConstructionState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSConstructionState() {}
// Cross Module References
	RTSPLUGIN_API UEnum* Z_Construct_UEnum_RTSPlugin_ERTSConstructionState();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
// End Cross Module References
	static UEnum* ERTSConstructionState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_RTSPlugin_ERTSConstructionState, Z_Construct_UPackage__Script_RTSPlugin(), TEXT("ERTSConstructionState"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERTSConstructionState(ERTSConstructionState_StaticEnum, TEXT("/Script/RTSPlugin"), TEXT("ERTSConstructionState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_RTSPlugin_ERTSConstructionState_CRC() { return 2872914770U; }
	UEnum* Z_Construct_UEnum_RTSPlugin_ERTSConstructionState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_RTSPlugin();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERTSConstructionState"), 0, Get_Z_Construct_UEnum_RTSPlugin_ERTSConstructionState_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERTSConstructionState::CONSTRUCTIONSTATE_NotStarted", (int64)ERTSConstructionState::CONSTRUCTIONSTATE_NotStarted },
				{ "ERTSConstructionState::CONSTRUCTIONSTATE_Constructing", (int64)ERTSConstructionState::CONSTRUCTIONSTATE_Constructing },
				{ "ERTSConstructionState::CONSTRUCTIONSTATE_Paused", (int64)ERTSConstructionState::CONSTRUCTIONSTATE_Paused },
				{ "ERTSConstructionState::CONSTRUCTIONSTATE_Finished", (int64)ERTSConstructionState::CONSTRUCTIONSTATE_Finished },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "CONSTRUCTIONSTATE_Constructing.ToolTip", "Building is being constructed right now." },
				{ "CONSTRUCTIONSTATE_Finished.ToolTip", "Construction has finished." },
				{ "CONSTRUCTIONSTATE_NotStarted.ToolTip", "Construction has not yet started." },
				{ "CONSTRUCTIONSTATE_Paused.ToolTip", "Construction timer is paused." },
				{ "ModuleRelativePath", "Classes/RTSConstructionState.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ERTSConstructionState",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ERTSConstructionState",
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
