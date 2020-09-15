#pragma once



#include "Components/ActorComponent.h"
#include "TD2020AttackComponent.generated.h"

/**
* Adds one or more attacks to the actor.
* These can also be used for healing.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020AttackComponent : public UActorComponent
{
	GENERATED_BODY()
};
