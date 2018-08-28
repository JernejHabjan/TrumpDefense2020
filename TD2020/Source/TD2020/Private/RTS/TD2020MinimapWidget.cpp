#include "TD2020.h"
#include "TD2020MinimapWidget.h"

#include "Components/BrushComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Rendering/DrawElements.h"

#include "TD2020MinimapVolume.h"
#include "TD2020OwnerComponent.h"
#include "TD2020PlayerController.h"
#include "TD2020PlayerState.h"
#include "TD2020VisionInfo.h"
#include "TD2020VisionState.h"

#include "TD2020VisionVolume.h"
#include "EngineUtils.h"


UTD2020MinimapWidget::UTD2020MinimapWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UTD2020MinimapWidget::SetupVisionInfo(ATD2020VisionInfo* InVisionInfo)
{
	for (TActorIterator<ATD2020VisionVolume> It(GetWorld()); It; ++It)
	{
		VisionVolume = *It;
		break;
	}

	if (!VisionVolume)
	{
		UE_LOG(LogTD2020, Warning, TEXT("No TD2020VisionVolume found, won't draw vision on minimap."));
		return;
	}

	VisionInfo = InVisionInfo;

	if (!VisionInfo)
	{
		UE_LOG(LogTD2020, Warning, TEXT("No vision info found, won't draw vision on minimap."));
		return;
	}

	UE_LOG(LogTD2020, Log, TEXT("Drawing vision for team %i on minimap."), VisionInfo->TeamIndex);
}

void UTD2020MinimapWidget::NotifyOnDrawUnit(
	FPaintContext& Context,
	AActor* Actor,
	APlayerState* ActorOwner,
	const FVector2D& MinimapPosition,
	APlayerState* LocalPlayer) const
{
	ReceiveOnDrawUnit(Context, Actor, ActorOwner, MinimapPosition, LocalPlayer);
}

void UTD2020MinimapWidget::NativeConstruct()
{
	UUserWidget::NativeConstruct();

	// Get minimap bounds.
	for (TActorIterator<ATD2020MinimapVolume> It(GetWorld()); It; ++It)
	{
		MinimapVolume = *It;
		break;
	}

	if (MinimapVolume)
	{
		UBrushComponent* MinimapBrushComponent = MinimapVolume->GetBrushComponent();
		FBoxSphereBounds MinimapBounds = MinimapBrushComponent->CalcBounds(MinimapBrushComponent->GetComponentTransform());

		MinimapWorldSize = MinimapBounds.BoxExtent * 2;
	}
	else
	{
		UE_LOG(LogTD2020, Warning, TEXT("No TD2020MinimapVolume found. Minimap won't be showing unit positions."));
	}
}

void UTD2020MinimapWidget::NativePaint(FPaintContext& InContext) const
{
	UUserWidget::NativePaint(InContext);

	InContext.MaxLayer++;

	DrawBackground(InContext);
	DrawUnits(InContext);
	DrawVision(InContext);
	DrawViewFrustum(InContext);
}

FReply UTD2020MinimapWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	// Apply default handling.
	auto Reply = UUserWidget::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

	if (Reply.IsEventHandled())
	{
		return Reply;
	}

	// Handle MouseMove events from now on.
	bMouseDown = true;

	// Handle initial click.
	return HandleMinimapClick(InGeometry, InMouseEvent);
}

FReply UTD2020MinimapWidget::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	// Apply default handling.
	auto Reply = UUserWidget::NativeOnMouseButtonUp(InGeometry, InMouseEvent);

	if (Reply.IsEventHandled())
	{
		return Reply;
	}

	// Stop handling MouseMove events.
	bMouseDown = false;
	return FReply::Handled();
}

FReply UTD2020MinimapWidget::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	// Apply default handling.
	auto Reply = UUserWidget::NativeOnMouseMove(InGeometry, InMouseEvent);

	if (Reply.IsEventHandled())
	{
		return Reply;
	}

	if (bMouseDown)
	{
		// Handle movement.
		return HandleMinimapClick(InGeometry, InMouseEvent);
	}

	return FReply::Unhandled();
}

void UTD2020MinimapWidget::DrawBackground(FPaintContext& InContext) const
{
	if (!bDrawBackground)
	{
		return;
	}

	DrawBoxWithBrush(InContext, FVector2D(0, 0), MinimapBackground);
}

