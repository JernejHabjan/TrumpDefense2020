// No copyright - copy as you please

#pragma once

#include "Engine/UserDefinedStruct.h"
#include "Enums/EBuildingType.h"
#include "Enums/EOccupationType.h"
#include "Building_STRUCT.generated.h"

class ABuildingMaster;

USTRUCT(BlueprintType)
struct FBuilding_Struct
{
	GENERATED_BODY()

	//Building Master BP object reference
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	ABuildingMaster* BuildingReference;

	//Building type enum
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EBuildingType_Enum BuildingType;

	// Building name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FString BuildingName;

	// Occupation type enum 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		EOccupationType_Enum OccupationType;

	// Maximum number of employeees in building
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int MaxEmployees;

	// Maximum number of residents in building
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int MaxResidents;
	
	// defaults 
	FBuilding_Struct(
		ABuildingMaster* BuildingReference = nullptr,
		EBuildingType_Enum BuildingType = EBuildingType_Enum::Residential,
		FString BuildingName = TEXT(""),
		EOccupationType_Enum OccupationType = EOccupationType_Enum::Unemployment,
		int MaxEmployees = 0,
		int MaxResidents = 0
	)
	{
		this->BuildingReference = BuildingReference;
		this->BuildingType = BuildingType;
		this->BuildingName = BuildingName;
		this->OccupationType = OccupationType;
		this->MaxEmployees = MaxEmployees;
		this->MaxResidents = MaxResidents;
	}
	
};


UCLASS()
class TD2020_API UBuilding : public UUserDefinedStruct
{
	GENERATED_BODY()
	
	
	
	
};
