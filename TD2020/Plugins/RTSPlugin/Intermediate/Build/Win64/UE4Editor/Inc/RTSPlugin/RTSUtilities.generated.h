// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class AActor;
class UActorComponent;
class UWorld;
struct FVector;
class UShapeComponent;
#ifdef RTSPLUGIN_RTSUtilities_generated_h
#error "RTSUtilities.generated.h already included, missing '#pragma once' in RTSUtilities.h"
#endif
#define RTSPLUGIN_RTSUtilities_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOwnerMeetsAllRequirementsFor) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(AActor,Z_Param_OwnedActor); \
		P_GET_OBJECT(UClass,Z_Param_DesiredProduct); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URTSUtilities::OwnerMeetsAllRequirementsFor(Z_Param_WorldContextObject,Z_Param_OwnedActor,Z_Param_DesiredProduct); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindDefaultComponentByClass) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_InActorClass); \
		P_GET_OBJECT(UClass,Z_Param_InComponentClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UActorComponent**)Z_Param__Result=URTSUtilities::FindDefaultComponentByClass(Z_Param_InActorClass,Z_Param_InComponentClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsSuitableLocationForActor) \
	{ \
		P_GET_OBJECT(UWorld,Z_Param_World); \
		P_GET_OBJECT(UClass,Z_Param_ActorClass); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URTSUtilities::IsSuitableLocationForActor(Z_Param_World,Z_Param_ActorClass,Z_Param_Out_Location); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsReadyToUse) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URTSUtilities::IsReadyToUse(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsAIUnit) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URTSUtilities::IsAIUnit(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGroundLocation) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FVector,Z_Param_Location); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=URTSUtilities::GetGroundLocation(Z_Param_WorldContextObject,Z_Param_Location); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetShapeCollisionHeight) \
	{ \
		P_GET_OBJECT(UShapeComponent,Z_Param_ShapeComponent); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetShapeCollisionHeight(Z_Param_ShapeComponent); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetShapeCollisionSize) \
	{ \
		P_GET_OBJECT(UShapeComponent,Z_Param_ShapeComponent); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetShapeCollisionSize(Z_Param_ShapeComponent); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorCollisionHeight) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetActorCollisionHeight(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorCollisionSize) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetActorCollisionSize(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCollisionHeight) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_ActorClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetCollisionHeight(Z_Param_ActorClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCollisionSize) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_ActorClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetCollisionSize(Z_Param_ActorClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorDistance) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_First); \
		P_GET_OBJECT(AActor,Z_Param_Second); \
		P_GET_UBOOL(Z_Param_bConsiderCollisionSize); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetActorDistance(Z_Param_First,Z_Param_Second,Z_Param_bConsiderCollisionSize); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOwnerMeetsAllRequirementsFor) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(AActor,Z_Param_OwnedActor); \
		P_GET_OBJECT(UClass,Z_Param_DesiredProduct); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URTSUtilities::OwnerMeetsAllRequirementsFor(Z_Param_WorldContextObject,Z_Param_OwnedActor,Z_Param_DesiredProduct); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindDefaultComponentByClass) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_InActorClass); \
		P_GET_OBJECT(UClass,Z_Param_InComponentClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UActorComponent**)Z_Param__Result=URTSUtilities::FindDefaultComponentByClass(Z_Param_InActorClass,Z_Param_InComponentClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsSuitableLocationForActor) \
	{ \
		P_GET_OBJECT(UWorld,Z_Param_World); \
		P_GET_OBJECT(UClass,Z_Param_ActorClass); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URTSUtilities::IsSuitableLocationForActor(Z_Param_World,Z_Param_ActorClass,Z_Param_Out_Location); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsReadyToUse) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URTSUtilities::IsReadyToUse(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsAIUnit) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=URTSUtilities::IsAIUnit(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetGroundLocation) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FVector,Z_Param_Location); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FVector*)Z_Param__Result=URTSUtilities::GetGroundLocation(Z_Param_WorldContextObject,Z_Param_Location); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetShapeCollisionHeight) \
	{ \
		P_GET_OBJECT(UShapeComponent,Z_Param_ShapeComponent); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetShapeCollisionHeight(Z_Param_ShapeComponent); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetShapeCollisionSize) \
	{ \
		P_GET_OBJECT(UShapeComponent,Z_Param_ShapeComponent); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetShapeCollisionSize(Z_Param_ShapeComponent); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorCollisionHeight) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetActorCollisionHeight(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorCollisionSize) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Actor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetActorCollisionSize(Z_Param_Actor); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCollisionHeight) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_ActorClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetCollisionHeight(Z_Param_ActorClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCollisionSize) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_ActorClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetCollisionSize(Z_Param_ActorClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActorDistance) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_First); \
		P_GET_OBJECT(AActor,Z_Param_Second); \
		P_GET_UBOOL(Z_Param_bConsiderCollisionSize); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=URTSUtilities::GetActorDistance(Z_Param_First,Z_Param_Second,Z_Param_bConsiderCollisionSize); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSUtilities(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSUtilities(); \
public: \
	DECLARE_CLASS(URTSUtilities, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSUtilities) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_INCLASS \
private: \
	static void StaticRegisterNativesURTSUtilities(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSUtilities(); \
public: \
	DECLARE_CLASS(URTSUtilities, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSUtilities) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSUtilities(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSUtilities) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSUtilities); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSUtilities); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSUtilities(URTSUtilities&&); \
	NO_API URTSUtilities(const URTSUtilities&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSUtilities(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSUtilities(URTSUtilities&&); \
	NO_API URTSUtilities(const URTSUtilities&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSUtilities); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSUtilities); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSUtilities)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_16_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h_19_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class RTSUtilities."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSUtilities_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
