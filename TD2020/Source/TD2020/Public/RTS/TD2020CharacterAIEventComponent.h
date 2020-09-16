#pragma once



#include "Components/ActorComponent.h"
#include "TD2020CharacterAIEventComponent.generated.h"




/**
* Allows interested listeners to register for AI events (e.g. issued orders).
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020CharacterAIEventComponent : public UActorComponent
{
    GENERATED_BODY()
};
