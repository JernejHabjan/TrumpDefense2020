#include "TD2020.h"
#include "TD2020Utilities.h"
#include "Components/ShapeComponent.h"
#include "Landscape.h"
#include "TD2020OwnerComponent.h"
#include "TD2020ConstructionSiteComponent.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "TD2020RequirementsComponent.h"
#include "Engine/SCS_Node.h"
#include "EngineUtils.h"
#include "TD2020PlayerState.h"


UTD2020Utilities::UTD2020Utilities(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}


float UTD2020Utilities::GetActorDistance(AActor* First, AActor* Second, bool bConsiderCollisionSize)
{
    if (!First || !Second)
    {
        return 0.0f;
    }

    float Distance = First->GetDistanceTo(Second);

    if (bConsiderCollisionSize)
    {
        Distance -= GetActorCollisionSize(First) / 2.0f;
        Distance -= GetActorCollisionSize(Second) / 2.0f;
    }

    return Distance;
}

float UTD2020Utilities::GetCollisionSize(TSubclassOf<AActor> ActorClass)
{
    AActor* DefaultActor = ActorClass->GetDefaultObject<AActor>();
    return GetActorCollisionSize(DefaultActor) * DefaultActor->GetActorRelativeScale3D().X;
}

float UTD2020Utilities::GetCollisionHeight(TSubclassOf<AActor> ActorClass)
{
    AActor* DefaultActor = ActorClass->GetDefaultObject<AActor>();
    return GetActorCollisionHeight(DefaultActor) * DefaultActor->GetActorRelativeScale3D().Z;
}

float UTD2020Utilities::GetActorCollisionSize(AActor* Actor)
{
    if (!Actor)
    {
        return 0.0f;
    }

    UShapeComponent* ShapeComponent = Actor->FindComponentByClass<UShapeComponent>();
    return GetShapeCollisionSize(ShapeComponent);
}

float UTD2020Utilities::GetActorCollisionHeight(AActor* Actor)
{
    if (!Actor)
    {
        return 0.0f;
    }

    UShapeComponent* ShapeComponent = Actor->FindComponentByClass<UShapeComponent>();
    return GetShapeCollisionHeight(ShapeComponent);
}

float UTD2020Utilities::GetShapeCollisionSize(UShapeComponent* ShapeComponent)
{
    if (!ShapeComponent)
    {
        return 0.0f;
    }

    FCollisionShape CollisionShape = ShapeComponent->GetCollisionShape();

    return CollisionShape.IsCapsule() ?
        CollisionShape.Capsule.Radius * 2 :
        FMath::Max(CollisionShape.Box.HalfExtentX, CollisionShape.Box.HalfExtentY) * 2;
}

float UTD2020Utilities::GetShapeCollisionHeight(UShapeComponent* ShapeComponent)
{
    if (!ShapeComponent)
    {
        return 0.0f;
    }

    FCollisionShape CollisionShape = ShapeComponent->GetCollisionShape();

    return CollisionShape.IsCapsule() ?
        CollisionShape.Capsule.HalfHeight * 2 :
        CollisionShape.Box.HalfExtentZ * 2;
}

FVector UTD2020Utilities::GetGroundLocation(UObject* WorldContextObject, FVector Location)
{
    if (!WorldContextObject)
    {
        return Location;
    }

    // Cast ray to hit world.
    FCollisionObjectQueryParams Params(FCollisionObjectQueryParams::InitType::AllObjects);
    TArray<FHitResult> HitResults;

    WorldContextObject->GetWorld()->LineTraceMultiByObjectType(
        HitResults,
        FVector(Location.X, Location.Y, 10000.0f),
        FVector(Location.X, Location.Y, -10000.0f),
        Params);

    for (auto& HitResult : HitResults)
    {
        if (HitResult.Actor != nullptr)
        {
            ALandscape* Landscape = Cast<ALandscape>(HitResult.Actor.Get());

            if (Landscape != nullptr)
            {
                return HitResult.Location;
            }

            continue;
        }

        return HitResult.Location;
    }

    return Location;
}

bool UTD2020Utilities::IsAIUnit(AActor* Actor)
{
    if (!Actor)
    {
        return false;
    }

    // Check owner.
    auto OwnerComponent = Actor->FindComponentByClass<UTD2020OwnerComponent>();

    if (!OwnerComponent)
    {
        return false;
    }

    return OwnerComponent->GetPlayerOwner() && OwnerComponent->GetPlayerOwner()->bIsABot;
}

