// No copyright - copy as you please

#pragma once
#include "TD2020.h"
#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "EGameSpeed.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EGameSpeed_Enum : uint8
{
	Speed_0 UMETA(DisplayName = "Speed_0"),
	Speed_1 UMETA(DisplayName = "Speed_1"),
	Speed_2 UMETA(DisplayName = "Speed_2"),
	Speed_3 UMETA(DisplayName = "Speed_3"),
	Speed_4 UMETA(DisplayName = "Speed_4"),
	Speed_5 UMETA(DisplayName = "Speed_5")
};


UCLASS()
class TD2020_API UEGameSpeed : public UUserDefinedEnum
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
		EGameSpeed_Enum GameSpeed;

	//Rest of Class Code


	
};
