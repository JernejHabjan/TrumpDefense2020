#include "TD2020.h"
#include "TD2020BuildingCursor.h"

#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Materials/Material.h"


ATD2020BuildingCursor::ATD2020BuildingCursor()
{
	Mesh = CreateOptionalDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SetRootComponent(Mesh);
}

void ATD2020BuildingCursor::SetMesh(USkeletalMesh* BuildingMesh, const FVector& MeshRelativeScale3D)
{
	Mesh->SetSkeletalMesh(BuildingMesh);
	SetActorRelativeScale3D(MeshRelativeScale3D);
}

void ATD2020BuildingCursor::SetValidLocation()
{
	Mesh->SetMaterial(0, ValidLocationMaterial);
}

void ATD2020BuildingCursor::SetInvalidLocation()
{
	Mesh->SetMaterial(0, InvalidLocationMaterial);
}
