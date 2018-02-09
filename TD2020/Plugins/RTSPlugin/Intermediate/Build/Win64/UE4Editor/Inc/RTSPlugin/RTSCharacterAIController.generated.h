// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
class AActor;
enum class ERTSOrderType : uint8;
#ifdef RTSPLUGIN_RTSCharacterAIController_generated_h
#error "RTSCharacterAIController.generated.h already included, missing '#pragma once' in RTSCharacterAIController.h"
#endif
#define RTSPLUGIN_RTSCharacterAIController_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIssueStopOrder) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueStopOrder(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueReturnResourcesOrder) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueReturnResourcesOrder(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueMoveOrder) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueMoveOrder(Z_Param_Out_Location); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueGatherOrder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueGatherOrder(Z_Param_ResourceSource); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueContinueConstructionOrder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ConstructionSite); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueContinueConstructionOrder(Z_Param_ConstructionSite); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueBeginConstructionOrder) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueBeginConstructionOrder(Z_Param_BuildingClass,Z_Param_Out_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueAttackOrder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueAttackOrder(Z_Param_Target); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsIdle) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsIdle(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHasOrder) \
	{ \
		P_GET_ENUM(ERTSOrderType,Z_Param_OrderType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->HasOrder(ERTSOrderType(Z_Param_OrderType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindTargetInAcquisitionRadius) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->FindTargetInAcquisitionRadius(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIssueStopOrder) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueStopOrder(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueReturnResourcesOrder) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueReturnResourcesOrder(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueMoveOrder) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueMoveOrder(Z_Param_Out_Location); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueGatherOrder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueGatherOrder(Z_Param_ResourceSource); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueContinueConstructionOrder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ConstructionSite); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueContinueConstructionOrder(Z_Param_ConstructionSite); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueBeginConstructionOrder) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueBeginConstructionOrder(Z_Param_BuildingClass,Z_Param_Out_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIssueAttackOrder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IssueAttackOrder(Z_Param_Target); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsIdle) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsIdle(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHasOrder) \
	{ \
		P_GET_ENUM(ERTSOrderType,Z_Param_OrderType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->HasOrder(ERTSOrderType(Z_Param_OrderType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindTargetInAcquisitionRadius) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->FindTargetInAcquisitionRadius(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARTSCharacterAIController(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSCharacterAIController(); \
public: \
	DECLARE_CLASS(ARTSCharacterAIController, AAIController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSCharacterAIController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_INCLASS \
private: \
	static void StaticRegisterNativesARTSCharacterAIController(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSCharacterAIController(); \
public: \
	DECLARE_CLASS(ARTSCharacterAIController, AAIController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSCharacterAIController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSCharacterAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSCharacterAIController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSCharacterAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSCharacterAIController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSCharacterAIController(ARTSCharacterAIController&&); \
	NO_API ARTSCharacterAIController(const ARTSCharacterAIController&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSCharacterAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSCharacterAIController(ARTSCharacterAIController&&); \
	NO_API ARTSCharacterAIController(const ARTSCharacterAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSCharacterAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSCharacterAIController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSCharacterAIController)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_18_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCharacterAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
