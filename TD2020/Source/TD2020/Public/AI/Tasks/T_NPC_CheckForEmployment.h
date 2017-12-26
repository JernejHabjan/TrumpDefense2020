// No copyright - copy as you please

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"

#include "T_NPC_CheckForEmployment.generated.h"


UCLASS(Blueprintable)
class TD2020_API UT_NPC_CheckForEmployment : public UBTTask_BlueprintBase
{
	GENERATED_BODY()


		UPROPERTY(EditAnywhere, Category = AI)
		ANPC *NPC;

public:

	void ReceiveExecuteAI(AAIController* OwnerController, APawn* ControlledPawn);

};
