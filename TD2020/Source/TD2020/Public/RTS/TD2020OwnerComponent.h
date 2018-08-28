#pragma once


#include "Components/ActorComponent.h"

#include "TD2020OwnerComponent.generated.h"


class AController;

class ATD2020PlayerState;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTD2020OwnerComponentOwnerChangedSignature, AController*, NewOwner);


/**
* Specifies the owning player of the actor.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020OwnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UTD2020OwnerComponent(const FObjectInitializer& ObjectInitializer);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	/** Gets the player owning the actor. */
	UFUNCTION(BlueprintCallable)
	ATD2020PlayerState* GetPlayerOwner();

	/** Sets the player owning the actor. */
	UFUNCTION(BlueprintCallable)
	void SetPlayerOwner(AController* Controller);


	/** Checks whether the actor belongs to the same team as the specified one. */
	UFUNCTION(BlueprintCallable)
	bool IsSameTeamAsActor(AActor* Other);

	/** Checks whether the player owning the actor belongs to the same team as the specified player. */
	UFUNCTION(BlueprintCallable)
	bool IsSameTeamAsController(AController* C);


	/** Event when the actor is owned by a different player. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020OwnerComponentOwnerChangedSignature OnOwnerChanged;


private:
	/** Player owning this actor. */
	UPROPERTY(replicated)
	ATD2020PlayerState* PlayerOwner;
};
