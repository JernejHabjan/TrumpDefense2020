#pragma once

#include "RTSPluginPCH.h"

#include "Blueprint/UserWidget.h"

#include "RTSMinimapWidget.generated.h"


class ARTSMinimapVolume;
class ARTSPlayerController;
class ARTSVisionInfo;
class ARTSVisionVolume;


/**
* Widget for drawing a high-level overview of unit positions.
*/
UCLASS(Blueprintable)
class RTSPLUGIN_API URTSMinimapWidget : public UUserWidget
{
	GENERATED_UCLASS_BODY()

public:
	/** Brush for drawing the background of the current map. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RTS|Background")
	FSlateBrush MinimapBackground;

	/** Brush for drawing own units on the minimap. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RTS|Units")
	FSlateBrush OwnUnitsBrush;

	/** Brush for drawing enemy units on the minimap. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RTS|Units")
	FSlateBrush EnemyUnitsBrush;

	/** Brush for drawing neutral units on the minimap. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RTS|Units")
	FSlateBrush NeutralUnitsBrush;

	/** Brush for drawing unknown areas on the minimap. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RTS|Vision")
	FSlateBrush UnknownAreasBrush;

	/** Brush for drawing known but not visible areas on the minimap. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RTS|Vision")
	FSlateBrush KnownAreasBrush;

	/** Whether to draw the minimap background layer. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RTS|Background")
	bool bDrawBackground = true;

	/** Whether to draw unit dots on the minimap, with OwnUnitsBrush, EnemyUnitsBrush and NeutralUnitsBrush. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RTS|Units")
	bool bDrawUnitsWithTeamColors = true;

	/** Whether to draw vision on the minimap, with UnknownAreasBrush, KnownAreasBrush and VisibleAreasBrush. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RTS|Vision")
	bool bDrawVision = true;

	/** Whether to show the current camera frustum on the minimap. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RTS|Camera")
	bool bDrawViewFrustum = true;


	/** Sets the vision info to draw on the minimap. */
	UFUNCTION(BlueprintCallable)
	void SetupVisionInfo(ARTSVisionInfo* VisionInfo);


	/** Event for custom drawing of units on the minimap (e.g. for drawing hero portraits for hero units). */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS", meta = (DisplayName = "OnDrawUnit"))
	void ReceiveOnDrawUnit(
		UPARAM(ref) FPaintContext& Context,
		AActor* Actor,
		APlayerState* ActorOwner,
		const FVector2D& MinimapPosition,
		APlayerState* LocalPlayer) const;

	/** Event for custom drawing of units on the minimap. */
	virtual void NotifyOnDrawUnit(
		FPaintContext& Context,
		AActor* Actor,
		APlayerState* ActorOwner,
		const FVector2D& MinimapPosition,
		APlayerState* LocalPlayer) const;

protected:
	void NativeConstruct() override;
	void NativePaint(FPaintContext& InContext) const override;
	FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

private:
	bool bMouseDown;
	ARTSMinimapVolume* MinimapVolume;
	FVector MinimapWorldSize;
	ARTSVisionInfo* VisionInfo;
	ARTSVisionVolume* VisionVolume;

	void DrawBackground(FPaintContext& InContext) const;
	void DrawUnits(FPaintContext& InContext) const;
	void DrawVision(FPaintContext& InContext) const;
	void DrawViewFrustum(FPaintContext& InContext) const;

	void DrawBoxWithBrush(FPaintContext& InContext, const FVector2D& Position, const FSlateBrush& Brush) const;

	FReply HandleMinimapClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);

	FVector MinimapToWorld(const FVector2D& MinimapPosition) const;
	bool ViewportToWorld(ARTSPlayerController* Player, const FVector2D& ViewportPosition, FVector& OutWorldPosition) const;
	FVector2D WorldToMinimap(const FVector& WorldPosition) const;
};
