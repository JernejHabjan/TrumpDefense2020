// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class URTSResourceType;
#ifdef RTSPLUGIN_RTSPlayerResourcesComponent_generated_h
#error "RTSPlayerResourcesComponent.generated.h already included, missing '#pragma once' in RTSPlayerResourcesComponent.h"
#endif
#define RTSPLUGIN_RTSPlayerResourcesComponent_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_13_DELEGATE \
struct _Script_RTSPlugin_eventRTSPlayerResourcesComponentResourcesChangedSignature_Parms \
{ \
	TSubclassOf<URTSResourceType>  ResourceType; \
	float OldResourceAmount; \
	float NewResourceAmount; \
	bool bSyncedFromServer; \
}; \
static inline void FRTSPlayerResourcesComponentResourcesChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSPlayerResourcesComponentResourcesChangedSignature, TSubclassOf<URTSResourceType>  ResourceType, float OldResourceAmount, float NewResourceAmount, bool bSyncedFromServer) \
{ \
	_Script_RTSPlugin_eventRTSPlayerResourcesComponentResourcesChangedSignature_Parms Parms; \
	Parms.ResourceType=ResourceType; \
	Parms.OldResourceAmount=OldResourceAmount; \
	Parms.NewResourceAmount=NewResourceAmount; \
	Parms.bSyncedFromServer=bSyncedFromServer ? true : false; \
	RTSPlayerResourcesComponentResourcesChangedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execReceivedResourceAmounts) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReceivedResourceAmounts(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execReceivedResourceAmounts) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReceivedResourceAmounts(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSPlayerResourcesComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSPlayerResourcesComponent(); \
public: \
	DECLARE_CLASS(URTSPlayerResourcesComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSPlayerResourcesComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_INCLASS \
private: \
	static void StaticRegisterNativesURTSPlayerResourcesComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSPlayerResourcesComponent(); \
public: \
	DECLARE_CLASS(URTSPlayerResourcesComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSPlayerResourcesComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSPlayerResourcesComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSPlayerResourcesComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSPlayerResourcesComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSPlayerResourcesComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSPlayerResourcesComponent(URTSPlayerResourcesComponent&&); \
	NO_API URTSPlayerResourcesComponent(const URTSPlayerResourcesComponent&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSPlayerResourcesComponent(URTSPlayerResourcesComponent&&); \
	NO_API URTSPlayerResourcesComponent(const URTSPlayerResourcesComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSPlayerResourcesComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSPlayerResourcesComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSPlayerResourcesComponent)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_19_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSPlayerResourcesComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
