#include "TD2020.h"
#include "TD2020PlayerAdvantageComponent.h"

UTD2020PlayerAdvantageComponent::UTD2020PlayerAdvantageComponent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    bGodModeEnabled = false;
    SpeedBoostFactor = 1.0f;
}
