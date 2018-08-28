#pragma once


#include "GameFramework/Volume.h"

#include "TD2020CameraBoundsVolume.generated.h"


/**
 * Volume that restricts TD2020 camera movement.
 * TD2020 cameras are not allowed to move outside of this volume.
 * There should never be more than one camera bounds volume per level.
 */
UCLASS()
class TD2020_API ATD2020CameraBoundsVolume : public AVolume
{
    GENERATED_UCLASS_BODY()
};
