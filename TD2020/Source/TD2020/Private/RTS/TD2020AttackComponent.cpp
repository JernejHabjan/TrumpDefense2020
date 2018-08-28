#include "TD2020.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"

#include "TD2020AttackComponent.h"
#include "TD2020Projectile.h"


UTD2020AttackComponent::UTD2020AttackComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTD2020AttackComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	// Update cooldown timer.
	if (RemainingCooldown > 0)
	{
		RemainingCooldown -= DeltaTime;

		if (RemainingCooldown <= 0)
		{
			UE_LOG(LogTD2020, Log, TEXT("Actor %s attack is ready again."), *GetOwner()->GetName());

			// Notify listeners.
			OnCooldownReady.Broadcast();
		}
	}
}

void UTD2020AttackComponent::UseAttack(int32 AttackIndex, AActor* Target)
{
	AActor* Owner = GetOwner();
	APawn* OwnerPawn = Cast<APawn>(Owner);
	AController* OwnerController = OwnerPawn ? OwnerPawn->GetController() : nullptr;

	if (!IsValid(Target))
	{
		return;
	}

	// Check cooldown.
	if (RemainingCooldown > 0)
	{
		return;
	}

	// Use attack.
	UE_LOG(LogTD2020, Log, TEXT("Actor %s attacks %s."), *Owner->GetName(), *Target->GetName());

	const FTD2020AttackData& Attack = Attacks[0];

	ATD2020Projectile* SpawnedProjectile = nullptr;

	if (Attack.ProjectileClass != nullptr)
	{
		// Fire projectile.
		// Build spawn transform.
		FVector SpawnLocation = Owner->GetActorLocation();
		FRotator SpawnRotation = Owner->GetActorRotation();
		FTransform SpawnTransform = FTransform(SpawnRotation, SpawnLocation);

		// Build spawn info.
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.Instigator = OwnerPawn;
		SpawnInfo.ObjectFlags |= RF_Transient;

		// Spawn projectile.
		SpawnedProjectile = GetWorld()->SpawnActor<ATD2020Projectile>(Attack.ProjectileClass, SpawnTransform, SpawnInfo);

		if (SpawnedProjectile)
		{
			UE_LOG(LogTD2020, Log, TEXT("%s fired projectile %s at target %s."), *Owner->GetName(), *SpawnedProjectile->GetName(), *Target->GetName());

			// Aim at target.
			SpawnedProjectile->FireAt(
				Target,
				Attack.Damage,
				Attack.DamageType,
				OwnerController,
				Owner);
		}
	}
	else
	{
		// Deal damage immediately.
		Target->TakeDamage(Attack.Damage, FDamageEvent(Attack.DamageType), OwnerController, Owner);
	}

	// Start cooldown timer.
	RemainingCooldown = Attack.Cooldown;

	// Notify listeners.
	OnAttackUsed.Broadcast(Attack, Target, SpawnedProjectile);
}
