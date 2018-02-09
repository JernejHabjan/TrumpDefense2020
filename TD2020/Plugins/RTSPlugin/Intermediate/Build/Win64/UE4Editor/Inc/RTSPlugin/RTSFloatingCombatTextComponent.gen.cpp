// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSFloatingCombatTextComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSFloatingCombatTextComponent() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSFloatingCombatTextComponent_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSFloatingCombatTextComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSFloatingCombatTextComponent_AddText();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
// End Cross Module References
	void URTSFloatingCombatTextComponent::StaticRegisterNativesURTSFloatingCombatTextComponent()
	{
		UClass* Class = URTSFloatingCombatTextComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddText", (Native)&URTSFloatingCombatTextComponent::execAddText },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URTSFloatingCombatTextComponent_AddText()
	{
		struct RTSFloatingCombatTextComponent_eventAddText_Parms
		{
			FString Text;
			FLinearColor Color;
			float Scale;
			float Lifetime;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Lifetime = { UE4CodeGen_Private::EPropertyClass::Float, "Lifetime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSFloatingCombatTextComponent_eventAddText_Parms, Lifetime), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Scale = { UE4CodeGen_Private::EPropertyClass::Float, "Scale", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSFloatingCombatTextComponent_eventAddText_Parms, Scale), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color = { UE4CodeGen_Private::EPropertyClass::Struct, "Color", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(RTSFloatingCombatTextComponent_eventAddText_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(NewProp_Color_MetaData, ARRAY_COUNT(NewProp_Color_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Text = { UE4CodeGen_Private::EPropertyClass::Str, "Text", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSFloatingCombatTextComponent_eventAddText_Parms, Text), METADATA_PARAMS(NewProp_Text_MetaData, ARRAY_COUNT(NewProp_Text_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Lifetime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Scale,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Color,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Text,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSFloatingCombatTextComponent.h" },
				{ "ToolTip", "Adds the specified text to be displayed above the actor in the HUD for a short time." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSFloatingCombatTextComponent, "AddText", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04C20401, sizeof(RTSFloatingCombatTextComponent_eventAddText_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URTSFloatingCombatTextComponent_NoRegister()
	{
		return URTSFloatingCombatTextComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSFloatingCombatTextComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UActorComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URTSFloatingCombatTextComponent_AddText, "AddText" }, // 141106320
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "IncludePath", "RTSFloatingCombatTextComponent.h" },
				{ "ModuleRelativePath", "Classes/RTSFloatingCombatTextComponent.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
				{ "ToolTip", "Stores floating texts to be displayed above the actor." },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSFloatingCombatTextComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSFloatingCombatTextComponent::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
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
	IMPLEMENT_CLASS(URTSFloatingCombatTextComponent, 893492284);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSFloatingCombatTextComponent(Z_Construct_UClass_URTSFloatingCombatTextComponent, &URTSFloatingCombatTextComponent::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSFloatingCombatTextComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSFloatingCombatTextComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
