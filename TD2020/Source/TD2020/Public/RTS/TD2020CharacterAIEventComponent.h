#pragma once



#include "Components/ActorComponent.h"

#include "TD2020OrderType.h"

#include "TD2020CharacterAIEventComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTD2020CharacterAIEventComponentOrderChangedSignature, ETD2020OrderType, NewOrder);


/**
* Allows interested listeners to register for AI events (e.g. issued orders).
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020CharacterAIEventComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    /** Event when the actor has received a new order. */
    UPROPERTY(BlueprintAssignable, Category = "TD2020")
    FTD2020CharacterAIEventComponentOrderChangedSignature OnOrderChanged;
};
