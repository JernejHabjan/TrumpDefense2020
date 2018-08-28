#include "TD2020.h"
#include "TD2020PlayerState.h"

#include "TD2020PlayerController.h"
#include "TD2020TeamInfo.h"
#include "Net/UnrealNetwork.h"

bool ATD2020PlayerState::IsSameTeamAs(ATD2020PlayerState* Other)
{
	if (!Other)
	{
		return false;
	}

	ATD2020TeamInfo* FirstTeam = Team;
	ATD2020TeamInfo* SecondTeam = Other->Team;

	if (!FirstTeam || !SecondTeam)
	{
		return false;
	}

	return FirstTeam->TeamIndex == SecondTeam->TeamIndex;
}

void ATD2020PlayerState::OnTeamChanged()
{
	NotifyOnTeamChanged(Team);
}

void ATD2020PlayerState::NotifyOnTeamChanged(ATD2020TeamInfo* NewTeam)
{
	if (NewTeam)
	{
		UE_LOG(LogTD2020, Log, TEXT("Player %s added to team %d."), *GetName(), NewTeam->TeamIndex);
	}
	else
	{
		UE_LOG(LogTD2020, Log, TEXT("Player %s added to team None."), *GetName());
	}

	// Notify listeners.
	ReceiveOnTeamChanged(NewTeam);

	// Notify player.
	ATD2020PlayerController* PlayerController = Cast<ATD2020PlayerController>(GetOwner());

	if (PlayerController)
	{
		PlayerController->NotifyOnTeamChanged(NewTeam);
	}
}

void ATD2020PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATD2020PlayerState, Team);
}
