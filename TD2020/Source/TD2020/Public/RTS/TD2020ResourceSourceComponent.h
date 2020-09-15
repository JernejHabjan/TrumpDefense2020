#pragma once
#include "Components/ActorComponent.h"
#include "Templates/SubclassOf.h"
//#include "TD2020ResourceType.h" // NEW
#include "TD2020ResourceSourceComponent.generated.h"


/**
* Adds resources to be gathered from the actor.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020ResourceSourceComponent : public UActorComponent
{
	GENERATED_BODY()

};
