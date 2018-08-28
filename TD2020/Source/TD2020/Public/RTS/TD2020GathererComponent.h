#pragma once



#include "Components/ActorComponent.h"

#include "TD2020GatherData.h"
#include "TD2020ResourceType.h"
#include "TD2020GathererComponent.generated.h"


class AActor;



DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTD2020GathererComponentResourcesGatheredSignature, AActor*, ResourceSource, const FTD2020GatherData&, GatherData, float, GatheredAmount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTD2020GathererComponentResourcesReturnedSignature, AActor*, ResourceDrain, TSubclassOf<class UTD2020ResourceType>, ResourceType, float, ReturnedAmount);


/**
* Allows the actor to gather resources.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020GathererComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Amount of resources the actor is carrying. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020", replicated)
	float CarriedResourceAmount;

	/** Type of resource the actor is carrying. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020", replicated)
	TSubclassOf<class UTD2020ResourceType> CarriedResourceType;

	/** Resources that can be gathered by the actor. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	TArray<FTD2020GatherData> GatheredResources;

	/** Time before the next resources are gathered, in seconds. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float RemainingCooldown;

	/** Types of actors the gatherer can gather resources from. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	TArray<TSubclassOf<AActor>> ResourceSourceActorClasses;

	/** Radius in which the actor will automatically gather resources from, in cm. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float ResourceSweepRadius;


	UTD2020GathererComponent(const FObjectInitializer& ObjectInitializer);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;


	/** Checks whether the actor can gather from the specified source, e.g. is allowed to gather, and is not at capacity limit. */
	UFUNCTION(BlueprintCallable)
	virtual bool CanGatherFrom(AActor* ResourceSource);

	/** Finds the closest resource drain for returning currently carried resources. */
	UFUNCTION(BlueprintCallable)
	virtual AActor* FindClosestResourceDrain() const;

	/** Gets the resource source the actor has recently been gathering from, if available, or a similar one within its sweep radius. */
	UFUNCTION(BlueprintCallable)
	virtual AActor* GetPreferredResourceSource() const;

    /** Gets the closest resource source of the specified type within the passed maximum distance around the actor (0 means anywhere). */
    UFUNCTION(BlueprintCallable)
    virtual AActor* GetClosestResourceSource(TSubclassOf<class UTD2020ResourceType> DesiredResourceType, float MaxDistance) const;

	/** Gets the maximum distance for gathering resources from the specified source. */
	UFUNCTION(BlueprintCallable)
	virtual float GetGatherRange(AActor* ResourceSource);

	/** Whether the gatherer is currently carrying any resources that could be returned. */
	UFUNCTION(BlueprintCallable)
	bool IsCarryingResources() const;

	/** Whether this gatherer is currently gathering resources. */
	UFUNCTION(BlueprintCallable)
	bool IsGathering() const;

	/** StaTD2020 the cooldown timer for gathering resources from the specified source. */
	UFUNCTION(BlueprintCallable)
	virtual void StartGatheringResources(AActor* ResourceSource);

	/** Gathers resources from the specified source and staTD2020 the cooldown timer. */
	UFUNCTION(BlueprintCallable)
	virtual float GatherResources(AActor* ResourceSource);

	/** Returns resources to the specified drain. */
	UFUNCTION(BlueprintCallable)
	virtual float ReturnResources(AActor* ResourceDrain);


	/** Event when the actor has gathered resources from a source. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020GathererComponentResourcesGatheredSignature OnResourcesGathered;

	/** Event when the actor has returned resources to a drain. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020GathererComponentResourcesReturnedSignature OnResourcesReturned;

private:
	/** Resource source the actor is currently gathering from .*/
	AActor* CurrentResourceSource;

	/** Resource source the actor has been gathering from before.*/
	AActor* PreviousResourceSource;

	/** Type of resource gathered before. */
	TSubclassOf<class UTD2020ResourceType> PreviousResourceType;


	bool GetGatherDataForResourceSource(AActor* ResourceSource, FTD2020GatherData* OutGatherData);
	bool GetGatherDataForResourceType(TSubclassOf<UTD2020ResourceType> ResourceType, FTD2020GatherData* OutGatherData);
	void LeaveCurrentResourceSource();
};
