#include "TD2020.h"
#include "TD2020ResourceDrainComponent.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"

#include "TD2020PlayerResourcesComponent.h"


UTD2020ResourceDrainComponent::UTD2020ResourceDrainComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GathererCapacity = 1;
}

float UTD2020ResourceDrainComponent::ReturnResources(AActor* Gatherer, TSubclassOf<UTD2020ResourceType> ResourceType, float ResourceAmount)
{
	// Notify player.
	auto Owner = GetOwner()->GetOwner();

	if (!Owner)
	{
		return 0.0f;
	}

    auto PlayerResourcesComponent = Owner->FindComponentByClass<UTD2020PlayerResourcesComponent>();

    if (!PlayerResourcesComponent)
    {
        return 0.0f;
    }

	float ReturnedResources = PlayerResourcesComponent->AddResources(ResourceType, ResourceAmount);

	if (ReturnedResources <= 0.0f)
	{
		return 0.0f;
	}

	UE_LOG(LogTD2020, Log, TEXT("Actor %s has returned %f resources of type %s to %s."),
		*Gatherer->GetName(),
		ReturnedResources,
		*ResourceType->GetName(),
		*GetOwner()->GetName());

	// Notify listeners.
	OnResourcesReturned.Broadcast(Gatherer, ResourceType, ReturnedResources);
	return ReturnedResources;
}
