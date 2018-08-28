#pragma once


#include "Components/ActorComponent.h"
#include "TD2020VisionComponent.generated.h"


/**
* Allows the actor to reveal areas covered by fog of war.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020VisionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Radius in which the actor reveals areas covered by fog of war, in cm. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020", meta = (ClampMin = 0), replicated)
	float SightRadius;


	UTD2020VisionComponent(const FObjectInitializer& ObjectInitializer);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
