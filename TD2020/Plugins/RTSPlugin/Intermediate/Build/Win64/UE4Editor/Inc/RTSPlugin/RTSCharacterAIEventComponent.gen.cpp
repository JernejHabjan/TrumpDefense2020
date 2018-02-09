// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSCharacterAIEventComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSCharacterAIEventComponent() {}
// Cross Module References
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSCharacterAIEventComponentOrderChangedSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UEnum* Z_Construct_UEnum_RTSPlugin_ERTSOrderType();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSCharacterAIEventComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSCharacterAIEventComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSCharacterAIEventComponentOrderChangedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSCharacterAIEventComponentOrderChangedSignature_Parms
		{
			ERTSOrderType NewOrder;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_NewOrder = { UE4CodeGen_Private::EPropertyClass::Enum, "NewOrder", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSCharacterAIEventComponentOrderChangedSignature_Parms, NewOrder), Z_Construct_UEnum_RTSPlugin_ERTSOrderType, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_NewOrder_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewOrder,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewOrder_Underlying,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSCharacterAIEventComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSCharacterAIEventComponentOrderChangedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSCharacterAIEventComponentOrderChangedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	void URTSCharacterAIEventComponent::StaticRegisterNativesURTSCharacterAIEventComponent()
	{
	}
	UClass* Z_Construct_UClass_URTSCharacterAIEventComponent_NoRegister()
	{
		return URTSCharacterAIEventComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSCharacterAIEventComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "IncludePath", "RTSCharacterAIEventComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSCharacterAIEventComponent.h" },
				{ "ToolTip", "Allows interested listeners to register for AI events (e.g. issued orders)." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnOrderChanged_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSCharacterAIEventComponent.h" },
				{ "ToolTip", "Event when the actor has received a new order." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnOrderChanged = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnOrderChanged", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSCharacterAIEventComponent, OnOrderChanged), Z_Construct_UDelegateFunction_RTSPlugin_RTSCharacterAIEventComponentOrderChangedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnOrderChanged_MetaData, ARRAY_COUNT(NewProp_OnOrderChanged_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnOrderChanged,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSCharacterAIEventComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSCharacterAIEventComponent::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
				nullptr, 0,
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
	IMPLEMENT_CLASS(URTSCharacterAIEventComponent, 728544638);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSCharacterAIEventComponent(Z_Construct_UClass_URTSCharacterAIEventComponent, &URTSCharacterAIEventComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSCharacterAIEventComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSCharacterAIEventComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
