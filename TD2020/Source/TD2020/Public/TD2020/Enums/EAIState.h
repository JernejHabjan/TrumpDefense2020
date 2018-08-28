// No copyright - copy as you please

#pragma once
#include "TD2020.h"
#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "EAIState.generated.h"


UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EAIState_Enum : uint8
{
	Homeless	UMETA(DisplayName = "Homeless"),
	Working		 UMETA(DisplayName = "Working"),
	Sleeping	 UMETA(DisplayName = "Sleeping"),
	MoveByCommander	 UMETA(DisplayName = "MoveByCommander")


	
};

UCLASS()
class TD2020_API UEAIState : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
		EAIState_Enum AIState;

	//Rest of Class Code



	
};