bool UTD2020Utilities::IsReadyToUse(AActor* Actor)
{
	if (!Actor)
	{
		return false;
	}

	auto ConstructionSiteComponent = Actor->FindComponentByClass<UTD2020ConstructionSiteComponent>();

	return ConstructionSiteComponent == nullptr || ConstructionSiteComponent->IsFinished();
}

bool UTD2020Utilities::IsSuitableLocationForActor(UWorld* World, TSubclassOf<AActor> ActorClass, const FVector& Location)
{
    if (!World)
    {
        return false;
    }

    UShapeComponent* ShapeComponent = FindDefaultComponentByClass<UShapeComponent>(ActorClass);

    if (!ShapeComponent)
    {
        return true;
    }

    FCollisionObjectQueryParams Params(FCollisionObjectQueryParams::AllDynamicObjects);

    return !World->OverlapAnyTestByObjectType(
        Location,
        FQuat::Identity,
        Params,
        ShapeComponent->GetCollisionShape());
}

UActorComponent* UTD2020Utilities::FindDefaultComponentByClass(const TSubclassOf<AActor> InActorClass, const TSubclassOf<UActorComponent> InComponentClass)
{
	// Check CDO.
	AActor* ActorCDO = InActorClass->GetDefaultObject<AActor>();;
	UActorComponent* FoundComponent = ActorCDO->FindComponentByClass(InComponentClass);

	if (FoundComponent)
	{
		return FoundComponent;
	}

	// Check blueprint nodes. Components added in blueprint editor only (and not in code) are not available from CDO.
	UBlueprintGeneratedClass* ActorBlueprintGeneratedClass = Cast<UBlueprintGeneratedClass>(InActorClass);

	if (!ActorBlueprintGeneratedClass)
	{
		return nullptr;
	}

	const TArray<USCS_Node*>& ActorBlueprintNodes = ActorBlueprintGeneratedClass->SimpleConstructionScript->GetAllNodes();

	for (USCS_Node* Node : ActorBlueprintNodes)
	{
		if (Node->ComponentClass->IsChildOf(InComponentClass))
		{
			return Node->ComponentTemplate;
		}
	}

	return nullptr;
}

bool UTD2020Utilities::OwnerMeetsAllRequirementsFor(UObject* WorldContextObject, AActor* OwnedActor, TSubclassOf<AActor> DesiredProduct)
{
    TSubclassOf<AActor> MissingRequirement;
    return !GetMissingRequirementFor(WorldContextObject, OwnedActor, DesiredProduct, MissingRequirement);
}

bool UTD2020Utilities::GetMissingRequirementFor(UObject* WorldContextObject, AActor* OwnedActor, TSubclassOf<AActor> DesiredProduct, TSubclassOf<AActor>& OutMissingRequirement)
{
    if (!WorldContextObject || !OwnedActor || !OwnedActor->GetOwner())
    {
        return false;
    }

    // Check owner.
    UTD2020OwnerComponent* OwnerComponent = OwnedActor->FindComponentByClass<UTD2020OwnerComponent>();

    if (OwnerComponent == nullptr)
    {
        return false;
    }

    // Check if any requirements.
    UTD2020RequirementsComponent* RequirementsComponent = FindDefaultComponentByClass<UTD2020RequirementsComponent>(DesiredProduct);

    if (!RequirementsComponent || RequirementsComponent->RequiredActors.Num() <= 0)
    {
        return false;
    }

    // Check if owning player owns all required actors.
    TArray<TSubclassOf<AActor>> RequiredActors = RequirementsComponent->RequiredActors;

    for (TActorIterator<AActor> ActorItr(WorldContextObject->GetWorld()); ActorItr; ++ActorItr)
    {
        AActor* SomeActor = *ActorItr;
        UTD2020OwnerComponent* OtherOwnerComponent = SomeActor->FindComponentByClass<UTD2020OwnerComponent>();

        if (OtherOwnerComponent && OtherOwnerComponent->GetPlayerOwner() == OwnerComponent->GetPlayerOwner() && IsReadyToUse(SomeActor))
        {
            RequiredActors.Remove(SomeActor->GetClass());

            if (RequiredActors.Num() == 0)
            {
                // All requirements checked.
                return false;
            }
        }
    }

    OutMissingRequirement = RequiredActors[0];
    return true;
}
