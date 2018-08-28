#pragma once


#include "Components/ActorComponent.h"

#include "TD2020NameComponent.generated.h"


/**
* Adds a localizable name to the actor.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020NameComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    /** Name of the actor. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
    FText Name;
};
