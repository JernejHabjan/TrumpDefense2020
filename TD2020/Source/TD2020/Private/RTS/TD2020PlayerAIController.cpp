#include "TD2020.h"
#include "TD2020PlayerAIController.h"

#include "EngineUtils.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"

#include "TD2020BuilderComponent.h"
#include "TD2020CharacterAIController.h"
#include "TD2020ConstructionSiteComponent.h"
#include "TD2020PlayerResourcesComponent.h"
#include "TD2020ProductionComponent.h"
#include "TD2020ProductionCostComponent.h"
#include "TD2020ResourceSourceComponent.h"
#include "TD2020ResourceDrainComponent.h"
#include "TD2020Utilities.h"


ATD2020PlayerAIController::ATD2020PlayerAIController()
{
    PlayerResourcesComponent = CreateDefaultSubobject<UTD2020PlayerResourcesComponent>(TEXT("Player Resources"));

    bWantsPlayerState = true;

    MaximumBaseBuildingDistance = 1500.0f;
}

TSubclassOf<APawn> ATD2020PlayerAIController::GetNextPawnToProduce() const
{
    // Count own actors.
    TMap<TSubclassOf<APawn>, int32> OwnPawns;

    for (TActorIterator<APawn> PawnItr(GetWorld()); PawnItr; ++PawnItr)
    {
        APawn* SomePawn = *PawnItr;

        if (SomePawn->GetOwner() != this)
        {
            continue;
        }

        int32& NumOwnedPawns = OwnPawns.FindOrAdd(SomePawn->GetClass());
        ++NumOwnedPawns;
    }

    // TODO(np): Also count actors already in production/construction.

    // Check build order.
    TMap<TSubclassOf<APawn>, int32> BuildOrderPawns;
    for (TSubclassOf<APawn> PawnClass : BuildOrder)
    {
        int32& NumRequiredPawns = BuildOrderPawns.FindOrAdd(PawnClass);
        ++NumRequiredPawns;

        if (NumRequiredPawns > OwnPawns.FindRef(PawnClass))
        {
            return PawnClass;
        }
    }

    return APawn::StaticClass();
}

AActor* ATD2020PlayerAIController::GetPrimaryResourceDrain() const
{
    APawn* PrimaryResourceDrain = nullptr;

    for (TActorIterator<APawn> PawnItr(GetWorld()); PawnItr; ++PawnItr)
    {
        APawn* SomePawn = *PawnItr;

        if (SomePawn->GetOwner() != this)
        {
            continue;
        }

        if (SomePawn->FindComponentByClass<UTD2020ResourceDrainComponent>() == nullptr)
        {
            continue;
        }

        return SomePawn;
    }

    return nullptr;
}

AActor* ATD2020PlayerAIController::GetPrimaryResourceSource() const
{
    // Get resource drain.
    AActor* PrimaryResourceDrain = GetPrimaryResourceDrain();

    if (PrimaryResourceDrain == nullptr)
    {
        return nullptr;
    }

    // Sweep for sources.
    AActor* ClosestResourceSource = nullptr;
    float ClosestResourceSourceDistance = 0.0f;

    for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        auto ResourceSource = *ActorItr;

        // Check if found resource source.
        auto ResourceSourceComponent = ResourceSource->FindComponentByClass<UTD2020ResourceSourceComponent>();

        if (!ResourceSourceComponent)
        {
            continue;
        }

        // Check resource type.
        if (ResourceSourceComponent->ResourceType != PrimaryResourceType)
        {
            continue;
        }

        // Check distance.
        float Distance = PrimaryResourceDrain->GetDistanceTo(ResourceSource);

        if (!ClosestResourceSource || Distance < ClosestResourceSourceDistance)
        {
            ClosestResourceSource = ResourceSource;
            ClosestResourceSourceDistance = Distance;
        }
    }

    return ClosestResourceSource;
}

bool ATD2020PlayerAIController::CanPayFor(TSubclassOf<APawn> PawnClass) const
{
    UTD2020ProductionCostComponent* ProductionCostComponent = UTD2020Utilities::FindDefaultComponentByClass<UTD2020ProductionCostComponent>(PawnClass);

    if (ProductionCostComponent)
    {
        return PlayerResourcesComponent->CanPayAllResources(ProductionCostComponent->Resources);
    }

    UTD2020ConstructionSiteComponent* ConstructionSiteComponent = UTD2020Utilities::FindDefaultComponentByClass<UTD2020ConstructionSiteComponent>(PawnClass);

    if (ConstructionSiteComponent)
    {
        return PlayerResourcesComponent->CanPayAllResources(ConstructionSiteComponent->ConstructionCosts);
    }

    return true;
}

