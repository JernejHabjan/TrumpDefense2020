// No copyright - copy as you please

#pragma once
#include "TD2020.h"
#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "EOccupationType.generated.h"


UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EOccupationType_Enum : uint8
{
	Unemployment		UMETA(DisplayName = "Unemployment"),
	Construction		UMETA(DisplayName = "Construction"),
	Miner				UMETA(DisplayName = "Miner")

};


UCLASS()
class TD2020_API UEOccupationType : public UUserDefinedEnum
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
	EOccupationType_Enum OccupationType;

	//Rest of Class Code
	
	
};
