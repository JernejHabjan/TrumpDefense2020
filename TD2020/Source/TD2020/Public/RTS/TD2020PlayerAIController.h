#pragma once


#include "AIController.h"

#include "TD2020PlayerAIController.generated.h"


class UBehaviorTree;
class UBlackboardData;
class APawn;

class UTD2020PlayerResourcesComponent;


/**
* AI controller that drives strategic TD2020 player AI.
*/
UCLASS()
class TD2020_API ATD2020PlayerAIController : public AAIController
{
    GENERATED_BODY()

public:
    ATD2020PlayerAIController();

    /** Behavior tree to use for driving the player AI. */
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "TD2020")
    UBehaviorTree* PlayerBehaviorTreeAsset;

    /** Blackboard to use for holding all data relevant to the player AI. */
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "TD2020")
    UBlackboardData* PlayerBlackboardAsset;

    /** Units and buildings the AI should produce, in order. */
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "TD2020")
    TArray<TSubclassOf<APawn>> BuildOrder;

    /** Maximum distance of a new building to an existing one, in cm. */
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "TD2020")
    float MaximumBaseBuildingDistance;

    /** Type of the primary resource for the AI to gather (e.g. used for placing resource drains). */
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "TD2020")
    TSubclassOf<class UTD2020ResourceType> PrimaryResourceType;


    /** Checks the build order and returns the class of the next pawn to produce, or the Pawn class if nothing needs to be produced. */
    UFUNCTION(BlueprintPure)
    TSubclassOf<APawn> GetNextPawnToProduce() const;

    /** Gets the primary resource drain of the AI. */
    UFUNCTION(BlueprintCallable)
    virtual AActor* GetPrimaryResourceDrain() const;

    /** Gets the closest resource source of the primary resource type around the first resource drain of the AI. */
    UFUNCTION(BlueprintCallable)
    virtual AActor* GetPrimaryResourceSource() const;

    /** Checks the available resources for the AI and whether it can pay for a pawn of the specified class. */
    UFUNCTION(BlueprintPure)
    bool CanPayFor(TSubclassOf<APawn> PawnClass) const;

    /** Checks whether the AI meets all tech tree requirements for a pawn of the specified class. */
    UFUNCTION(BlueprintPure)
    bool MeetsAllRequirementsFor(TSubclassOf<APawn> PawnClass) const;

    /** Selects an arbitrary production actor for producing a pawn of the specified class and staTD2020 production. */
    UFUNCTION(BlueprintCallable)
    bool StartProduction(TSubclassOf<APawn> PawnClass);

protected:
    virtual void OnPossess(APawn* InPawn) override;


private:
    /** Stores the resources available for this player. */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
    UTD2020PlayerResourcesComponent* PlayerResourcesComponent;
};
