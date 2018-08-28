#pragma once



#include "Components/ActorComponent.h"

#include "TD2020AttackData.h"

#include "TD2020AttackComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTD2020AttackComponentCooldownReadySignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTD2020AttackComponentAttackedUsedSignature, const FTD2020AttackData&, Attack, AActor*, Target, ATD2020Projectile*, Projectile);


/**
* Adds one or more attacks to the actor.
* These can also be used for healing.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020AttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Radius in which the actor will automatically select and attack targets, in cm. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float AcquisitionRadius;

	/** Radius around the home location of the actor it won't leave when automatically attacking targets, in cm. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float ChaseRadius;

	/** Attacks available for the actor. Different attacks might be used at different ranges, or against different types of targets. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	TArray<FTD2020AttackData> Attacks;

	/** Time before the next attack can be used, in seconds. This is shared between attacks.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	float RemainingCooldown;


	UTD2020AttackComponent(const FObjectInitializer& ObjectInitializer);


	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;


	/** Uses the passed attack on the specified target and staTD2020 the cooldown timer. */
	UFUNCTION(BlueprintCallable)
	void UseAttack(int32 AttackIndex, AActor* Target);


	/** Event when the attack cooldown has expired. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020AttackComponentCooldownReadySignature OnCooldownReady;

	/** Event when an actor has used an attack. */
	UPROPERTY(BlueprintAssignable, Category = "TD2020")
	FTD2020AttackComponentAttackedUsedSignature OnAttackUsed;
};
