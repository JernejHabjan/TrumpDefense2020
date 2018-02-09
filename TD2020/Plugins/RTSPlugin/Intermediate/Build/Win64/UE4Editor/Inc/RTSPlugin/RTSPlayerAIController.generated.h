// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
class AActor;
#ifdef RTSPLUGIN_RTSPlayerAIController_generated_h
#error "RTSPlayerAIController.generated.h already included, missing '#pragma once' in RTSPlayerAIController.h"
#endif
#define RTSPLUGIN_RTSPlayerAIController_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStartProduction) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_PawnClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->StartProduction(Z_Param_PawnClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMeetsAllRequirementsFor) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_PawnClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->MeetsAllRequirementsFor(Z_Param_PawnClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCanPayFor) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_PawnClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanPayFor(Z_Param_PawnClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPrimaryResourceSource) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->GetPrimaryResourceSource(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPrimaryResourceDrain) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->GetPrimaryResourceDrain(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNextPawnToProduce) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TSubclassOf<APawn> *)Z_Param__Result=this->GetNextPawnToProduce(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStartProduction) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_PawnClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->StartProduction(Z_Param_PawnClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMeetsAllRequirementsFor) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_PawnClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->MeetsAllRequirementsFor(Z_Param_PawnClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCanPayFor) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_PawnClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanPayFor(Z_Param_PawnClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPrimaryResourceSource) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->GetPrimaryResourceSource(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPrimaryResourceDrain) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->GetPrimaryResourceDrain(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNextPawnToProduce) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TSubclassOf<APawn> *)Z_Param__Result=this->GetNextPawnToProduce(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARTSPlayerAIController(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSPlayerAIController(); \
public: \
	DECLARE_CLASS(ARTSPlayerAIController, AAIController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSPlayerAIController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_INCLASS \
private: \
	static void StaticRegisterNativesARTSPlayerAIController(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSPlayerAIController(); \
public: \
	DECLARE_CLASS(ARTSPlayerAIController, AAIController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSPlayerAIController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSPlayerAIController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSPlayerAIController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSPlayerAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSPlayerAIController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSPlayerAIController(ARTSPlayerAIController&&); \
	NO_API ARTSPlayerAIController(const ARTSPlayerAIController&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSPlayerAIController(ARTSPlayerAIController&&); \
	NO_API ARTSPlayerAIController(const ARTSPlayerAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSPlayerAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSPlayerAIController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARTSPlayerAIController)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PlayerResourcesComponent() { return STRUCT_OFFSET(ARTSPlayerAIController, PlayerResourcesComponent); }


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_20_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
