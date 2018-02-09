// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Classes/RTSPluginPCH.h"
#include "Classes/RTSMinimapWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTSMinimapWidget() {}
// Cross Module References
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSMinimapWidget_NoRegister();
	RTSPLUGIN_API UClass* Z_Construct_UClass_URTSMinimapWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_RTSPlugin();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSMinimapWidget_ReceiveOnDrawUnit();
	ENGINE_API UClass* Z_Construct_UClass_APlayerState_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UMG_API UScriptStruct* Z_Construct_UScriptStruct_FPaintContext();
	RTSPLUGIN_API UFunction* Z_Construct_UFunction_URTSMinimapWidget_SetupVisionInfo();
	RTSPLUGIN_API UClass* Z_Construct_UClass_ARTSVisionInfo_NoRegister();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
// End Cross Module References
	static FName NAME_URTSMinimapWidget_ReceiveOnDrawUnit = FName(TEXT("ReceiveOnDrawUnit"));
	void URTSMinimapWidget::ReceiveOnDrawUnit(FPaintContext& Context, AActor* Actor, APlayerState* ActorOwner, FVector2D const& MinimapPosition, APlayerState* LocalPlayer) const
	{
		RTSMinimapWidget_eventReceiveOnDrawUnit_Parms Parms;
		Parms.Context=Context;
		Parms.Actor=Actor;
		Parms.ActorOwner=ActorOwner;
		Parms.MinimapPosition=MinimapPosition;
		Parms.LocalPlayer=LocalPlayer;
		const_cast<URTSMinimapWidget*>(this)->ProcessEvent(FindFunctionChecked(NAME_URTSMinimapWidget_ReceiveOnDrawUnit),&Parms);
		Context=Parms.Context;
	}
	void URTSMinimapWidget::StaticRegisterNativesURTSMinimapWidget()
	{
		UClass* Class = URTSMinimapWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetupVisionInfo", (Native)&URTSMinimapWidget::execSetupVisionInfo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_URTSMinimapWidget_ReceiveOnDrawUnit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LocalPlayer = { UE4CodeGen_Private::EPropertyClass::Object, "LocalPlayer", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSMinimapWidget_eventReceiveOnDrawUnit_Parms, LocalPlayer), Z_Construct_UClass_APlayerState_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinimapPosition_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_MinimapPosition = { UE4CodeGen_Private::EPropertyClass::Struct, "MinimapPosition", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(RTSMinimapWidget_eventReceiveOnDrawUnit_Parms, MinimapPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(NewProp_MinimapPosition_MetaData, ARRAY_COUNT(NewProp_MinimapPosition_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorOwner = { UE4CodeGen_Private::EPropertyClass::Object, "ActorOwner", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSMinimapWidget_eventReceiveOnDrawUnit_Parms, ActorOwner), Z_Construct_UClass_APlayerState_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor = { UE4CodeGen_Private::EPropertyClass::Object, "Actor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSMinimapWidget_eventReceiveOnDrawUnit_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Context = { UE4CodeGen_Private::EPropertyClass::Struct, "Context", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000180, 1, nullptr, STRUCT_OFFSET(RTSMinimapWidget_eventReceiveOnDrawUnit_Parms, Context), Z_Construct_UScriptStruct_FPaintContext, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_LocalPlayer,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MinimapPosition,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ActorOwner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Actor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Context,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "RTS" },
				{ "DisplayName", "OnDrawUnit" },
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Event for custom drawing of units on the minimap (e.g. for drawing hero portraits for hero units)." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSMinimapWidget, "ReceiveOnDrawUnit", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x48C20800, sizeof(RTSMinimapWidget_eventReceiveOnDrawUnit_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_URTSMinimapWidget_SetupVisionInfo()
	{
		struct RTSMinimapWidget_eventSetupVisionInfo_Parms
		{
			ARTSVisionInfo* VisionInfo;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VisionInfo = { UE4CodeGen_Private::EPropertyClass::Object, "VisionInfo", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(RTSMinimapWidget_eventSetupVisionInfo_Parms, VisionInfo), Z_Construct_UClass_ARTSVisionInfo_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_VisionInfo,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Sets the vision info to draw on the minimap." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_URTSMinimapWidget, "SetupVisionInfo", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(RTSMinimapWidget_eventSetupVisionInfo_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_URTSMinimapWidget_NoRegister()
	{
		return URTSMinimapWidget::StaticClass();
	}
	UClass* Z_Construct_UClass_URTSMinimapWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UUserWidget,
				(UObject* (*)())Z_Construct_UPackage__Script_RTSPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_URTSMinimapWidget_ReceiveOnDrawUnit, "ReceiveOnDrawUnit" }, // 556134347
				{ &Z_Construct_UFunction_URTSMinimapWidget_SetupVisionInfo, "SetupVisionInfo" }, // 2156292693
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "IncludePath", "RTSMinimapWidget.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Widget for drawing a high-level overview of unit positions." },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDrawViewFrustum_MetaData[] = {
				{ "Category", "RTS|Camera" },
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Whether to show the current camera frustum on the minimap." },
			};
#endif
			auto NewProp_bDrawViewFrustum_SetBit = [](void* Obj){ ((URTSMinimapWidget*)Obj)->bDrawViewFrustum = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDrawViewFrustum = { UE4CodeGen_Private::EPropertyClass::Bool, "bDrawViewFrustum", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(URTSMinimapWidget), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bDrawViewFrustum_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bDrawViewFrustum_MetaData, ARRAY_COUNT(NewProp_bDrawViewFrustum_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDrawVision_MetaData[] = {
				{ "Category", "RTS|Vision" },
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Whether to draw vision on the minimap, with UnknownAreasBrush, KnownAreasBrush and VisibleAreasBrush." },
			};
#endif
			auto NewProp_bDrawVision_SetBit = [](void* Obj){ ((URTSMinimapWidget*)Obj)->bDrawVision = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDrawVision = { UE4CodeGen_Private::EPropertyClass::Bool, "bDrawVision", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(URTSMinimapWidget), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bDrawVision_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bDrawVision_MetaData, ARRAY_COUNT(NewProp_bDrawVision_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDrawUnitsWithTeamColors_MetaData[] = {
				{ "Category", "RTS|Units" },
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Whether to draw unit dots on the minimap, with OwnUnitsBrush, EnemyUnitsBrush and NeutralUnitsBrush." },
			};
#endif
			auto NewProp_bDrawUnitsWithTeamColors_SetBit = [](void* Obj){ ((URTSMinimapWidget*)Obj)->bDrawUnitsWithTeamColors = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDrawUnitsWithTeamColors = { UE4CodeGen_Private::EPropertyClass::Bool, "bDrawUnitsWithTeamColors", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(URTSMinimapWidget), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bDrawUnitsWithTeamColors_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bDrawUnitsWithTeamColors_MetaData, ARRAY_COUNT(NewProp_bDrawUnitsWithTeamColors_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDrawBackground_MetaData[] = {
				{ "Category", "RTS|Background" },
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Whether to draw the minimap background layer." },
			};
#endif
			auto NewProp_bDrawBackground_SetBit = [](void* Obj){ ((URTSMinimapWidget*)Obj)->bDrawBackground = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDrawBackground = { UE4CodeGen_Private::EPropertyClass::Bool, "bDrawBackground", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(URTSMinimapWidget), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bDrawBackground_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bDrawBackground_MetaData, ARRAY_COUNT(NewProp_bDrawBackground_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_KnownAreasBrush_MetaData[] = {
				{ "Category", "RTS|Vision" },
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Brush for drawing known but not visible areas on the minimap." },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_KnownAreasBrush = { UE4CodeGen_Private::EPropertyClass::Struct, "KnownAreasBrush", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(URTSMinimapWidget, KnownAreasBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(NewProp_KnownAreasBrush_MetaData, ARRAY_COUNT(NewProp_KnownAreasBrush_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UnknownAreasBrush_MetaData[] = {
				{ "Category", "RTS|Vision" },
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Brush for drawing unknown areas on the minimap." },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_UnknownAreasBrush = { UE4CodeGen_Private::EPropertyClass::Struct, "UnknownAreasBrush", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(URTSMinimapWidget, UnknownAreasBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(NewProp_UnknownAreasBrush_MetaData, ARRAY_COUNT(NewProp_UnknownAreasBrush_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NeutralUnitsBrush_MetaData[] = {
				{ "Category", "RTS|Units" },
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Brush for drawing neutral units on the minimap." },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_NeutralUnitsBrush = { UE4CodeGen_Private::EPropertyClass::Struct, "NeutralUnitsBrush", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(URTSMinimapWidget, NeutralUnitsBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(NewProp_NeutralUnitsBrush_MetaData, ARRAY_COUNT(NewProp_NeutralUnitsBrush_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnemyUnitsBrush_MetaData[] = {
				{ "Category", "RTS|Units" },
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Brush for drawing enemy units on the minimap." },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_EnemyUnitsBrush = { UE4CodeGen_Private::EPropertyClass::Struct, "EnemyUnitsBrush", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(URTSMinimapWidget, EnemyUnitsBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(NewProp_EnemyUnitsBrush_MetaData, ARRAY_COUNT(NewProp_EnemyUnitsBrush_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OwnUnitsBrush_MetaData[] = {
				{ "Category", "RTS|Units" },
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Brush for drawing own units on the minimap." },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_OwnUnitsBrush = { UE4CodeGen_Private::EPropertyClass::Struct, "OwnUnitsBrush", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(URTSMinimapWidget, OwnUnitsBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(NewProp_OwnUnitsBrush_MetaData, ARRAY_COUNT(NewProp_OwnUnitsBrush_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinimapBackground_MetaData[] = {
				{ "Category", "RTS|Background" },
				{ "ModuleRelativePath", "Classes/RTSMinimapWidget.h" },
				{ "ToolTip", "Brush for drawing the background of the current map." },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_MinimapBackground = { UE4CodeGen_Private::EPropertyClass::Struct, "MinimapBackground", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000015, 1, nullptr, STRUCT_OFFSET(URTSMinimapWidget, MinimapBackground), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(NewProp_MinimapBackground_MetaData, ARRAY_COUNT(NewProp_MinimapBackground_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bDrawViewFrustum,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bDrawVision,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bDrawUnitsWithTeamColors,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bDrawBackground,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_KnownAreasBrush,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_UnknownAreasBrush,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NeutralUnitsBrush,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_EnemyUnitsBrush,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OwnUnitsBrush,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MinimapBackground,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URTSMinimapWidget>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URTSMinimapWidget::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B01080u,
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
	IMPLEMENT_CLASS(URTSMinimapWidget, 672307829);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URTSMinimapWidget(Z_Construct_UClass_URTSMinimapWidget, &URTSMinimapWidget::StaticClass, TEXT("/Script/RTSPlugin"), TEXT("URTSMinimapWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URTSMinimapWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
