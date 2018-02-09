// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AController;
#ifdef RTSPLUGIN_RTSGameMode_generated_h
#error "RTSGameMode.generated.h already included, missing '#pragma once' in RTSGameMode.h"
#endif
#define RTSPLUGIN_RTSGameMode_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execTransferOwnership) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_GET_OBJECT(AController,Z_Param_NewOwner); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TransferOwnership(Z_Param_Actor,Z_Param_NewOwner); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execTransferOwnership) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_GET_OBJECT(AController,Z_Param_NewOwner); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TransferOwnership(Z_Param_Actor,Z_Param_NewOwner); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_EVENT_PARMS \
	struct RTSGameMode_eventReceiveOnPlayerDefeated_Parms \
	{ \
		AController* Player; \
	};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_CALLBACK_WRAPPERS
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARTSGameMode(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSGameMode(); \
public: \
	DECLARE_CLASS(ARTSGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_INCLASS \
private: \
	static void StaticRegisterNativesARTSGameMode(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSGameMode(); \
public: \
	DECLARE_CLASS(ARTSGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSGameMode(ARTSGameMode&&); \
	NO_API ARTSGameMode(const ARTSGameMode&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSGameMode(ARTSGameMode&&); \
	NO_API ARTSGameMode(const ARTSGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSGameMode)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_21_PROLOG \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_EVENT_PARMS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_CALLBACK_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_CALLBACK_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
