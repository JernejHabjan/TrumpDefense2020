// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSPlayerState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSPlayerState() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSPlayerState_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSPlayerState();
	ENGINE_API UClass* Z_Construct_UClass_APlayerState();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSPlayerState_IsSameTeamAs();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSPlayerState_OnTeamChanged();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSPlayerState_ReceiveOnTeamChanged();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSTeamInfo_NoRegister();
// End Cross Module References
	static FName NAME_ARTSPlayerState_ReceiveOnTeamChanged = FName(TEXT("ReceiveOnTeamChanged"));
	void ARTSPlayerState::ReceiveOnTeamChanged(ARTSTeamInfo* NewTeam)
	{
		RTSPlayerState_eventReceiveOnTeamChanged_Parms Parms;
		Parms.NewTeam=NewTeam;
		ProcessEvent(FindFunctionChecked(NAME_ARTSPlayerState_ReceiveOnTeamChanged),&Parms);
	}
	void ARTSPlayerState::StaticRegisterNativesARTSPlayerState()
	{
		UClass* Class = ARTSPlayerState::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "IsSameTeamAs", (Native)&ARTSPlayerState::execIsSameTeamAs },
			{ "OnTeamChanged", (Native)&ARTSPlayerState::execOnTeamChanged },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ARTSPlayerState_IsSameTeamAs()
	{
		struct RTSPlayerState_eventIsSameTeamAs_Parms
		{
			ARTSPlayerState* Other;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSPlayerState_eventIsSameTeamAs_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSPlayerState_eventIsSameTeamAs_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Other = { UE4CodeGen_Private::EPropertyClass::Object, "Other", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSPlayerState_eventIsSameTeamAs_Parms, Other), Z_Construct_UClass_ARTSPlayerState_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Other,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSPlayerState.h" },
				{ "ToolTip", "Checks whether this player belong to the same team as the specified one." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSPlayerState, "IsSameTeamAs", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSPlayerState_eventIsSameTeamAs_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSPlayerState_OnTeamChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSPlayerState.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSPlayerState, "OnTeamChanged", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSPlayerState_ReceiveOnTeamChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NewTeam = { UE4CodeGen_Private::EPropertyClass::Object, "NewTeam", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSPlayerState_eventReceiveOnTeamChanged_Parms, NewTeam), Z_Construct_UClass_ARTSTeamInfo_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewTeam,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS|Team" },
				{ "DisplayName", "OnTeamChanged" },
				{ "ModuleRelativePath", "Classes/RTSPlayerState.h" },
				{ "ToolTip", "Event when this player changed team." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSPlayerState, "ReceiveOnTeamChanged", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(RTSPlayerState_eventReceiveOnTeamChanged_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARTSPlayerState_NoRegister()
	{
		return ARTSPlayerState::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSPlayerState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_APlayerState,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ARTSPlayerState_IsSameTeamAs, "IsSameTeamAs" }, // 2225152509
				{ &Z_Construct_UFunction_ARTSPlayerState_OnTeamChanged, "OnTeamChanged" }, // 1419720500
				{ &Z_Construct_UFunction_ARTSPlayerState_ReceiveOnTeamChanged, "ReceiveOnTeamChanged" }, // 3125836019
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "RTSPlayerState.h" },
				{ "ModuleRelativePath", "Classes/RTSPlayerState.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
				{ "ToolTip", "Player state with RTS features, such as teams." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Team_MetaData[] = {
				{ "Category", "Team" },
				{ "ModuleRelativePath", "Classes/RTSPlayerState.h" },
				{ "ToolTip", "Team this player belongs to." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Team = { UE4CodeGen_Private::EPropertyClass::Object, "Team", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000100000034, 1, "OnTeamChanged", STRUCT_OFFSET(ARTSPlayerState, Team), Z_Construct_UClass_ARTSTeamInfo_NoRegister, METADATA_PARAMS(NewProp_Team_MetaData, ARRAY_COUNT(NewProp_Team_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Team,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSPlayerState>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSPlayerState::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900280u,
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
	IMPLEMENT_CLASS(ARTSPlayerState, 2393623300);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSPlayerState(Z_Construct_UClass_ARTSPlayerState, &ARTSPlayerState::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSPlayerState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSPlayerState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
