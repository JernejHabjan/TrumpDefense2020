// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSVisionState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSVisionState() {}
// Cross Module References
	RTSPLUGIN_API UEnum* Z_Construct_UEnum_RTSPlugin_ERTSVisionState();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
// End Cross Module References
	static UEnum* ERTSVisionState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_RTSPlugin_ERTSVisionState, Z_Construct_UPackage__Script_RTSPlugin(), TEXT("ERTSVisionState"));
		}
		return Singleton;
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERTSVisionState(ERTSVisionState_StaticEnum, TEXT("/Script/RTSPlugin"), TEXT("ERTSVisionState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_RTSPlugin_ERTSVisionState_CRC() { return 3782614224U; }
	UEnum* Z_Construct_UEnum_RTSPlugin_ERTSVisionState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_RTSPlugin();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERTSVisionState"), 0, Get_Z_Construct_UEnum_RTSPlugin_ERTSVisionState_CRC(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERTSVisionState::VISION_Unknown", (int64)ERTSVisionState::VISION_Unknown },
				{ "ERTSVisionState::VISION_Known", (int64)ERTSVisionState::VISION_Known },
				{ "ERTSVisionState::VISION_Visible", (int64)ERTSVisionState::VISION_Visible },
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/RTSVisionState.h" },
				{ "VISION_Known.ToolTip", "Area has been visited before, but is currently not." },
				{ "VISION_Unknown.ToolTip", "Area has never been visited before." },
				{ "VISION_Visible.ToolTip", "Area is revealed right now." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				"ERTSVisionState",
				RF_Public|RF_Transient|RF_MarkAsNative,
				nullptr,
				(uint8)UEnum::ECppForm::EnumClass,
				"ERTSVisionState",
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
