// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class URTSResourceType;
#ifdef RTSPLUGIN_RTSResourceDrainComponent_generated_h
#error "RTSResourceDrainComponent.generated.h already included, missing '#pragma once' in RTSResourceDrainComponent.h"
#endif
#define RTSPLUGIN_RTSResourceDrainComponent_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_13_DELEGATE \
struct _Script_RTSPlugin_eventRTSResourceDrainComponentResourcesReturnedSignature_Parms \
{ \
	AActor* Gatherer; \
	TSubclassOf<URTSResourceType>  ResourceType; \
	float ResourceAmount; \
}; \
static inline void FRTSResourceDrainComponentResourcesReturnedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSResourceDrainComponentResourcesReturnedSignature, AActor* Gatherer, TSubclassOf<URTSResourceType>  ResourceType, float ResourceAmount) \
{ \
	_Script_RTSPlugin_eventRTSResourceDrainComponentResourcesReturnedSignature_Parms Parms; \
	Parms.Gatherer=Gatherer; \
	Parms.ResourceType=ResourceType; \
	Parms.ResourceAmount=ResourceAmount; \
	RTSResourceDrainComponentResourcesReturnedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_RPC_WRAPPERS
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_RPC_WRAPPERS_NO_PURE_DECLS
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSResourceDrainComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSResourceDrainComponent(); \
public: \
	DECLARE_CLASS(URTSResourceDrainComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSResourceDrainComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_INCLASS \
private: \
	static void StaticRegisterNativesURTSResourceDrainComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSResourceDrainComponent(); \
public: \
	DECLARE_CLASS(URTSResourceDrainComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSResourceDrainComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSResourceDrainComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSResourceDrainComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSResourceDrainComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSResourceDrainComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSResourceDrainComponent(URTSResourceDrainComponent&&); \
	NO_API URTSResourceDrainComponent(const URTSResourceDrainComponent&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSResourceDrainComponent(URTSResourceDrainComponent&&); \
	NO_API URTSResourceDrainComponent(const URTSResourceDrainComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSResourceDrainComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSResourceDrainComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSResourceDrainComponent)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_19_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSResourceDrainComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
