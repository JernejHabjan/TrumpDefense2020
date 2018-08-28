#pragma once
#include "Components/ActorComponent.h"
#include "TD2020BuilderComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTD2020BuilderComponentAssignedToConstructionSiteSignature, AActor*, ConstructionSite);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTD2020BuilderComponentRemovedFromConstructionSiteSignature, AActor*, ConstructionSite);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTD2020BuilderComponentConstructionSiteEnteredSignature, AActor*, ConstructionSite);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTD2020BuilderComponentConstructionSiteLeftSignature, AActor*, ConstructionSite);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTD2020BuilderComponentConstructionStartedSignature, AActor*, ConstructionSite);


/**
 * Allows the actor to construct buildings.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020BuilderComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Types of buildings the builder can construct. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	TArray<TSubclassOf<AActor>> ConstructibleBuildingClasses;

	/** Whether the builder enters the construction site while working on it, or not. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	bool bEnterConstructionSite;

    /** Distance of the builder to the construction site while building. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
    float ConstructionSiteOffset;


	/** Assigns the builder to the specified construction site. */
	UFUNCTION(BlueprintCallable)
	virtual void AssignToConstructionSite(AActor* ConstructionSite);

	/** Spawns a building of the specified type at the target location and assigns the builder. */
	UFUNCTION(BlueprintCallable)
	virtual void BeginConstruction(TSubclassOf<AActor> BuildingClass, const FVector& TargetLocation);

	/** Spawns a building of the specified type at the target location and assigns the builder. */
	UFUNCTION(BlueprintCallable)
	void BeginConstructionByIndex(int32 BuildingIndex, const FVector& TargetLocation);

	/** Gets the construction site the builder is currently working on. */
	UFUNCTION(BlueprintCallable)
	AActor* GetAssignedConstructionSite();

	/** Removes the builder from its assigned construction site. */
	UFUNCTION(BlueprintCallable)
	virtual void LeaveConstructionSite();


	/** Event when the builder has been assigned to a construction site. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020BuilderComponentAssignedToConstructionSiteSignature OnAssignedToConstructionSite;

	/** Event when the builder is no longer assigned to a construction site. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020BuilderComponentRemovedFromConstructionSiteSignature OnRemovedFromConstructionSite;

	/** Event when the builder has entered a construction site. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020BuilderComponentConstructionSiteEnteredSignature OnConstructionSiteEntered;

	/** Event when the builder has left a construction site. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020BuilderComponentConstructionSiteLeftSignature OnConstructionSiteLeft;

	/** Event when the builder has created a new construction site. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020BuilderComponentConstructionSiteEnteredSignature OnConstructionStarted;


private:
	/** Construction site the builder is currently working on. */
	AActor* AssignedConstructionSite;
};
