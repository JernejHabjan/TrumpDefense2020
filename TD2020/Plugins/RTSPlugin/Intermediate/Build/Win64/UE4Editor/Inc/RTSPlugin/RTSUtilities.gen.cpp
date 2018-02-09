// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSUtilities.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSUtilities() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSUtilities_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSUtilities();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_FindDefaultComponentByClass();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_GetActorCollisionHeight();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_GetActorCollisionSize();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_GetActorDistance();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_GetCollisionHeight();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_GetCollisionSize();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_GetGroundLocation();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_GetShapeCollisionHeight();
	ENGINE_API UClass* Z_Construct_UClass_UShapeComponent_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_GetShapeCollisionSize();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_IsAIUnit();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_IsReadyToUse();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_IsSuitableLocationForActor();
	ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSUtilities_OwnerMeetsAllRequirementsFor();
// End Cross Module References
	void URTSUtilities::StaticRegisterNativesURTSUtilities()
	{
		UClass* Class = URTSUtilities::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FindDefaultComponentByClass", (Native)&URTSUtilities::execFindDefaultComponentByClass },
			{ "GetActorCollisionHeight", (Native)&URTSUtilities::execGetActorCollisionHeight },
			{ "GetActorCollisionSize", (Native)&URTSUtilities::execGetActorCollisionSize },
			{ "GetActorDistance", (Native)&URTSUtilities::execGetActorDistance },
			{ "GetCollisionHeight", (Native)&URTSUtilities::execGetCollisionHeight },
			{ "GetCollisionSize", (Native)&URTSUtilities::execGetCollisionSize },
			{ "GetGroundLocation", (Native)&URTSUtilities::execGetGroundLocation },
			{ "GetShapeCollisionHeight", (Native)&URTSUtilities::execGetShapeCollisionHeight },
			{ "GetShapeCollisionSize", (Native)&URTSUtilities::execGetShapeCollisionSize },
			{ "IsAIUnit", (Native)&URTSUtilities::execIsAIUnit },
			{ "IsReadyToUse", (Native)&URTSUtilities::execIsReadyToUse },
			{ "IsSuitableLocationForActor", (Native)&URTSUtilities::execIsSuitableLocationForActor },
			{ "OwnerMeetsAllRequirementsFor", (Native)&URTSUtilities::execOwnerMeetsAllRequirementsFor },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_FindDefaultComponentByClass()
	{
		struct RTSUtilities_eventFindDefaultComponentByClass_Parms
		{
			const TSubclassOf<AActor>  InActorClass;
			const TSubclassOf<UActorComponent>  InComponentClass;
			UActorComponent* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080588, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventFindDefaultComponentByClass_Parms, ReturnValue), Z_Construct_UClass_UActorComponent_NoRegister, METADATA_PARAMS(NewProp_ReturnValue_MetaData, ARRAY_COUNT(NewProp_ReturnValue_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InComponentClass_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_InComponentClass = { UE4CodeGen_Private::EPropertyClass::Class, "InComponentClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000082, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventFindDefaultComponentByClass_Parms, InComponentClass), Z_Construct_UClass_UActorComponent_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_InComponentClass_MetaData, ARRAY_COUNT(NewProp_InComponentClass_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InActorClass_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_InActorClass = { UE4CodeGen_Private::EPropertyClass::Class, "InActorClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000082, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventFindDefaultComponentByClass_Parms, InActorClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_InActorClass_MetaData, ARRAY_COUNT(NewProp_InActorClass_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InComponentClass,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InActorClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Searches the components attached to the specified actor class and returns the first encountered component of the specified class." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "FindDefaultComponentByClass", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(RTSUtilities_eventFindDefaultComponentByClass_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_GetActorCollisionHeight()
	{
		struct RTSUtilities_eventGetActorCollisionHeight_Parms
		{
			AActor* Actor;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetActorCollisionHeight_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetActorCollisionHeight_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Actor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Gets the approximated collision height of the specified actor." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "GetActorCollisionHeight", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(RTSUtilities_eventGetActorCollisionHeight_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_GetActorCollisionSize()
	{
		struct RTSUtilities_eventGetActorCollisionSize_Parms
		{
			AActor* Actor;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetActorCollisionSize_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetActorCollisionSize_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Actor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Gets the approximated collision size of the specified actor." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "GetActorCollisionSize", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(RTSUtilities_eventGetActorCollisionSize_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_GetActorDistance()
	{
		struct RTSUtilities_eventGetActorDistance_Parms
		{
			AActor* First;
			AActor* Second;
			bool bConsiderCollisionSize;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetActorDistance_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			auto NewProp_bConsiderCollisionSize_SetBit = [](void* Obj){ ((RTSUtilities_eventGetActorDistance_Parms*)Obj)->bConsiderCollisionSize = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bConsiderCollisionSize = { UE4CodeGen_Private::EPropertyClass::Bool, "bConsiderCollisionSize", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSUtilities_eventGetActorDistance_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bConsiderCollisionSize_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Second = { UE4CodeGen_Private::EPropertyClass::Object, "Second", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetActorDistance_Parms, Second), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_First = { UE4CodeGen_Private::EPropertyClass::Object, "First", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetActorDistance_Parms, First), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bConsiderCollisionSize,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Second,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_First,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Gets the distance between the two specified actors, optionally subtracting their collision sizes." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "GetActorDistance", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(RTSUtilities_eventGetActorDistance_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_GetCollisionHeight()
	{
		struct RTSUtilities_eventGetCollisionHeight_Parms
		{
			TSubclassOf<AActor>  ActorClass;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetCollisionHeight_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ActorClass = { UE4CodeGen_Private::EPropertyClass::Class, "ActorClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetCollisionHeight_Parms, ActorClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ActorClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Gets the approximated collision height of actors of the specified class." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "GetCollisionHeight", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(RTSUtilities_eventGetCollisionHeight_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_GetCollisionSize()
	{
		struct RTSUtilities_eventGetCollisionSize_Parms
		{
			TSubclassOf<AActor>  ActorClass;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetCollisionSize_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ActorClass = { UE4CodeGen_Private::EPropertyClass::Class, "ActorClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetCollisionSize_Parms, ActorClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ActorClass,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Gets the approximated collision size of actors of the specified class." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "GetCollisionSize", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(RTSUtilities_eventGetCollisionSize_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_GetGroundLocation()
	{
		struct RTSUtilities_eventGetGroundLocation_Parms
		{
			UObject* WorldContextObject;
			FVector Location;
			FVector ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetGroundLocation_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location = { UE4CodeGen_Private::EPropertyClass::Struct, "Location", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetGroundLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetGroundLocation_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Location,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WorldContextObject,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Casts a ray to determine the z coordinate of the specified location on ground level." },
				{ "WorldContext", "WorldContextObject" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "GetGroundLocation", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14822401, sizeof(RTSUtilities_eventGetGroundLocation_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_GetShapeCollisionHeight()
	{
		struct RTSUtilities_eventGetShapeCollisionHeight_Parms
		{
			UShapeComponent* ShapeComponent;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetShapeCollisionHeight_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShapeComponent_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShapeComponent = { UE4CodeGen_Private::EPropertyClass::Object, "ShapeComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetShapeCollisionHeight_Parms, ShapeComponent), Z_Construct_UClass_UShapeComponent_NoRegister, METADATA_PARAMS(NewProp_ShapeComponent_MetaData, ARRAY_COUNT(NewProp_ShapeComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ShapeComponent,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Gets the approximated collision height of the specified shape." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "GetShapeCollisionHeight", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(RTSUtilities_eventGetShapeCollisionHeight_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_GetShapeCollisionSize()
	{
		struct RTSUtilities_eventGetShapeCollisionSize_Parms
		{
			UShapeComponent* ShapeComponent;
			float ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetShapeCollisionSize_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShapeComponent_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShapeComponent = { UE4CodeGen_Private::EPropertyClass::Object, "ShapeComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventGetShapeCollisionSize_Parms, ShapeComponent), Z_Construct_UClass_UShapeComponent_NoRegister, METADATA_PARAMS(NewProp_ShapeComponent_MetaData, ARRAY_COUNT(NewProp_ShapeComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ShapeComponent,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Gets the approximated collision size of the specified shape." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "GetShapeCollisionSize", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(RTSUtilities_eventGetShapeCollisionSize_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_IsAIUnit()
	{
		struct RTSUtilities_eventIsAIUnit_Parms
		{
			AActor* Actor;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSUtilities_eventIsAIUnit_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSUtilities_eventIsAIUnit_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventIsAIUnit_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Actor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Checks whether the specified actor is owned by an AI player." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "IsAIUnit", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(RTSUtilities_eventIsAIUnit_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_IsReadyToUse()
	{
		struct RTSUtilities_eventIsReadyToUse_Parms
		{
			AActor* Actor;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSUtilities_eventIsReadyToUse_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSUtilities_eventIsReadyToUse_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventIsReadyToUse_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Actor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Checks whether the specified actor is ready to use (e.g. finished construction)." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "IsReadyToUse", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14022401, sizeof(RTSUtilities_eventIsReadyToUse_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_IsSuitableLocationForActor()
	{
		struct RTSUtilities_eventIsSuitableLocationForActor_Parms
		{
			UWorld* World;
			TSubclassOf<AActor>  ActorClass;
			FVector Location;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSUtilities_eventIsSuitableLocationForActor_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSUtilities_eventIsSuitableLocationForActor_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location = { UE4CodeGen_Private::EPropertyClass::Struct, "Location", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventIsSuitableLocationForActor_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(NewProp_Location_MetaData, ARRAY_COUNT(NewProp_Location_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ActorClass = { UE4CodeGen_Private::EPropertyClass::Class, "ActorClass", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventIsSuitableLocationForActor_Parms, ActorClass), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_World = { UE4CodeGen_Private::EPropertyClass::Object, "World", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventIsSuitableLocationForActor_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Location,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ActorClass,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_World,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Checks whether the specified actor can be placed at the passed location." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "IsSuitableLocationForActor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C22401, sizeof(RTSUtilities_eventIsSuitableLocationForActor_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSUtilities_OwnerMeetsAllRequirementsFor()
	{
		struct RTSUtilities_eventOwnerMeetsAllRequirementsFor_Parms
		{
			UObject* WorldContextObject;
			AActor* OwnedActor;
			TSubclassOf<AActor>  DesiredProduct;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSUtilities_eventOwnerMeetsAllRequirementsFor_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSUtilities_eventOwnerMeetsAllRequirementsFor_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_DesiredProduct = { UE4CodeGen_Private::EPropertyClass::Class, "DesiredProduct", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventOwnerMeetsAllRequirementsFor_Parms, DesiredProduct), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OwnedActor = { UE4CodeGen_Private::EPropertyClass::Object, "OwnedActor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventOwnerMeetsAllRequirementsFor_Parms, OwnedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject = { UE4CodeGen_Private::EPropertyClass::Object, "WorldContextObject", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSUtilities_eventOwnerMeetsAllRequirementsFor_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DesiredProduct,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OwnedActor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WorldContextObject,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Checks if the owner of the specified actor meets all requirements for producing the desired new actor." },
				{ "WorldContext", "WorldContextObject" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSUtilities, "OwnerMeetsAllRequirementsFor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(RTSUtilities_eventOwnerMeetsAllRequirementsFor_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URTSUtilities_NoRegister()
	{
		return URTSUtilities::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSUtilities()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URTSUtilities_FindDefaultComponentByClass, "FindDefaultComponentByClass" }, // 976877611
				{ &Z_Construct_UFunction_URTSUtilities_GetActorCollisionHeight, "GetActorCollisionHeight" }, // 1866357791
				{ &Z_Construct_UFunction_URTSUtilities_GetActorCollisionSize, "GetActorCollisionSize" }, // 2761787259
				{ &Z_Construct_UFunction_URTSUtilities_GetActorDistance, "GetActorDistance" }, // 1381257236
				{ &Z_Construct_UFunction_URTSUtilities_GetCollisionHeight, "GetCollisionHeight" }, // 3938213668
				{ &Z_Construct_UFunction_URTSUtilities_GetCollisionSize, "GetCollisionSize" }, // 4167818446
				{ &Z_Construct_UFunction_URTSUtilities_GetGroundLocation, "GetGroundLocation" }, // 1973296158
				{ &Z_Construct_UFunction_URTSUtilities_GetShapeCollisionHeight, "GetShapeCollisionHeight" }, // 2586016158
				{ &Z_Construct_UFunction_URTSUtilities_GetShapeCollisionSize, "GetShapeCollisionSize" }, // 3551381177
				{ &Z_Construct_UFunction_URTSUtilities_IsAIUnit, "IsAIUnit" }, // 138184502
				{ &Z_Construct_UFunction_URTSUtilities_IsReadyToUse, "IsReadyToUse" }, // 285530747
				{ &Z_Construct_UFunction_URTSUtilities_IsSuitableLocationForActor, "IsSuitableLocationForActor" }, // 4291279807
				{ &Z_Construct_UFunction_URTSUtilities_OwnerMeetsAllRequirementsFor, "OwnerMeetsAllRequirementsFor" }, // 2301020491
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "RTSUtilities.h" },
				{ "ModuleRelativePath", "Classes/RTSUtilities.h" },
				{ "ToolTip", "Various utility functions." },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSUtilities>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSUtilities::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URTSUtilities, 3721065541);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSUtilities(Z_Construct_UClass_URTSUtilities, &URTSUtilities::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSUtilities"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSUtilities);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
