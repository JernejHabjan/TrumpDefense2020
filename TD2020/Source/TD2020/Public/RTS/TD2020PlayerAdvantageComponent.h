#pragma once


#include "Components/ActorComponent.h"

#include "TD2020PlayerAdvantageComponent.generated.h"


/**
* Attach to player or AI controllers. Provides bonuses for various gameplay elements.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020PlayerAdvantageComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UTD2020PlayerAdvantageComponent(const FObjectInitializer& ObjectInitializer);

    /** Whether units controlled by the player are invulnerable, or not. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020|Advantage")
    bool bGodModeEnabled;

    /** Factor to multiply all construction and production speed with. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020|Advantage")
    float SpeedBoostFactor;
};
