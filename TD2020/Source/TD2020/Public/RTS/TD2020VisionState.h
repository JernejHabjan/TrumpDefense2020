#pragma once


#include "TD2020VisionState.generated.h"


UENUM(BlueprintType)
enum class ETD2020VisionState : uint8
{
	/** Area has never been visited before. */
	VISION_Unknown,

	/** Area has been visited before, but is currently not. */
	VISION_Known,

	/** Area is revealed right now. */
	VISION_Visible
};
