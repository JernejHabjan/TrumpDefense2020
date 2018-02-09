// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FVector2D;
struct FLinearColor;
#ifdef RTSPLUGIN_RTSHUD_generated_h
#error "RTSHUD.generated.h already included, missing '#pragma once' in RTSHUD.h"
#endif
#define RTSPLUGIN_RTSHUD_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetActorSizeOnScreen) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=this->GetActorSizeOnScreen(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorCenterOnScreen) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=this->GetActorCenterOnScreen(Z_Param_Actor); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetActorSizeOnScreen) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=this->GetActorSizeOnScreen(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorCenterOnScreen) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector2D*)Z_Param__Result=this->GetActorCenterOnScreen(Z_Param_Actor); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_EVENT_PARMS \
	struct RTSHUD_eventReceiveDrawConstructionProgressBar_Parms \
	{ \
		AActor* Actor; \
		float ConstructionTime; \
		float RemainingConstructionTime; \
		float ProgressPercentage; \
		float SuggestedProgressBarLeft; \
		float SuggestedProgressBarTop; \
		float SuggestedProgressBarWidth; \
		float SuggestedProgressBarHeight; \
	}; \
	struct RTSHUD_eventReceiveDrawFloatingCombatText_Parms \
	{ \
		AActor* Actor; \
		FString Text; \
		FLinearColor Color; \
		float Scale; \
		float Lifetime; \
		float RemainingLifetime; \
		float LifetimePercentage; \
		float SuggestedTextLeft; \
		float SuggestedTextTop; \
	}; \
	struct RTSHUD_eventReceiveDrawHealthBar_Parms \
	{ \
		AActor* Actor; \
		float CurrentHealth; \
		float MaximumHealth; \
		float HealthPercentage; \
		float SuggestedHealthBarLeft; \
		float SuggestedHealthBarTop; \
		float SuggestedHealthBarWidth; \
		float SuggestedHealthBarHeight; \
	}; \
	struct RTSHUD_eventReceiveDrawHoveredActorEffect_Parms \
	{ \
		AActor* HoveredActor; \
	}; \
	struct RTSHUD_eventReceiveDrawProductionProgressBar_Parms \
	{ \
		AActor* Actor; \
		float ProductionTime; \
		float RemainingProductionTime; \
		float ProgressPercentage; \
		float SuggestedProgressBarLeft; \
		float SuggestedProgressBarTop; \
		float SuggestedProgressBarWidth; \
		float SuggestedProgressBarHeight; \
	}; \
	struct RTSHUD_eventReceiveDrawSelectionFrame_Parms \
	{ \
		float ScreenX; \
		float ScreenY; \
		float Width; \
		float Height; \
	};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_CALLBACK_WRAPPERS
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARTSHUD(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSHUD(); \
public: \
	DECLARE_CLASS(ARTSHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSHUD) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_INCLASS \
private: \
	static void StaticRegisterNativesARTSHUD(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSHUD(); \
public: \
	DECLARE_CLASS(ARTSHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSHUD) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSHUD(ARTSHUD&&); \
	NO_API ARTSHUD(const ARTSHUD&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSHUD(ARTSHUD&&); \
	NO_API ARTSHUD(const ARTSHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSHUD)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_13_PROLOG \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_EVENT_PARMS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_CALLBACK_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_CALLBACK_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
