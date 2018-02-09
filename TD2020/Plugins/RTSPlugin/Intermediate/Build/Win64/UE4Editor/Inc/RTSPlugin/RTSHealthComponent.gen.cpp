// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSHealthComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSHealthComponent() {}
// Cross Module References
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSHealthComponentKilledSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSHealthComponentHealthChangedSignature__DelegateSignature();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSHealthComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSHealthComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSHealthComponentKilledSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSHealthComponentKilledSignature_Parms
		{
			AController* PreviousOwner;
			AActor* DamageCauser;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DamageCauser = { UE4CodeGen_Private::EPropertyClass::Object, "DamageCauser", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSHealthComponentKilledSignature_Parms, DamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PreviousOwner = { UE4CodeGen_Private::EPropertyClass::Object, "PreviousOwner", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSHealthComponentKilledSignature_Parms, PreviousOwner), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DamageCauser,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PreviousOwner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSHealthComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSHealthComponentKilledSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSHealthComponentKilledSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSHealthComponentHealthChangedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSHealthComponentHealthChangedSignature_Parms
		{
			float OldHealth;
			float NewHealth;
			AActor* DamageCauser;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DamageCauser = { UE4CodeGen_Private::EPropertyClass::Object, "DamageCauser", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSHealthComponentHealthChangedSignature_Parms, DamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewHealth = { UE4CodeGen_Private::EPropertyClass::Float, "NewHealth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSHealthComponentHealthChangedSignature_Parms, NewHealth), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OldHealth = { UE4CodeGen_Private::EPropertyClass::Float, "OldHealth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSHealthComponentHealthChangedSignature_Parms, OldHealth), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DamageCauser,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewHealth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OldHealth,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSHealthComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSHealthComponentHealthChangedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSHealthComponentHealthChangedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	void URTSHealthComponent::StaticRegisterNativesURTSHealthComponent()
	{
	}
	UClass* Z_Construct_UClass_URTSHealthComponent_NoRegister()
	{
		return URTSHealthComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSHealthComponent()
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
				{ "IncludePath", "RTSHealthComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSHealthComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Adds health to the actor, e.g. for taking damage and dying." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnKilled_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSHealthComponent.h" },
				{ "ToolTip", "Event when the actor has been killed." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnKilled = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnKilled", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSHealthComponent, OnKilled), Z_Construct_UDelegateFunction_RTSPlugin_RTSHealthComponentKilledSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnKilled_MetaData, ARRAY_COUNT(NewProp_OnKilled_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnHealthChanged_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSHealthComponent.h" },
				{ "ToolTip", "Event when the current health of the actor has changed." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHealthChanged = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnHealthChanged", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSHealthComponent, OnHealthChanged), Z_Construct_UDelegateFunction_RTSPlugin_RTSHealthComponentHealthChangedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnHealthChanged_MetaData, ARRAY_COUNT(NewProp_OnHealthChanged_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaximumHealth_MetaData[] = {
				{ "Category", "RTS" },
				{ "ClampMin", "0" },
				{ "ModuleRelativePath", "Classes/RTSHealthComponent.h" },
				{ "ToolTip", "Maximum health of the actor." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaximumHealth = { UE4CodeGen_Private::EPropertyClass::Float, "MaximumHealth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSHealthComponent, MaximumHealth), METADATA_PARAMS(NewProp_MaximumHealth_MetaData, ARRAY_COUNT(NewProp_MaximumHealth_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentHealth_MetaData[] = {
				{ "Category", "RTS" },
				{ "ClampMin", "0" },
				{ "ModuleRelativePath", "Classes/RTSHealthComponent.h" },
				{ "ToolTip", "Current health of the actor." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth = { UE4CodeGen_Private::EPropertyClass::Float, "CurrentHealth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000025, 1, nullptr, STRUCT_OFFSET(URTSHealthComponent, CurrentHealth), METADATA_PARAMS(NewProp_CurrentHealth_MetaData, ARRAY_COUNT(NewProp_CurrentHealth_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnKilled,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnHealthChanged,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaximumHealth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentHealth,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSHealthComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSHealthComponent::StaticClass,
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
	IMPLEMENT_CLASS(URTSHealthComponent, 1967056596);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSHealthComponent(Z_Construct_UClass_URTSHealthComponent, &URTSHealthComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSHealthComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSHealthComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
