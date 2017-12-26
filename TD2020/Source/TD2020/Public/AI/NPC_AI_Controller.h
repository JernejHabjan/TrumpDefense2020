// No copyright - copy as you please

#pragma once

#include "AIController.h"
#include "Enums/EOccupationType.h"
#include "Enums/EAIState.h"
#include "NPC_AI_Controller.generated.h"

class ACameraPawnController;
class AMyGameState;
class UBlackboardComponent;
class UBehaviorTreeComponent;

UCLASS()
class TD2020_API ANPC_AI_Controller : public AAIController
{
	GENERATED_BODY()

		
	UPROPERTY(Transient)
	UBlackboardComponent *BlackboardComp; //NPC BB
											
	UPROPERTY(Transient)
	UBehaviorTreeComponent *BehaviorComp; //NPC BT

	// BLACKBOARD KEYS
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FVector TargetLocation_BK; 

	//This is the destination building that the NPC is moving to
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UObject* Destination_BK;

	//This is the current location (building) of the NPC when not moving
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UObject* CurrentLocation_BK;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	bool IsBusy_BK;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UObject* SelfActor_BK;

	
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	EOccupationType_Enum OccupationType_BK;

	//This is the current state of the NPC
	
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	EAIState_Enum AIState_BK;


	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UObject* HouseReference_BK;

public:

	// VARIABLES
	// References
	UPROPERTY(BlueprintReadWrite, Category = "AI|References")
	ACameraPawnController* CameraPawnController;

	//UPROPERTY(BlueprintReadWrite, Category = "AI|References")
	//ANPC* NPC;
	
	UPROPERTY(BlueprintReadWrite, Category = "AI|References")
	AMyGameState* MyGameState;

	// Properties
	UPROPERTY(BlueprintReadWrite, Category = "AI|Properties")
	float TimeUnit;

	UPROPERTY(BlueprintReadWrite, Category = "AI|Properties")
	float StaminaHourlyRegeneration;

	UPROPERTY(BlueprintReadWrite, Category = "AI|Properties")
	float StaminaHourdlyDeduction;

	UPROPERTY(BlueprintReadWrite, Category = "AI|Properties")
	FTimerHandle RegainStaminaHandle;

	UPROPERTY(BlueprintReadWrite, Category = "AI|Properties")
	FTimerHandle DepleteStaminaHandle;




	// FUNCTIONS
	virtual void Possess(APawn* InPawn) override;



public:
	ANPC_AI_Controller();





	// FUNCTIONS

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "TODO")
		void CheckForHousing(bool &DidFindHousing, AResidentialMaster* &House); /// TODO ---- RESIDENTIAL MASTER CONFLICT














	/*inline getter functions*/
	FORCEINLINE UBlackboardComponent *GetBlackBoardComp() const { return BlackboardComp; }
	FORCEINLINE FVector GetTargetLocation_BK() const { return TargetLocation_BK; }

};
