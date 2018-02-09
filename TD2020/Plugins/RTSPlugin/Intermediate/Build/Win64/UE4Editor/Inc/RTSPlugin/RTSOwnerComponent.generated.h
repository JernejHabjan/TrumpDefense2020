// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AController;
class AActor;
class ARTSPlayerState;
#ifdef RTSPLUGIN_RTSOwnerComponent_generated_h
#error "RTSOwnerComponent.generated.h already included, missing '#pragma once' in RTSOwnerComponent.h"
#endif
#define RTSPLUGIN_RTSOwnerComponent_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_15_DELEGATE \
struct _Script_RTSPlugin_eventRTSOwnerComponentOwnerChangedSignature_Parms \
{ \
	AController* NewOwner; \
}; \
static inline void FRTSOwnerComponentOwnerChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSOwnerComponentOwnerChangedSignature, AController* NewOwner) \
{ \
	_Script_RTSPlugin_eventRTSOwnerComponentOwnerChangedSignature_Parms Parms; \
	Parms.NewOwner=NewOwner; \
	RTSOwnerComponentOwnerChangedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsSameTeamAsController) \
	{ \
		P_GET_OBJECT(AController,Z_Param_C); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsSameTeamAsController(Z_Param_C); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsSameTeamAsActor) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Other); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsSameTeamAsActor(Z_Param_Other); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPlayerOwner) \
	{ \
		P_GET_OBJECT(AController,Z_Param_Controller); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetPlayerOwner(Z_Param_Controller); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayerOwner) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ARTSPlayerState**)Z_Param__Result=this->GetPlayerOwner(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsSameTeamAsController) \
	{ \
		P_GET_OBJECT(AController,Z_Param_C); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsSameTeamAsController(Z_Param_C); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsSameTeamAsActor) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Other); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsSameTeamAsActor(Z_Param_Other); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPlayerOwner) \
	{ \
		P_GET_OBJECT(AController,Z_Param_Controller); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetPlayerOwner(Z_Param_Controller); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayerOwner) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ARTSPlayerState**)Z_Param__Result=this->GetPlayerOwner(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSOwnerComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSOwnerComponent(); \
public: \
	DECLARE_CLASS(URTSOwnerComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSOwnerComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_INCLASS \
private: \
	static void StaticRegisterNativesURTSOwnerComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSOwnerComponent(); \
public: \
	DECLARE_CLASS(URTSOwnerComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSOwnerComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSOwnerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSOwnerComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSOwnerComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSOwnerComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSOwnerComponent(URTSOwnerComponent&&); \
	NO_API URTSOwnerComponent(const URTSOwnerComponent&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSOwnerComponent(URTSOwnerComponent&&); \
	NO_API URTSOwnerComponent(const URTSOwnerComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSOwnerComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSOwnerComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSOwnerComponent)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PlayerOwner() { return STRUCT_OFFSET(URTSOwnerComponent, PlayerOwner); }


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_21_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSOwnerComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
