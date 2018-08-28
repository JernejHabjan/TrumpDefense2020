#include "TD2020.h"
#include "TD2020PlayerResourcesComponent.h"

#include "GameFramework/Actor.h"

#include "TD2020ResourceType.h"
#include "Net/UnrealNetwork.h"

UTD2020PlayerResourcesComponent::UTD2020PlayerResourcesComponent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    SetIsReplicated(true);
}

void UTD2020PlayerResourcesComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(UTD2020PlayerResourcesComponent, ResourceAmounts);
    DOREPLIFETIME(UTD2020PlayerResourcesComponent, ResourceTypes);
}


void UTD2020PlayerResourcesComponent::BeginPlay()
{
	UActorComponent::BeginPlay();

    // Check resource types.
    int32 ResourceTypeNum = ResourceTypes.Num();
    int32 ResourceAmountNum = ResourceAmounts.Num();

    for (int32 Index = ResourceAmountNum; Index < ResourceTypeNum; ++Index)
    {
        UE_LOG(LogTD2020, Warning, TEXT("Starting amount for resource type %s not set for player %s, assuming zero."),
            *ResourceTypes[Index]->GetName(),
            *GetOwner()->GetName());

        ResourceAmounts.Add(0);
    }
}

bool UTD2020PlayerResourcesComponent::GetResources(TSubclassOf<UTD2020ResourceType> ResourceType, float* OutResourceAmount)
{
    // Get current resource amount.
    int32 ResourceIndex = ResourceTypes.IndexOfByKey(ResourceType);

    if (ResourceIndex == INDEX_NONE)
    {
        UE_LOG(LogTD2020, Error, TEXT("Unknown resource type %s for player %s."),
            *ResourceType->GetName(),
            *GetOwner()->GetName());

        *OutResourceAmount = 0.0f;
        return false;
    }

    *OutResourceAmount = ResourceAmounts[ResourceIndex];
    return true;
}

bool UTD2020PlayerResourcesComponent::CanPayResources(TSubclassOf<UTD2020ResourceType> ResourceType, float ResourceAmount)
{
    float AvailableResources;

    if (!GetResources(ResourceType, &AvailableResources))
    {
        return false;
    }

    if (AvailableResources < ResourceAmount)
    {
        return false;
    }

    return true;
}

bool UTD2020PlayerResourcesComponent::CanPayAllResources(TMap<TSubclassOf<UTD2020ResourceType>, float> Resources)
{
    for (auto& Resource : Resources)
    {
        if (!CanPayResources(Resource.Key, Resource.Value))
        {
            return false;
        }
    }

    return true;
}

float UTD2020PlayerResourcesComponent::AddResources(TSubclassOf<UTD2020ResourceType> ResourceType, float ResourceAmount)
{
    // Get current resource amount.
    float OldResourceAmount;
    if (!GetResources(ResourceType, &OldResourceAmount))
    {
        return 0.0f;
    }

    // Add resources.
    int32 ResourceIndex = ResourceTypes.IndexOfByKey(ResourceType);
    float NewResourceAmount = OldResourceAmount + ResourceAmount;
    ResourceAmounts[ResourceIndex] = NewResourceAmount;

    UE_LOG(LogTD2020, Log, TEXT("Player %s stock of %s has changed to %f."),
        *GetOwner()->GetName(),
        *ResourceType->GetName(),
        NewResourceAmount);

    // Notify listeners.
    OnResourcesChanged.Broadcast(ResourceType, OldResourceAmount, NewResourceAmount, false);
    return ResourceAmount;
}

float UTD2020PlayerResourcesComponent::PayResources(TSubclassOf<UTD2020ResourceType> ResourceType, float ResourceAmount)
{
    // Get current resource amount.
    float OldResourceAmount;
    if (!GetResources(ResourceType, &OldResourceAmount))
    {
        return 0.0f;
    }

    if (OldResourceAmount < ResourceAmount)
    {
        return 0.0f;
    }

    // Deduct resources.
    return AddResources(ResourceType, -ResourceAmount);
}

void UTD2020PlayerResourcesComponent::PayAllResources(TMap<TSubclassOf<UTD2020ResourceType>, float> Resources)
{
    for (auto& Resource : Resources)
    {
        PayResources(Resource.Key, Resource.Value);
    }
}

void UTD2020PlayerResourcesComponent::ReceivedResourceAmounts()
{
    for (int32 Index = 0; Index < ResourceTypes.Num(); ++Index)
    {
        OnResourcesChanged.Broadcast(ResourceTypes[Index], 0.0f, ResourceAmounts[Index], true);
    }
}
