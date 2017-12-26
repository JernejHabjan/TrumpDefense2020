// No copyright - copy as you please

#pragma once

#include "Engine/UserDefinedStruct.h"
#include "Enums/ENPCSex.h"
#include "Enums/EOccupationType.h"
#include "NPCProfile_STRUCT.generated.h"


class ABuildingMaster;
class AResidentialMaster;

USTRUCT(BlueprintType)
struct FNPCProfile_Struct
{
	GENERATED_BODY()


	// NPC name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FString NPC_Name;

	// Gender of NPC
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	ENPCSex_Enum Sex;

	// Job of NPC
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	EOccupationType_Enum OccupationType;

	// Place of employment of NPC
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	ABuildingMaster* PlaceOfEmployment;

	// Residency of NPC
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	AResidentialMaster* Residency;

	// defaults 
	FNPCProfile_Struct(
		FString NPC_Name = FString(),
		ENPCSex_Enum Sex = ENPCSex_Enum::Male,
		EOccupationType_Enum OccupationType = EOccupationType_Enum::Unemployment,
		ABuildingMaster* PlaceOfEmployment = nullptr,
		AResidentialMaster* Residency = nullptr
	) {
		this->NPC_Name = NPC_Name;
		this->Sex = Sex;
		this->OccupationType = OccupationType;
		this->PlaceOfEmployment = PlaceOfEmployment;
		this->Residency = Residency;
	};
	
};



UCLASS()
class TD2020_API UNPCProfile : public UUserDefinedStruct
{
	GENERATED_BODY()
	
};
