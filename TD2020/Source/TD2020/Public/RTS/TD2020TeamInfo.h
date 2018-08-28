#pragma once
#include "GameFramework/Info.h"
#include "TD2020TeamInfo.generated.h"

/**
* Team that consists of multiple players.
*/
UCLASS()
class TD2020_API ATD2020TeamInfo : public AInfo
{
	GENERATED_BODY()

	ATD2020TeamInfo();

public:
	/** Index of this team. */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = ReceivedTeamIndex, Category = "Team")
	uint8 TeamIndex;

	/** Adds the specified player to this team. */
	UFUNCTION(BlueprintCallable, Category = "Team")
	virtual void AddToTeam(AController* Player);

	/** Removes the specified player from this team. */
	UFUNCTION(BlueprintCallable, Category = "Team")
	virtual void RemoveFromTeam(AController* Player);

	/** Gets all players belonging to this  team. */
	UFUNCTION()
	TArray<AController*> GetTeamMembers();


protected:
	UFUNCTION()
	virtual void ReceivedTeamIndex();

private:
	/** Players on this team. */
	TArray<AController*> TeamMembers;
};