void UTD2020MinimapWidget::DrawUnits(FPaintContext& InContext) const
{
	if (!MinimapVolume)
	{
		return;
	}

	APlayerController* Player = GetOwningPlayer();

	for (TActorIterator<AActor> ActorIt(GetWorld()); ActorIt; ++ActorIt)
	{
		AActor* Actor = *ActorIt;
		UTD2020OwnerComponent* OwnerComponent = Actor->FindComponentByClass<UTD2020OwnerComponent>();

		FVector ActorLocationWorld = Actor->GetActorLocation();
		FVector2D ActorLocationMinimap = WorldToMinimap(ActorLocationWorld);
		
		// Draw on minimap.
		if (bDrawUnitsWithTeamColors && OwnerComponent)
		{
			if (OwnerComponent->GetPlayerOwner() == Player->PlayerState)
			{
				DrawBoxWithBrush(InContext, ActorLocationMinimap, OwnUnitsBrush);
			}
			else if (OwnerComponent->GetPlayerOwner() != nullptr && !OwnerComponent->IsSameTeamAsController(Player))
			{
				DrawBoxWithBrush(InContext, ActorLocationMinimap, EnemyUnitsBrush);
			}
			else
			{
				DrawBoxWithBrush(InContext, ActorLocationMinimap, NeutralUnitsBrush);
			}
		}
		
		// Allow custom drawing.
		NotifyOnDrawUnit(
			InContext,
			Actor,
			OwnerComponent ? OwnerComponent->GetPlayerOwner() : nullptr,
			ActorLocationMinimap,
			Player->PlayerState);
	}
}

void UTD2020MinimapWidget::DrawVision(FPaintContext& InContext) const
{
	if (!bDrawVision)
	{
		return;
	}

	if (!VisionVolume || !VisionInfo)
	{
		return;
	}

	// Check all vision tiles.
	FIntVector VisionTileSize = VisionVolume->GetTileSize();

	for (int32 VisionY = 0; VisionY < VisionTileSize.Y; ++VisionY)
	{
		int32 MinimapY = MinimapBackground.ImageSize.Y * VisionY / VisionTileSize.Y;

		for (int32 VisionX = 0; VisionX < VisionTileSize.X; ++VisionX)
		{
			ETD2020VisionState VisionState = VisionInfo->GetVision(VisionX, VisionY);
			int32 MinimapX = MinimapBackground.ImageSize.X * VisionX / VisionTileSize.X;

			// Rotate to match UI coordinate system.
			float RotatedMinimapX = MinimapY;
			float RotatedMinimapY = MinimapBackground.ImageSize.X - MinimapX;

			FVector2D TileLocationMinimap = FVector2D(RotatedMinimapX, RotatedMinimapY);

			switch (VisionState)
			{
				case ETD2020VisionState::VISION_Unknown:
					DrawBoxWithBrush(InContext, TileLocationMinimap, UnknownAreasBrush);
					break;

				case ETD2020VisionState::VISION_Known:
					DrawBoxWithBrush(InContext, TileLocationMinimap, KnownAreasBrush);
					break;
			}
		}
	}
}

void UTD2020MinimapWidget::DrawViewFrustum(FPaintContext& InContext) const
{
	if (!bDrawViewFrustum)
	{
		return;
	}

	// Get viewport size.
	ATD2020PlayerController* Player = Cast<ATD2020PlayerController>(GetOwningPlayer());

	if (!Player)
	{
		return;
	}


	int32 ViewportWidth;
	int32 ViewportHeight;

	Player->GetViewportSize(ViewportWidth, ViewportHeight);

	// Cast four rays.
	FVector2D ViewportTopLeft(0, 0);
	FVector2D ViewportTopRight(ViewportWidth, 0);
	FVector2D ViewportBottomLeft(0, ViewportHeight);
	FVector2D ViewportBottomRight(ViewportWidth, ViewportHeight);

	FVector WorldTopLeft;
	FVector WorldTopRight;
	FVector WorldBottomLeft;
	FVector WorldBottomRight;

	ViewportToWorld(Player, ViewportTopLeft, WorldTopLeft);
	ViewportToWorld(Player, ViewportTopRight, WorldTopRight);
	ViewportToWorld(Player, ViewportBottomLeft, WorldBottomLeft);
	ViewportToWorld(Player, ViewportBottomRight, WorldBottomRight);

	// Convert to minimap space.
	FVector2D MinimapTopLeft = WorldToMinimap(WorldTopLeft);
	FVector2D MinimapTopRight = WorldToMinimap(WorldTopRight);
	FVector2D MinimapBottomLeft = WorldToMinimap(WorldBottomLeft);
	FVector2D MinimapBottomRight = WorldToMinimap(WorldBottomRight);

	// Draw view frustum.
	TArray<FVector2D> Points;

	Points.Add(MinimapTopLeft);
	Points.Add(MinimapTopRight);
	Points.Add(MinimapBottomRight);
	Points.Add(MinimapBottomLeft);
	Points.Add(MinimapTopLeft);

	FSlateDrawElement::MakeLines(
		InContext.OutDrawElements,
		InContext.MaxLayer,
		InContext.AllottedGeometry.ToPaintGeometry(),
		Points);
}

