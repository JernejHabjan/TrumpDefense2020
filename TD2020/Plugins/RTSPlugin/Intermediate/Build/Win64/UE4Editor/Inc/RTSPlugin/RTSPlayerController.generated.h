// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class APawn;
struct FVector;
class ARTSTeamInfo;
class ARTSPlayerState;
struct FPointerEvent;
struct FVector2D;
class ARTSVisionInfo;
#ifdef RTSPLUGIN_RTSPlayerController_generated_h
#error "RTSPlayerController.generated.h already included, missing '#pragma once' in RTSPlayerController.h"
#endif
#define RTSPLUGIN_RTSPlayerController_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_RPC_WRAPPERS \
	virtual bool ServerCancelProduction_Validate(AActor* ); \
	virtual void ServerCancelProduction_Implementation(AActor* ProductionActor); \
	virtual bool ServerStartProduction_Validate(AActor* , int32 ); \
	virtual void ServerStartProduction_Implementation(AActor* ProductionActor, int32 ProductIndex); \
	virtual bool ServerIssueStopOrder_Validate(APawn* ); \
	virtual void ServerIssueStopOrder_Implementation(APawn* OrderedPawn); \
	virtual bool ServerIssueMoveOrder_Validate(APawn* , FVector const& ); \
	virtual void ServerIssueMoveOrder_Implementation(APawn* OrderedPawn, FVector const& TargetLocation); \
	virtual bool ServerIssueContinueConstructionOrder_Validate(APawn* , AActor* ); \
	virtual void ServerIssueContinueConstructionOrder_Implementation(APawn* OrderedPawn, AActor* ConstructionSite); \
	virtual bool ServerIssueGatherOrder_Validate(APawn* , AActor* ); \
	virtual void ServerIssueGatherOrder_Implementation(APawn* OrderedPawn, AActor* ResourceSource); \
	virtual bool ServerIssueBeginConstructionOrder_Validate(APawn* , TSubclassOf<AActor>  , FVector const& ); \
	virtual void ServerIssueBeginConstructionOrder_Implementation(APawn* OrderedPawn, TSubclassOf<AActor>  BuildingClass, FVector const& TargetLocation); \
	virtual bool ServerIssueAttackOrder_Validate(APawn* , AActor* ); \
	virtual void ServerIssueAttackOrder_Implementation(APawn* OrderedPawn, AActor* Target); \
	virtual bool ServerCancelConstruction_Validate(AActor* ); \
	virtual void ServerCancelConstruction_Implementation(AActor* ConstructionSite); \
	virtual bool CanPlaceBuilding_Implementation(TSubclassOf<AActor>  BuildingClass, FVector const& Location) const; \
 \
	DECLARE_FUNCTION(execCancelProduction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CancelProduction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartDefaultProduction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartDefaultProduction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCancelConstruction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CancelConstruction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCancelBuildingPlacement) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CancelBuildingPlacement(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConfirmBuildingPlacement) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ConfirmBuildingPlacement(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBeginDefaultBuildingPlacement) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->BeginDefaultBuildingPlacement(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopToggleSelection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopToggleSelection(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartToggleSelection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartToggleSelection(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAddSelection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopAddSelection(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartAddSelection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartAddSelection(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopShowingProductionProgressBars) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopShowingProductionProgressBars(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartShowingProductionProgressBars) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartShowingProductionProgressBars(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopShowingHealthBars) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopShowingHealthBars(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartShowingHealthBars) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartShowingHealthBars(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopShowingConstructionProgressBars) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopShowingConstructionProgressBars(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartShowingConstructionProgressBars) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartShowingConstructionProgressBars(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFinishSelectActors) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->FinishSelectActors(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartSelectActors) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartSelectActors(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerCancelProduction) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ProductionActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerCancelProduction_Validate(Z_Param_ProductionActor)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerCancelProduction_Validate")); \
			return; \
		} \
		this->ServerCancelProduction_Implementation(Z_Param_ProductionActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerStartProduction) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ProductionActor); \
		P_GET_PROPERTY(UIntProperty,Z_Param_ProductIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerStartProduction_Validate(Z_Param_ProductionActor,Z_Param_ProductIndex)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerStartProduction_Validate")); \
			return; \
		} \
		this->ServerStartProduction_Implementation(Z_Param_ProductionActor,Z_Param_ProductIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerIssueStopOrder) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_OrderedPawn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerIssueStopOrder_Validate(Z_Param_OrderedPawn)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerIssueStopOrder_Validate")); \
			return; \
		} \
		this->ServerIssueStopOrder_Implementation(Z_Param_OrderedPawn); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerIssueMoveOrder) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_OrderedPawn); \
		P_GET_STRUCT(FVector,Z_Param_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerIssueMoveOrder_Validate(Z_Param_OrderedPawn,Z_Param_TargetLocation)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerIssueMoveOrder_Validate")); \
			return; \
		} \
		this->ServerIssueMoveOrder_Implementation(Z_Param_OrderedPawn,Z_Param_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerIssueContinueConstructionOrder) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_OrderedPawn); \
		P_GET_OBJECT(AActor,Z_Param_ConstructionSite); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerIssueContinueConstructionOrder_Validate(Z_Param_OrderedPawn,Z_Param_ConstructionSite)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerIssueContinueConstructionOrder_Validate")); \
			return; \
		} \
		this->ServerIssueContinueConstructionOrder_Implementation(Z_Param_OrderedPawn,Z_Param_ConstructionSite); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerIssueGatherOrder) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_OrderedPawn); \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerIssueGatherOrder_Validate(Z_Param_OrderedPawn,Z_Param_ResourceSource)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerIssueGatherOrder_Validate")); \
			return; \
		} \
		this->ServerIssueGatherOrder_Implementation(Z_Param_OrderedPawn,Z_Param_ResourceSource); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerIssueBeginConstructionOrder) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_OrderedPawn); \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_GET_STRUCT(FVector,Z_Param_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerIssueBeginConstructionOrder_Validate(Z_Param_OrderedPawn,Z_Param_BuildingClass,Z_Param_TargetLocation)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerIssueBeginConstructionOrder_Validate")); \
			return; \
		} \
		this->ServerIssueBeginConstructionOrder_Implementation(Z_Param_OrderedPawn,Z_Param_BuildingClass,Z_Param_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerIssueAttackOrder) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_OrderedPawn); \
		P_GET_OBJECT(AActor,Z_Param_Target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerIssueAttackOrder_Validate(Z_Param_OrderedPawn,Z_Param_Target)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerIssueAttackOrder_Validate")); \
			return; \
		} \
		this->ServerIssueAttackOrder_Implementation(Z_Param_OrderedPawn,Z_Param_Target); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerCancelConstruction) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ConstructionSite); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerCancelConstruction_Validate(Z_Param_ConstructionSite)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerCancelConstruction_Validate")); \
			return; \
		} \
		this->ServerCancelConstruction_Implementation(Z_Param_ConstructionSite); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueOrder) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueOrder(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCanPlaceBuilding) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanPlaceBuilding_Implementation(Z_Param_BuildingClass,Z_Param_Out_Location); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBeginBuildingPlacement) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->BeginBuildingPlacement(Z_Param_BuildingClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCheckCanBeginBuildingPlacement) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CheckCanBeginBuildingPlacement(Z_Param_BuildingClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsProductionProgressBarHotkeyPressed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsProductionProgressBarHotkeyPressed(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsHealthBarHotkeyPressed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsHealthBarHotkeyPressed(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsConstructionProgressBarHotkeyPressed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsConstructionProgressBarHotkeyPressed(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup9) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup9(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup8) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup8(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup7) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup7(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup6) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup6(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup5) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup5(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup4) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup4(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup3) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup3(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup2) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup2(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup1) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup1(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup0) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup0(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup9) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup9(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup8) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup8(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup7) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup7(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup6) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup6(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup5) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup5(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup4) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup4(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup3) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup3(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup2) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup2(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup1) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup1(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup0) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup0(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSelectActors) \
	{ \
		P_GET_TARRAY(AActor*,Z_Param_Actors); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SelectActors(Z_Param_Actors); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueStopOrder) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueStopOrder(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueProductionOrder) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ProductIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueProductionOrder(Z_Param_ProductIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCheckCanIssueProductionOrder) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ProductIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CheckCanIssueProductionOrder(Z_Param_ProductIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueMoveOrder) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IssueMoveOrder(Z_Param_Out_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueGatherOrder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IssueGatherOrder(Z_Param_ResourceSource); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueContinueConstructionOrder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ConstructionSite); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IssueContinueConstructionOrder(Z_Param_ConstructionSite); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueBeginConstructionOrder) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IssueBeginConstructionOrder(Z_Param_BuildingClass,Z_Param_Out_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueAttackOrder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IssueAttackOrder(Z_Param_Target); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTeamInfo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ARTSTeamInfo**)Z_Param__Result=this->GetTeamInfo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSelectedActors) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<AActor*>*)Z_Param__Result=this->GetSelectedActors(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayerState) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ARTSPlayerState**)Z_Param__Result=this->GetPlayerState(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetHoveredActor) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->GetHoveredActor(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool ServerCancelProduction_Validate(AActor* ); \
	virtual void ServerCancelProduction_Implementation(AActor* ProductionActor); \
	virtual bool ServerStartProduction_Validate(AActor* , int32 ); \
	virtual void ServerStartProduction_Implementation(AActor* ProductionActor, int32 ProductIndex); \
	virtual bool ServerIssueStopOrder_Validate(APawn* ); \
	virtual void ServerIssueStopOrder_Implementation(APawn* OrderedPawn); \
	virtual bool ServerIssueMoveOrder_Validate(APawn* , FVector const& ); \
	virtual void ServerIssueMoveOrder_Implementation(APawn* OrderedPawn, FVector const& TargetLocation); \
	virtual bool ServerIssueContinueConstructionOrder_Validate(APawn* , AActor* ); \
	virtual void ServerIssueContinueConstructionOrder_Implementation(APawn* OrderedPawn, AActor* ConstructionSite); \
	virtual bool ServerIssueGatherOrder_Validate(APawn* , AActor* ); \
	virtual void ServerIssueGatherOrder_Implementation(APawn* OrderedPawn, AActor* ResourceSource); \
	virtual bool ServerIssueBeginConstructionOrder_Validate(APawn* , TSubclassOf<AActor>  , FVector const& ); \
	virtual void ServerIssueBeginConstructionOrder_Implementation(APawn* OrderedPawn, TSubclassOf<AActor>  BuildingClass, FVector const& TargetLocation); \
	virtual bool ServerIssueAttackOrder_Validate(APawn* , AActor* ); \
	virtual void ServerIssueAttackOrder_Implementation(APawn* OrderedPawn, AActor* Target); \
	virtual bool ServerCancelConstruction_Validate(AActor* ); \
	virtual void ServerCancelConstruction_Implementation(AActor* ConstructionSite); \
 \
	DECLARE_FUNCTION(execCancelProduction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CancelProduction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartDefaultProduction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartDefaultProduction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCancelConstruction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CancelConstruction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCancelBuildingPlacement) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CancelBuildingPlacement(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConfirmBuildingPlacement) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ConfirmBuildingPlacement(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBeginDefaultBuildingPlacement) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->BeginDefaultBuildingPlacement(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopToggleSelection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopToggleSelection(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartToggleSelection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartToggleSelection(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopAddSelection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopAddSelection(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartAddSelection) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartAddSelection(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopShowingProductionProgressBars) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopShowingProductionProgressBars(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartShowingProductionProgressBars) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartShowingProductionProgressBars(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopShowingHealthBars) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopShowingHealthBars(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartShowingHealthBars) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartShowingHealthBars(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStopShowingConstructionProgressBars) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StopShowingConstructionProgressBars(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartShowingConstructionProgressBars) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartShowingConstructionProgressBars(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFinishSelectActors) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->FinishSelectActors(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartSelectActors) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartSelectActors(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerCancelProduction) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ProductionActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerCancelProduction_Validate(Z_Param_ProductionActor)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerCancelProduction_Validate")); \
			return; \
		} \
		this->ServerCancelProduction_Implementation(Z_Param_ProductionActor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerStartProduction) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ProductionActor); \
		P_GET_PROPERTY(UIntProperty,Z_Param_ProductIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerStartProduction_Validate(Z_Param_ProductionActor,Z_Param_ProductIndex)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerStartProduction_Validate")); \
			return; \
		} \
		this->ServerStartProduction_Implementation(Z_Param_ProductionActor,Z_Param_ProductIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerIssueStopOrder) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_OrderedPawn); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerIssueStopOrder_Validate(Z_Param_OrderedPawn)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerIssueStopOrder_Validate")); \
			return; \
		} \
		this->ServerIssueStopOrder_Implementation(Z_Param_OrderedPawn); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerIssueMoveOrder) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_OrderedPawn); \
		P_GET_STRUCT(FVector,Z_Param_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerIssueMoveOrder_Validate(Z_Param_OrderedPawn,Z_Param_TargetLocation)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerIssueMoveOrder_Validate")); \
			return; \
		} \
		this->ServerIssueMoveOrder_Implementation(Z_Param_OrderedPawn,Z_Param_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerIssueContinueConstructionOrder) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_OrderedPawn); \
		P_GET_OBJECT(AActor,Z_Param_ConstructionSite); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerIssueContinueConstructionOrder_Validate(Z_Param_OrderedPawn,Z_Param_ConstructionSite)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerIssueContinueConstructionOrder_Validate")); \
			return; \
		} \
		this->ServerIssueContinueConstructionOrder_Implementation(Z_Param_OrderedPawn,Z_Param_ConstructionSite); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerIssueGatherOrder) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_OrderedPawn); \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerIssueGatherOrder_Validate(Z_Param_OrderedPawn,Z_Param_ResourceSource)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerIssueGatherOrder_Validate")); \
			return; \
		} \
		this->ServerIssueGatherOrder_Implementation(Z_Param_OrderedPawn,Z_Param_ResourceSource); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerIssueBeginConstructionOrder) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_OrderedPawn); \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_GET_STRUCT(FVector,Z_Param_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerIssueBeginConstructionOrder_Validate(Z_Param_OrderedPawn,Z_Param_BuildingClass,Z_Param_TargetLocation)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerIssueBeginConstructionOrder_Validate")); \
			return; \
		} \
		this->ServerIssueBeginConstructionOrder_Implementation(Z_Param_OrderedPawn,Z_Param_BuildingClass,Z_Param_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerIssueAttackOrder) \
	{ \
		P_GET_OBJECT(APawn,Z_Param_OrderedPawn); \
		P_GET_OBJECT(AActor,Z_Param_Target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerIssueAttackOrder_Validate(Z_Param_OrderedPawn,Z_Param_Target)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerIssueAttackOrder_Validate")); \
			return; \
		} \
		this->ServerIssueAttackOrder_Implementation(Z_Param_OrderedPawn,Z_Param_Target); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execServerCancelConstruction) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ConstructionSite); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		if (!this->ServerCancelConstruction_Validate(Z_Param_ConstructionSite)) \
		{ \
			RPC_ValidateFailed(TEXT("ServerCancelConstruction_Validate")); \
			return; \
		} \
		this->ServerCancelConstruction_Implementation(Z_Param_ConstructionSite); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueOrder) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueOrder(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCanPlaceBuilding) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanPlaceBuilding_Implementation(Z_Param_BuildingClass,Z_Param_Out_Location); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBeginBuildingPlacement) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->BeginBuildingPlacement(Z_Param_BuildingClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCheckCanBeginBuildingPlacement) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CheckCanBeginBuildingPlacement(Z_Param_BuildingClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsProductionProgressBarHotkeyPressed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsProductionProgressBarHotkeyPressed(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsHealthBarHotkeyPressed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsHealthBarHotkeyPressed(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsConstructionProgressBarHotkeyPressed) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsConstructionProgressBarHotkeyPressed(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup9) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup9(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup8) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup8(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup7) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup7(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup6) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup6(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup5) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup5(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup4) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup4(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup3) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup3(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup2) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup2(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup1) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup1(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup0) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup0(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControlGroup) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadControlGroup(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup9) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup9(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup8) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup8(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup7) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup7(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup6) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup6(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup5) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup5(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup4) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup4(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup3) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup3(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup2) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup2(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup1) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup1(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup0) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup0(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControlGroup) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SaveControlGroup(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSelectActors) \
	{ \
		P_GET_TARRAY(AActor*,Z_Param_Actors); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SelectActors(Z_Param_Actors); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueStopOrder) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueStopOrder(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueProductionOrder) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ProductIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueProductionOrder(Z_Param_ProductIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCheckCanIssueProductionOrder) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_ProductIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CheckCanIssueProductionOrder(Z_Param_ProductIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueMoveOrder) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IssueMoveOrder(Z_Param_Out_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueGatherOrder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IssueGatherOrder(Z_Param_ResourceSource); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueContinueConstructionOrder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ConstructionSite); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IssueContinueConstructionOrder(Z_Param_ConstructionSite); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueBeginConstructionOrder) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IssueBeginConstructionOrder(Z_Param_BuildingClass,Z_Param_Out_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueAttackOrder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IssueAttackOrder(Z_Param_Target); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTeamInfo) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ARTSTeamInfo**)Z_Param__Result=this->GetTeamInfo(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetSelectedActors) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<AActor*>*)Z_Param__Result=this->GetSelectedActors(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayerState) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ARTSPlayerState**)Z_Param__Result=this->GetPlayerState(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetHoveredActor) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->GetHoveredActor(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_EVENT_PARMS \
	struct RTSPlayerController_eventCanPlaceBuilding_Parms \
	{ \
		TSubclassOf<AActor>  BuildingClass; \
		FVector Location; \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		RTSPlayerController_eventCanPlaceBuilding_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	}; \
	struct RTSPlayerController_eventReceiveOnActorOwnerChanged_Parms \
	{ \
		AActor* Actor; \
	}; \
	struct RTSPlayerController_eventReceiveOnBuildingPlacementCancelled_Parms \
	{ \
		TSubclassOf<AActor>  BuildingClass; \
	}; \
	struct RTSPlayerController_eventReceiveOnBuildingPlacementConfirmed_Parms \
	{ \
		TSubclassOf<AActor>  BuildingClass; \
		FVector Location; \
	}; \
	struct RTSPlayerController_eventReceiveOnBuildingPlacementError_Parms \
	{ \
		TSubclassOf<AActor>  BuildingClass; \
		FVector Location; \
	}; \
	struct RTSPlayerController_eventReceiveOnBuildingPlacementStarted_Parms \
	{ \
		TSubclassOf<AActor>  BuildingClass; \
	}; \
	struct RTSPlayerController_eventReceiveOnErrorOccurred_Parms \
	{ \
		FString ErrorMessage; \
	}; \
	struct RTSPlayerController_eventReceiveOnIssuedAttackOrder_Parms \
	{ \
		APawn* OrderedPawn; \
		AActor* Target; \
	}; \
	struct RTSPlayerController_eventReceiveOnIssuedBeginConstructionOrder_Parms \
	{ \
		APawn* OrderedPawn; \
		TSubclassOf<AActor>  BuildingClass; \
		FVector TargetLocation; \
	}; \
	struct RTSPlayerController_eventReceiveOnIssuedContinueConstructionOrder_Parms \
	{ \
		APawn* OrderedPawn; \
		AActor* ConstructionSite; \
	}; \
	struct RTSPlayerController_eventReceiveOnIssuedGatherOrder_Parms \
	{ \
		APawn* OrderedPawn; \
		AActor* ResourceSource; \
	}; \
	struct RTSPlayerController_eventReceiveOnIssuedMoveOrder_Parms \
	{ \
		APawn* OrderedPawn; \
		FVector TargetLocation; \
	}; \
	struct RTSPlayerController_eventReceiveOnIssuedProductionOrder_Parms \
	{ \
		AActor* OrderedActor; \
		int32 ProductIndex; \
	}; \
	struct RTSPlayerController_eventReceiveOnIssuedStopOrder_Parms \
	{ \
		APawn* OrderedPawn; \
	}; \
	struct RTSPlayerController_eventReceiveOnMinimapClicked_Parms \
	{ \
		FPointerEvent InMouseEvent; \
		FVector2D MinimapPosition; \
		FVector WorldPosition; \
	}; \
	struct RTSPlayerController_eventReceiveOnSelectionChanged_Parms \
	{ \
		TArray<AActor*> Selection; \
	}; \
	struct RTSPlayerController_eventReceiveOnTeamChanged_Parms \
	{ \
		ARTSTeamInfo* NewTeam; \
	}; \
	struct RTSPlayerController_eventReceiveOnVisionInfoAvailable_Parms \
	{ \
		ARTSVisionInfo* VisionInfo; \
	}; \
	struct RTSPlayerController_eventServerCancelConstruction_Parms \
	{ \
		AActor* ConstructionSite; \
	}; \
	struct RTSPlayerController_eventServerCancelProduction_Parms \
	{ \
		AActor* ProductionActor; \
	}; \
	struct RTSPlayerController_eventServerIssueAttackOrder_Parms \
	{ \
		APawn* OrderedPawn; \
		AActor* Target; \
	}; \
	struct RTSPlayerController_eventServerIssueBeginConstructionOrder_Parms \
	{ \
		APawn* OrderedPawn; \
		TSubclassOf<AActor>  BuildingClass; \
		FVector TargetLocation; \
	}; \
	struct RTSPlayerController_eventServerIssueContinueConstructionOrder_Parms \
	{ \
		APawn* OrderedPawn; \
		AActor* ConstructionSite; \
	}; \
	struct RTSPlayerController_eventServerIssueGatherOrder_Parms \
	{ \
		APawn* OrderedPawn; \
		AActor* ResourceSource; \
	}; \
	struct RTSPlayerController_eventServerIssueMoveOrder_Parms \
	{ \
		APawn* OrderedPawn; \
		FVector TargetLocation; \
	}; \
	struct RTSPlayerController_eventServerIssueStopOrder_Parms \
	{ \
		APawn* OrderedPawn; \
	}; \
	struct RTSPlayerController_eventServerStartProduction_Parms \
	{ \
		AActor* ProductionActor; \
		int32 ProductIndex; \
	};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_CALLBACK_WRAPPERS
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARTSPlayerController(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSPlayerController(); \
public: \
	DECLARE_CLASS(ARTSPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSPlayerController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_INCLASS \
private: \
	static void StaticRegisterNativesARTSPlayerController(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSPlayerController(); \
public: \
	DECLARE_CLASS(ARTSPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSPlayerController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSPlayerController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSPlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSPlayerController(ARTSPlayerController&&); \
	NO_API ARTSPlayerController(const ARTSPlayerController&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSPlayerController(ARTSPlayerController&&); \
	NO_API ARTSPlayerController(const ARTSPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARTSPlayerController)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PlayerAdvantageComponent() { return STRUCT_OFFSET(ARTSPlayerController, PlayerAdvantageComponent); } \
	FORCEINLINE static uint32 __PPO__PlayerResourcesComponent() { return STRUCT_OFFSET(ARTSPlayerController, PlayerResourcesComponent); }


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_25_PROLOG \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_EVENT_PARMS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_CALLBACK_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_CALLBACK_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
