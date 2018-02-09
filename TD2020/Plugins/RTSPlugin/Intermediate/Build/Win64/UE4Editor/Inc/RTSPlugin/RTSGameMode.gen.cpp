// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSGameMode() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSGameMode_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSGameMode_ReceiveOnPlayerDefeated();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSGameMode_TransferOwnership();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSPlayerAIController_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSTeamInfo_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	static FName NAME_ARTSGameMode_ReceiveOnPlayerDefeated = FName(TEXT("ReceiveOnPlayerDefeated"));
	void ARTSGameMode::ReceiveOnPlayerDefeated(AController* Player)
	{
		RTSGameMode_eventReceiveOnPlayerDefeated_Parms Parms;
		Parms.Player=Player;
		ProcessEvent(FindFunctionChecked(NAME_ARTSGameMode_ReceiveOnPlayerDefeated),&Parms);
	}
	void ARTSGameMode::StaticRegisterNativesARTSGameMode()
	{
		UClass* Class = ARTSGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "TransferOwnership", (Native)&ARTSGameMode::execTransferOwnership },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ARTSGameMode_ReceiveOnPlayerDefeated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Player = { UE4CodeGen_Private::EPropertyClass::Object, "Player", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSGameMode_eventReceiveOnPlayerDefeated_Parms, Player), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Player,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "DisplayName", "OnPlayerDefeated" },
				{ "ModuleRelativePath", "Classes/RTSGameMode.h" },
				{ "ToolTip", "Event when a player has been defeated." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSGameMode, "ReceiveOnPlayerDefeated", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(RTSGameMode_eventReceiveOnPlayerDefeated_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSGameMode_TransferOwnership()
	{
		struct RTSGameMode_eventTransferOwnership_Parms
		{
			AActor* Actor;
			AController* NewOwner;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NewOwner = { UE4CodeGen_Private::EPropertyClass::Object, "NewOwner", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSGameMode_eventTransferOwnership_Parms, NewOwner), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSGameMode_eventTransferOwnership_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewOwner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Actor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSGameMode.h" },
				{ "ToolTip", "Sets the specified player as the owner of the passed actor." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSGameMode, "TransferOwnership", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSGameMode_eventTransferOwnership_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARTSGameMode_NoRegister()
	{
		return ARTSGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ARTSGameMode_ReceiveOnPlayerDefeated, "ReceiveOnPlayerDefeated" }, // 1640585812
				{ &Z_Construct_UFunction_ARTSGameMode_TransferOwnership, "TransferOwnership" }, // 1896285125
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "RTSGameMode.h" },
				{ "ModuleRelativePath", "Classes/RTSGameMode.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
				{ "ToolTip", "Game mode with RTS features, such as spawning initial units for each player." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerAIControllerClass_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Classes/RTSGameMode.h" },
				{ "ToolTip", "AIController class to spawn for AI players." },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_PlayerAIControllerClass = { UE4CodeGen_Private::EPropertyClass::Class, "PlayerAIControllerClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000010001, 1, nullptr, STRUCT_OFFSET(ARTSGameMode, PlayerAIControllerClass), Z_Construct_UClass_ARTSPlayerAIController_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_PlayerAIControllerClass_MetaData, ARRAY_COUNT(NewProp_PlayerAIControllerClass_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TeamClass_MetaData[] = {
				{ "Category", "Team" },
				{ "ModuleRelativePath", "Classes/RTSGameMode.h" },
				{ "ToolTip", "Class of TeamInfo to spawn." },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_TeamClass = { UE4CodeGen_Private::EPropertyClass::Class, "TeamClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000010001, 1, nullptr, STRUCT_OFFSET(ARTSGameMode, TeamClass), Z_Construct_UClass_ARTSTeamInfo_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_TeamClass_MetaData, ARRAY_COUNT(NewProp_TeamClass_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Teams_MetaData[] = {
				{ "Category", "Team" },
				{ "ModuleRelativePath", "Classes/RTSGameMode.h" },
				{ "ToolTip", "Teams of the current match." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Teams = { UE4CodeGen_Private::EPropertyClass::Array, "Teams", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ARTSGameMode, Teams), METADATA_PARAMS(NewProp_Teams_MetaData, ARRAY_COUNT(NewProp_Teams_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Teams_Inner = { UE4CodeGen_Private::EPropertyClass::Object, "Teams", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UClass_ARTSTeamInfo_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NumTeams_MetaData[] = {
				{ "Category", "Team" },
				{ "ModuleRelativePath", "Classes/RTSGameMode.h" },
				{ "ToolTip", "Number of teams to create." },
			};
#endif
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_NumTeams = { UE4CodeGen_Private::EPropertyClass::Byte, "NumTeams", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010001, 1, nullptr, STRUCT_OFFSET(ARTSGameMode, NumTeams), nullptr, METADATA_PARAMS(NewProp_NumTeams_MetaData, ARRAY_COUNT(NewProp_NumTeams_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefeatConditionActor_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGameMode.h" },
				{ "ToolTip", "Optional type of actor that is required for a player to be alive. As soon as no actor of the specified type is alive, the player is defeated." },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_DefeatConditionActor = { UE4CodeGen_Private::EPropertyClass::Class, "DefeatConditionActor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000005, 1, nullptr, STRUCT_OFFSET(ARTSGameMode, DefeatConditionActor), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_DefeatConditionActor_MetaData, ARRAY_COUNT(NewProp_DefeatConditionActor_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InitialActorPositions_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGameMode.h" },
				{ "ToolTip", "Relative locations of the actors to spawn for each player in the game, relative to their respetive start spot." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_InitialActorPositions = { UE4CodeGen_Private::EPropertyClass::Array, "InitialActorPositions", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ARTSGameMode, InitialActorPositions), METADATA_PARAMS(NewProp_InitialActorPositions_MetaData, ARRAY_COUNT(NewProp_InitialActorPositions_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_InitialActorPositions_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "InitialActorPositions", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InitialActors_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSGameMode.h" },
				{ "ToolTip", "Actors to spawn for each player in the game." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_InitialActors = { UE4CodeGen_Private::EPropertyClass::Array, "InitialActors", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000005, 1, nullptr, STRUCT_OFFSET(ARTSGameMode, InitialActors), METADATA_PARAMS(NewProp_InitialActors_MetaData, ARRAY_COUNT(NewProp_InitialActors_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_InitialActors_Inner = { UE4CodeGen_Private::EPropertyClass::Class, "InitialActors", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000000, 1, nullptr, 0, Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PlayerAIControllerClass,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TeamClass,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Teams,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Teams_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NumTeams,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DefeatConditionActor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InitialActorPositions,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InitialActorPositions_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InitialActors,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InitialActors_Inner,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSGameMode>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSGameMode::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
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
	IMPLEMENT_CLASS(ARTSGameMode, 1698098047);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSGameMode(Z_Construct_UClass_ARTSGameMode, &ARTSGameMode::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
