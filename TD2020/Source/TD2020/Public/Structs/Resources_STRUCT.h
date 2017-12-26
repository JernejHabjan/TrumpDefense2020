// No copyright - copy as you please

#pragma once

#include "Engine/UserDefinedStruct.h"
#include "Enums/EProximityType.h"
#include "Engine/DataTable.h"
#include "Resources_STRUCT.generated.h"

class UTexture2D;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FResources_Struct : public FTableRowBase
{
	GENERATED_BODY()


	// Resource static mesh reference
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	UStaticMesh* ResourceMesh;

	// Thumbnail of resource - picture
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		UTexture2D* ResourcesThumbnail;

	// Resource name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FString ProperResourceName;

	// Proximity type of resource (mining, farming...)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EProximityType_Enum  ProximityType;

	// Harvest time of resource (in hours)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float HarvestTime;

	// defaults 
	FResources_Struct(
		UStaticMesh* ResourceMesh = nullptr,
		UTexture2D* ResourcesThumbnail = nullptr,
		FString ProperResourceName = TEXT("Resource"),
		EProximityType_Enum  ProximityType = EProximityType_Enum::None,
		float HarvestTime = 1.0f
		)
	{
		this->ResourceMesh = ResourceMesh;
		this->ResourcesThumbnail = ResourcesThumbnail;
		this->ProperResourceName = ProperResourceName;
		this->ProximityType = ProximityType;
		this->HarvestTime = HarvestTime;

	}

};

UCLASS()
class TD2020_API UResources : public UUserDefinedStruct
{
	GENERATED_BODY()
	
	
	
	
};
