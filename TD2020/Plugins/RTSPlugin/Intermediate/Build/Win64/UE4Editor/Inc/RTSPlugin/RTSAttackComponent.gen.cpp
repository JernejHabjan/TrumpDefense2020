// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSAttackComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSAttackComponent() {}
// Cross Module References
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSAttackComponentAttackedUsedSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSProjectile_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	RTSPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FRTSAttackData();
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSAttackComponentCooldownReadySignature__DelegateSignature();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSAttackComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSAttackComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSAttackComponent_UseAttack();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSAttackComponentAttackedUsedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSAttackComponentAttackedUsedSignature_Parms
		{
			FRTSAttackData Attack;
			AActor* Target;
			ARTSProjectile* Projectile;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Projectile = { UE4CodeGen_Private::EPropertyClass::Object, "Projectile", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSAttackComponentAttackedUsedSignature_Parms, Projectile), Z_Construct_UClass_ARTSProjectile_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Target = { UE4CodeGen_Private::EPropertyClass::Object, "Target", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSAttackComponentAttackedUsedSignature_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Attack_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Attack = { UE4CodeGen_Private::EPropertyClass::Struct, "Attack", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSAttackComponentAttackedUsedSignature_Parms, Attack), Z_Construct_UScriptStruct_FRTSAttackData, METADATA_PARAMS(NewProp_Attack_MetaData, ARRAY_COUNT(NewProp_Attack_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Projectile,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Target,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Attack,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSAttackComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSAttackComponentAttackedUsedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSAttackComponentAttackedUsedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSAttackComponentCooldownReadySignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSAttackComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSAttackComponentCooldownReadySignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	void URTSAttackComponent::StaticRegisterNativesURTSAttackComponent()
	{
		UClass* Class = URTSAttackComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UseAttack", (Native)&URTSAttackComponent::execUseAttack },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URTSAttackComponent_UseAttack()
	{
		struct RTSAttackComponent_eventUseAttack_Parms
		{
			int32 AttackIndex;
			AActor* Target;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Target = { UE4CodeGen_Private::EPropertyClass::Object, "Target", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSAttackComponent_eventUseAttack_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_AttackIndex = { UE4CodeGen_Private::EPropertyClass::Int, "AttackIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSAttackComponent_eventUseAttack_Parms, AttackIndex), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Target,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AttackIndex,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSAttackComponent.h" },
				{ "ToolTip", "Uses the passed attack on the specified target and starts the cooldown timer." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSAttackComponent, "UseAttack", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSAttackComponent_eventUseAttack_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URTSAttackComponent_NoRegister()
	{
		return URTSAttackComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSAttackComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URTSAttackComponent_UseAttack, "UseAttack" }, // 2418283418
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "IncludePath", "RTSAttackComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSAttackComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Adds one or more attacks to the actor.\nThese can also be used for healing." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnAttackUsed_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSAttackComponent.h" },
				{ "ToolTip", "Event when an actor has used an attack." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAttackUsed = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnAttackUsed", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSAttackComponent, OnAttackUsed), Z_Construct_UDelegateFunction_RTSPlugin_RTSAttackComponentAttackedUsedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnAttackUsed_MetaData, ARRAY_COUNT(NewProp_OnAttackUsed_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnCooldownReady_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSAttackComponent.h" },
				{ "ToolTip", "Event when the attack cooldown has expired." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCooldownReady = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnCooldownReady", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSAttackComponent, OnCooldownReady), Z_Construct_UDelegateFunction_RTSPlugin_RTSAttackComponentCooldownReadySignature__DelegateSignature, METADATA_PARAMS(NewProp_OnCooldownReady_MetaData, ARRAY_COUNT(NewProp_OnCooldownReady_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RemainingCooldown_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSAttackComponent.h" },
				{ "ToolTip", "Time before the next attack can be used, in seconds. This is shared between attacks." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RemainingCooldown = { UE4CodeGen_Private::EPropertyClass::Float, "RemainingCooldown", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSAttackComponent, RemainingCooldown), METADATA_PARAMS(NewProp_RemainingCooldown_MetaData, ARRAY_COUNT(NewProp_RemainingCooldown_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Attacks_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSAttackComponent.h" },
				{ "ToolTip", "Attacks available for the actor. Different attacks might be used at different ranges, or against different types of targets." },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Attacks = { UE4CodeGen_Private::EPropertyClass::Array, "Attacks", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSAttackComponent, Attacks), METADATA_PARAMS(NewProp_Attacks_MetaData, ARRAY_COUNT(NewProp_Attacks_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Attacks_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Attacks", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FRTSAttackData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChaseRadius_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSAttackComponent.h" },
				{ "ToolTip", "Radius around the home location of the actor it won't leave when automatically attacking targets, in cm." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ChaseRadius = { UE4CodeGen_Private::EPropertyClass::Float, "ChaseRadius", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSAttackComponent, ChaseRadius), METADATA_PARAMS(NewProp_ChaseRadius_MetaData, ARRAY_COUNT(NewProp_ChaseRadius_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AcquisitionRadius_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSAttackComponent.h" },
				{ "ToolTip", "Radius in which the actor will automatically select and attack targets, in cm." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AcquisitionRadius = { UE4CodeGen_Private::EPropertyClass::Float, "AcquisitionRadius", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(URTSAttackComponent, AcquisitionRadius), METADATA_PARAMS(NewProp_AcquisitionRadius_MetaData, ARRAY_COUNT(NewProp_AcquisitionRadius_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnAttackUsed,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnCooldownReady,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RemainingCooldown,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Attacks,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Attacks_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ChaseRadius,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AcquisitionRadius,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSAttackComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSAttackComponent::StaticClass,
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
	IMPLEMENT_CLASS(URTSAttackComponent, 642061537);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSAttackComponent(Z_Construct_UClass_URTSAttackComponent, &URTSAttackComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSAttackComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSAttackComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
