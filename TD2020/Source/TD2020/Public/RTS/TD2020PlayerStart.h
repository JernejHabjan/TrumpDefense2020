#pragma once


#include "GameFramework/PlayerStart.h"

#include "TD2020PlayerStart.generated.h"


/**
* Player start with TD2020 features, such as which player has been spawned at this start.
*/
UCLASS()
class TD2020_API ATD2020PlayerStart : public APlayerStart
{
	GENERATED_BODY()

public:
	/** Team to add the spawned player to. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Team")
	int32 TeamIndex;

	/** Player who's been spawned at this start. */
	AController* Player;
};
