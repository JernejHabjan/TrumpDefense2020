#include "TD2020.h"
#include "TD2020ContainerComponent.h"

#include "GameFramework/Actor.h"


UTD2020ContainerComponent::UTD2020ContainerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UTD2020ContainerComponent::CanLoadActor(AActor* Actor) const
{
	return Capacity < 0 || ContainedActors.Num() < Capacity;
}

void UTD2020ContainerComponent::LoadActor(AActor* Actor)
{
	if (!CanLoadActor(Actor))
	{
		return;
	}

	if (ContainedActors.Contains(Actor))
	{
		return;
	}

	// Add to container.
	ContainedActors.Add(Actor);

	// Hide actor.
	Actor->SetActorHiddenInGame(true);
	Actor->SetActorEnableCollision(false);

	// Notify listeners.
	OnActorEntered.Broadcast(Actor);

	UE_LOG(LogTD2020, Log, TEXT("Actor %s has entered %s."), *Actor->GetName(), *GetOwner()->GetName());
}

void UTD2020ContainerComponent::UnloadActor(AActor* Actor)
{
	if (!ContainedActors.Contains(Actor))
	{
		return;
	}

	// Remove from container.
	ContainedActors.Remove(Actor);

	// Show actor.
	Actor->SetActorHiddenInGame(false);
	Actor->SetActorEnableCollision(true);

	// Notify listeners.
	OnActorLeft.Broadcast(Actor);

	UE_LOG(LogTD2020, Log, TEXT("Actor %s has left %s."), *Actor->GetName(), *GetOwner()->GetName());
}
