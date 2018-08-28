#include "TD2020.h"
#include "TD2020PortraitComponent.h"

#include "TD2020PlayerState.h"
#include "TD2020TeamInfo.h"
#include "Net/UnrealNetwork.h"
#include "TD2020OwnerComponent.h"
#include "GameFramework/Controller.h"

UTD2020OwnerComponent::UTD2020OwnerComponent(const FObjectInitializer& ObjectInitializer)
{
	SetIsReplicated(true);
}

void UTD2020OwnerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UTD2020OwnerComponent, PlayerOwner);
}


ATD2020PlayerState* UTD2020OwnerComponent::GetPlayerOwner()
{
	return PlayerOwner;
}

void UTD2020OwnerComponent::SetPlayerOwner(AController* Controller)
{
	ATD2020PlayerState* PreviousOwner = PlayerOwner;

	if (!Controller)
	{
		PlayerOwner = nullptr;
	}
	else
	{
		PlayerOwner = Cast<ATD2020PlayerState>(Controller->PlayerState);
	}

	if (PlayerOwner != PreviousOwner)
	{
		// Notify listeners.
		OnOwnerChanged.Broadcast(Controller);
	}
}

bool UTD2020OwnerComponent::IsSameTeamAsActor(AActor* Other)
{
	if (!Other)
	{
		return false;
	}

	ATD2020PlayerState* MyOwner = GetPlayerOwner();

	if (!MyOwner)
	{
		return false;
	}

	UTD2020OwnerComponent* OtherOwnerComponent = Other->FindComponentByClass<UTD2020OwnerComponent>();

	if (!OtherOwnerComponent)
	{
		return false;
	}

	ATD2020PlayerState* OtherOwner = OtherOwnerComponent->GetPlayerOwner();

	return MyOwner->IsSameTeamAs(OtherOwner);
}

bool UTD2020OwnerComponent::IsSameTeamAsController(AController* C)
{
	ATD2020PlayerState* MyOwner = GetPlayerOwner();
	ATD2020PlayerState* OtherPlayer = Cast<ATD2020PlayerState>(C->PlayerState);

	return MyOwner && MyOwner->IsSameTeamAs(OtherPlayer);
}
