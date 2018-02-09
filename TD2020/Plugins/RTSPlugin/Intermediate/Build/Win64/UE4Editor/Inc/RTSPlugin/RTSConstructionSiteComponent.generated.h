// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class URTSResourceType;
class AActor;
#ifdef RTSPLUGIN_RTSConstructionSiteComponent_generated_h
#error "RTSConstructionSiteComponent.generated.h already included, missing '#pragma once' in RTSConstructionSiteComponent.h"
#endif
#define RTSPLUGIN_RTSConstructionSiteComponent_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_20_DELEGATE \
struct _Script_RTSPlugin_eventRTSConstructionSiteComponentConstructionCostRefundedSignature_Parms \
{ \
	TSubclassOf<URTSResourceType>  ResourceType; \
	float ResourceAmount; \
}; \
static inline void FRTSConstructionSiteComponentConstructionCostRefundedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSConstructionSiteComponentConstructionCostRefundedSignature, TSubclassOf<URTSResourceType>  ResourceType, float ResourceAmount) \
{ \
	_Script_RTSPlugin_eventRTSConstructionSiteComponentConstructionCostRefundedSignature_Parms Parms; \
	Parms.ResourceType=ResourceType; \
	Parms.ResourceAmount=ResourceAmount; \
	RTSConstructionSiteComponentConstructionCostRefundedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_19_DELEGATE \
struct _Script_RTSPlugin_eventRTSConstructionSiteComponentBuilderConsumedSignature_Parms \
{ \
	AActor* Builder; \
}; \
static inline void FRTSConstructionSiteComponentBuilderConsumedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSConstructionSiteComponentBuilderConsumedSignature, AActor* Builder) \
{ \
	_Script_RTSPlugin_eventRTSConstructionSiteComponentBuilderConsumedSignature_Parms Parms; \
	Parms.Builder=Builder; \
	RTSConstructionSiteComponentBuilderConsumedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_18_DELEGATE \
static inline void FRTSConstructionSiteComponentConstructionCanceledSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSConstructionSiteComponentConstructionCanceledSignature) \
{ \
	RTSConstructionSiteComponentConstructionCanceledSignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_17_DELEGATE \
static inline void FRTSConstructionSiteComponentConstructionFinishedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSConstructionSiteComponentConstructionFinishedSignature) \
{ \
	RTSConstructionSiteComponentConstructionFinishedSignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_16_DELEGATE \
struct _Script_RTSPlugin_eventRTSConstructionSiteComponentConstructionStartedSignature_Parms \
{ \
	float TotalConstructionTime; \
}; \
static inline void FRTSConstructionSiteComponentConstructionStartedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSConstructionSiteComponentConstructionStartedSignature, float TotalConstructionTime) \
{ \
	_Script_RTSPlugin_eventRTSConstructionSiteComponentConstructionStartedSignature_Parms Parms; \
	Parms.TotalConstructionTime=TotalConstructionTime; \
	RTSConstructionSiteComponentConstructionStartedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCancelConstruction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CancelConstruction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFinishConstruction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->FinishConstruction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartConstruction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartConstruction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsFinished) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsFinished(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsConstructing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsConstructing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetProgressPercentage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetProgressPercentage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCanAssignBuilder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Builder); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanAssignBuilder(Z_Param_Builder); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCancelConstruction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CancelConstruction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFinishConstruction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->FinishConstruction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartConstruction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartConstruction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsFinished) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsFinished(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsConstructing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsConstructing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetProgressPercentage) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetProgressPercentage(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCanAssignBuilder) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Builder); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanAssignBuilder(Z_Param_Builder); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSConstructionSiteComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSConstructionSiteComponent(); \
public: \
	DECLARE_CLASS(URTSConstructionSiteComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSConstructionSiteComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_INCLASS \
private: \
	static void StaticRegisterNativesURTSConstructionSiteComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSConstructionSiteComponent(); \
public: \
	DECLARE_CLASS(URTSConstructionSiteComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSConstructionSiteComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSConstructionSiteComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSConstructionSiteComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSConstructionSiteComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSConstructionSiteComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSConstructionSiteComponent(URTSConstructionSiteComponent&&); \
	NO_API URTSConstructionSiteComponent(const URTSConstructionSiteComponent&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSConstructionSiteComponent(URTSConstructionSiteComponent&&); \
	NO_API URTSConstructionSiteComponent(const URTSConstructionSiteComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSConstructionSiteComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSConstructionSiteComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSConstructionSiteComponent)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_24_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSConstructionSiteComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
