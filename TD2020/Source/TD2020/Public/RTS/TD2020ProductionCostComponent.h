#pragma once

#include "Components/ActorComponent.h"
#include "TD2020ProductionCostType.h"
#include "TD2020ResourceType.h" // NEW
#include "TD2020ProductionCostComponent.generated.h"


//class UTD2020ResourceType;


/** Specifies the time and resources required to construct the actor. */
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020ProductionCostComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** When to pay resources for production. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	ETD2020ProductionCostType ProductionCostType;

	/** Time for producing the actor, in seconds. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float ProductionTime;

	/** Resources to pay for producing the actor. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	TMap<TSubclassOf<UTD2020ResourceType>, float> Resources;

	/** Resources to refund when canceling production. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float RefundFactor;


	UTD2020ProductionCostComponent(const FObjectInitializer& ObjectInitializer);
};
