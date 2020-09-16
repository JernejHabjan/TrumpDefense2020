#pragma once


#include "Components/ActorComponent.h"
#include "TD2020PlayerResourcesComponent.generated.h"

//class UTD2020ResourceType;


/**
* Attach to player or AI controllers. Allows the controller to store resources.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020PlayerResourcesComponent : public UActorComponent
{
    GENERATED_BODY()
	UTD2020PlayerResourcesComponent(const FObjectInitializer& ObjectInitializer);

};
