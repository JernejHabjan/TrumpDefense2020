#include "TD2020.h"
#include "TD2020CharacterAIController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "TD2020AttackComponent.h"
#include "TD2020AttackableComponent.h"
#include "TD2020BuilderComponent.h"
#include "TD2020Character.h"
#include "TD2020CharacterAIEventComponent.h"
#include "TD2020GathererComponent.h"
#include "TD2020OwnerComponent.h"


void ATD2020CharacterAIController::OnPossess(APawn* InPawn)
{
    Super::Possess(InPawn);

	AttackComponent = InPawn->FindComponentByClass<UTD2020AttackComponent>();

    // Make AI use assigned blackboard.
    UBlackboardComponent* BlackboardComponent;

	if (UseBlackboard(CharacterBlackboardAsset, BlackboardComponent))
	{
		// Setup blackboard.
		IssueStopOrder();
	}

    // Run behavior tree.
    RunBehaviorTree(CharacterBehaviorTreeAsset);
}

void ATD2020CharacterAIController::FindTargetInAcquisitionRadius()
{
	if (!AttackComponent)
	{
		return;
	}

	// Find nearby actors.
	TArray<struct FHitResult> HitResults;
	TraceSphere(GetPawn()->GetActorLocation(), AttackComponent->AcquisitionRadius, GetPawn(), ECC_Pawn, HitResults);

	// Find target to acquire.
	for (auto& HitResult : HitResults)
	{
		if (HitResult.Actor == nullptr)
		{
			continue;
		}

		if (HitResult.Actor == GetPawn())
		{
			continue;
		}
		
		// Check owner.
		auto MyActor = GetPawn();
		auto TargetActor = HitResult.Actor.Get();

		if (MyActor && TargetActor)
		{
			auto MyOwnerComponent = MyActor->FindComponentByClass<UTD2020OwnerComponent>();

			if (MyOwnerComponent && MyOwnerComponent->IsSameTeamAsActor(TargetActor))
			{
				continue;
			}
		}

		// Check if found attackable actor.
		auto AttackableComponent = HitResult.Actor->FindComponentByClass<UTD2020AttackableComponent>();

		if (!AttackableComponent)
		{
			continue;
		}

		// Acquire target.
		Blackboard->SetValueAsObject(TEXT("TargetActor"), HitResult.Actor.Get());

		UE_LOG(LogTD2020, Log, TEXT("%s automatically acquired target %s."), *GetPawn()->GetName(), *HitResult.Actor->GetName());
		return;
	}
}

bool ATD2020CharacterAIController::HasOrder(ETD2020OrderType OrderType) const
{
    return Blackboard->GetValueAsEnum(TEXT("OrderType")) == (uint8)OrderType;
}

bool ATD2020CharacterAIController::IsIdle() const
{
    return HasOrder(ETD2020OrderType::ORDER_None);
}

void ATD2020CharacterAIController::IssueAttackOrder(AActor* Target)
{
	if (!VerifyBlackboard())
	{
		return;
	}

	// Update blackboard.
	SetOrderType(ETD2020OrderType::ORDER_Attack);
	ClearBuildingClass();
	ClearHomeLocation();
	SetTargetActor(Target);
	ClearTargetLocation();

	// Stop any current orders and start over.
	ApplyOrders();
}

void ATD2020CharacterAIController::IssueBeginConstructionOrder(TSubclassOf<AActor> BuildingClass, const FVector& TargetLocation)
{
	if (!VerifyBlackboard())
	{
		return;
	}

	// Somehow, classes are not properly serialized to blackboard values and back, so we're going to use the building index here instead.
	UTD2020BuilderComponent* BuilderComponent = GetPawn()->FindComponentByClass<UTD2020BuilderComponent>();

	if (!BuilderComponent)
	{
		return;
	}

	int32 BuildingIndex = BuilderComponent->ConstructibleBuildingClasses.IndexOfByKey(BuildingClass);

	if (BuildingIndex == INDEX_NONE)
	{
		return;
	}

	// Update blackboard.
	SetOrderType(ETD2020OrderType::ORDER_BeginConstruction);
	SetBuildingClass(BuildingIndex);
	ClearHomeLocation();
	ClearTargetActor();
	SetTargetLocation(TargetLocation);

	// Stop any current orders and start over.
	ApplyOrders();
}

void ATD2020CharacterAIController::IssueContinueConstructionOrder(AActor* ConstructionSite)
{
	if (!VerifyBlackboard())
	{
		return;
	}

	// Update blackboard.
	SetOrderType(ETD2020OrderType::ORDER_ContinueConstruction);
	ClearBuildingClass();
	ClearHomeLocation();
	SetTargetActor(ConstructionSite);
	ClearTargetLocation();

	// Stop any current orders and start over.
	ApplyOrders();
}

void ATD2020CharacterAIController::IssueGatherOrder(AActor* ResourceSource)
{
	if (!VerifyBlackboard())
	{
		return;
	}

	// Update blackboard.
	SetOrderType(ETD2020OrderType::ORDER_Gather);
	ClearBuildingClass();
	ClearHomeLocation();
	SetTargetActor(ResourceSource);
	ClearTargetLocation();

	// Stop any current orders and start over.
	ApplyOrders();
}