bool ATD2020PlayerAIController::MeetsAllRequirementsFor(TSubclassOf<APawn> PawnClass) const
{
    AActor* AnyOwnActor = GetPrimaryResourceDrain();
    return UTD2020Utilities::OwnerMeetsAllRequirementsFor(AnyOwnActor, AnyOwnActor, PawnClass);
}

bool ATD2020PlayerAIController::StartProduction(TSubclassOf<APawn> PawnClass)
{
    // Find suitable factory.
    for (TActorIterator<APawn> PawnItr(GetWorld()); PawnItr; ++PawnItr)
    {
        APawn* SomePawn = *PawnItr;

        if (SomePawn->GetOwner() != this)
        {
            continue;
        }

        UTD2020ProductionComponent* ProductionComponent = SomePawn->FindComponentByClass<UTD2020ProductionComponent>();
        
        if (!ProductionComponent)
        {
            continue;
        }

        if (!ProductionComponent->AvailableProducts.Contains(PawnClass))
        {
            continue;
        }

        // Start production.
        ProductionComponent->StartProduction(PawnClass);
        return true;
    }

    // Get any own building location.
    APawn* OwnBuilding = nullptr;

    for (TActorIterator<APawn> PawnItr(GetWorld()); PawnItr; ++PawnItr)
    {
        APawn* SomePawn = *PawnItr;

        if (SomePawn->GetOwner() != this)
        {
            continue;
        }

        UTD2020ConstructionSiteComponent* ConstructionSiteComponent = SomePawn->FindComponentByClass<UTD2020ConstructionSiteComponent>();

        if (!ConstructionSiteComponent)
        {
            continue;
        }

        OwnBuilding = SomePawn;
        break;
    }

    // Find suitable builder.
    UWorld* World = GetWorld();

    if (!World)
    {
        return false;
    }

    for (TActorIterator<APawn> PawnItr(GetWorld()); PawnItr; ++PawnItr)
    {
        APawn* SomePawn = *PawnItr;

        if (SomePawn->GetOwner() != this)
        {
            continue;
        }

        UTD2020BuilderComponent* BuilderComponent = SomePawn->FindComponentByClass<UTD2020BuilderComponent>();

        if (!BuilderComponent)
        {
            continue;
        }

        if (!BuilderComponent->ConstructibleBuildingClasses.Contains(PawnClass))
        {
            continue;
        }

        ATD2020CharacterAIController* PawnController = Cast<ATD2020CharacterAIController>(SomePawn->GetController());

        if (!PawnController)
        {
            continue;
        }

        if (PawnController->HasOrder(ETD2020OrderType::ORDER_BeginConstruction) ||
            PawnController->HasOrder(ETD2020OrderType::ORDER_ContinueConstruction))
        {
            // Don't take builders away from constructing other buildings.
            continue;
        }

        // Find suitable building location: Get random nearby location.
        FVector TargetLocation = OwnBuilding != nullptr ? OwnBuilding->GetActorLocation() : SomePawn->GetActorLocation();
        TargetLocation.X += FMath::FRandRange(-MaximumBaseBuildingDistance, MaximumBaseBuildingDistance);
        TargetLocation.Y += FMath::FRandRange(-MaximumBaseBuildingDistance, MaximumBaseBuildingDistance);
        
        TargetLocation = UTD2020Utilities::GetGroundLocation(this, TargetLocation);

        // If there's a primary resource drain, prevent blocking its path.
        AActor* PrimaryResourceSource = GetPrimaryResourceSource();
        AActor* PrimaryResourceDrain = GetPrimaryResourceDrain();

        if (PrimaryResourceSource != nullptr &&
            PrimaryResourceDrain != nullptr &&
            FVector::DistSquaredXY(PrimaryResourceSource->GetActorLocation(), TargetLocation) <
            FVector::DistSquaredXY(PrimaryResourceSource->GetActorLocation(), PrimaryResourceDrain->GetActorLocation()))
        {
            continue;
        }

        // Issue construction order.
        PawnController->IssueBeginConstructionOrder(PawnClass, TargetLocation);
        return true;
    }

    return false;
}

void ATD2020PlayerAIController::OnPossess(APawn* InPawn)
{
    Super::Possess(InPawn);

    // Make AI use assigned blackboard.
    UBlackboardComponent* BlackboardComponent;

    if (!UseBlackboard(PlayerBlackboardAsset, BlackboardComponent))
    {
        UE_LOG(LogTD2020, Warning, TEXT("Failed to set up blackboard for AI %s."), *GetName());
    }

    // Run behavior tree.
    RunBehaviorTree(PlayerBehaviorTreeAsset);
}
