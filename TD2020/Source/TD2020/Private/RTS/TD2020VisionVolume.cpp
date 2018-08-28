#include "TD2020.h"
#include "TD2020VisionVolume.h"

#include "Components/BrushComponent.h"


ATD2020VisionVolume::ATD2020VisionVolume(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FVector ATD2020VisionVolume::GetWorldSize() const
{
	if(Enable)
		return WorldSize;
	else
		return FVector(0, 0, 0);
}

FIntVector ATD2020VisionVolume::GetTileSize() const
{
	if(Enable)
		return TileSize;
	else
		return FIntVector(0, 0, 0);
}

FIntVector ATD2020VisionVolume::WorldToTile(const FVector& WorldPosition) const
{
	if (Enable) {
		// Get relative world position.
		float RelativeWorldX = WorldPosition.X / WorldSize.X + 0.5f;
		float RelativeWorldY = WorldPosition.Y / WorldSize.Y + 0.5f;

		//// Rotate to match UI coordinate system.
		//float temp = RelativeWorldX;
		//RelativeWorldX = RelativeWorldY;
		//RelativeWorldY = 1 - temp;

		// Convert to minimap coordinates.
		int32 TileX = FMath::FloorToInt(RelativeWorldX * TileSize.X);
		int32 TileY = FMath::FloorToInt(RelativeWorldY * TileSize.Y);

		return FIntVector(TileX, TileY, 0);
	}
	else {
		return FIntVector(0, 0, 0);
	}
}

void ATD2020VisionVolume::BeginPlay()
{
	Super::BeginPlay();
	if (Enable) {

	
		// Get vision world size.
		UBrushComponent* VisionBrushComponent = GetBrushComponent();
		FBoxSphereBounds VisionBounds = VisionBrushComponent->CalcBounds(VisionBrushComponent->GetComponentTransform());

		WorldSize = VisionBounds.BoxExtent * 2;

		// Calculate tile size.
		TileSize = FIntVector(
			FMath::FloorToInt(WorldSize.X / SizePerTile),
			FMath::FloorToInt(WorldSize.Y / SizePerTile),
			FMath::FloorToInt(WorldSize.Z / SizePerTile));

		UE_LOG(LogTD2020, Log, TEXT("Vision tile grid has size %i x %i x %i."), TileSize.X, TileSize.Y, TileSize.Z);
	}
}
