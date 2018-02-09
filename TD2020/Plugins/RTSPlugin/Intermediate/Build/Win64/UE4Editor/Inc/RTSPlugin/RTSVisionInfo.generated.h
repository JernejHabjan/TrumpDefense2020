// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class ARTSVisionInfo;
#ifdef RTSPLUGIN_RTSVisionInfo_generated_h
#error "RTSVisionInfo.generated.h already included, missing '#pragma once' in RTSVisionInfo.h"
#endif
#define RTSPLUGIN_RTSVisionInfo_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execReceivedTeamIndex) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReceivedTeamIndex(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVisionInfoForTeam) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UByteProperty,Z_Param_InTeamIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ARTSVisionInfo**)Z_Param__Result=ARTSVisionInfo::GetVisionInfoForTeam(Z_Param_WorldContextObject,Z_Param_InTeamIndex); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execReceivedTeamIndex) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReceivedTeamIndex(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetVisionInfoForTeam) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UByteProperty,Z_Param_InTeamIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ARTSVisionInfo**)Z_Param__Result=ARTSVisionInfo::GetVisionInfoForTeam(Z_Param_WorldContextObject,Z_Param_InTeamIndex); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARTSVisionInfo(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSVisionInfo(); \
public: \
	DECLARE_CLASS(ARTSVisionInfo, AInfo, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSVisionInfo) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_INCLASS \
private: \
	static void StaticRegisterNativesARTSVisionInfo(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSVisionInfo(); \
public: \
	DECLARE_CLASS(ARTSVisionInfo, AInfo, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSVisionInfo) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSVisionInfo(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSVisionInfo) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSVisionInfo); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSVisionInfo); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSVisionInfo(ARTSVisionInfo&&); \
	NO_API ARTSVisionInfo(const ARTSVisionInfo&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSVisionInfo(ARTSVisionInfo&&); \
	NO_API ARTSVisionInfo(const ARTSVisionInfo&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSVisionInfo); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSVisionInfo); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARTSVisionInfo)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_20_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSVisionInfo_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
