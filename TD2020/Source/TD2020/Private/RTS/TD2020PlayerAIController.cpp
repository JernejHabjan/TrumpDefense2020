#include "TD2020.h"
#include "TD2020PlayerAIController.h"

#include "EngineUtils.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"

#include "TD2020BuilderComponent.h"
#include "TD2020ConstructionSiteComponent.h"
#include "TD2020PlayerResourcesComponent.h"
#include "TD2020ProductionComponent.h"
#include "TD2020ProductionCostComponent.h"
#include "TD2020ResourceSourceComponent.h"
#include "TD2020ResourceDrainComponent.h"
#include "TD2020Utilities.h"


ATD2020PlayerAIController::ATD2020PlayerAIController()
{
   
}

TSubclassOf<APawn> ATD2020PlayerAIController::GetNextPawnToProduce() const
{
	return nullptr;
}

AActor* ATD2020PlayerAIController::GetPrimaryResourceDrain() const
{

    return nullptr;
}

AActor* ATD2020PlayerAIController::GetPrimaryResourceSource() const
{
   

    return nullptr;
}

bool ATD2020PlayerAIController::CanPayFor(TSubclassOf<APawn> PawnClass) const
{
  
    return true;
}

bool ATD2020PlayerAIController::MeetsAllRequirementsFor(TSubclassOf<APawn> PawnClass) const
{
    AActor* AnyOwnActor = GetPrimaryResourceDrain();
    return UTD2020Utilities::OwnerMeetsAllRequirementsFor(AnyOwnActor, AnyOwnActor, PawnClass);
}

bool ATD2020PlayerAIController::StartProduction(TSubclassOf<APawn> PawnClass)
{
    // Find suitable factory.
   
    return false;
}

void ATD2020PlayerAIController::Possess(APawn* InPawn)
{
   
}
