#pragma once


#include "Components/ActorComponent.h"

#include "TD2020HealthComponent.generated.h"



/**
* Adds health to the actor, e.g. for taking damage and dying.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020HealthComponent : public UActorComponent
{
	GENERATED_BODY()

};
