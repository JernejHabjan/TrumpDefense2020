// No copyright - copy as you please

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "EBuildingType.generated.h"


UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EBuildingType_Enum : uint8
{
	Residential UMETA(DisplayName = "Residential"),
	Commercial UMETA(DisplayName = "Commercial"),
	Industrial UMETA(DisplayName = "Industrial")
	
};

UCLASS()
class TD2020_API UEBuildingType : public UUserDefinedEnum
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
		EBuildingType_Enum BuildingType;

	//Rest of Class Code

	
	
};
