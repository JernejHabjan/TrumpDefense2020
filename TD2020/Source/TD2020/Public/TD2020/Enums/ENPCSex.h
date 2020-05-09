// No copyright - copy as you please

#pragma once
#include "TD2020.h"
#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "ENPCSex.generated.h"


UENUM(BlueprintType) //"BlueprintType" is essential to include
enum class ENPCSex_Enum : uint8
{
    Male UMETA(DisplayName = "Male"),
    Female UMETA(DisplayName = "Female")
};


UCLASS()
class TD2020_API UENPCSex : public UUserDefinedEnum
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
    ENPCSex_Enum NPCSex;

    //Rest of Class Code
};
