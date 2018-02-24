// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RTSPLUGIN_RTSCheatManager_generated_h
#error "RTSCheatManager.generated.h already included, missing '#pragma once' in RTSCheatManager.h"
#endif
#define RTSPLUGIN_RTSCheatManager_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execVictory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Victory(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoney) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Money(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGod) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->God(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBoost) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Boost(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execVictory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Victory(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMoney) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Money(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGod) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->God(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBoost) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Boost(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSCheatManager(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSCheatManager(); \
public: \
	DECLARE_CLASS(URTSCheatManager, UCheatManager, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSCheatManager) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_INCLASS \
private: \
	static void StaticRegisterNativesURTSCheatManager(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSCheatManager(); \
public: \
	DECLARE_CLASS(URTSCheatManager, UCheatManager, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSCheatManager) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSCheatManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSCheatManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSCheatManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSCheatManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSCheatManager(URTSCheatManager&&); \
	NO_API URTSCheatManager(const URTSCheatManager&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSCheatManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSCheatManager(URTSCheatManager&&); \
	NO_API URTSCheatManager(const URTSCheatManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSCheatManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSCheatManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSCheatManager)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_12_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSCheatManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
