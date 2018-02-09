// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RTSPLUGIN_RTSSelectableComponent_generated_h
#error "RTSSelectableComponent.generated.h already included, missing '#pragma once' in RTSSelectableComponent.h"
#endif
#define RTSPLUGIN_RTSSelectableComponent_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_11_DELEGATE \
static inline void FRTSSelectableComponentDeselectedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSSelectableComponentDeselectedSignature) \
{ \
	RTSSelectableComponentDeselectedSignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_10_DELEGATE \
static inline void FRTSSelectableComponentSelectedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSSelectableComponentSelectedSignature) \
{ \
	RTSSelectableComponentSelectedSignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsSelected) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsSelected(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDeselectActor) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DeselectActor(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSelectActor) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SelectActor(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsSelected) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsSelected(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDeselectActor) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DeselectActor(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSelectActor) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SelectActor(); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSSelectableComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSSelectableComponent(); \
public: \
	DECLARE_CLASS(URTSSelectableComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSSelectableComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_INCLASS \
private: \
	static void StaticRegisterNativesURTSSelectableComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSSelectableComponent(); \
public: \
	DECLARE_CLASS(URTSSelectableComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSSelectableComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSSelectableComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSSelectableComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSSelectableComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSSelectableComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSSelectableComponent(URTSSelectableComponent&&); \
	NO_API URTSSelectableComponent(const URTSSelectableComponent&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSSelectableComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSSelectableComponent(URTSSelectableComponent&&); \
	NO_API URTSSelectableComponent(const URTSSelectableComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSSelectableComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSSelectableComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSSelectableComponent)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_17_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSSelectableComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
