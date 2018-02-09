// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSOwnerComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSOwnerComponent() {}
// Cross Module References
	RTSPLUGIN_API UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSOwnerComponentOwnerChangedSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSOwnerComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSOwnerComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSOwnerComponent_GetPlayerOwner();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSPlayerState_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSOwnerComponent_IsSameTeamAsActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSOwnerComponent_IsSameTeamAsController();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSOwnerComponent_SetPlayerOwner();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_RTSPlugin_RTSOwnerComponentOwnerChangedSignature__DelegateSignature()
	{
		struct _Script_RTSPlugin_eventRTSOwnerComponentOwnerChangedSignature_Parms
		{
			AController* NewOwner;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NewOwner = { UE4CodeGen_Private::EPropertyClass::Object, "NewOwner", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_RTSPlugin_eventRTSOwnerComponentOwnerChangedSignature_Parms, NewOwner), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NewOwner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSOwnerComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_RTSPlugin, "RTSOwnerComponentOwnerChangedSignature__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_RTSPlugin_eventRTSOwnerComponentOwnerChangedSignature_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	void URTSOwnerComponent::StaticRegisterNativesURTSOwnerComponent()
	{
		UClass* Class = URTSOwnerComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetPlayerOwner", (Native)&URTSOwnerComponent::execGetPlayerOwner },
			{ "IsSameTeamAsActor", (Native)&URTSOwnerComponent::execIsSameTeamAsActor },
			{ "IsSameTeamAsController", (Native)&URTSOwnerComponent::execIsSameTeamAsController },
			{ "SetPlayerOwner", (Native)&URTSOwnerComponent::execSetPlayerOwner },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URTSOwnerComponent_GetPlayerOwner()
	{
		struct RTSOwnerComponent_eventGetPlayerOwner_Parms
		{
			ARTSPlayerState* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSOwnerComponent_eventGetPlayerOwner_Parms, ReturnValue), Z_Construct_UClass_ARTSPlayerState_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSOwnerComponent.h" },
				{ "ToolTip", "Gets the player owning the actor." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSOwnerComponent, "GetPlayerOwner", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSOwnerComponent_eventGetPlayerOwner_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSOwnerComponent_IsSameTeamAsActor()
	{
		struct RTSOwnerComponent_eventIsSameTeamAsActor_Parms
		{
			AActor* Other;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSOwnerComponent_eventIsSameTeamAsActor_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSOwnerComponent_eventIsSameTeamAsActor_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Other = { UE4CodeGen_Private::EPropertyClass::Object, "Other", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSOwnerComponent_eventIsSameTeamAsActor_Parms, Other), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Other,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSOwnerComponent.h" },
				{ "ToolTip", "Checks whether the actor belongs to the same team as the specified one." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSOwnerComponent, "IsSameTeamAsActor", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSOwnerComponent_eventIsSameTeamAsActor_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSOwnerComponent_IsSameTeamAsController()
	{
		struct RTSOwnerComponent_eventIsSameTeamAsController_Parms
		{
			AController* C;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((RTSOwnerComponent_eventIsSameTeamAsController_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(RTSOwnerComponent_eventIsSameTeamAsController_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_C = { UE4CodeGen_Private::EPropertyClass::Object, "C", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSOwnerComponent_eventIsSameTeamAsController_Parms, C), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_C,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSOwnerComponent.h" },
				{ "ToolTip", "Checks whether the player owning the actor belongs to the same team as the specified player." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSOwnerComponent, "IsSameTeamAsController", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSOwnerComponent_eventIsSameTeamAsController_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSOwnerComponent_SetPlayerOwner()
	{
		struct RTSOwnerComponent_eventSetPlayerOwner_Parms
		{
			AController* Controller;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Controller = { UE4CodeGen_Private::EPropertyClass::Object, "Controller", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSOwnerComponent_eventSetPlayerOwner_Parms, Controller), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Controller,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSOwnerComponent.h" },
				{ "ToolTip", "Sets the player owning the actor." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSOwnerComponent, "SetPlayerOwner", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSOwnerComponent_eventSetPlayerOwner_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URTSOwnerComponent_NoRegister()
	{
		return URTSOwnerComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSOwnerComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URTSOwnerComponent_GetPlayerOwner, "GetPlayerOwner" }, // 4061048039
				{ &Z_Construct_UFunction_URTSOwnerComponent_IsSameTeamAsActor, "IsSameTeamAsActor" }, // 2521911801
				{ &Z_Construct_UFunction_URTSOwnerComponent_IsSameTeamAsController, "IsSameTeamAsController" }, // 1519554545
				{ &Z_Construct_UFunction_URTSOwnerComponent_SetPlayerOwner, "SetPlayerOwner" }, // 3634399456
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "IncludePath", "RTSOwnerComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSOwnerComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Specifies the owning player of the actor." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerOwner_MetaData[] = {
				{ "ModuleRelativePath", "Classes/RTSOwnerComponent.h" },
				{ "ToolTip", "Player owning this actor." },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerOwner = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerOwner", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000020, 1, nullptr, STRUCT_OFFSET(URTSOwnerComponent, PlayerOwner), Z_Construct_UClass_ARTSPlayerState_NoRegister, METADATA_PARAMS(NewProp_PlayerOwner_MetaData, ARRAY_COUNT(NewProp_PlayerOwner_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnOwnerChanged_MetaData[] = {
				{ "Category", "RTS" },
				{ "ModuleRelativePath", "Classes/RTSOwnerComponent.h" },
				{ "ToolTip", "Event when the actor is owned by a different player." },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnOwnerChanged = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnOwnerChanged", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(URTSOwnerComponent, OnOwnerChanged), Z_Construct_UDelegateFunction_RTSPlugin_RTSOwnerComponentOwnerChangedSignature__DelegateSignature, METADATA_PARAMS(NewProp_OnOwnerChanged_MetaData, ARRAY_COUNT(NewProp_OnOwnerChanged_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PlayerOwner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnOwnerChanged,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSOwnerComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSOwnerComponent::StaticClass,
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
	IMPLEMENT_CLASS(URTSOwnerComponent, 3981891811);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSOwnerComponent(Z_Construct_UClass_URTSOwnerComponent, &URTSOwnerComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSOwnerComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSOwnerComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
