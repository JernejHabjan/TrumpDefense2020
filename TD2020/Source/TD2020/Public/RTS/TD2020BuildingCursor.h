#pragma once

#include "GameFramework/Actor.h"
#include "TD2020BuildingCursor.generated.h"


class UMaterial;
class USkeletalMesh;
class USkeletalMeshComponent;


/** 3D cursor for selecting a location for a building. */
UCLASS()
class TD2020_API ATD2020BuildingCursor : public AActor
{
	GENERATED_BODY()

public:
	/** Material to apply while the current location is valid. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	UMaterial* ValidLocationMaterial;

	/** Material to apply while the current location is invalid. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	UMaterial* InvalidLocationMaterial;


	ATD2020BuildingCursor();


	/** Sets the preview mesh of this cursor. */
	void SetMesh(USkeletalMesh* BuildingMesh, const FVector& MeshRelativeScale3D);

	/** Applies the material for valid locations. */
	void SetValidLocation();

	/** Applies the material for invalid locations. */
	void SetInvalidLocation();

private:
	/** Current preview mesh of this cursor. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* Mesh;
};
