#pragma once

#include "RTSPluginPCH.h"

#include "GameFramework/Character.h"

#include "RTSCharacter.generated.h"


class AController;
class UDecalComponent;

struct FRTSAttackData;
class URTSSelectableComponent;


/**
* Character with RTS features, such as taking damage.
*/
UCLASS()
class RTSPLUGIN_API ARTSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ARTSCharacter();


	virtual void Tick(float DeltaSeconds) override;
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

protected:
	virtual void BeginPlay() override;

private:
	/** Decal used for rendering the selection circle of this character. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UDecalComponent* SelectionCircleDecalComponent;

	URTSSelectableComponent* SelectableComponent;
};
