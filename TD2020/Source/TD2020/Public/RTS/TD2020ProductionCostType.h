#pragma once


#include "TD2020ProductionCostType.generated.h"


UENUM(BlueprintType)
enum class ETD2020ProductionCostType : uint8
{
	/** Pay whole production cost as soon as production staTD2020. */
	COST_PayImmediately,

	/** Pay production costs every tick while production proceeds. */
	COST_PayOverTime,

	/** Don't pay production costs automatically. */
	COST_PayCustom
};
