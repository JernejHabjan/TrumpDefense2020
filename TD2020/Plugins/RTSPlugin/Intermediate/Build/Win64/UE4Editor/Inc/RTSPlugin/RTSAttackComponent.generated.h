// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRTSAttackData;
class AActor;
class ARTSProjectile;
#ifdef RTSPLUGIN_RTSAttackComponent_generated_h
#error "RTSAttackComponent.generated.h already included, missing '#pragma once' in RTSAttackComponent.h"
#endif
#define RTSPLUGIN_RTSAttackComponent_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_13_DELEGATE \
struct _Script_RTSPlugin_eventRTSAttackComponentAttackedUsedSignature_Parms \
{ \
	FRTSAttackData Attack; \
	AActor* Target; \
	ARTSProjectile* Projectile; \
}; \
static inline void FRTSAttackComponentAttackedUsedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSAttackComponentAttackedUsedSignature, FRTSAttackData const& Attack, AActor* Target, ARTSProjectile* Projectile) \
{ \
	_Script_RTSPlugin_eventRTSAttackComponentAttackedUsedSignature_Parms Parms; \
	Parms.Attack=Attack; \
	Parms.Target=Target; \
	Parms.Projectile=Projectile; \
	RTSAttackComponentAttackedUsedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_12_DELEGATE \
static inline void FRTSAttackComponentCooldownReadySignature_DelegateWrapper(const FMulticastScriptDelegate& RTSAttackComponentCooldownReadySignature) \
{ \
	RTSAttackComponentCooldownReadySignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUseAttack) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_AttackIndex); \
		P_GET_OBJECT(AActor,Z_Param_Target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UseAttack(Z_Param_AttackIndex,Z_Param_Target); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUseAttack) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_AttackIndex); \
		P_GET_OBJECT(AActor,Z_Param_Target); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->UseAttack(Z_Param_AttackIndex,Z_Param_Target); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSAttackComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSAttackComponent(); \
public: \
	DECLARE_CLASS(URTSAttackComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSAttackComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_INCLASS \
private: \
	static void StaticRegisterNativesURTSAttackComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSAttackComponent(); \
public: \
	DECLARE_CLASS(URTSAttackComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSAttackComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSAttackComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSAttackComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSAttackComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSAttackComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSAttackComponent(URTSAttackComponent&&); \
	NO_API URTSAttackComponent(const URTSAttackComponent&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSAttackComponent(URTSAttackComponent&&); \
	NO_API URTSAttackComponent(const URTSAttackComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSAttackComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSAttackComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSAttackComponent)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_20_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSAttackComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
