// No copyright - copy as you please

#pragma once
#include "TD2020.h"
#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "ENPCNameFemale.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ENPCNameFemale_Enum : uint8
{
	Ana UMETA(DisplayName = "Ana"),
	Anja UMETA(DisplayName = "Anja"),
	Nika UMETA(DisplayName = "Nika"),
	Ema UMETA(DisplayName = "Ema"),


	ENPCNameFemale_MAX UMETA(DisplayName = "MAX"),

};

UCLASS()
class TD2020_API UENPCNameFemale : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
	ENPCNameFemale_Enum NPCNameFemale;

	//Rest of Class Code


};
