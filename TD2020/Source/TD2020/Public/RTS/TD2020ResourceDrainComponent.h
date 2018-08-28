#pragma once
#include "Components/ActorComponent.h"
#include "TD2020ResourceType.h" // NEW
#include "TD2020ResourceDrainComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTD2020ResourceDrainComponentResourcesReturnedSignature, AActor*, Gatherer, TSubclassOf<UTD2020ResourceType>, ResourceType, float, ResourceAmount);


/**
* Allows resources to be returned to the actor.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020ResourceDrainComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Types of resources that can be returned to the actor. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	TArray<TSubclassOf<class UTD2020ResourceType>> ResourceTypes;

	/** Whether gatherers must enter the resource drain for returning resources. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	bool bGathererMustEnter;

	/** How many gatherers may enter at the same time. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	int32 GathererCapacity;


	UTD2020ResourceDrainComponent(const FObjectInitializer& ObjectInitializer);


	/** Returns resources to this actor, notifying the owning player. */
	virtual float ReturnResources(AActor* Gatherer, TSubclassOf<class UTD2020ResourceType> ResourceType, float ResourceAmount);


	/** Event when resources have been returned to the actor. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020ResourceDrainComponentResourcesReturnedSignature OnResourcesReturned;
};
