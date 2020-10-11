#pragma once
#include "Logging/LogMacros.h"


/** when you modify this, please note that this information can be saved with instances
* also DefaultEngine.ini [/Script/Engine.CollisionProfile] should match with this list **/
#define COLLISION_LANDSCAPE		ECC_GameTraceChannel1
#define COLLISION_BUILDING		ECC_GameTraceChannel2


DECLARE_LOG_CATEGORY_EXTERN(LogTD2020, Log, All);
