// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSProjectile.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSProjectile() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSProjectile_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSProjectile();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSProjectile_FireAt();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSProjectile_ReceiveOnProjectileDetonated();
	ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
// End Cross Module References
	static FName NAME_ARTSProjectile_ReceiveOnProjectileDetonated = FName(TEXT("ReceiveOnProjectileDetonated"));
	void ARTSProjectile::ReceiveOnProjectileDetonated(AActor* ProjectileTarget, float ProjectileDamage, TSubclassOf<UDamageType>  ProjectileDamageType, AController* ProjectileInstigator, AActor* ProjectileDamageCauser)
	{
		RTSProjectile_eventReceiveOnProjectileDetonated_Parms Parms;
		Parms.ProjectileTarget=ProjectileTarget;
		Parms.ProjectileDamage=ProjectileDamage;
		Parms.ProjectileDamageType=ProjectileDamageType;
		Parms.ProjectileInstigator=ProjectileInstigator;
		Parms.ProjectileDamageCauser=ProjectileDamageCauser;
		ProcessEvent(FindFunctionChecked(NAME_ARTSProjectile_ReceiveOnProjectileDetonated),&Parms);
	}
	void ARTSProjectile::StaticRegisterNativesARTSProjectile()
	{
		UClass* Class = ARTSProjectile::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FireAt", (Native)&ARTSProjectile::execFireAt },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ARTSProjectile_FireAt()
	{
		struct RTSProjectile_eventFireAt_Parms
		{
			AActor* ProjectileTarget;
			float ProjectileDamage;
			TSubclassOf<UDamageType>  ProjectileDamageType;
			AController* ProjectileInstigator;
			AActor* ProjectileDamageCauser;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileDamageCauser = { UE4CodeGen_Private::EPropertyClass::Object, "ProjectileDamageCauser", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProjectile_eventFireAt_Parms, ProjectileDamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileInstigator = { UE4CodeGen_Private::EPropertyClass::Object, "ProjectileInstigator", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProjectile_eventFireAt_Parms, ProjectileInstigator), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProjectileDamageType = { UE4CodeGen_Private::EPropertyClass::Class, "ProjectileDamageType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSProjectile_eventFireAt_Parms, ProjectileDamageType), Z_Construct_UClass_UDamageType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ProjectileDamage = { UE4CodeGen_Private::EPropertyClass::Float, "ProjectileDamage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProjectile_eventFireAt_Parms, ProjectileDamage), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileTarget = { UE4CodeGen_Private::EPropertyClass::Object, "ProjectileTarget", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProjectile_eventFireAt_Parms, ProjectileTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileDamageCauser,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileInstigator,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileDamageType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileDamage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileTarget,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSProjectile.h" },
				{ "ToolTip", "Locks on to the specified target, dealing damage on impact." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSProjectile, "FireAt", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSProjectile_eventFireAt_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSProjectile_ReceiveOnProjectileDetonated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileDamageCauser = { UE4CodeGen_Private::EPropertyClass::Object, "ProjectileDamageCauser", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProjectile_eventReceiveOnProjectileDetonated_Parms, ProjectileDamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileInstigator = { UE4CodeGen_Private::EPropertyClass::Object, "ProjectileInstigator", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProjectile_eventReceiveOnProjectileDetonated_Parms, ProjectileInstigator), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProjectileDamageType = { UE4CodeGen_Private::EPropertyClass::Class, "ProjectileDamageType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(RTSProjectile_eventReceiveOnProjectileDetonated_Parms, ProjectileDamageType), Z_Construct_UClass_UDamageType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ProjectileDamage = { UE4CodeGen_Private::EPropertyClass::Float, "ProjectileDamage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProjectile_eventReceiveOnProjectileDetonated_Parms, ProjectileDamage), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileTarget = { UE4CodeGen_Private::EPropertyClass::Object, "ProjectileTarget", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSProjectile_eventReceiveOnProjectileDetonated_Parms, ProjectileTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileDamageCauser,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileInstigator,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileDamageType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileDamage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileTarget,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "DisplayName", "OnProjectileDetonated" },
				{ "ModuleRelativePath", "Classes/RTSProjectile.h" },
				{ "ToolTip", "Event when this projectile hits its target." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSProjectile, "ReceiveOnProjectileDetonated", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(RTSProjectile_eventReceiveOnProjectileDetonated_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARTSProjectile_NoRegister()
	{
		return ARTSProjectile::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSProjectile()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ARTSProjectile_FireAt, "FireAt" }, // 1680579773
				{ &Z_Construct_UFunction_ARTSProjectile_ReceiveOnProjectileDetonated, "ReceiveOnProjectileDetonated" }, // 2535950003
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "RTSProjectile.h" },
				{ "ModuleRelativePath", "Classes/RTSProjectile.h" },
				{ "ToolTip", "Projectile with RTS features, such as following a target and dealing damage." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovement_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "RTSProjectile" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Classes/RTSProjectile.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovement = { UE4CodeGen_Private::EPropertyClass::Object, "ProjectileMovement", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(ARTSProjectile, ProjectileMovement), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(NewProp_ProjectileMovement_MetaData, ARRAY_COUNT(NewProp_ProjectileMovement_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProjectileMovement,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSProjectile>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSProjectile::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
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
	IMPLEMENT_CLASS(ARTSProjectile, 4222831694);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSProjectile(Z_Construct_UClass_ARTSProjectile, &ARTSProjectile::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSProjectile"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSProjectile);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
