#pragma once
#include "Templates/SubclassOf.h"
#include "TD2020AttackData.generated.h"


class ATD2020Projectile;


USTRUCT(BlueprintType)
struct TD2020_API FTD2020AttackData
{
	GENERATED_USTRUCT_BODY()

public:
	/** Time before this attack can be used again, in seconds. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	float Cooldown;

	/** Damage dealt by this attack. Negative values could mean healing, depending on the game. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	float Damage;

	/** Type of the damage caused by this attack. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	TSubclassOf<class UDamageType> DamageType;

	/** Range of this attack, in cm. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	float Range;

	/** Type of the projectile to spawn. If not set, damage will be dealt instantly. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
	TSubclassOf<class ATD2020Projectile> ProjectileClass;
};
