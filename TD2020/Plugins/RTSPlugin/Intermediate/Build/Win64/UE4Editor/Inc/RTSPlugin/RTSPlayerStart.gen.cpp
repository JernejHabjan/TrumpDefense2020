// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSPlayerStart.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSPlayerStart() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSPlayerStart_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSPlayerStart();
	ENGINE_API UClass* Z_Construct_UClass_APlayerStart();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
// End Cross Module References
	void ARTSPlayerStart::StaticRegisterNativesARTSPlayerStart()
	{
	}
	UClass* Z_Construct_UClass_ARTSPlayerStart_NoRegister()
	{
		return ARTSPlayerStart::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSPlayerStart()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_APlayerStart,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Collision Lighting LightColor Force" },
				{ "IncludePath", "RTSPlayerStart.h" },
				{ "ModuleRelativePath", "Classes/RTSPlayerStart.h" },
				{ "ToolTip", "Player start with RTS features, such as which player has been spawned at this start." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TeamIndex_MetaData[] = {
				{ "Category", "Team" },
				{ "ModuleRelativePath", "Classes/RTSPlayerStart.h" },
				{ "ToolTip", "Team to add the spawned player to." },
			};
#endif
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_TeamIndex = { UE4CodeGen_Private::EPropertyClass::Int, "TeamIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ARTSPlayerStart, TeamIndex), METADATA_PARAMS(NewProp_TeamIndex_MetaData, ARRAY_COUNT(NewProp_TeamIndex_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TeamIndex,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSPlayerStart>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSPlayerStart::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
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
	IMPLEMENT_CLASS(ARTSPlayerStart, 1708011273);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSPlayerStart(Z_Construct_UClass_ARTSPlayerStart, &ARTSPlayerStart::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSPlayerStart"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSPlayerStart);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
