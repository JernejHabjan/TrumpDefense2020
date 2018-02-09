// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSHUD() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSHUD_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSHUD_GetActorCenterOnScreen();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSHUD_GetActorSizeOnScreen();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSHUD_ReceiveDrawConstructionProgressBar();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSHUD_ReceiveDrawFloatingCombatText();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSHUD_ReceiveDrawHealthBar();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSHUD_ReceiveDrawHoveredActorEffect();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSHUD_ReceiveDrawProductionProgressBar();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_ARTSHUD_ReceiveDrawSelectionFrame();
// End Cross Module References
	static FName NAME_ARTSHUD_ReceiveDrawConstructionProgressBar = FName(TEXT("ReceiveDrawConstructionProgressBar"));
	void ARTSHUD::ReceiveDrawConstructionProgressBar(AActor* Actor, float ConstructionTime, float RemainingConstructionTime, float ProgressPercentage, float SuggestedProgressBarLeft, float SuggestedProgressBarTop, float SuggestedProgressBarWidth, float SuggestedProgressBarHeight)
	{
		RTSHUD_eventReceiveDrawConstructionProgressBar_Parms Parms;
		Parms.Actor=Actor;
		Parms.ConstructionTime=ConstructionTime;
		Parms.RemainingConstructionTime=RemainingConstructionTime;
		Parms.ProgressPercentage=ProgressPercentage;
		Parms.SuggestedProgressBarLeft=SuggestedProgressBarLeft;
		Parms.SuggestedProgressBarTop=SuggestedProgressBarTop;
		Parms.SuggestedProgressBarWidth=SuggestedProgressBarWidth;
		Parms.SuggestedProgressBarHeight=SuggestedProgressBarHeight;
		ProcessEvent(FindFunctionChecked(NAME_ARTSHUD_ReceiveDrawConstructionProgressBar),&Parms);
	}
	static FName NAME_ARTSHUD_ReceiveDrawFloatingCombatText = FName(TEXT("ReceiveDrawFloatingCombatText"));
	void ARTSHUD::ReceiveDrawFloatingCombatText(AActor* Actor, const FString& Text, FLinearColor const& Color, float Scale, float Lifetime, float RemainingLifetime, float LifetimePercentage, float SuggestedTextLeft, float SuggestedTextTop)
	{
		RTSHUD_eventReceiveDrawFloatingCombatText_Parms Parms;
		Parms.Actor=Actor;
		Parms.Text=Text;
		Parms.Color=Color;
		Parms.Scale=Scale;
		Parms.Lifetime=Lifetime;
		Parms.RemainingLifetime=RemainingLifetime;
		Parms.LifetimePercentage=LifetimePercentage;
		Parms.SuggestedTextLeft=SuggestedTextLeft;
		Parms.SuggestedTextTop=SuggestedTextTop;
		ProcessEvent(FindFunctionChecked(NAME_ARTSHUD_ReceiveDrawFloatingCombatText),&Parms);
	}
	static FName NAME_ARTSHUD_ReceiveDrawHealthBar = FName(TEXT("ReceiveDrawHealthBar"));
	void ARTSHUD::ReceiveDrawHealthBar(AActor* Actor, float CurrentHealth, float MaximumHealth, float HealthPercentage, float SuggestedHealthBarLeft, float SuggestedHealthBarTop, float SuggestedHealthBarWidth, float SuggestedHealthBarHeight)
	{
		RTSHUD_eventReceiveDrawHealthBar_Parms Parms;
		Parms.Actor=Actor;
		Parms.CurrentHealth=CurrentHealth;
		Parms.MaximumHealth=MaximumHealth;
		Parms.HealthPercentage=HealthPercentage;
		Parms.SuggestedHealthBarLeft=SuggestedHealthBarLeft;
		Parms.SuggestedHealthBarTop=SuggestedHealthBarTop;
		Parms.SuggestedHealthBarWidth=SuggestedHealthBarWidth;
		Parms.SuggestedHealthBarHeight=SuggestedHealthBarHeight;
		ProcessEvent(FindFunctionChecked(NAME_ARTSHUD_ReceiveDrawHealthBar),&Parms);
	}
	static FName NAME_ARTSHUD_ReceiveDrawHoveredActorEffect = FName(TEXT("ReceiveDrawHoveredActorEffect"));
	void ARTSHUD::ReceiveDrawHoveredActorEffect(AActor* HoveredActor)
	{
		RTSHUD_eventReceiveDrawHoveredActorEffect_Parms Parms;
		Parms.HoveredActor=HoveredActor;
		ProcessEvent(FindFunctionChecked(NAME_ARTSHUD_ReceiveDrawHoveredActorEffect),&Parms);
	}
	static FName NAME_ARTSHUD_ReceiveDrawProductionProgressBar = FName(TEXT("ReceiveDrawProductionProgressBar"));
	void ARTSHUD::ReceiveDrawProductionProgressBar(AActor* Actor, float ProductionTime, float RemainingProductionTime, float ProgressPercentage, float SuggestedProgressBarLeft, float SuggestedProgressBarTop, float SuggestedProgressBarWidth, float SuggestedProgressBarHeight)
	{
		RTSHUD_eventReceiveDrawProductionProgressBar_Parms Parms;
		Parms.Actor=Actor;
		Parms.ProductionTime=ProductionTime;
		Parms.RemainingProductionTime=RemainingProductionTime;
		Parms.ProgressPercentage=ProgressPercentage;
		Parms.SuggestedProgressBarLeft=SuggestedProgressBarLeft;
		Parms.SuggestedProgressBarTop=SuggestedProgressBarTop;
		Parms.SuggestedProgressBarWidth=SuggestedProgressBarWidth;
		Parms.SuggestedProgressBarHeight=SuggestedProgressBarHeight;
		ProcessEvent(FindFunctionChecked(NAME_ARTSHUD_ReceiveDrawProductionProgressBar),&Parms);
	}
	static FName NAME_ARTSHUD_ReceiveDrawSelectionFrame = FName(TEXT("ReceiveDrawSelectionFrame"));
	void ARTSHUD::ReceiveDrawSelectionFrame(float ScreenX, float ScreenY, float Width, float Height)
	{
		RTSHUD_eventReceiveDrawSelectionFrame_Parms Parms;
		Parms.ScreenX=ScreenX;
		Parms.ScreenY=ScreenY;
		Parms.Width=Width;
		Parms.Height=Height;
		ProcessEvent(FindFunctionChecked(NAME_ARTSHUD_ReceiveDrawSelectionFrame),&Parms);
	}
	void ARTSHUD::StaticRegisterNativesARTSHUD()
	{
		UClass* Class = ARTSHUD::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetActorCenterOnScreen", (Native)&ARTSHUD::execGetActorCenterOnScreen },
			{ "GetActorSizeOnScreen", (Native)&ARTSHUD::execGetActorSizeOnScreen },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ARTSHUD_GetActorCenterOnScreen()
	{
		struct RTSHUD_eventGetActorCenterOnScreen_Parms
		{
			AActor* Actor;
			FVector2D ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventGetActorCenterOnScreen_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventGetActorCenterOnScreen_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Actor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSHUD, "GetActorCenterOnScreen", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54820401, sizeof(RTSHUD_eventGetActorCenterOnScreen_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSHUD_GetActorSizeOnScreen()
	{
		struct RTSHUD_eventGetActorSizeOnScreen_Parms
		{
			AActor* Actor;
			FVector2D ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventGetActorSizeOnScreen_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventGetActorSizeOnScreen_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Actor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSHUD, "GetActorSizeOnScreen", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x54820401, sizeof(RTSHUD_eventGetActorSizeOnScreen_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSHUD_ReceiveDrawConstructionProgressBar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedProgressBarHeight = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedProgressBarHeight", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawConstructionProgressBar_Parms, SuggestedProgressBarHeight), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedProgressBarWidth = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedProgressBarWidth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawConstructionProgressBar_Parms, SuggestedProgressBarWidth), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedProgressBarTop = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedProgressBarTop", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawConstructionProgressBar_Parms, SuggestedProgressBarTop), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedProgressBarLeft = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedProgressBarLeft", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawConstructionProgressBar_Parms, SuggestedProgressBarLeft), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ProgressPercentage = { UE4CodeGen_Private::EPropertyClass::Float, "ProgressPercentage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawConstructionProgressBar_Parms, ProgressPercentage), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RemainingConstructionTime = { UE4CodeGen_Private::EPropertyClass::Float, "RemainingConstructionTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawConstructionProgressBar_Parms, RemainingConstructionTime), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ConstructionTime = { UE4CodeGen_Private::EPropertyClass::Float, "ConstructionTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawConstructionProgressBar_Parms, ConstructionTime), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawConstructionProgressBar_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedProgressBarHeight,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedProgressBarWidth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedProgressBarTop,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedProgressBarLeft,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProgressPercentage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RemainingConstructionTime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ConstructionTime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Actor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "DisplayName", "DrawConstructionProgressBar" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Event for drawing the construction progress bar for the specified unit." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSHUD, "ReceiveDrawConstructionProgressBar", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(RTSHUD_eventReceiveDrawConstructionProgressBar_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSHUD_ReceiveDrawFloatingCombatText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedTextTop = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedTextTop", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawFloatingCombatText_Parms, SuggestedTextTop), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedTextLeft = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedTextLeft", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawFloatingCombatText_Parms, SuggestedTextLeft), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LifetimePercentage = { UE4CodeGen_Private::EPropertyClass::Float, "LifetimePercentage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawFloatingCombatText_Parms, LifetimePercentage), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RemainingLifetime = { UE4CodeGen_Private::EPropertyClass::Float, "RemainingLifetime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawFloatingCombatText_Parms, RemainingLifetime), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Lifetime = { UE4CodeGen_Private::EPropertyClass::Float, "Lifetime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawFloatingCombatText_Parms, Lifetime), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Scale = { UE4CodeGen_Private::EPropertyClass::Float, "Scale", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawFloatingCombatText_Parms, Scale), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color = { UE4CodeGen_Private::EPropertyClass::Struct, "Color", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawFloatingCombatText_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(NewProp_Color_MetaData, ARRAY_COUNT(NewProp_Color_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_Text = { UE4CodeGen_Private::EPropertyClass::Str, "Text", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawFloatingCombatText_Parms, Text), METADATA_PARAMS(NewProp_Text_MetaData, ARRAY_COUNT(NewProp_Text_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawFloatingCombatText_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedTextTop,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedTextLeft,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_LifetimePercentage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RemainingLifetime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Lifetime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Scale,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Color,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Text,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Actor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "DisplayName", "DrawFloatingCombatText" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Event for drawaing a floating combat text." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSHUD, "ReceiveDrawFloatingCombatText", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08C20800, sizeof(RTSHUD_eventReceiveDrawFloatingCombatText_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSHUD_ReceiveDrawHealthBar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedHealthBarHeight = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedHealthBarHeight", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawHealthBar_Parms, SuggestedHealthBarHeight), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedHealthBarWidth = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedHealthBarWidth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawHealthBar_Parms, SuggestedHealthBarWidth), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedHealthBarTop = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedHealthBarTop", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawHealthBar_Parms, SuggestedHealthBarTop), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedHealthBarLeft = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedHealthBarLeft", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawHealthBar_Parms, SuggestedHealthBarLeft), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HealthPercentage = { UE4CodeGen_Private::EPropertyClass::Float, "HealthPercentage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawHealthBar_Parms, HealthPercentage), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaximumHealth = { UE4CodeGen_Private::EPropertyClass::Float, "MaximumHealth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawHealthBar_Parms, MaximumHealth), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentHealth = { UE4CodeGen_Private::EPropertyClass::Float, "CurrentHealth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawHealthBar_Parms, CurrentHealth), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawHealthBar_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedHealthBarHeight,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedHealthBarWidth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedHealthBarTop,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedHealthBarLeft,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HealthPercentage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaximumHealth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CurrentHealth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Actor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "DisplayName", "DrawHealthBar" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Event for drawing the health bar for the specified actor." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSHUD, "ReceiveDrawHealthBar", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(RTSHUD_eventReceiveDrawHealthBar_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSHUD_ReceiveDrawHoveredActorEffect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HoveredActor = { UE4CodeGen_Private::EPropertyClass::Object, "HoveredActor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawHoveredActorEffect_Parms, HoveredActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HoveredActor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "DisplayName", "DrawHoveredActorEffect" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Event for drawing an effect for the currently hovered actor." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSHUD, "ReceiveDrawHoveredActorEffect", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(RTSHUD_eventReceiveDrawHoveredActorEffect_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSHUD_ReceiveDrawProductionProgressBar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedProgressBarHeight = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedProgressBarHeight", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawProductionProgressBar_Parms, SuggestedProgressBarHeight), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedProgressBarWidth = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedProgressBarWidth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawProductionProgressBar_Parms, SuggestedProgressBarWidth), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedProgressBarTop = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedProgressBarTop", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawProductionProgressBar_Parms, SuggestedProgressBarTop), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SuggestedProgressBarLeft = { UE4CodeGen_Private::EPropertyClass::Float, "SuggestedProgressBarLeft", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawProductionProgressBar_Parms, SuggestedProgressBarLeft), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ProgressPercentage = { UE4CodeGen_Private::EPropertyClass::Float, "ProgressPercentage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawProductionProgressBar_Parms, ProgressPercentage), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RemainingProductionTime = { UE4CodeGen_Private::EPropertyClass::Float, "RemainingProductionTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawProductionProgressBar_Parms, RemainingProductionTime), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ProductionTime = { UE4CodeGen_Private::EPropertyClass::Float, "ProductionTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawProductionProgressBar_Parms, ProductionTime), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawProductionProgressBar_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedProgressBarHeight,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedProgressBarWidth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedProgressBarTop,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SuggestedProgressBarLeft,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProgressPercentage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RemainingProductionTime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ProductionTime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Actor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "DisplayName", "DrawProductionProgressBar" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Event for drawing the production progress bar for the specified unit." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSHUD, "ReceiveDrawProductionProgressBar", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(RTSHUD_eventReceiveDrawProductionProgressBar_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ARTSHUD_ReceiveDrawSelectionFrame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Height = { UE4CodeGen_Private::EPropertyClass::Float, "Height", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawSelectionFrame_Parms, Height), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Width = { UE4CodeGen_Private::EPropertyClass::Float, "Width", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawSelectionFrame_Parms, Width), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ScreenY = { UE4CodeGen_Private::EPropertyClass::Float, "ScreenY", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawSelectionFrame_Parms, ScreenY), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ScreenX = { UE4CodeGen_Private::EPropertyClass::Float, "ScreenX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSHUD_eventReceiveDrawSelectionFrame_Parms, ScreenX), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Height,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Width,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ScreenY,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ScreenX,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "DisplayName", "DrawSelectionFrame" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Event for drawing the selection frame because the mouse is being dragged." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ARTSHUD, "ReceiveDrawSelectionFrame", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(RTSHUD_eventReceiveDrawSelectionFrame_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ARTSHUD_NoRegister()
	{
		return ARTSHUD::StaticClass();
	}
	UClass* Z_Construct_UClass_ARTSHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AHUD,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ARTSHUD_GetActorCenterOnScreen, "GetActorCenterOnScreen" }, // 3169810744
				{ &Z_Construct_UFunction_ARTSHUD_GetActorSizeOnScreen, "GetActorSizeOnScreen" }, // 889408272
				{ &Z_Construct_UFunction_ARTSHUD_ReceiveDrawConstructionProgressBar, "ReceiveDrawConstructionProgressBar" }, // 1254779014
				{ &Z_Construct_UFunction_ARTSHUD_ReceiveDrawFloatingCombatText, "ReceiveDrawFloatingCombatText" }, // 1706622410
				{ &Z_Construct_UFunction_ARTSHUD_ReceiveDrawHealthBar, "ReceiveDrawHealthBar" }, // 1737361218
				{ &Z_Construct_UFunction_ARTSHUD_ReceiveDrawHoveredActorEffect, "ReceiveDrawHoveredActorEffect" }, // 2029434383
				{ &Z_Construct_UFunction_ARTSHUD_ReceiveDrawProductionProgressBar, "ReceiveDrawProductionProgressBar" }, // 328767542
				{ &Z_Construct_UFunction_ARTSHUD_ReceiveDrawSelectionFrame, "ReceiveDrawSelectionFrame" }, // 1182377135
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Rendering Actor Input Replication" },
				{ "IncludePath", "RTSHUD.h" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
				{ "ToolTip", "HUD with RTS features, such as showing a selection frame." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bFadeOutFloatingCombatTexts_MetaData[] = {
				{ "Category", "RTS|Floating Combat Texts" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to automatically adjust the alpha value of the color of floating combat texts depending on their elapsed lifetime." },
			};
#endif
			auto NewProp_bFadeOutFloatingCombatTexts_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bFadeOutFloatingCombatTexts = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFadeOutFloatingCombatTexts = { UE4CodeGen_Private::EPropertyClass::Bool, "bFadeOutFloatingCombatTexts", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bFadeOutFloatingCombatTexts_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bFadeOutFloatingCombatTexts_MetaData, ARRAY_COUNT(NewProp_bFadeOutFloatingCombatTexts_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FloatingCombatTextSpeed_MetaData[] = {
				{ "Category", "RTS|Floating Combat Texts" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "How many pixels the floating combat text should rise, per second." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FloatingCombatTextSpeed = { UE4CodeGen_Private::EPropertyClass::Float, "FloatingCombatTextSpeed", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ARTSHUD, FloatingCombatTextSpeed), METADATA_PARAMS(NewProp_FloatingCombatTextSpeed_MetaData, ARRAY_COUNT(NewProp_FloatingCombatTextSpeed_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowFloatingCombatTexts_MetaData[] = {
				{ "Category", "RTS|Floating Combat Texts" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to show floating combat texts above actors." },
			};
#endif
			auto NewProp_bShowFloatingCombatTexts_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bShowFloatingCombatTexts = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowFloatingCombatTexts = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowFloatingCombatTexts", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bShowFloatingCombatTexts_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bShowFloatingCombatTexts_MetaData, ARRAY_COUNT(NewProp_bShowFloatingCombatTexts_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowHotkeyProductionProgressBars_MetaData[] = {
				{ "Category", "RTS|Production Progress Bars" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to show production progress bars while the respective hotkey is pressed." },
			};
#endif
			auto NewProp_bShowHotkeyProductionProgressBars_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bShowHotkeyProductionProgressBars = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowHotkeyProductionProgressBars = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowHotkeyProductionProgressBars", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bShowHotkeyProductionProgressBars_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bShowHotkeyProductionProgressBars_MetaData, ARRAY_COUNT(NewProp_bShowHotkeyProductionProgressBars_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowSelectionProductionProgressBars_MetaData[] = {
				{ "Category", "RTS|Production Progress Bars" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to show production progress bars for selected units." },
			};
#endif
			auto NewProp_bShowSelectionProductionProgressBars_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bShowSelectionProductionProgressBars = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowSelectionProductionProgressBars = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowSelectionProductionProgressBars", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bShowSelectionProductionProgressBars_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bShowSelectionProductionProgressBars_MetaData, ARRAY_COUNT(NewProp_bShowSelectionProductionProgressBars_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowHoverProductionProgressBars_MetaData[] = {
				{ "Category", "RTS|Production Progress Bars" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to show production progress bars for hovered units." },
			};
#endif
			auto NewProp_bShowHoverProductionProgressBars_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bShowHoverProductionProgressBars = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowHoverProductionProgressBars = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowHoverProductionProgressBars", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bShowHoverProductionProgressBars_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bShowHoverProductionProgressBars_MetaData, ARRAY_COUNT(NewProp_bShowHoverProductionProgressBars_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAlwaysShowProductionProgressBars_MetaData[] = {
				{ "Category", "RTS|Production Progress Bars" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to always show all production progress bars." },
			};
#endif
			auto NewProp_bAlwaysShowProductionProgressBars_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bAlwaysShowProductionProgressBars = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAlwaysShowProductionProgressBars = { UE4CodeGen_Private::EPropertyClass::Bool, "bAlwaysShowProductionProgressBars", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bAlwaysShowProductionProgressBars_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bAlwaysShowProductionProgressBars_MetaData, ARRAY_COUNT(NewProp_bAlwaysShowProductionProgressBars_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowHotkeyConstructionProgressBars_MetaData[] = {
				{ "Category", "RTS|Construction Progress Bars" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to show construction progress bars while the respective hotkey is pressed." },
			};
#endif
			auto NewProp_bShowHotkeyConstructionProgressBars_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bShowHotkeyConstructionProgressBars = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowHotkeyConstructionProgressBars = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowHotkeyConstructionProgressBars", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bShowHotkeyConstructionProgressBars_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bShowHotkeyConstructionProgressBars_MetaData, ARRAY_COUNT(NewProp_bShowHotkeyConstructionProgressBars_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowSelectionConstructionProgressBars_MetaData[] = {
				{ "Category", "RTS|Construction Progress Bars" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to show construction progress bars for selected units." },
			};
#endif
			auto NewProp_bShowSelectionConstructionProgressBars_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bShowSelectionConstructionProgressBars = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowSelectionConstructionProgressBars = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowSelectionConstructionProgressBars", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bShowSelectionConstructionProgressBars_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bShowSelectionConstructionProgressBars_MetaData, ARRAY_COUNT(NewProp_bShowSelectionConstructionProgressBars_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowHoverConstructionProgressBars_MetaData[] = {
				{ "Category", "RTS|Construction Progress Bars" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to show construction progress bars for hovered units." },
			};
#endif
			auto NewProp_bShowHoverConstructionProgressBars_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bShowHoverConstructionProgressBars = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowHoverConstructionProgressBars = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowHoverConstructionProgressBars", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bShowHoverConstructionProgressBars_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bShowHoverConstructionProgressBars_MetaData, ARRAY_COUNT(NewProp_bShowHoverConstructionProgressBars_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAlwaysShowConstructionProgressBars_MetaData[] = {
				{ "Category", "RTS|Construction Progress Bars" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to always show all construction progress bars." },
			};
#endif
			auto NewProp_bAlwaysShowConstructionProgressBars_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bAlwaysShowConstructionProgressBars = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAlwaysShowConstructionProgressBars = { UE4CodeGen_Private::EPropertyClass::Bool, "bAlwaysShowConstructionProgressBars", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bAlwaysShowConstructionProgressBars_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bAlwaysShowConstructionProgressBars_MetaData, ARRAY_COUNT(NewProp_bAlwaysShowConstructionProgressBars_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowHotkeyHealthBars_MetaData[] = {
				{ "Category", "RTS|Health Bars" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to show health bars while the respective hotkey is pressed." },
			};
#endif
			auto NewProp_bShowHotkeyHealthBars_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bShowHotkeyHealthBars = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowHotkeyHealthBars = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowHotkeyHealthBars", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bShowHotkeyHealthBars_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bShowHotkeyHealthBars_MetaData, ARRAY_COUNT(NewProp_bShowHotkeyHealthBars_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowSelectionHealthBars_MetaData[] = {
				{ "Category", "RTS|Health Bars" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to show health bars for selected units." },
			};
#endif
			auto NewProp_bShowSelectionHealthBars_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bShowSelectionHealthBars = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowSelectionHealthBars = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowSelectionHealthBars", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bShowSelectionHealthBars_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bShowSelectionHealthBars_MetaData, ARRAY_COUNT(NewProp_bShowSelectionHealthBars_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowHoverHealthBars_MetaData[] = {
				{ "Category", "RTS|Health Bars" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to show health bars for hovered units." },
			};
#endif
			auto NewProp_bShowHoverHealthBars_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bShowHoverHealthBars = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowHoverHealthBars = { UE4CodeGen_Private::EPropertyClass::Bool, "bShowHoverHealthBars", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bShowHoverHealthBars_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bShowHoverHealthBars_MetaData, ARRAY_COUNT(NewProp_bShowHoverHealthBars_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAlwaysShowHealthBars_MetaData[] = {
				{ "Category", "RTS|Health Bars" },
				{ "ModuleRelativePath", "Classes/RTSHUD.h" },
				{ "ToolTip", "Whether to always show all health bars. You may expose this in your own Options window: Some professional players might want this for perfect micro-management." },
			};
#endif
			auto NewProp_bAlwaysShowHealthBars_SetBit = [](void* Obj){ ((ARTSHUD*)Obj)->bAlwaysShowHealthBars = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAlwaysShowHealthBars = { UE4CodeGen_Private::EPropertyClass::Bool, "bAlwaysShowHealthBars", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ARTSHUD), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bAlwaysShowHealthBars_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bAlwaysShowHealthBars_MetaData, ARRAY_COUNT(NewProp_bAlwaysShowHealthBars_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bFadeOutFloatingCombatTexts,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FloatingCombatTextSpeed,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bShowFloatingCombatTexts,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bShowHotkeyProductionProgressBars,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bShowSelectionProductionProgressBars,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bShowHoverProductionProgressBars,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bAlwaysShowProductionProgressBars,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bShowHotkeyConstructionProgressBars,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bShowSelectionConstructionProgressBars,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bShowHoverConstructionProgressBars,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bAlwaysShowConstructionProgressBars,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bShowHotkeyHealthBars,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bShowSelectionHealthBars,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bShowHoverHealthBars,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bAlwaysShowHealthBars,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ARTSHUD>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ARTSHUD::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x0090028Cu,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				"Game",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARTSHUD, 2815931212);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARTSHUD(Z_Construct_UClass_ARTSHUD, &ARTSHUD::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("ARTSHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARTSHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
