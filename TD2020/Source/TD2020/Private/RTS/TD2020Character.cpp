#include "TD2020.h"
#include "TD2020Character.h"

#include "Components/CapsuleComponent.h"
#include "Components/DecalComponent.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

#include "TD2020AttackData.h"
#include "TD2020GameMode.h"
#include "TD2020HealthComponent.h"
#include "TD2020SelectableComponent.h"
#include "WorldCollision.h"

ATD2020Character::ATD2020Character()
{
	// Create selection circle.
	SelectionCircleDecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("SelectionCircleDecal"));
	SelectionCircleDecalComponent->SetRelativeRotation(FRotator::MakeFromEuler(FVector(0.0f, -90.0f, 0.0f)));

	// Enable replication.
	bReplicates = true;
}

void ATD2020Character::BeginPlay()
{
	Super::BeginPlay();

	// Cache component references.
	SelectableComponent = FindComponentByClass<UTD2020SelectableComponent>();

	// Setup selection circle.
	FCollisionShape CollisionShape = GetCapsuleComponent()->GetCollisionShape();
	float DecalHeight = CollisionShape.Capsule.HalfHeight * 2;
	float DecalRadius = CollisionShape.Capsule.Radius;

	SelectionCircleDecalComponent->DecalSize = FVector(DecalHeight, DecalRadius, DecalRadius);
}

void ATD2020Character::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (SelectableComponent && SelectableComponent->IsSelected())
	{
		// Show selection circle.
		SelectionCircleDecalComponent->SetWorldLocation(GetActorLocation());
	}
	else
	{
		// HACK(np): Hide selection circle.
		SelectionCircleDecalComponent->SetWorldLocation(FVector(0.0f, 0.0f, -10000.0f));
	}
}

float ATD2020Character::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	// Adjust health.
	UTD2020HealthComponent* HealthComponent = FindComponentByClass<UTD2020HealthComponent>();
	if (!HealthComponent)
	{
		return 0.0f;
	}

	return HealthComponent->TakeDamage(ActualDamage, DamageEvent, EventInstigator, DamageCauser);
}
