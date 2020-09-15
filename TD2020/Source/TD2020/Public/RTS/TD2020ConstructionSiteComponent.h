#pragma once

#include "Components/ActorComponent.h"
#include "TD2020ConstructionState.h"
#include "TD2020ProductionCostType.h"
#include "TD2020ResourceType.h"
#include "TD2020ConstructionSiteComponent.generated.h"





/** Allows constructing the actor over time. */
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020ConstructionSiteComponent : public UActorComponent
{
	GENERATED_BODY()
};
