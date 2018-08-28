#pragma once

#include "Templates/SubclassOf.h"
#include "TD2020ProductionQueue.generated.h"


USTRUCT(BlueprintType)
struct TD2020_API FTD2020ProductionQueue
{
	GENERATED_BODY()

public:
	/** Products queued for production. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	TArray<TSubclassOf<AActor>> Queue;

	/** Time before the current actor in the queue is produced, in seconds. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float RemainingProductionTime;


	/** Gets the product with the specified index in this queue. */
	TSubclassOf<AActor> operator[](int32 Index) const;


	/** Enqueues the specified product. */
	void Add(TSubclassOf<AActor> Product);

	/** Gets the number of products in this queue. */
	int32 Num() const;

	/** Removes the product with the specified index in this queue, advancing all later products. */
	void RemoveAt(int32 Index);
};
