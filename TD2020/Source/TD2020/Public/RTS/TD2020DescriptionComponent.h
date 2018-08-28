#pragma once


#include "Components/ActorComponent.h"

#include "TD2020DescriptionComponent.generated.h"


/**
* Adds a localizable description to the actor.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020DescriptionComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    /** Description of the actor. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
    FText Description;
};
