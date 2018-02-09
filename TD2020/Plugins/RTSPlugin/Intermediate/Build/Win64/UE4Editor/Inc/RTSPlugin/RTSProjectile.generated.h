// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UDamageType;
class AController;
#ifdef RTSPLUGIN_RTSProjectile_generated_h
#error "RTSProjectile.generated.h already included, missing '#pragma once' in RTSProjectile.h"
#endif
#define RTSPLUGIN_RTSProjectile_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execFireAt) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ProjectileTarget); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ProjectileDamage); \
		P_GET_OBJECT(UClass,Z_Param_ProjectileDamageType); \
		P_GET_OBJECT(AController,Z_Param_ProjectileInstigator); \
		P_GET_OBJECT(AActor,Z_Param_ProjectileDamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->FireAt(Z_Param_ProjectileTarget,Z_Param_ProjectileDamage,Z_Param_ProjectileDamageType,Z_Param_ProjectileInstigator,Z_Param_ProjectileDamageCauser); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFireAt) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ProjectileTarget); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_ProjectileDamage); \
		P_GET_OBJECT(UClass,Z_Param_ProjectileDamageType); \
		P_GET_OBJECT(AController,Z_Param_ProjectileInstigator); \
		P_GET_OBJECT(AActor,Z_Param_ProjectileDamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->FireAt(Z_Param_ProjectileTarget,Z_Param_ProjectileDamage,Z_Param_ProjectileDamageType,Z_Param_ProjectileInstigator,Z_Param_ProjectileDamageCauser); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_EVENT_PARMS \
	struct RTSProjectile_eventReceiveOnProjectileDetonated_Parms \
	{ \
		AActor* ProjectileTarget; \
		float ProjectileDamage; \
		TSubclassOf<UDamageType>  ProjectileDamageType; \
		AController* ProjectileInstigator; \
		AActor* ProjectileDamageCauser; \
	};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_CALLBACK_WRAPPERS
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARTSProjectile(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSProjectile(); \
public: \
	DECLARE_CLASS(ARTSProjectile, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSProjectile) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_INCLASS \
private: \
	static void StaticRegisterNativesARTSProjectile(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSProjectile(); \
public: \
	DECLARE_CLASS(ARTSProjectile, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSProjectile) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSProjectile(ARTSProjectile&&); \
	NO_API ARTSProjectile(const ARTSProjectile&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSProjectile(ARTSProjectile&&); \
	NO_API ARTSProjectile(const ARTSProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARTSProjectile)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(ARTSProjectile, ProjectileMovement); }


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_16_PROLOG \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_EVENT_PARMS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_CALLBACK_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_CALLBACK_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
