#pragma once

#include "Components/ActorComponent.h"

#include "TD2020PortraitComponent.generated.h"


class UTexture2D;


/**
* Adds a portrait to the actor that can be shown in the UI.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020PortraitComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Portrait of the actor. Can be shown in the UI. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	UTexture2D* Portrait;
};
