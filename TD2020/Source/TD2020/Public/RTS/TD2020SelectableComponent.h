#pragma once

#include "Components/ActorComponent.h"
#include "TD2020SelectableComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTD2020SelectableComponentSelectedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTD2020SelectableComponentDeselectedSignature);


/**
 * Allows selecting the actor, e.g. by left-click.
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class TD2020_API UTD2020SelectableComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Selects the unit for the local player. */
	UFUNCTION(BlueprintCallable)
	void SelectActor();

	/** Deselects the unit for the local player. */
	UFUNCTION(BlueprintCallable)
	void DeselectActor();

	/** Checks whether the unit is currently selected by the local player, or not. */
	UFUNCTION(BlueprintCallable)
	bool IsSelected();


	/** Event when the actor has been deselected. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020SelectableComponentDeselectedSignature OnDeselected;

	/** Event when the actor has been selected. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020SelectableComponentSelectedSignature OnSelected;


private:
	/** Whether the unit is currently selected by the local player, or not. */
	bool bSelected;
};
