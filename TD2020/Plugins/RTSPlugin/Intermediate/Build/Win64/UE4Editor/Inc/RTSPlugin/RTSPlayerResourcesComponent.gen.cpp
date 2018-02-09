// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSPlayerResourcesComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSPlayerResourcesComponent() {}
// Cross Module References
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSPlayerResourcesComponentResourcesChangedSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSResourceType_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSPlayerResourcesComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSPlayerResourcesComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSPlayerResourcesComponent_ReceivedResourceAmounts();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSPlayerResourcesComponentResourcesChangedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSPlayerResourcesComponentResourcesChangedSignature_Parms
		{
			TSubclassOf<URTSResourceType>  ResourceType;
			float OldResourceAmount;
			float NewResourceAmount;
			bool bSyncedFromServer;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_bSyncedFromServer_SetBit = [](void* Obj){ ((_Script_RTSPlugin_eventRTSPlayerResourcesComponentResourcesChangedSignature_Parms*)Obj)->bSyncedFromServer = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSyncedFromServer = { UE4CodeGen_Private::EPropertyClass::Bool, "bSyncedFromServer", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(_Script_RTSPlugin_eventRTSPlayerResourcesComponentResourcesChangedSignature_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bSyncedFromServer_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewResourceAmount = { UE4CodeGen_Private::EPropertyClass::Float, "NewResourceAmount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSPlayerResourcesComponentResourcesChangedSignature_Parms, NewResourceAmount), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OldResourceAmount = { UE4CodeGen_Private::EPropertyClass::Float, "OldResourceAmount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSPlayerResourcesComponentResourcesChangedSignature_Parms, OldResourceAmount), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ResourceType = { UE4CodeGen_Private::EPropertyClass::Class, "ResourceType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSPlayerResourcesComponentResourcesChangedSignature_Parms, ResourceType), Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bSyncedFromServer,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewResourceAmount,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OldResourceAmount,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceType,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSPlayerResourcesComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSPlayerResourcesComponentResourcesChangedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSPlayerResourcesComponentResourcesChangedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	void URTSPlayerResourcesComponent::StaticRegisterNativesURTSPlayerResourcesComponent()
	{
		UClass* Class = URTSPlayerResourcesComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ReceivedResourceAmounts", (Native)&URTSPlayerResourcesComponent::execReceivedResourceAmounts },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URTSPlayerResourcesComponent_ReceivedResourceAmounts()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSPlayerResourcesComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSPlayerResourcesComponent, "ReceivedResourceAmounts", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URTSPlayerResourcesComponent_NoRegister()
	{
		return URTSPlayerResourcesComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSPlayerResourcesComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URTSPlayerResourcesComponent_ReceivedResourceAmounts, "ReceivedResourceAmounts" }, // 505345049
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "IncludePath", "RTSPlayerResourcesComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSPlayerResourcesComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Attach to player or AI controllers. Allows the controller to store resources." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnResourcesChanged_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSPlayerResourcesComponent.h" },
				{ "ToolTip", "Event when the current resource stock amount for the player has changed." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnResourcesChanged = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnResourcesChanged", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSPlayerResourcesComponent, OnResourcesChanged), Z_Construct_UDelegateFunction_RTSPlugin_RTSPlayerResourcesComponentResourcesChangedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnResourcesChanged_MetaData, ARRAY_COUNT(NewProp_OnResourcesChanged_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResourceTypes_MetaData[] = {
				{ "Category", "RTS|Resources" },
				{ "ModuleRelativePath", "Classes/RTSPlayerResourcesComponent.h" },
				{ "ToolTip", "Types of resources currently available to this player. Num must match ResourceAmounts. Need to use an array here instead of map for replication." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ResourceTypes = { UE4CodeGen_Private::EPropertyClass::Array, "ResourceTypes", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000025, 1, nullptr, STRUCT_OFFSET(URTSPlayerResourcesComponent, ResourceTypes), METADATA_PARAMS(NewProp_ResourceTypes_MetaData, ARRAY_COUNT(NewProp_ResourceTypes_MetaData)) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ResourceTypes_Inner = { UE4CodeGen_Private::EPropertyClass::Class, "ResourceTypes", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000000, 1, nullptr, 0, Z_Construct_UClass_URTSResourceType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResourceAmounts_MetaData[] = {
				{ "Category", "RTS|Resources" },
				{ "ModuleRelativePath", "Classes/RTSPlayerResourcesComponent.h" },
				{ "ToolTip", "Resources currently available to this player. Num must match ResourceTypes. Need to use an array here instead of map for replication." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ResourceAmounts = { UE4CodeGen_Private::EPropertyClass::Array, "ResourceAmounts", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000100000025, 1, "ReceivedResourceAmounts", STRUCT_OFFSET(URTSPlayerResourcesComponent, ResourceAmounts), METADATA_PARAMS(NewProp_ResourceAmounts_MetaData, ARRAY_COUNT(NewProp_ResourceAmounts_MetaData)) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ResourceAmounts_Inner = { UE4CodeGen_Private::EPropertyClass::Float, "ResourceAmounts", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnResourcesChanged,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceTypes,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceTypes_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceAmounts,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ResourceAmounts_Inner,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSPlayerResourcesComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSPlayerResourcesComponent::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(URTSPlayerResourcesComponent, 209571097);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSPlayerResourcesComponent(Z_Construct_UClass_URTSPlayerResourcesComponent, &URTSPlayerResourcesComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSPlayerResourcesComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSPlayerResourcesComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
