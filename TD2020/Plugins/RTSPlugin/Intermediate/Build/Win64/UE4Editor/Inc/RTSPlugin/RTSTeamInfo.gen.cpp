// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSTeamInfo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSTeamInfo() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSTeamInfo_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSTeamInfo();
	ENGINE_API UClass* Z_Construct_UClass_AInfo();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSTeamInfo_AddToTeam();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSTeamInfo_GetTeamMembers();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSTeamInfo_ReceivedTeamIndex();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSTeamInfo_RemoveFromTeam();
// End Cross Module References
	void ARTSTeamInfo::StaticRegisterNativesARTSTeamInfo()
	{
		UClass* Class = ARTSTeamInfo::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddToTeam", (Native)&ARTSTeamInfo::execAddToTeam },
			{ "GetTeamMembers", (Native)&ARTSTeamInfo::execGetTeamMembers },
			{ "ReceivedTeamIndex", (Native)&ARTSTeamInfo::execReceivedTeamIndex },
			{ "RemoveFromTeam", (Native)&ARTSTeamInfo::execRemoveFromTeam },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ARTSTeamInfo_AddToTeam()
	{
		struct RTSTeamInfo_eventAddToTeam_Parms
		{
			AController* Player;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Player = { UE4CodeGen_Private::EPropertyClass::Object, "Player", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSTeamInfo_eventAddToTeam_Parms, Player), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Player,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Team" },
				{ "ModuleRelativePath", "Classes/RTSTeamInfo.h" },
				{ "ToolTip", "Adds the specified player to this team." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSTeamInfo, "AddToTeam", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, sizeof(RTSTeamInfo_eventAddToTeam_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSTeamInfo_GetTeamMembers()
	{
		struct RTSTeamInfo_eventGetTeamMembers_Parms
		{
			TArray<AController*> ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSTeamInfo_eventGetTeamMembers_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSTeamInfo.h" },
				{ "ToolTip", "Gets all players belonging to this  team." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSTeamInfo, "GetTeamMembers", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020401, sizeof(RTSTeamInfo_eventGetTeamMembers_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSTeamInfo_ReceivedTeamIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSTeamInfo.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSTeamInfo, "ReceivedTeamIndex", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00080400, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSTeamInfo_RemoveFromTeam()
	{
		struct RTSTeamInfo_eventRemoveFromTeam_Parms
		{
			AController* Player;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Player = { UE4CodeGen_Private::EPropertyClass::Object, "Player", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSTeamInfo_eventRemoveFromTeam_Parms, Player), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Player,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Team" },
				{ "ModuleRelativePath", "Classes/RTSTeamInfo.h" },
				{ "ToolTip", "Removes the specified player from this team." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSTeamInfo, "RemoveFromTeam", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, sizeof(RTSTeamInfo_eventRemoveFromTeam_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARTSTeamInfo_NoRegister()
	{
		return ARTSTeamInfo::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSTeamInfo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AInfo,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ARTSTeamInfo_AddToTeam, "AddToTeam" }, // 1152314013
				{ &Z_Construct_UFunction_ARTSTeamInfo_GetTeamMembers, "GetTeamMembers" }, // 2298347527
				{ &Z_Construct_UFunction_ARTSTeamInfo_ReceivedTeamIndex, "ReceivedTeamIndex" }, // 2819476124
				{ &Z_Construct_UFunction_ARTSTeamInfo_RemoveFromTeam, "RemoveFromTeam" }, // 3508205628
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "RTSTeamInfo.h" },
				{ "ModuleRelativePath", "Classes/RTSTeamInfo.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
				{ "ToolTip", "Team that consists of multiple players." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TeamIndex_MetaData[] = {
				{ "Category", "Team" },
				{ "ModuleRelativePath", "Classes/RTSTeamInfo.h" },
				{ "ToolTip", "Index of this team." },
			};
#endif
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_TeamIndex = { UE4CodeGen_Private::EPropertyClass::Byte, "TeamIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000100000034, 1, "ReceivedTeamIndex", STRUCT_OFFSET(ARTSTeamInfo, TeamIndex), nullptr, METADATA_PARAMS(NewProp_TeamIndex_MetaData, ARRAY_COUNT(NewProp_TeamIndex_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TeamIndex,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSTeamInfo>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSTeamInfo::StaticClass,
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
	IMPLEMENT_CLASS(ARTSTeamInfo, 268003336);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSTeamInfo(Z_Construct_UClass_ARTSTeamInfo, &ARTSTeamInfo::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSTeamInfo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSTeamInfo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
