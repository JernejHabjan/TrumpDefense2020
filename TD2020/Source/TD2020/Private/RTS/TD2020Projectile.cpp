#include "TD2020.h"
#include "TD2020Projectile.h"

#include "GameFramework/ProjectileMovementComponent.h"


ATD2020Projectile::ATD2020Projectile()
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

    bFired = false;

	// Enable replication.
	// This might change in the future, as we don't really care about exact projectile positions on client-side.
	bReplicates = true;
}

void ATD2020Projectile::FireAt(
	AActor* ProjectileTarget,
	float ProjectileDamage,
	TSubclassOf<class UDamageType> ProjectileDamageType,
	AController* ProjectileEventInstigator,
	AActor* ProjectileDamageCauser)
{
	if (!ProjectileTarget)
	{
		UE_LOG(LogTD2020, Error, TEXT("No target set for projectile %s!"), *GetName());
		return;
	}

	Target = ProjectileTarget;
	Damage = ProjectileDamage;
	DamageType = ProjectileDamageType;
	EventInstigator = ProjectileEventInstigator;
	DamageCauser = ProjectileDamageCauser;

	// Set direction.
	FVector Direction = Target->GetActorLocation() - GetActorLocation();
	FVector DirectionNormalized = Direction.GetSafeNormal(0.01f);

	ProjectileMovement->Velocity = DirectionNormalized * ProjectileMovement->InitialSpeed;

	if (ProjectileMovement->bIsHomingProjectile)
	{
		// Set target.
		ProjectileMovement->HomingTargetComponent = Target->GetRootComponent();
	}

    // Set time to impact.
    TimeToImpact = Direction.Size() / ProjectileMovement->InitialSpeed;
    bFired = true;
}

void ATD2020Projectile::Tick(float DeltaSeconds)
{
    if (!bFired)
    {
        return;
    }

    TimeToImpact -= DeltaSeconds;

	if (TimeToImpact > 0.0f)
	{
        return;
	}

    if (IsValid(Target))
    {
        UE_LOG(LogTD2020, Log, TEXT("Projectile %s hit target %s for %f damage."), *GetName(), *Target->GetName(), Damage);

        // Deal damage.
        Target->TakeDamage(Damage, FDamageEvent(DamageType), EventInstigator, DamageCauser);

        // Notify listeners.
        NotifyOnProjectileDetonated(Target, Damage, DamageType, EventInstigator, DamageCauser);
    }

    // Destroy projectile.
    Destroy();
}

void ATD2020Projectile::NotifyOnProjectileDetonated(
	AActor* ProjectileTarget,
	float ProjectileDamage,
	TSubclassOf<class UDamageType> ProjectileDamageType,
	AController* ProjectileEventInstigator,
	AActor* ProjectileDamageCauser)
{
	ReceiveOnProjectileDetonated(ProjectileTarget, ProjectileDamage, ProjectileDamageType, ProjectileEventInstigator, ProjectileDamageCauser);
}
