#pragma once


#include "TD2020OrderType.generated.h"


UENUM(BlueprintType)
enum class ETD2020OrderType : uint8
{
    /** Idle. */
    ORDER_None,

    /** Move to a destination in the world. */
    ORDER_Move,

    /** Attack another actor. */
    ORDER_Attack,

    /** Create a new construction site. */
    ORDER_BeginConstruction,

    /** Finish a building construction. */
    ORDER_ContinueConstruction,

    /** Gather resources. */
    ORDER_Gather,

    /** Return carried resources. */
    ORDER_ReturnResources,

    ORDER_AttackMove
};
