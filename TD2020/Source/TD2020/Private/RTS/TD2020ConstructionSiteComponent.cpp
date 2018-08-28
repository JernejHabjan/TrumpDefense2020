#include "TD2020.h"
#include "TD2020ConstructionSiteComponent.h"

#include "GameFramework/Actor.h"

#include "TD2020BuilderComponent.h"
#include "TD2020ContainerComponent.h"
#include "TD2020PlayerAdvantageComponent.h"
#include "TD2020PlayerResourcesComponent.h"
#include "TD2020ResourceType.h"
#include "Net/UnrealNetwork.h"

UTD2020ConstructionSiteComponent::UTD2020ConstructionSiteComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;

	SetIsReplicated(true);

	State = ETD2020ConstructionState::CONSTRUCTIONSTATE_NotStarted;
	RefundFactor = 0.5f;
}

void UTD2020ConstructionSiteComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UTD2020ConstructionSiteComponent, RemainingConstructionTime);
}

void UTD2020ConstructionSiteComponent::BeginPlay()
{
	UActorComponent::BeginPlay();

	// Set container size.
	auto ContainerComponent = GetOwner()->FindComponentByClass<UTD2020ContainerComponent>();

	if (ContainerComponent)
	{
		ContainerComponent->Capacity = MaxAssignedBuilders;
	}
}

void UTD2020ConstructionSiteComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	UActorComponent::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Check for autostart.
	if (State == ETD2020ConstructionState::CONSTRUCTIONSTATE_NotStarted && bStartImmediately)
	{
		StartConstruction();
	}
	else if (State == ETD2020ConstructionState::CONSTRUCTIONSTATE_Finished)
	{
		return;
	}

    // Check for speed boosts.
    float SpeedBoostFactor = 1.0f;
    AActor* OwningActor = GetOwner();

    if (OwningActor)
    {
        AActor* OwningPlayer = OwningActor->GetOwner();

        if (OwningPlayer)
        {
            UTD2020PlayerAdvantageComponent* PlayerAdvantageComponent = OwningPlayer->FindComponentByClass<UTD2020PlayerAdvantageComponent>();

            if (PlayerAdvantageComponent)
            {
                SpeedBoostFactor = PlayerAdvantageComponent->SpeedBoostFactor;
            }
        }
    }

	// Compute construction progress based on number of assigned builders.
	float ConstructionProgress =
        (DeltaTime * ProgressMadeAutomatically * SpeedBoostFactor) +
        (DeltaTime * ProgressMadePerBuilder * AssignedBuilders.Num() * SpeedBoostFactor);

	// Check construction costs.
	bool bConstructionCostPaid = false;

	if (ConstructionCostType == ETD2020ProductionCostType::COST_PayOverTime)
	{
        auto Owner = GetOwner()->GetOwner();

        if (!Owner)
        {
            UE_LOG(LogTD2020, Error, TEXT("%s needs to pay for construction, but has no owner."), *Owner->GetName());
            return;
        }

        auto PlayerResourcesComponent = Owner->FindComponentByClass<UTD2020PlayerResourcesComponent>();

		if (!PlayerResourcesComponent)
		{
			UE_LOG(LogTD2020, Error, TEXT("%s needs to pay for construction, but has no PlayerResourcesComponent."), *Owner->GetName());
			return;
		}

		bool bCanPayAllConstructionCosts = true;

		for (auto& Resource : ConstructionCosts)
		{
			float ResourceAmount = Resource.Value * ConstructionProgress / ConstructionTime;

			if (!PlayerResourcesComponent->CanPayResources(Resource.Key, ResourceAmount))
			{
				// Construction stopped until resources become available again.
				bCanPayAllConstructionCosts = false;
				break;
			}
		}

		if (bCanPayAllConstructionCosts)
		{
			// Pay construction costs.
			for (auto& Resource : ConstructionCosts)
			{
				float ResourceAmount = Resource.Value * ConstructionProgress / ConstructionTime;
                PlayerResourcesComponent->PayResources(Resource.Key, ResourceAmount);
			}

			bConstructionCostPaid = true;
		}
	}
	else
	{
		bConstructionCostPaid = true;
	}

	if (!bConstructionCostPaid)
	{
		return;
	}

	// Update construction progress.
	RemainingConstructionTime -= ConstructionProgress;

	// Check if finished.
	if (RemainingConstructionTime <= 0)
	{
		FinishConstruction();
	}
}

bool UTD2020ConstructionSiteComponent::CanAssignBuilder(AActor* Builder) const
{
	return AssignedBuilders.Num() < MaxAssignedBuilders;
}

