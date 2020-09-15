#pragma once

#include "Components/ActorComponent.h"
#include "TD2020ProductionCostType.h"
#include "TD2020ResourceType.h" // NEW
#include "TD2020ProductionCostComponent.generated.h"


//class UTD2020ResourceType;


/** Specifies the time and resources required to construct the actor. */
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020ProductionCostComponent : public UActorComponent
{
	GENERATED_BODY()

};
