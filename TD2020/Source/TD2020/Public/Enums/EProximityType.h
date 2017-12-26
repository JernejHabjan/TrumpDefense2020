// No copyright - copy as you please

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "EProximityType.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EProximityType_Enum : uint8
{
	None UMETA(DisplayName = "None"),
	Mining UMETA(DisplayName = "Mining"),
	Farming UMETA(DisplayName = "Farming")
};

UCLASS()
class TD2020_API UEProximityType : public UUserDefinedEnum
{
	GENERATED_BODY()
	

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
	EProximityType_Enum ProximityType;

	//Rest of Class Code

	
	
};
