// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef RTSPLUGIN_RTSContainerComponent_generated_h
#error "RTSContainerComponent.generated.h already included, missing '#pragma once' in RTSContainerComponent.h"
#endif
#define RTSPLUGIN_RTSContainerComponent_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_11_DELEGATE \
struct _Script_RTSPlugin_eventRTSContainerComponentActorLeftSignature_Parms \
{ \
	AActor* Actor; \
}; \
static inline void FRTSContainerComponentActorLeftSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSContainerComponentActorLeftSignature, AActor* Actor) \
{ \
	_Script_RTSPlugin_eventRTSContainerComponentActorLeftSignature_Parms Parms; \
	Parms.Actor=Actor; \
	RTSContainerComponentActorLeftSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_10_DELEGATE \
struct _Script_RTSPlugin_eventRTSContainerComponentActorEnteredSignature_Parms \
{ \
	AActor* Actor; \
}; \
static inline void FRTSContainerComponentActorEnteredSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSContainerComponentActorEnteredSignature, AActor* Actor) \
{ \
	_Script_RTSPlugin_eventRTSContainerComponentActorEnteredSignature_Parms Parms; \
	Parms.Actor=Actor; \
	RTSContainerComponentActorEnteredSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUnloadActor) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UnloadActor(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadActor) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadActor(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCanLoadActor) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanLoadActor(Z_Param_Actor); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUnloadActor) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UnloadActor(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadActor) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LoadActor(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCanLoadActor) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanLoadActor(Z_Param_Actor); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSContainerComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSContainerComponent(); \
public: \
	DECLARE_CLASS(URTSContainerComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSContainerComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_INCLASS \
private: \
	static void StaticRegisterNativesURTSContainerComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSContainerComponent(); \
public: \
	DECLARE_CLASS(URTSContainerComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSContainerComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSContainerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSContainerComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSContainerComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSContainerComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSContainerComponent(URTSContainerComponent&&); \
	NO_API URTSContainerComponent(const URTSContainerComponent&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSContainerComponent(URTSContainerComponent&&); \
	NO_API URTSContainerComponent(const URTSContainerComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSContainerComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSContainerComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSContainerComponent)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_15_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSContainerComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
