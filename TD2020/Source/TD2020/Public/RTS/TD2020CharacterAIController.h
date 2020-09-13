#pragma once


#include "AIController.h"

#include "TD2020OrderType.h"

#include "TD2020CharacterAIController.generated.h"


class UTD2020AttackComponent;


/**
* AI controller that drives TD2020 unit movement and orders.
*/
UCLASS()
class TD2020_API ATD2020CharacterAIController : public AAIController
{
    GENERATED_BODY()

public:
    /** Behavior tree to use for driving the character AI. */
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "TD2020")
    UBehaviorTree* CharacterBehaviorTreeAsset;

    /** Blackboard to use for holding all data relevant to the character AI. */
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "TD2020")
    UBlackboardData* CharacterBlackboardAsset;


	/** Makes the pawn look for a feasible target in its acquisition radius. */
	UFUNCTION(BlueprintCallable)
	void FindTargetInAcquisitionRadius();

    /** Checks whether the pawn has an order of the specified type. */
    UFUNCTION(BlueprintPure)
    bool HasOrder(ETD2020OrderType OrderType) const;

    /** Checks whether the pawn is idle, or has any orders. */
    UFUNCTION(BlueprintPure)
    bool IsIdle() const;

	/** Makes the pawn attack the specified target. */
	UFUNCTION(BlueprintCallable)
	void IssueAttackOrder(AActor* Target);

	/** Makes the pawn construct the specified building at the passed location. */
	UFUNCTION(BlueprintCallable)
	void IssueBeginConstructionOrder(TSubclassOf<AActor> BuildingClass, const FVector& TargetLocation);

	/** Makes the pawn continue constructing the specified building. */
	UFUNCTION(BlueprintCallable)
	void IssueContinueConstructionOrder(AActor* ConstructionSite);

	/** Makes the pawn gather resources from the specified source. */
	UFUNCTION(BlueprintCallable)
	void IssueGatherOrder(AActor* ResourceSource);

    /** Makes the pawn move towards the specified location. */
    UFUNCTION(BlueprintCallable)
    void IssueMoveOrder(const FVector& Location);

	/** Makes the pawn move towards the closest resource drain and return all carried resources. */
	UFUNCTION(BlueprintCallable)
	void IssueReturnResourcesOrder();

	/** Makes the pawn stop all actions immediately. */
	UFUNCTION(BlueprintCallable)
	void IssueStopOrder();

protected:
	virtual void OnPossess(APawn* InPawn) override;

private:
	UTD2020AttackComponent* AttackComponent;

	void ApplyOrders();

	void ClearBuildingClass();
	void ClearHomeLocation();
	void ClearTargetActor();
	void ClearTargetLocation();

	void SetBuildingClass(int32 BuildingIndex);
	void SetHomeLocation(const FVector& HomeLocation);
	void SetOrderType(const ETD2020OrderType OrderType);
	void SetTargetActor(AActor* TargetActor);
	void SetTargetLocation(const FVector& TargetLocation);

	bool TraceSphere(
		const FVector& Location,
		const float Radius,
		AActor* ActorToIgnore,
		ECollisionChannel TraceChannel,
		TArray<struct FHitResult>& OutHitResults);

	bool VerifyBlackboard();
};
