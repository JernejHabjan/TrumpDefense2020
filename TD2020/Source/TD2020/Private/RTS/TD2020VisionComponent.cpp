#include "TD2020.h"
#include "TD2020VisionComponent.h"
#include "Net/UnrealNetwork.h"

UTD2020VisionComponent::UTD2020VisionComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetIsReplicated(true);
}

void UTD2020VisionComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UTD2020VisionComponent, SightRadius);
}
