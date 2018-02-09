// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSVisionInfo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSVisionInfo() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSVisionInfo_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSVisionInfo();
	ENGINE_API UClass* Z_Construct_UClass_AInfo();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSVisionInfo_GetVisionInfoForTeam();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSVisionInfo_ReceivedTeamIndex();
// End Cross Module References
	void ARTSVisionInfo::StaticRegisterNativesARTSVisionInfo()
	{
		UClass* Class = ARTSVisionInfo::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetVisionInfoForTeam", (Native)&ARTSVisionInfo::execGetVisionInfoForTeam },
			{ "ReceivedTeamIndex", (Native)&ARTSVisionInfo::execReceivedTeamIndex },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ARTSVisionInfo_GetVisionInfoForTeam()
	{
		struct RTSVisionInfo_eventGetVisionInfoForTeam_Parms
		{
			UObject* WorldContextObject;
			uint8 InTeamIndex;
			ARTSVisionInfo* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSVisionInfo_eventGetVisionInfoForTeam_Parms, ReturnValue), Z_Construct_UClass_ARTSVisionInfo_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_InTeamIndex = { UE4CodeGen_Private::EPropertyClass::Byte, "InTeamIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSVisionInfo_eventGetVisionInfoForTeam_Parms, InTeamIndex), nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSVisionInfo_eventGetVisionInfoForTeam_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InTeamIndex,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WorldContextObject,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSVisionInfo.h" },
				{ "ToolTip", "Gets vision information for the specified team." },
				{ "WorldContext", "WorldContextObject" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSVisionInfo, "GetVisionInfoForTeam", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(RTSVisionInfo_eventGetVisionInfoForTeam_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSVisionInfo_ReceivedTeamIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSVisionInfo.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSVisionInfo, "ReceivedTeamIndex", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARTSVisionInfo_NoRegister()
	{
		return ARTSVisionInfo::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSVisionInfo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AInfo,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ARTSVisionInfo_GetVisionInfoForTeam, "GetVisionInfoForTeam" }, // 2331152030
				{ &Z_Construct_UFunction_ARTSVisionInfo_ReceivedTeamIndex, "ReceivedTeamIndex" }, // 810913100
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "RTSVisionInfo.h" },
				{ "ModuleRelativePath", "Classes/RTSVisionInfo.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
				{ "ToolTip", "Defines the visible areas for a player or team." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TeamIndex_MetaData[] = {
				{ "Category", "Team" },
				{ "ModuleRelativePath", "Classes/RTSVisionInfo.h" },
				{ "ToolTip", "Index of the team this actor keeps track of the vision for." },
			};
#endif
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_TeamIndex = { UE4CodeGen_Private::EPropertyClass::Byte, "TeamIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000100000034, 1, "ReceivedTeamIndex", STRUCT_OFFSET(ARTSVisionInfo, TeamIndex), nullptr, METADATA_PARAMS(NewProp_TeamIndex_MetaData, ARRAY_COUNT(NewProp_TeamIndex_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TeamIndex,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSVisionInfo>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSVisionInfo::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
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
	IMPLEMENT_CLASS(ARTSVisionInfo, 2521991510);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSVisionInfo(Z_Construct_UClass_ARTSVisionInfo, &ARTSVisionInfo::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSVisionInfo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSVisionInfo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
