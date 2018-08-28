#include "TD2020.h"
#include "TD2020ResourceSourceComponent.h"
#include "TD2020ResourceType.h"
#include "Net/UnrealNetwork.h"
#include "Engine/World.h"
#include "TD2020ContainerComponent.h"


UTD2020ResourceSourceComponent::UTD2020ResourceSourceComponent(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	GatheringFactor = 1.0f;
	GathererCapacity = 1;

	SetIsReplicated(true);
}

void UTD2020ResourceSourceComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UTD2020ResourceSourceComponent, CurrentResources);
}

void UTD2020ResourceSourceComponent::BeginPlay()
{
	UActorComponent::BeginPlay();

	// Set container size.
	auto ContainerComponent = GetOwner()->FindComponentByClass<UTD2020ContainerComponent>();

	if (ContainerComponent)
	{
		ContainerComponent->Capacity = GathererCapacity;
	}
}

float UTD2020ResourceSourceComponent::ExtractResources(AActor* Gatherer, float ResourceAmount)
{
	// Compute actual amount gathered.
	float GatheredAmount = ResourceAmount * GatheringFactor;

	if (GatheredAmount > CurrentResources)
	{
		GatheredAmount = CurrentResources;
	}

	// Deduct resources.
	float OldResources = CurrentResources;
	CurrentResources -= GatheredAmount;
	float NewResources = CurrentResources;

	UE_LOG(LogTD2020, Log, TEXT("Actor %s has gathered %f resources of type %s from %s, reducing remaining resources to %f."),
		*Gatherer->GetName(),
		GatheredAmount,
		*ResourceType->GetName(),
		*GetOwner()->GetName(),
		CurrentResources);

	// Notify listeners.
	OnResourcesChanged.Broadcast(OldResources, NewResources);

	// Check if we're depleted.
	if (CurrentResources <= 0)
	{
		UE_LOG(LogTD2020, Log, TEXT("Actor %s has been depleted."), *GetOwner()->GetName());

        // Notify listeners.
        OnDepleted.Broadcast();

		// Destroy this actor.
		GetOwner()->Destroy();
	}

	return GatheredAmount;
}

bool UTD2020ResourceSourceComponent::CanGathererEnter(AActor* Gatherer) const
{
	auto ContainerComponent = GetOwner()->FindComponentByClass<UTD2020ContainerComponent>();
	return !ContainerComponent || ContainerComponent->ContainedActors.Contains(Gatherer) || ContainerComponent->CanLoadActor(Gatherer);
}
