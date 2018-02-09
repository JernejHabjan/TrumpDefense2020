// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class URTSResourceType;
class AActor;
#ifdef RTSPLUGIN_RTSProductionComponent_generated_h
#error "RTSProductionComponent.generated.h already included, missing '#pragma once' in RTSProductionComponent.h"
#endif
#define RTSPLUGIN_RTSProductionComponent_generated_h

#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_16_DELEGATE \
struct _Script_RTSPlugin_eventRTSProductionComponentProductionCostRefundedSignature_Parms \
{ \
	TSubclassOf<URTSResourceType>  ResourceType; \
	float ResourceAmount; \
}; \
static inline void FRTSProductionComponentProductionCostRefundedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSProductionComponentProductionCostRefundedSignature, TSubclassOf<URTSResourceType>  ResourceType, float ResourceAmount) \
{ \
	_Script_RTSPlugin_eventRTSProductionComponentProductionCostRefundedSignature_Parms Parms; \
	Parms.ResourceType=ResourceType; \
	Parms.ResourceAmount=ResourceAmount; \
	RTSProductionComponentProductionCostRefundedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_15_DELEGATE \
struct _Script_RTSPlugin_eventRTSProductionComponentProductionCanceledSignature_Parms \
{ \
	TSubclassOf<AActor>  ProductClass; \
	int32 QueueIndex; \
	float ElapsedProductionTime; \
}; \
static inline void FRTSProductionComponentProductionCanceledSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSProductionComponentProductionCanceledSignature, TSubclassOf<AActor>  ProductClass, int32 QueueIndex, float ElapsedProductionTime) \
{ \
	_Script_RTSPlugin_eventRTSProductionComponentProductionCanceledSignature_Parms Parms; \
	Parms.ProductClass=ProductClass; \
	Parms.QueueIndex=QueueIndex; \
	Parms.ElapsedProductionTime=ElapsedProductionTime; \
	RTSProductionComponentProductionCanceledSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_14_DELEGATE \
struct _Script_RTSPlugin_eventRTSProductionComponentProductionFinishedSignature_Parms \
{ \
	AActor* Product; \
	int32 QueueIndex; \
}; \
static inline void FRTSProductionComponentProductionFinishedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSProductionComponentProductionFinishedSignature, AActor* Product, int32 QueueIndex) \
{ \
	_Script_RTSPlugin_eventRTSProductionComponentProductionFinishedSignature_Parms Parms; \
	Parms.Product=Product; \
	Parms.QueueIndex=QueueIndex; \
	RTSProductionComponentProductionFinishedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_13_DELEGATE \
struct _Script_RTSPlugin_eventRTSProductionComponentProductionStartedSignature_Parms \
{ \
	TSubclassOf<AActor>  ProductClass; \
	int32 QueueIndex; \
	float TotalProductionTime; \
}; \
static inline void FRTSProductionComponentProductionStartedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSProductionComponentProductionStartedSignature, TSubclassOf<AActor>  ProductClass, int32 QueueIndex, float TotalProductionTime) \
{ \
	_Script_RTSPlugin_eventRTSProductionComponentProductionStartedSignature_Parms Parms; \
	Parms.ProductClass=ProductClass; \
	Parms.QueueIndex=QueueIndex; \
	Parms.TotalProductionTime=TotalProductionTime; \
	RTSProductionComponentProductionStartedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_12_DELEGATE \
struct _Script_RTSPlugin_eventRTSProductionComponentProductQueuedSignature_Parms \
{ \
	TSubclassOf<AActor>  ProductClass; \
	int32 QueueIndex; \
}; \
static inline void FRTSProductionComponentProductQueuedSignature_DelegateWrapper(const FMulticastScriptDelegate& RTSProductionComponentProductQueuedSignature, TSubclassOf<AActor>  ProductClass, int32 QueueIndex) \
{ \
	_Script_RTSPlugin_eventRTSProductionComponentProductQueuedSignature_Parms Parms; \
	Parms.ProductClass=ProductClass; \
	Parms.QueueIndex=QueueIndex; \
	RTSProductionComponentProductQueuedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCancelProduction) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_QueueIndex); \
		P_GET_PROPERTY(UIntProperty,Z_Param_ProductIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CancelProduction(Z_Param_QueueIndex,Z_Param_ProductIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFinishProduction) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_QueueIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->FinishProduction(Z_Param_QueueIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartProduction) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_ProductClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartProduction(Z_Param_ProductClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsProducing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsProducing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetRemainingProductionTime) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_QueueIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetRemainingProductionTime(Z_Param_QueueIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetProgressPercentage) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_QueueIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetProgressPercentage(Z_Param_QueueIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetProductionTimeForProduct) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_ProductClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetProductionTimeForProduct(Z_Param_ProductClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetProductionTime) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_QueueIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetProductionTime(Z_Param_QueueIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentProduction) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_QueueIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TSubclassOf<AActor> *)Z_Param__Result=this->GetCurrentProduction(Z_Param_QueueIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindQueueForProduct) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_ProductClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->FindQueueForProduct(Z_Param_ProductClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCanAssignProduction) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_ProductClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanAssignProduction(Z_Param_ProductClass); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCancelProduction) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_QueueIndex); \
		P_GET_PROPERTY(UIntProperty,Z_Param_ProductIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CancelProduction(Z_Param_QueueIndex,Z_Param_ProductIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFinishProduction) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_QueueIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->FinishProduction(Z_Param_QueueIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartProduction) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_ProductClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->StartProduction(Z_Param_ProductClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsProducing) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->IsProducing(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetRemainingProductionTime) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_QueueIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetRemainingProductionTime(Z_Param_QueueIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetProgressPercentage) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_QueueIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetProgressPercentage(Z_Param_QueueIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetProductionTimeForProduct) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_ProductClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetProductionTimeForProduct(Z_Param_ProductClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetProductionTime) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_QueueIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetProductionTime(Z_Param_QueueIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentProduction) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_QueueIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TSubclassOf<AActor> *)Z_Param__Result=this->GetCurrentProduction(Z_Param_QueueIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execFindQueueForProduct) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_ProductClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->FindQueueForProduct(Z_Param_ProductClass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCanAssignProduction) \
	{ \
		P_GET_OBJECT(UClass,Z_Param_ProductClass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->CanAssignProduction(Z_Param_ProductClass); \
		P_NATIVE_END; \
	}


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURTSProductionComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSProductionComponent(); \
public: \
	DECLARE_CLASS(URTSProductionComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSProductionComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_INCLASS \
private: \
	static void StaticRegisterNativesURTSProductionComponent(); \
	friend RTSPLUGIN_API class UClass* Z_Construct_UClass_URTSProductionComponent(); \
public: \
	DECLARE_CLASS(URTSProductionComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/RTSPlugin"), NO_API) \
	DECLARE_SERIALIZER(URTSProductionComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URTSProductionComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSProductionComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSProductionComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSProductionComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSProductionComponent(URTSProductionComponent&&); \
	NO_API URTSProductionComponent(const URTSProductionComponent&); \
public:


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URTSProductionComponent(URTSProductionComponent&&); \
	NO_API URTSProductionComponent(const URTSProductionComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URTSProductionComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URTSProductionComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URTSProductionComponent)


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_PRIVATE_PROPERTY_OFFSET
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_20_PROLOG
#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_RPC_WRAPPERS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_INCLASS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_PRIVATE_PROPERTY_OFFSET \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_INCLASS_NO_PURE_DECLS \
	TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TD2020_Plugins_RTSPlugin_Source_RTSPlugin_Classes_RTSProductionComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