float UTD2020ConstructionSiteComponent::GetProgressPercentage() const
{
	return 1 - (RemainingConstructionTime / ConstructionTime);
}

bool UTD2020ConstructionSiteComponent::IsConstructing() const
{
	return State == ETD2020ConstructionState::CONSTRUCTIONSTATE_Constructing;
}

bool UTD2020ConstructionSiteComponent::IsFinished() const
{
	return State == ETD2020ConstructionState::CONSTRUCTIONSTATE_Finished;
}

void UTD2020ConstructionSiteComponent::StartConstruction()
{
	if (State != ETD2020ConstructionState::CONSTRUCTIONSTATE_NotStarted)
	{
		return;
	}

	// Check construction cost.
	if (ConstructionCostType == ETD2020ProductionCostType::COST_PayImmediately)
	{
        auto Owner = GetOwner()->GetOwner();

        if (!Owner)
        {
            UE_LOG(LogTD2020, Error, TEXT("%s needs to pay for construction, but has no owner."), *Owner->GetName());
            return;
        }

        auto PlayerResourcesComponent = Owner->FindComponentByClass<UTD2020PlayerResourcesComponent>();

		if (!PlayerResourcesComponent)
		{
			UE_LOG(LogTD2020, Error, TEXT("%s needs to pay for construction, but has no PlayerResourcesComponent."), *Owner->GetName());
			CancelConstruction();
			return;
		}

		if (!PlayerResourcesComponent->CanPayAllResources(ConstructionCosts))
		{
			UE_LOG(LogTD2020, Error, TEXT("%s needs to pay for constructing %s, but does not have enough resources."),
				*Owner->GetName(),
				*GetOwner()->GetName());
			CancelConstruction();
			return;
		}

		// Pay construction costs.
        PlayerResourcesComponent->PayAllResources(ConstructionCosts);
	}

	// Start construction.
	RemainingConstructionTime = ConstructionTime;
	State = ETD2020ConstructionState::CONSTRUCTIONSTATE_Constructing;

	UE_LOG(LogTD2020, Log, TEXT("Construction %s started."), *GetName());

	// Notify listeners.
	OnConstructionStarted.Broadcast(ConstructionTime);
}

void UTD2020ConstructionSiteComponent::FinishConstruction()
{
	RemainingConstructionTime = 0;
	State = ETD2020ConstructionState::CONSTRUCTIONSTATE_Finished;

	UE_LOG(LogTD2020, Log, TEXT("Construction %s finished."), *GetOwner()->GetName());

	// Notify builders.
	if (bConsumesBuilders)
	{
		for (AActor* Builder : AssignedBuilders)
		{
			Builder->Destroy();
			OnBuilderConsumed.Broadcast(Builder);
		}
	}

	// Notify listeners.
	OnConstructionFinished.Broadcast();
}

void UTD2020ConstructionSiteComponent::CancelConstruction()
{
	if (IsFinished())
	{
		return;
	}

	UE_LOG(LogTD2020, Log, TEXT("Construction %s canceled."), *GetName());

	// Refund resources.
    auto Owner = GetOwner()->GetOwner();

    if (Owner)
    {
        auto PlayerResourcesComponent = Owner->FindComponentByClass<UTD2020PlayerResourcesComponent>();

        if (!PlayerResourcesComponent)
        {
            float TimeRefundFactor = 0.0f;

            if (ConstructionCostType == ETD2020ProductionCostType::COST_PayImmediately)
            {
                TimeRefundFactor = 1.0f;
            }
            else if (ConstructionCostType == ETD2020ProductionCostType::COST_PayOverTime)
            {
                TimeRefundFactor = GetProgressPercentage();
            }

            float ActualRefundFactor = RefundFactor * TimeRefundFactor;

            // Refund construction costs.
            for (auto& Resource : ConstructionCosts)
            {
                TSubclassOf<UTD2020ResourceType> ResourceType = Resource.Key;
                float ResourceAmount = Resource.Value * ActualRefundFactor;

                PlayerResourcesComponent->AddResources(ResourceType, ResourceAmount);

                UE_LOG(LogTD2020, Log, TEXT("%f %s of construction costs refunded."), ResourceAmount, *ResourceType->GetName());

                // Notify listeners.
                OnConstructionCostRefunded.Broadcast(ResourceType, ResourceAmount);
            }
        }
    }

	// Destroy construction site.
	GetOwner()->Destroy();

	// Notify listeners.
	OnConstructionCanceled.Broadcast();
}
