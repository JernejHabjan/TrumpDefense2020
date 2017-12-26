// No copyright - copy as you please

#include "T_NPC_CheckForEmployment.h"
#include "../NPC.h"
void UT_NPC_CheckForEmployment::ReceiveExecuteAI(AAIController * OwnerController, APawn * ControlledPawn)
{
	//reference cast
	if (!IsValid(NPC))
		NPC = Cast<ANPC>(ControlledPawn);


	bool SearchSuccessful = false;
	
	
	//NPC->CheckForEmployment(SearchSuccessful); // TODO UNCOMMENT LATER

	return FinishExecute(SearchSuccessful);
}
