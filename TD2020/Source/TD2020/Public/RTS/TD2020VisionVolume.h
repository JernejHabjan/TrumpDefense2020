#pragma once


#include "GameFramework/Volume.h"

#include "TD2020VisionVolume.generated.h"


/**
* Volume that defines the size and resolution of vision provided by units.
*/
UCLASS(Blueprintable)
class TD2020_API ATD2020VisionVolume : public AVolume
{
	GENERATED_UCLASS_BODY()

public:
	/** Size of a single tile of the vision grid imposed on the world. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020", meta = (ClampMin = 0))
	float SizePerTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	bool Enable;


	FVector GetWorldSize() const;
	FIntVector GetTileSize() const;

	FIntVector WorldToTile(const FVector& WorldPosition) const;

protected:
	virtual void BeginPlay() override;

private:
	FVector WorldSize;
	FIntVector TileSize;
};
