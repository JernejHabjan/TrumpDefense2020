#pragma once


#include "TD2020ResourceType.h"
#include "Templates/SubclassOf.h"
#include "TD2020GatherData.generated.h"




USTRUCT(BlueprintType)
struct TD2020_API FTD2020GatherData
{
	GENERATED_BODY()

public:
	/** Type of resources that can be gathered. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	TSubclassOf<class UTD2020ResourceType> ResourceType;

	/** Amount of resources gathered after each cooldown. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	float AmountPerGathering;

	/** Maximum amount of resources that can be carried. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	float Capacity;

	/** Time between two gatherings, in seconds. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	float Cooldown;

	/** Whether the actor needs to return to the drain in order to drop resources. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	bool bNeedsReturnToDrain;

	/** Range in which resources can be gathered, in cm. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	float Range;
};
