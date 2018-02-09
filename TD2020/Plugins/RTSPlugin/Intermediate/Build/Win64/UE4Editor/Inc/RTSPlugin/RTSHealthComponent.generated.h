// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AController;
class AActor;
#ifdef RTSPLUGIN_RTSHealthComponent_generated_h
#error "RTSHealthComponent.generated.h already included, missing '#pragma once' in RTSHealthComponent.h"
#endif
#define RTSPLUGIN_RTSHealthComponent_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_11_DELEGATE \
struct _Script_RTSPlugin_eventRTSHealthComponentKilledSignature_Parms \
{ \
	AController* PreviousOwner; \
	AActor* DamageCauser; \
}; \
static inline void FRTSHealthComponentKilledSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSHealthComponentKilledSignature, AController* PreviousOwner, AActor* DamageCauser) \
{ \
	_Script_RTSPlugin_eventRTSHealthComponentKilledSignature_Parms Parms; \
	Parms.PreviousOwner=PreviousOwner; \
	Parms.DamageCauser=DamageCauser; \
	RTSHealthComponentKilledSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_10_DELEGATE \
struct _Script_RTSPlugin_eventRTSHealthComponentHealthChangedSignature_Parms \
{ \
	float OldHealth; \
	float NewHealth; \
	AActor* DamageCauser; \
}; \
static inline void FRTSHealthComponentHealthChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSHealthComponentHealthChangedSignature, float OldHealth, float NewHealth, AActor* DamageCauser) \
{ \
	_Script_RTSPlugin_eventRTSHealthComponentHealthChangedSignature_Parms Parms; \
	Parms.OldHealth=OldHealth; \
	Parms.NewHealth=NewHealth; \
	Parms.DamageCauser=DamageCauser; \
	RTSHealthComponentHealthChangedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_RPC_WRAPPERS
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSHealthComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSHealthComponent(); \
public: \
	DECLARE_CLASS(URTSHealthComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSHealthComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_INCLASS \
private: \
	static void StaticRegisterNativesURTSHealthComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSHealthComponent(); \
public: \
	DECLARE_CLASS(URTSHealthComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSHealthComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSHealthComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSHealthComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSHealthComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSHealthComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSHealthComponent(URTSHealthComponent&&); \
	NO_API URTSHealthComponent(const URTSHealthComponent&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSHealthComponent(URTSHealthComponent&&); \
	NO_API URTSHealthComponent(const URTSHealthComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSHealthComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSHealthComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSHealthComponent)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_17_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSHealthComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
