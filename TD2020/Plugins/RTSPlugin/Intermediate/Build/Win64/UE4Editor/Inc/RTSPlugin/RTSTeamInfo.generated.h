// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AController;
#ifdef RTSPLUGIN_RTSTeamInfo_generated_h
#error "RTSTeamInfo.generated.h already included, missing '#pragma once' in RTSTeamInfo.h"
#endif
#define RTSPLUGIN_RTSTeamInfo_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execReceivedTeamIndex) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReceivedTeamIndex(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTeamMembers) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<AController*>*)Z_Param__Result=this->GetTeamMembers(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveFromTeam) \
	{ \
		P_GET_OBJECT(AController,Z_Param_Player); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->RemoveFromTeam(Z_Param_Player); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddToTeam) \
	{ \
		P_GET_OBJECT(AController,Z_Param_Player); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AddToTeam(Z_Param_Player); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execReceivedTeamIndex) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ReceivedTeamIndex(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTeamMembers) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<AController*>*)Z_Param__Result=this->GetTeamMembers(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveFromTeam) \
	{ \
		P_GET_OBJECT(AController,Z_Param_Player); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->RemoveFromTeam(Z_Param_Player); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddToTeam) \
	{ \
		P_GET_OBJECT(AController,Z_Param_Player); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->AddToTeam(Z_Param_Player); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARTSTeamInfo(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSTeamInfo(); \
public: \
	DECLARE_CLASS(ARTSTeamInfo, AInfo, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSTeamInfo) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_INCLASS \
private: \
	static void StaticRegisterNativesARTSTeamInfo(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_ARTSTeamInfo(); \
public: \
	DECLARE_CLASS(ARTSTeamInfo, AInfo, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(ARTSTeamInfo) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARTSTeamInfo(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARTSTeamInfo) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSTeamInfo); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSTeamInfo); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSTeamInfo(ARTSTeamInfo&&); \
	NO_API ARTSTeamInfo(const ARTSTeamInfo&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARTSTeamInfo(ARTSTeamInfo&&); \
	NO_API ARTSTeamInfo(const ARTSTeamInfo&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARTSTeamInfo); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARTSTeamInfo); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARTSTeamInfo)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_13_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSTeamInfo_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
