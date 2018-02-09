// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ARTSVisionInfo;
struct FPaintContext;
class AActor;
class APlayerState;
struct FVector2D;
#ifdef RTSPLUGIN_RTSMinimapWidget_generated_h
#error "RTSMinimapWidget.generated.h already included, missing '#pragma once' in RTSMinimapWidget.h"
#endif
#define RTSPLUGIN_RTSMinimapWidget_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetupVisionInfo) \
	{ \
		P_GET_OBJECT(ARTSVisionInfo,Z_Param_VisionInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetupVisionInfo(Z_Param_VisionInfo); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetupVisionInfo) \
	{ \
		P_GET_OBJECT(ARTSVisionInfo,Z_Param_VisionInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetupVisionInfo(Z_Param_VisionInfo); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_EVENT_PARMS \
	struct RTSMinimapWidget_eventReceiveOnDrawUnit_Parms \
	{ \
		FPaintContext Context; \
		AActor* Actor; \
		APlayerState* ActorOwner; \
		FVector2D MinimapPosition; \
		APlayerState* LocalPlayer; \
	};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_CALLBACK_WRAPPERS
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSMinimapWidget(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSMinimapWidget(); \
public: \
	DECLARE_CLASS(URTSMinimapWidget, UUserWidget, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSMinimapWidget) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_INCLASS \
private: \
	static void StaticRegisterNativesURTSMinimapWidget(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSMinimapWidget(); \
public: \
	DECLARE_CLASS(URTSMinimapWidget, UUserWidget, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSMinimapWidget) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSMinimapWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSMinimapWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSMinimapWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSMinimapWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSMinimapWidget(URTSMinimapWidget&&); \
	NO_API URTSMinimapWidget(const URTSMinimapWidget&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSMinimapWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSMinimapWidget(URTSMinimapWidget&&); \
	NO_API URTSMinimapWidget(const URTSMinimapWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSMinimapWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSMinimapWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSMinimapWidget)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_19_PROLOG \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_EVENT_PARMS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_CALLBACK_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_CALLBACK_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h_22_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class RTSMinimapWidget."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSMinimapWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
