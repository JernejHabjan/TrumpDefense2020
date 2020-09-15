#include "TD2020.h"
#include "TD2020BuilderComponent.h"

#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"

#include "TD2020ConstructionSiteComponent.h"
#include "TD2020ContainerComponent.h"
#include "TD2020GameMode.h"
#include "TD2020Utilities.h"


void UTD2020BuilderComponent::AssignToConstructionSite(AActor* ConstructionSite)
{
	
}

void UTD2020BuilderComponent::BeginConstruction(TSubclassOf<AActor> BuildingClass, const FVector& TargetLocation)
{
	// Get game, pawn and controller.
	
}

void UTD2020BuilderComponent::BeginConstructionByIndex(int32 BuildingIndex, const FVector& TargetLocation)
{
	
}

AActor* UTD2020BuilderComponent::GetAssignedConstructionSite()
{
	return AssignedConstructionSite;
}

void UTD2020BuilderComponent::LeaveConstructionSite()
{
	
}
