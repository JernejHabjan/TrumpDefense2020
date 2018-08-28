#pragma once


#include "GameFramework/PlayerState.h"

#include "TD2020PlayerState.generated.h"


class ATD2020TeamInfo;


/**
* Player state with TD2020 features, such as teams.
*/
UCLASS()
class TD2020_API ATD2020PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	/** Team this player belongs to. */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnTeamChanged, Category = "Team")
	ATD2020TeamInfo* Team;


	/** Checks whether this player belong to the same team as the specified one. */
	UFUNCTION(BlueprintCallable)
	bool IsSameTeamAs(ATD2020PlayerState* Other);


	UFUNCTION()
	void OnTeamChanged();

	/** Event when this player changed team. */
	virtual void NotifyOnTeamChanged(ATD2020TeamInfo* NewTeam);

	/** Event when this player changed team. */
	UFUNCTION(BlueprintImplementableEvent, Category = "TD2020|Team", meta = (DisplayName = "OnTeamChanged"))
	void ReceiveOnTeamChanged(ATD2020TeamInfo* NewTeam);
};
