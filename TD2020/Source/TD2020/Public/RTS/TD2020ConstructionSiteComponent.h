#pragma once

#include "Components/ActorComponent.h"
#include "TD2020ConstructionState.h"
#include "TD2020ProductionCostType.h"
#include "TD2020ResourceType.h"
#include "TD2020ConstructionSiteComponent.generated.h"





DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTD2020ConstructionSiteComponentConstructionStartedSignature, float, TotalConstructionTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTD2020ConstructionSiteComponentConstructionFinishedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTD2020ConstructionSiteComponentConstructionCanceledSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTD2020ConstructionSiteComponentBuilderConsumedSignature, AActor*, Builder);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTD2020ConstructionSiteComponentConstructionCostRefundedSignature, TSubclassOf<UTD2020ResourceType>, ResourceType, float, ResourceAmount);


/** Allows constructing the actor over time. */
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020ConstructionSiteComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Builders currently working at this construction site. */
	TArray<AActor*> AssignedBuilders;

	/** When to pay resources for construction. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	ETD2020ProductionCostType ConstructionCostType;

	/** Resources to pay for constructing the actor. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	TMap<TSubclassOf<UTD2020ResourceType>, float> ConstructionCosts;

	/** Time for constructing the actor, in seconds. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float ConstructionTime;

	/** Whether any builders working at this construction site are destroyed when finished. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	bool bConsumesBuilders;

	/** How many builders may be assigned to this construction site at the same time. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	int32 MaxAssignedBuilders;

	/** Factor to multiply all passed construction time with, independent of any currently assigned builders. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float ProgressMadeAutomatically;

	/** Factor to multiply all passed construction time with, multiplied with the number of currently assigned builders. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float ProgressMadePerBuilder;

	/** Time before the actor is constructed, in seconds. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020", replicated)
	float RemainingConstructionTime;

	/** Resources to refund when canceling construction. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float RefundFactor;

	/** Whether to start construction immediately after spawn, or not. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	bool bStartImmediately;


	UTD2020ConstructionSiteComponent(const FObjectInitializer& ObjectInitializer);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;


	/** Whether the specified builder can be assigned to this construction site. */
	UFUNCTION(BlueprintCallable)
	virtual bool CanAssignBuilder(AActor* Builder) const;

	/** Gets the current construction progress [0..1]. */
	UFUNCTION(BlueprintCallable)
	float GetProgressPercentage() const;

	/** Whether the construction timer is currently being ticked, or not. */
	UFUNCTION(BlueprintCallable)
	bool IsConstructing() const;

	/** Whether the construction is finished and the actor ready to use. */
	UFUNCTION(BlueprintCallable)
	bool IsFinished() const;

	/** StaTD2020 constructing the actor, setting the timer. */
	UFUNCTION(BlueprintCallable)
	virtual void StartConstruction();

	/** Finishes constructing the actor. */
	UFUNCTION(BlueprintCallable)
	virtual void FinishConstruction();

	/** Cancels constructing the actor, destroying it. */
	UFUNCTION(BlueprintCallable)
	virtual void CancelConstruction();


	/** Event when the construction timer has been started. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020ConstructionSiteComponentConstructionStartedSignature OnConstructionStarted;

	/** Event when the construction timer has been expired. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020ConstructionSiteComponentConstructionFinishedSignature OnConstructionFinished;

	/** Event when the construction has been canceled and the construction site destroyed. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020ConstructionSiteComponentConstructionCanceledSignature OnConstructionCanceled;

	/** Event when a builder working at this construction site has been destroyed. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020ConstructionSiteComponentBuilderConsumedSignature OnBuilderConsumed;

	/** Event when any construction costs have been refunded. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020ConstructionSiteComponentConstructionCostRefundedSignature OnConstructionCostRefunded;

private:
	/** Whether the construction timer is currently being ticked, or not. */
	ETD2020ConstructionState State;
};
