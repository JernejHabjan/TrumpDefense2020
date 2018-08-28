#pragma once


#include "GameFramework/GameStateBase.h"

#include "TD2020GameState.generated.h"


class ATD2020TeamInfo;


/**
* Game state with TD2020 features, such as teams.
*/
UCLASS()
class TD2020_API ATD2020GameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	/** Teams of the current match. */
	UPROPERTY(BlueprintReadOnly, Category = "Team")
	TArray<ATD2020TeamInfo*> Teams;
};
