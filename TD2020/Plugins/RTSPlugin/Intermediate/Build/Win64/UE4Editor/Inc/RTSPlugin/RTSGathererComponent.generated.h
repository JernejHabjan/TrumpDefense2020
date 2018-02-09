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
struct FRTSGatherData;
#ifdef RTSPLUGIN_RTSGathererComponent_generated_h
#error "RTSGathererComponent.generated.h already included, missing '#pragma once' in RTSGathererComponent.h"
#endif
#define RTSPLUGIN_RTSGathererComponent_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_17_DELEGATE \
struct _Script_RTSPlugin_eventRTSGathererComponentResourcesReturnedSignature_Parms \
{ \
	AActor* ResourceDrain; \
	TSubclassOf<URTSResourceType>  ResourceType; \
	float ReturnedAmount; \
}; \
static inline void FRTSGathererComponentResourcesReturnedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSGathererComponentResourcesReturnedSignature, AActor* ResourceDrain, TSubclassOf<URTSResourceType>  ResourceType, float ReturnedAmount) \
{ \
	_Script_RTSPlugin_eventRTSGathererComponentResourcesReturnedSignature_Parms Parms; \
	Parms.ResourceDrain=ResourceDrain; \
	Parms.ResourceType=ResourceType; \
	Parms.ReturnedAmount=ReturnedAmount; \
	RTSGathererComponentResourcesReturnedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_16_DELEGATE \
struct _Script_RTSPlugin_eventRTSGathererComponentResourcesGatheredSignature_Parms \
{ \
	AActor* ResourceSource; \
	FRTSGatherData GatherData; \
	float GatheredAmount; \
}; \
static inline void FRTSGathererComponentResourcesGatheredSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSGathererComponentResourcesGatheredSignature, AActor* ResourceSource, FRTSGatherData const& GatherData, float GatheredAmount) \
{ \
	_Script_RTSPlugin_eventRTSGathererComponentResourcesGatheredSignature_Parms Parms; \
	Parms.ResourceSource=ResourceSource; \
	Parms.GatherData=GatherData; \
	Parms.GatheredAmount=GatheredAmount; \
	RTSGathererComponentResourcesGatheredSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execReturnResources) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceDrain); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->ReturnResources(Z_Param_ResourceDrain); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGatherResources) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GatherResources(Z_Param_ResourceSource); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartGatheringResources) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartGatheringResources(Z_Param_ResourceSource); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsGathering) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsGathering(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsCarryingResources) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsCarryingResources(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGatherRange) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetGatherRange(Z_Param_ResourceSource); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetClosestResourceSource) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_DesiredResourceType); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxDistance); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->GetClosestResourceSource(Z_Param_DesiredResourceType,Z_Param_MaxDistance); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPreferredResourceSource) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->GetPreferredResourceSource(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindClosestResourceDrain) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->FindClosestResourceDrain(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCanGatherFrom) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanGatherFrom(Z_Param_ResourceSource); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execReturnResources) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceDrain); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->ReturnResources(Z_Param_ResourceDrain); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGatherResources) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GatherResources(Z_Param_ResourceSource); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartGatheringResources) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartGatheringResources(Z_Param_ResourceSource); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsGathering) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsGathering(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsCarryingResources) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsCarryingResources(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGatherRange) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetGatherRange(Z_Param_ResourceSource); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetClosestResourceSource) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_DesiredResourceType); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_MaxDistance); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->GetClosestResourceSource(Z_Param_DesiredResourceType,Z_Param_MaxDistance); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPreferredResourceSource) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->GetPreferredResourceSource(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindClosestResourceDrain) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->FindClosestResourceDrain(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCanGatherFrom) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ResourceSource); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanGatherFrom(Z_Param_ResourceSource); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSGathererComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSGathererComponent(); \
public: \
	DECLARE_CLASS(URTSGathererComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSGathererComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_INCLASS \
private: \
	static void StaticRegisterNativesURTSGathererComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSGathererComponent(); \
public: \
	DECLARE_CLASS(URTSGathererComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSGathererComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSGathererComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSGathererComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSGathererComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSGathererComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSGathererComponent(URTSGathererComponent&&); \
	NO_API URTSGathererComponent(const URTSGathererComponent&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSGathererComponent(URTSGathererComponent&&); \
	NO_API URTSGathererComponent(const URTSGathererComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSGathererComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSGathererComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSGathererComponent)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_23_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSGathererComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
