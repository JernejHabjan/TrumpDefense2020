// No copyright - copy as you please

#pragma once
#include <CoreMinimal.h>
#include <Engine/UserDefinedEnum.h>
#include "EMonthNames.generated.h"

UENUM(BlueprintType) //"BlueprintType" is essential to include
enum class EMonthNames_Enum : uint8
{
    January UMETA(DisplayName = "January"),
    February UMETA(DisplayName = "February"),
    March UMETA(DisplayName = "March"),
    April UMETA(DisplayName = "April"),
    May UMETA(DisplayName = "May"),
    June UMETA(DisplayName = "June"),
    July UMETA(DisplayName = "July"),
    August UMETA(DisplayName = "August"),
    September UMETA(DisplayName = "September"),
    October UMETA(DisplayName = "October"),
    November UMETA(DisplayName = "November"),
    December UMETA(DisplayName = "December")
};

UCLASS()
class TD2020_API UEMonthNames : public UUserDefinedEnum
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
    EMonthNames_Enum MonthNames;

    //Rest of Class Code
};
