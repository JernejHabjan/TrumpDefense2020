// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSGameState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSGameState() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSGameState_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSGameState();
	ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSTeamInfo_NoRegister();
// End Cross Module References
	void ARTSGameState::StaticRegisterNativesARTSGameState()
	{
	}
	UClass* Z_Construct_UClass_ARTSGameState_NoRegister()
	{
		return ARTSGameState::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSGameState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameStateBase,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "RTSGameState.h" },
				{ "ModuleRelativePath", "Classes/RTSGameState.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
				{ "ToolTip", "Game state with RTS features, such as teams." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Teams_MetaData[] = {
				{ "Category", "Team" },
				{ "ModuleRelativePath", "Classes/RTSGameState.h" },
				{ "ToolTip", "Teams of the current match." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Teams = { UE4CodeGen_Private::EPropertyClass::Array, "Teams", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ARTSGameState, Teams), METADATA_PARAMS(NewProp_Teams_MetaData, ARRAY_COUNT(NewProp_Teams_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Teams_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Teams", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_ARTSTeamInfo_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Teams,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Teams_Inner,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSGameState>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSGameState::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900280u,
				nullptr, 0,
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
	IMPLEMENT_CLASS(ARTSGameState, 275028793);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSGameState(Z_Construct_UClass_ARTSGameState, &ARTSGameState::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSGameState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSGameState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
