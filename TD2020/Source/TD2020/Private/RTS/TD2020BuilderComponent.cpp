#include "TD2020.h"
#include "TD2020BuilderComponent.h"

#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"

#include "TD2020CharacterAIController.h"
#include "TD2020ConstructionSiteComponent.h"
#include "TD2020ContainerComponent.h"
#include "TD2020GameMode.h"
#include "TD2020Utilities.h"


void UTD2020BuilderComponent::AssignToConstructionSite(AActor* ConstructionSite)
{
	if (!ConstructionSite)
	{
		return;
	}

	if (AssignedConstructionSite == ConstructionSite)
	{
		return;
	}

	auto ConstructionSiteComponent = ConstructionSite->FindComponentByClass<UTD2020ConstructionSiteComponent>();

	if (!ConstructionSiteComponent)
	{
		return;
	}

	if (ConstructionSiteComponent->CanAssignBuilder(GetOwner()))
	{
		// Assign builder.
		AssignedConstructionSite = ConstructionSite;
		ConstructionSiteComponent->AssignedBuilders.Add(GetOwner());

		// Notify listeners.
		OnAssignedToConstructionSite.Broadcast(ConstructionSite);

		UE_LOG(LogTD2020, Log, TEXT("Builder %s assigned to construction site %s."), *GetOwner()->GetName(), *ConstructionSite->GetName());

		if (bEnterConstructionSite)
		{
			// Enter construction site.
			auto ContainerComponent = ConstructionSite->FindComponentByClass<UTD2020ContainerComponent>();

			if (ContainerComponent)
			{
				ContainerComponent->LoadActor(GetOwner());
				OnConstructionSiteEntered.Broadcast(ConstructionSite);
			}
		}
	}
}

void UTD2020BuilderComponent::BeginConstruction(TSubclassOf<AActor> BuildingClass, const FVector& TargetLocation)
{
	// Get game, pawn and controller.
	ATD2020GameMode* GameMode = Cast<ATD2020GameMode>(UGameplayStatics::GetGameMode(this));

	if (!GameMode)
	{
		return;
	}

    auto Pawn = Cast<APawn>(GetOwner());

    if (!Pawn)
    {
        return;
    }

    auto PawnController = Cast<ATD2020CharacterAIController>(Pawn->GetController());

    if (!PawnController)
    {
        return;
    }

    // Check requirements.
    TSubclassOf<AActor> MissingRequirement;

    if (UTD2020Utilities::GetMissingRequirementFor(this, GetOwner(), BuildingClass, MissingRequirement))
    {
        UE_LOG(LogTD2020, Error, TEXT("Builder %s wants to build %s, but is missing requirement %s."), *GetOwner()->GetName(), *BuildingClass->GetName(), *MissingRequirement->GetName());

        // Player is missing a required actor. Stop.
        PawnController->IssueStopOrder();
        return;
    }

    // Move builder away in order to avoid collision.
    FVector BuilderLocation = Pawn->GetActorLocation();
    FVector ToTargetLocation = TargetLocation - BuilderLocation;
    ToTargetLocation.Z = 0.0f;
    FVector ToTargetLocationNormalized = ToTargetLocation.GetSafeNormal();
    float SafetyDistance = 
        (UTD2020Utilities::GetActorCollisionSize(Pawn) / 2 +
         UTD2020Utilities::GetCollisionSize(BuildingClass) / 2)
        + ConstructionSiteOffset;

    FVector SafeBuilderLocation = TargetLocation - ToTargetLocationNormalized * SafetyDistance;
    SafeBuilderLocation.Z = BuilderLocation.Z;

    Pawn->SetActorLocation(SafeBuilderLocation);

	// Spawn building.
	AActor* Building = GameMode->SpawnActorForPlayer(
		BuildingClass,
		Cast<AController>(GetOwner()->GetOwner()),
		FTransform(FRotator::ZeroRotator, TargetLocation));

	if (!Building)
	{
		return;
	}

	// Notify listeners.
	OnConstructionStarted.Broadcast(Building);

	UE_LOG(LogTD2020, Log, TEXT("Builder %s has created construction site %s."), *GetOwner()->GetName(), *Building->GetName());

	// Issue construction order.
	PawnController->IssueContinueConstructionOrder(Building);
}

void UTD2020BuilderComponent::BeginConstructionByIndex(int32 BuildingIndex, const FVector& TargetLocation)
{
	if (BuildingIndex < 0 || BuildingIndex >= ConstructibleBuildingClasses.Num())
	{
		return;
	}

	BeginConstruction(ConstructibleBuildingClasses[BuildingIndex], TargetLocation);
}

AActor* UTD2020BuilderComponent::GetAssignedConstructionSite()
{
	return AssignedConstructionSite;
}

void UTD2020BuilderComponent::LeaveConstructionSite()
{
	if (!AssignedConstructionSite)
	{
		return;
	}

	auto ConstructionSite = AssignedConstructionSite;
	auto ConstructionSiteComponent = ConstructionSite->FindComponentByClass<UTD2020ConstructionSiteComponent>();

	if (!ConstructionSiteComponent)
	{
		return;
	}

	// Remove builder.
	AssignedConstructionSite = nullptr;
	ConstructionSiteComponent->AssignedBuilders.Remove(GetOwner());

	// Notify listeners.
	OnRemovedFromConstructionSite.Broadcast(ConstructionSite);

	UE_LOG(LogTD2020, Log, TEXT("Builder %s has been unassigned from construction site %s."), *GetOwner()->GetName(), *ConstructionSite->GetName());

	if (bEnterConstructionSite)
	{
		// Leave construction site.
		auto ContainerComponent = ConstructionSite->FindComponentByClass<UTD2020ContainerComponent>();

		if (ContainerComponent)
		{
			ContainerComponent->UnloadActor(GetOwner());
			OnConstructionSiteLeft.Broadcast(ConstructionSite);
		}
	}
}
