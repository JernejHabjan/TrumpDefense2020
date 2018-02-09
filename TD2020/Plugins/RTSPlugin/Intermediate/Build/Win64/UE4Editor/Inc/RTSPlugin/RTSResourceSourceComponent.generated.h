// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef RTSPLUGIN_RTSResourceSourceComponent_generated_h
#error "RTSResourceSourceComponent.generated.h already included, missing '#pragma once' in RTSResourceSourceComponent.h"
#endif
#define RTSPLUGIN_RTSResourceSourceComponent_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_14_DELEGATE \
static inline void FRTSResourceSourceComponentDepletedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSResourceSourceComponentDepletedSignature) \
{ \
	RTSResourceSourceComponentDepletedSignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_13_DELEGATE \
struct _Script_RTSPlugin_eventRTSResourceSourceComponentResourcesChangedSignature_Parms \
{ \
	float OldResources; \
	float NewResources; \
}; \
static inline void FRTSResourceSourceComponentResourcesChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSResourceSourceComponentResourcesChangedSignature, float OldResources, float NewResources) \
{ \
	_Script_RTSPlugin_eventRTSResourceSourceComponentResourcesChangedSignature_Parms Parms; \
	Parms.OldResources=OldResources; \
	Parms.NewResources=NewResources; \
	RTSResourceSourceComponentResourcesChangedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCanGathererEnter) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Gatherer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanGathererEnter(Z_Param_Gatherer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExtractResources) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Gatherer); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ResourceAmount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->ExtractResources(Z_Param_Gatherer,Z_Param_ResourceAmount); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCanGathererEnter) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Gatherer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanGathererEnter(Z_Param_Gatherer); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execExtractResources) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Gatherer); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ResourceAmount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->ExtractResources(Z_Param_Gatherer,Z_Param_ResourceAmount); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSResourceSourceComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSResourceSourceComponent(); \
public: \
	DECLARE_CLASS(URTSResourceSourceComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSResourceSourceComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_INCLASS \
private: \
	static void StaticRegisterNativesURTSResourceSourceComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSResourceSourceComponent(); \
public: \
	DECLARE_CLASS(URTSResourceSourceComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSResourceSourceComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSResourceSourceComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSResourceSourceComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSResourceSourceComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSResourceSourceComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSResourceSourceComponent(URTSResourceSourceComponent&&); \
	NO_API URTSResourceSourceComponent(const URTSResourceSourceComponent&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSResourceSourceComponent(URTSResourceSourceComponent&&); \
	NO_API URTSResourceSourceComponent(const URTSResourceSourceComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSResourceSourceComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSResourceSourceComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSResourceSourceComponent)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_20_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceSourceComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
