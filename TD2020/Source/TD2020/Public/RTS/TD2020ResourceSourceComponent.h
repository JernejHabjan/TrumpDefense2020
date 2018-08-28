#pragma once
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
//#include "TD2020ResourceType.h" // NEW
#include "TD2020ResourceSourceComponent.generated.h"


class UTD2020ResourceType;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTD2020ResourceSourceComponentResourcesChangedSignature, float, OldResources, float, NewResources);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTD2020ResourceSourceComponentDepletedSignature);


/**
* Adds resources to be gathered from the actor.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020ResourceSourceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Type of resources to be gathered from the actor. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	TSubclassOf<UTD2020ResourceType> ResourceType;

	/** Current resources available at the actor. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020", meta = (ClampMin = 0), replicated)
	float CurrentResources;

	/** Maximum resources available at the actor. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020", meta = (ClampMin = 0))
	float MaximumResources;

	/** Factor to multiply all gathered resources with (e.g. very abundant resource nodes. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float GatheringFactor;

	/** Whether gatherers must enter the resource source for gathering. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	bool bGathererMustEnter;

	/** How many gatherers may enter at the same time. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	int32 GathererCapacity;


	UTD2020ResourceSourceComponent(const FObjectInitializer& ObjectInitializer);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void BeginPlay() override;


	/** Extracts resources from this actor, applying gathering factor and checking remaining amount. */
	UFUNCTION(BlueprintCallable)
	virtual float ExtractResources(AActor* Gatherer, float ResourceAmount);

	/** Checks whether the specified gatherer can enter the resource source right now. */
	UFUNCTION(BlueprintCallable)
	virtual bool CanGathererEnter(AActor* Gatherer) const;


	/** Event when the amount of available resources has changed. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020ResourceSourceComponentResourcesChangedSignature OnResourcesChanged;

	/** Event when the actor has been depleted. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020ResourceSourceComponentDepletedSignature OnDepleted;
};
