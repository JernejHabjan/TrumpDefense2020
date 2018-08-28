#pragma once


#include "Components/ActorComponent.h"

#include "TD2020HealthComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTD2020HealthComponentHealthChangedSignature, float, OldHealth, float, NewHealth, AActor*, DamageCauser);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTD2020HealthComponentKilledSignature, AController*, PreviousOwner, AActor*, DamageCauser);


/**
* Adds health to the actor, e.g. for taking damage and dying.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Current health of the actor. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020", meta = (ClampMin = 0), replicated)
	float CurrentHealth;

	/** Maximum health of the actor. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020", meta = (ClampMin = 0))
	float MaximumHealth;


	UTD2020HealthComponent(const FObjectInitializer& ObjectInitializer);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	/** Apply damage to this actor. */
	float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);


	/** Event when the current health of the actor has changed. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020HealthComponentHealthChangedSignature OnHealthChanged;

	/** Event when the actor has been killed. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020HealthComponentKilledSignature OnKilled;
};