void UTD2020MinimapWidget::DrawBoxWithBrush(FPaintContext& InContext, const FVector2D& Position, const FSlateBrush& Brush) const
{
	FSlateDrawElement::MakeBox(
		InContext.OutDrawElements,
		InContext.MaxLayer,
		InContext.AllottedGeometry.ToPaintGeometry(Position, Brush.ImageSize),
		&Brush,
		ESlateDrawEffect::None,
		Brush.TintColor.GetSpecifiedColor());
}

FReply UTD2020MinimapWidget::HandleMinimapClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	ATD2020PlayerController* Player = Cast<ATD2020PlayerController>(GetOwningPlayer());

	if (!Player)
	{
		FReply::Unhandled();
	}

	// Convert clicked minimap position to world space.
	FVector2D MinimapPosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	FVector WorldPosition = MinimapToWorld(MinimapPosition);

	// Notify player.
	Player->NotifyOnMinimapClicked(InMouseEvent, MinimapPosition, WorldPosition);
	return FReply::Handled();
}

FVector UTD2020MinimapWidget::MinimapToWorld(const FVector2D& MinimapPosition) const
{
	// Convert to relative minimap position.
	float RelativeMinimapX = MinimapPosition.X / MinimapBackground.ImageSize.X;
	float RelativeMinimapY = MinimapPosition.Y / MinimapBackground.ImageSize.Y;

	// Rotate to match UI coordinate system.
	float Temp = RelativeMinimapX;
	RelativeMinimapX = 1 - RelativeMinimapY;
	RelativeMinimapY = Temp;

	// Convert to world coordinates.
	float WorldX = (RelativeMinimapX - 0.5) * MinimapWorldSize.X;
	float WorldY = (RelativeMinimapY - 0.5) * MinimapWorldSize.Y;

	return FVector(WorldX, WorldY, 0.0f);
}

bool UTD2020MinimapWidget::ViewportToWorld(ATD2020PlayerController* Player, const FVector2D& ViewportPosition, FVector& OutWorldPosition) const
{
	// Get ray.
	FVector WorldOrigin;
	FVector WorldDirection;
	if (!UGameplayStatics::DeprojectScreenToWorld(Player, ViewportPosition, WorldOrigin, WorldDirection))
	{
		return false;
	}

	// Make plane.
	FPlane ZPlane = FPlane(FVector::ZeroVector, FVector::UpVector);

	// Calculate intersection point.
	OutWorldPosition = FMath::LinePlaneIntersection(WorldOrigin, WorldOrigin + WorldDirection * 1000.0f, ZPlane);
	return true;
}

FVector2D UTD2020MinimapWidget::WorldToMinimap(const FVector& WorldPosition) const
{
	// Get relative world position.
	float RelativeWorldX = WorldPosition.X / MinimapWorldSize.X + 0.5f;
	float RelativeWorldY = WorldPosition.Y / MinimapWorldSize.Y + 0.5f;

	// Rotate to match UI coordinate system.
	float Temp = RelativeWorldX;
	RelativeWorldX = RelativeWorldY;
	RelativeWorldY = 1 - Temp;

	// Convert to minimap coordinates.
	float MinimapX = RelativeWorldX * MinimapBackground.ImageSize.X;
	float MinimapY = RelativeWorldY * MinimapBackground.ImageSize.Y;

	return FVector2D(MinimapX, MinimapY);
}