void ATD2020CharacterAIController::IssueMoveOrder(const FVector& Location)
{
	if (!VerifyBlackboard())
	{
		return;
	}

    // Update blackboard.
	SetOrderType(ETD2020OrderType::ORDER_Move);
	ClearBuildingClass();
	ClearHomeLocation();
	ClearTargetActor();
	SetTargetLocation(Location);

    // Stop any current orders and start over.
	ApplyOrders();
}

void ATD2020CharacterAIController::IssueReturnResourcesOrder()
{
	if (!VerifyBlackboard())
	{
		return;
	}

	auto GathererComponent = GetPawn()->FindComponentByClass<UTD2020GathererComponent>();

	if (!GathererComponent)
	{
		return;
	}

	AActor* ResourceDrain = GathererComponent->FindClosestResourceDrain();

	if (!ResourceDrain)
	{
		return;
	}

	// Update blackboard.
	SetOrderType(ETD2020OrderType::ORDER_ReturnResources);
	ClearBuildingClass();
	ClearHomeLocation();
	SetTargetActor(ResourceDrain);
	ClearTargetLocation();

	// Stop any current orders and start over.
	ApplyOrders();
}

void ATD2020CharacterAIController::IssueStopOrder()
{
	if (!VerifyBlackboard())
	{
		return;
	}

	// Update blackboard.
	SetOrderType(ETD2020OrderType::ORDER_None);
	ClearBuildingClass();
	SetHomeLocation(GetPawn()->GetActorLocation());
	ClearTargetActor();
	ClearTargetLocation();

	// Stop any current orders and start over.
	ApplyOrders();
}

void ATD2020CharacterAIController::ApplyOrders()
{
	UBehaviorTreeComponent* BehaviorTreeComponent = Cast<UBehaviorTreeComponent>(BrainComponent);
	if (BehaviorTreeComponent)
	{
		BehaviorTreeComponent->RestartTree();
	}

    UTD2020CharacterAIEventComponent* CharacterAIEventComponent = GetPawn()->FindComponentByClass<UTD2020CharacterAIEventComponent>();
    if (CharacterAIEventComponent)
    {
        uint8 NewOrder = Blackboard->GetValueAsEnum(TEXT("OrderType"));
        CharacterAIEventComponent->OnOrderChanged.Broadcast((ETD2020OrderType)NewOrder);
    }
}

void ATD2020CharacterAIController::ClearBuildingClass()
{
	Blackboard->ClearValue(TEXT("BuildingClass"));
}

void ATD2020CharacterAIController::ClearHomeLocation()
{
	Blackboard->ClearValue(TEXT("HomeLocation"));
}

void ATD2020CharacterAIController::ClearTargetActor()
{
	Blackboard->ClearValue(TEXT("TargetActor"));
}

void ATD2020CharacterAIController::ClearTargetLocation()
{
	Blackboard->ClearValue(TEXT("TargetLocation"));
}

void ATD2020CharacterAIController::SetBuildingClass(int32 BuildingIndex)
{
	Blackboard->SetValueAsInt(TEXT("BuildingClass"), BuildingIndex);
}

void ATD2020CharacterAIController::SetHomeLocation(const FVector& HomeLocation)
{
	Blackboard->SetValueAsVector(TEXT("HomeLocation"), HomeLocation);
}

void ATD2020CharacterAIController::SetOrderType(const ETD2020OrderType OrderType)
{
	Blackboard->SetValueAsEnum(TEXT("OrderType"), (uint8)OrderType);
}

void ATD2020CharacterAIController::SetTargetActor(AActor* TargetActor)
{
	Blackboard->SetValueAsObject(TEXT("TargetActor"), TargetActor);
}

void ATD2020CharacterAIController::SetTargetLocation(const FVector& TargetLocation)
{
	Blackboard->SetValueAsVector(TEXT("TargetLocation"), TargetLocation);
}

bool ATD2020CharacterAIController::TraceSphere(
	const FVector& Location,
	const float Radius,
	AActor* ActorToIgnore,
	ECollisionChannel TraceChannel,
	TArray<struct FHitResult>& OutHitResults)
{
	UWorld* World = GetWorld();

	if (!World)
	{
		return false;
	}

	const FVector Start = Location;
	const FVector End = Location + FVector::ForwardVector * Radius;

	return World->SweepMultiByObjectType(
		OutHitResults,
		Start,
		End,
		FQuat(),
		FCollisionObjectQueryParams(TraceChannel),
		FCollisionShape::MakeSphere(Radius)
	);
}

bool ATD2020CharacterAIController::VerifyBlackboard()
{
	if (!Blackboard)
	{
		UE_LOG(LogTD2020, Warning, TEXT("Blackboard not set up for %s, can't receive orders. Check AI Controller Class and Auto Possess AI."), *GetPawn()->GetName());
		return false;
	}

	return true;
}
