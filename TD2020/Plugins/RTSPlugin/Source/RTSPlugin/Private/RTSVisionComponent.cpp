#include "RTSPluginPCH.h"
#include "RTSVisionComponent.h"
#include "Net/UnrealNetwork.h"

URTSVisionComponent::URTSVisionComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetIsReplicated(true);
}

void URTSVisionComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(URTSVisionComponent, SightRadius);
}
