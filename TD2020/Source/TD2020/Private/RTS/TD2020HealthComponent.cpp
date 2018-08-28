#include "TD2020.h"
#include "TD2020HealthComponent.h"
#include "TD2020GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Net/UnrealNetwork.h"



UTD2020HealthComponent::UTD2020HealthComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetIsReplicated(true);
}

void UTD2020HealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UTD2020HealthComponent, CurrentHealth);
}

float UTD2020HealthComponent::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float OldHealth = CurrentHealth;
	CurrentHealth -= Damage;
	float NewHealth = CurrentHealth;

	/*
	UE_LOG(LogTD2020, Log, TEXT("Actor %s has taken %f damage from %s, reducing health to %f."),
		*GetOwner()->GetName(),
		Damage,
		*DamageCauser->GetName(),
		CurrentHealth);
	*/

	// Notify listeners.
	OnHealthChanged.Broadcast(OldHealth, NewHealth, DamageCauser);

	// Check if we've just died.
	if (CurrentHealth <= 0)
	{
		UE_LOG(LogTD2020, Log, TEXT("Actor %s has been killed."), *GetOwner()->GetName());

		// Get owner before destruction.
		AController* OwningPlayer = Cast<AController>(GetOwner()->GetOwner());

        // Notify listeners.
        OnKilled.Broadcast(OwningPlayer, DamageCauser);

		// Destroy this actor.
		GetOwner()->Destroy();

		// Notify game mode.
		ATD2020GameMode* GameMode = Cast<ATD2020GameMode>(UGameplayStatics::GetGameMode(GetWorld()));

		if (GameMode != nullptr)
		{
			GameMode->NotifyOnActorKilled(GetOwner(), OwningPlayer);
		}
	}

	return Damage;
}
