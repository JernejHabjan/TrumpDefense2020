// No copyright - copy as you please

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "ENPCNameMale.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ENPCNameMale_Enum : uint8
{
	Janez UMETA(DisplayName = "Janez"),
	Gasper UMETA(DisplayName = "Gasper"),
	Miha UMETA(DisplayName = "Miha"),
	Boltezar UMETA(DisplayName = "Boltezar"),


	ENPCNameMale_MAX UMETA(DisplayName = "MAX"),
};
UCLASS()
class TD2020_API UENPCNameMale : public UUserDefinedEnum
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
	ENPCNameMale_Enum NPCNameMale;

	//Rest of Class Code
	
};
