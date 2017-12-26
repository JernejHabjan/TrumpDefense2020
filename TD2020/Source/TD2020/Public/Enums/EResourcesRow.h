// No copyright - copy as you please

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "EResourcesRow.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EResourcesRow_Enum : uint8
{
	
	None 		UMETA(DisplayName = "None"),
	Granite 	UMETA(DisplayName = "Granite")
};


UCLASS()
class TD2020_API UEResourcesRow : public UUserDefinedEnum
{
	GENERATED_BODY()
	

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
	EResourcesRow_Enum ResourcesRow;

	//Rest of Class Code


	
	
};
