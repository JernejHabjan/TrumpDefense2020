// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FVector;
#ifdef RTSPLUGIN_RTSBuilderComponent_generated_h
#error "RTSBuilderComponent.generated.h already included, missing '#pragma once' in RTSBuilderComponent.h"
#endif
#define RTSPLUGIN_RTSBuilderComponent_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_14_DELEGATE \
struct _Script_RTSPlugin_eventRTSBuilderComponentConstructionStartedSignature_Parms \
{ \
	AActor* ConstructionSite; \
}; \
static inline void FRTSBuilderComponentConstructionStartedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSBuilderComponentConstructionStartedSignature, AActor* ConstructionSite) \
{ \
	_Script_RTSPlugin_eventRTSBuilderComponentConstructionStartedSignature_Parms Parms; \
	Parms.ConstructionSite=ConstructionSite; \
	RTSBuilderComponentConstructionStartedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_13_DELEGATE \
struct _Script_RTSPlugin_eventRTSBuilderComponentConstructionSiteLeftSignature_Parms \
{ \
	AActor* ConstructionSite; \
}; \
static inline void FRTSBuilderComponentConstructionSiteLeftSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSBuilderComponentConstructionSiteLeftSignature, AActor* ConstructionSite) \
{ \
	_Script_RTSPlugin_eventRTSBuilderComponentConstructionSiteLeftSignature_Parms Parms; \
	Parms.ConstructionSite=ConstructionSite; \
	RTSBuilderComponentConstructionSiteLeftSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_12_DELEGATE \
struct _Script_RTSPlugin_eventRTSBuilderComponentConstructionSiteEnteredSignature_Parms \
{ \
	AActor* ConstructionSite; \
}; \
static inline void FRTSBuilderComponentConstructionSiteEnteredSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSBuilderComponentConstructionSiteEnteredSignature, AActor* ConstructionSite) \
{ \
	_Script_RTSPlugin_eventRTSBuilderComponentConstructionSiteEnteredSignature_Parms Parms; \
	Parms.ConstructionSite=ConstructionSite; \
	RTSBuilderComponentConstructionSiteEnteredSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_11_DELEGATE \
struct _Script_RTSPlugin_eventRTSBuilderComponentRemovedFromConstructionSiteSignature_Parms \
{ \
	AActor* ConstructionSite; \
}; \
static inline void FRTSBuilderComponentRemovedFromConstructionSiteSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSBuilderComponentRemovedFromConstructionSiteSignature, AActor* ConstructionSite) \
{ \
	_Script_RTSPlugin_eventRTSBuilderComponentRemovedFromConstructionSiteSignature_Parms Parms; \
	Parms.ConstructionSite=ConstructionSite; \
	RTSBuilderComponentRemovedFromConstructionSiteSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_10_DELEGATE \
struct _Script_RTSPlugin_eventRTSBuilderComponentAssignedToConstructionSiteSignature_Parms \
{ \
	AActor* ConstructionSite; \
}; \
static inline void FRTSBuilderComponentAssignedToConstructionSiteSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSBuilderComponentAssignedToConstructionSiteSignature, AActor* ConstructionSite) \
{ \
	_Script_RTSPlugin_eventRTSBuilderComponentAssignedToConstructionSiteSignature_Parms Parms; \
	Parms.ConstructionSite=ConstructionSite; \
	RTSBuilderComponentAssignedToConstructionSiteSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLeaveConstructionSite) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LeaveConstructionSite(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAssignedConstructionSite) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->GetAssignedConstructionSite(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBeginConstructionByIndex) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BuildingIndex); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->BeginConstructionByIndex(Z_Param_BuildingIndex,Z_Param_Out_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBeginConstruction) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->BeginConstruction(Z_Param_BuildingClass,Z_Param_Out_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAssignToConstructionSite) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ConstructionSite); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AssignToConstructionSite(Z_Param_ConstructionSite); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLeaveConstructionSite) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->LeaveConstructionSite(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAssignedConstructionSite) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AActor**)Z_Param__Result=this->GetAssignedConstructionSite(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBeginConstructionByIndex) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_BuildingIndex); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->BeginConstructionByIndex(Z_Param_BuildingIndex,Z_Param_Out_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBeginConstruction) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_BuildingClass); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_TargetLocation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->BeginConstruction(Z_Param_BuildingClass,Z_Param_Out_TargetLocation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAssignToConstructionSite) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ConstructionSite); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AssignToConstructionSite(Z_Param_ConstructionSite); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSBuilderComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSBuilderComponent(); \
public: \
	DECLARE_CLASS(URTSBuilderComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSBuilderComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_INCLASS \
private: \
	static void StaticRegisterNativesURTSBuilderComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSBuilderComponent(); \
public: \
	DECLARE_CLASS(URTSBuilderComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSBuilderComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSBuilderComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSBuilderComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSBuilderComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSBuilderComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSBuilderComponent(URTSBuilderComponent&&); \
	NO_API URTSBuilderComponent(const URTSBuilderComponent&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSBuilderComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSBuilderComponent(URTSBuilderComponent&&); \
	NO_API URTSBuilderComponent(const URTSBuilderComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSBuilderComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSBuilderComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSBuilderComponent)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_20_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSBuilderComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
