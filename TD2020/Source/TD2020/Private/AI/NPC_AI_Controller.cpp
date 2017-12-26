// No copyright - copy as you please
#pragma once
#include "NPC_AI_Controller.h"
#include "TD2020.h"
#include "NPC.h"
#include "Camera/CameraPawnController.h"
#include "Game/MyGameState.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h" //for now all types.. bool, obj etc


ANPC_AI_Controller::ANPC_AI_Controller()
{
	// initialize blackboard and behavior tree
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	BehaviorComp = CreateAbstractDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));

	// initialize blackboard keys
	TargetLocation_BK = FVector();
	Destination_BK = nullptr;
	CurrentLocation_BK = nullptr;
	IsBusy_BK = false;
	SelfActor_BK = nullptr;
	OccupationType_BK = EOccupationType_Enum::Unemployment;
	AIState_BK = EAIState_Enum::Homeless;
	HouseReference_BK = nullptr;



}

void ANPC_AI_Controller::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);
	/* get reference to the character*/
	/*ANPC *Character = Cast<ANPC>(InPawn);


	if (Character) {
		if (Character->BehaviorTree->BlackboardAsset) {
			BlackboardComp->InitializeBlackboard(*(Character->BehaviorTree->BlackboardAsset));
		}


		//Character->SetController(this); // ------------------------ TODO SET CONTROLLER




		// TODO POPULATE KEYS????






		BehaviorComp->StartTree(*Character->BehaviorTree);





	}*/
}
