#include "TD2020.h"
#include "TD2020TeamInfo.h"

#include "TD2020GameState.h"
#include "TD2020PlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Engine/World.h"

ATD2020TeamInfo::ATD2020TeamInfo()
{
	SetReplicates(true);
	bAlwaysRelevant = true;
	NetUpdateFrequency = 1.0f;

	// Force ReceivedTeamIndex() on clients.
	TeamIndex = 255;
}

void ATD2020TeamInfo::AddToTeam(AController* Player)
{
	if (Player == nullptr)
	{
		return;
	}

	ATD2020PlayerState* PlayerState = Cast<ATD2020PlayerState>(Player->PlayerState);
	if (PlayerState == nullptr)
	{
		return;
	}

	if (PlayerState->Team != nullptr)
	{
		RemoveFromTeam(Player);
	}

	PlayerState->Team = this;
	PlayerState->NotifyOnTeamChanged(this);

	TeamMembers.Add(Player);
}

void ATD2020TeamInfo::RemoveFromTeam(AController* Player)
{
	if (Player == nullptr)
	{
		return;
	}
	
	if (!TeamMembers.Contains(Player))
	{
		return;
	}

	TeamMembers.Remove(Player);

	ATD2020PlayerState* PlayerState = Cast<ATD2020PlayerState>(Player->PlayerState);

	if (PlayerState != nullptr)
	{
		PlayerState->Team = nullptr;
		PlayerState->NotifyOnTeamChanged(nullptr);
	}
}

TArray<AController*> ATD2020TeamInfo::GetTeamMembers()
{
	return TeamMembers;
}

void ATD2020TeamInfo::ReceivedTeamIndex()
{
	if (TeamIndex == 255)
	{
		return;
	}

	ATD2020GameState* GameState = GetWorld()->GetGameState<ATD2020GameState>();
	if (GameState == nullptr)
	{
		return;
	}

	if (GameState->Teams.Num() <= TeamIndex)
	{
		GameState->Teams.SetNum(TeamIndex + 1);
	}

	GameState->Teams[TeamIndex] = this;
}

void ATD2020TeamInfo::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ATD2020TeamInfo, TeamIndex, COND_InitialOnly);
}
