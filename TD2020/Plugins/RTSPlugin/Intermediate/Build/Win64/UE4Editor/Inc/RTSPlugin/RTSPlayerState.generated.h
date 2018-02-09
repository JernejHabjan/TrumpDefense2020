// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ARTSPlayerState;
class ARTSTeamInfo;
#ifdef RTSPLUGIN_RTSPlayerState_generated_h
#error "RTSPlayerState.generated.h already included, missing '#pragma once' in RTSPlayerState.h"
#endif
#define RTSPLUGIN_RTSPlayerState_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnTeamChanged) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnTeamChanged(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsSameTeamAs) \
	{ \
		P_GET_OBJECT(ARTSPlayerState,Z_Param_Other); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsSameTeamAs(Z_Param_Other); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnTeamChanged) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnTeamChanged(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsSameTeamAs) \
	{ \
		P_GET_OBJECT(ARTSPlayerState,Z_Param_Other); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsSameTeamAs(Z_Param_Other); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_EVENT_PARMS \
	struct RTSPlayerState_eventReceiveOnTeamChanged_Parms \
	{ \
		ARTSTeamInfo* NewTeam; \
	};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_CALLBACK_WRAPPERS
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARTSPlayerState(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSPlayerState(); \
public: \
	DECLARE_CLASS(ARTSPlayerState, APlayerState, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSPlayerState) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_INCLASS \
private: \
	static void StaticRegisterNativesARTSPlayerState(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSPlayerState(); \
public: \
	DECLARE_CLASS(ARTSPlayerState, APlayerState, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSPlayerState) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSPlayerState) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSPlayerState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSPlayerState); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSPlayerState(ARTSPlayerState&&); \
	NO_API ARTSPlayerState(const ARTSPlayerState&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSPlayerState(ARTSPlayerState&&); \
	NO_API ARTSPlayerState(const ARTSPlayerState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSPlayerState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSPlayerState); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSPlayerState)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_16_PROLOG \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_EVENT_PARMS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_CALLBACK_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_CALLBACK_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerState_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
