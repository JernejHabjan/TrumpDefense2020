#pragma once


#include "GameFramework/Character.h"

#include "TD2020Character.generated.h"


class AController;
class UDecalComponent;

struct FTD2020AttackData;
class UTD2020SelectableComponent;


/**
* Character with TD2020 features, such as taking damage.
*/
UCLASS()
class TD2020_API ATD2020Character : public ACharacter
{
	GENERATED_BODY()

public:
	ATD2020Character();


	virtual void Tick(float DeltaSeconds) override;
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

protected:
	virtual void BeginPlay() override;

private:
	/** Decal used for rendering the selection circle of this character. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UDecalComponent* SelectionCircleDecalComponent;

	UTD2020SelectableComponent* SelectableComponent;
};
