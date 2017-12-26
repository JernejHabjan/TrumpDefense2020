// No copyright - copy as you please

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "ELocationType.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ELocationType_Enum : uint8
{
	NoneSelected		UMETA(DisplayName = "NoneSelected"),
	Home				UMETA(DisplayName = "Home"),
	Office				UMETA(DisplayName = "Office"),
	Restaurant			UMETA(DisplayName = "Restaurant")
};

UCLASS()
class TD2020_API UELocationType : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
	ELocationType_Enum LocationType;

	//Rest of Class Code


	
};
