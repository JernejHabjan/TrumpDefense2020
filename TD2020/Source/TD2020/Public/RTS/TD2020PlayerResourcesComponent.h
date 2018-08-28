#pragma once


#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
#include "TD2020ResourceType.h" // NEW
#include "TD2020PlayerResourcesComponent.generated.h"

//class UTD2020ResourceType;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FTD2020PlayerResourcesComponentResourcesChangedSignature, TSubclassOf<UTD2020ResourceType>, ResourceType, float, OldResourceAmount, float, NewResourceAmount, bool, bSyncedFromServer);


/**
* Attach to player or AI controllers. Allows the controller to store resources.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020PlayerResourcesComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UTD2020PlayerResourcesComponent(const FObjectInitializer& ObjectInitializer);

    void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    void BeginPlay() override;


    /** Resources currently available to this player. Num must match ResourceTypes. Need to use an array here instead of map for replication. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020|Resources", ReplicatedUsing = ReceivedResourceAmounts)
    TArray<float> ResourceAmounts;

    /** Types of resources currently available to this player. Num must match ResourceAmounts. Need to use an array here instead of map for replication. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020|Resources", replicated)
    TArray<TSubclassOf<class UTD2020ResourceType>> ResourceTypes;


    /** Gets the amount of resources in stock of this player. */
    bool GetResources(TSubclassOf<class UTD2020ResourceType> ResourceType, float* OutResourceAmount);

    /** Checks the amount of resources in stock of this player. */
	UFUNCTION(BlueprintCallable)
    bool CanPayResources(TSubclassOf<class UTD2020ResourceType> ResourceType, float ResourceAmount);

    /** Checks the amount of resources in stock of this player. */
	UFUNCTION(BlueprintCallable)
    bool CanPayAllResources(TMap<TSubclassOf<class UTD2020ResourceType>, float> Resources);

    /** Adds the specified resources to the stock of this player. */
	UFUNCTION(BlueprintCallable)
    virtual float AddResources(TSubclassOf<class UTD2020ResourceType> ResourceType, float ResourceAmount);

    /** Removes the specified resources from the stock of this player. */
	UFUNCTION(BlueprintCallable)
    virtual float PayResources(TSubclassOf<class UTD2020ResourceType> ResourceType, float ResourceAmount);

    /** Removes the specified resources from the stock of this player. */
	UFUNCTION(BlueprintCallable)
    virtual void PayAllResources(TMap<TSubclassOf<class UTD2020ResourceType>, float> Resources);


    /** Event when the current resource stock amount for the player has changed. */
    UPROPERTY(BlueprintAssignable, Category = "TD2020")
    FTD2020PlayerResourcesComponentResourcesChangedSignature OnResourcesChanged;

private:
    UFUNCTION()
    void ReceivedResourceAmounts();
};
