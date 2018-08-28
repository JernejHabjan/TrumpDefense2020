#pragma once


#include "Components/ActorComponent.h"

#include "TD2020RequirementsComponent.generated.h"


class AActor;


/** Adds tech tree requirements to the actor. */
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020RequirementsComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    /** Types of actors the player needs to own in order to create this actor. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
    TArray<TSubclassOf<AActor>> RequiredActors;
};
