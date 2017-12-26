// No copyright - copy as you please
#pragma once

#include "CameraPawnController.h"
#include "Construction/ConstructionManager.h"
#include "Buildings/GhostBuilding.h"
#include "Game/MyGameState.h"
#include "Camera/CameraPawn.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine.h"
#include "Engine/EngineTypes.h"
#include "Libraries/FunctionLibrary.h"
#include "TD2020.h"

ACameraPawnController::ACameraPawnController()
{
	//DEFAULTS

	// REFERENCES
	
	CameraPawn = nullptr;
	MainHud = nullptr;
	ConstructionManager = nullptr;
	GhostBuilding = nullptr;
	MyGameState = nullptr;
	PauseWidget = nullptr;
	
	DisableCamNav = false;
	EnableActionInput = true;
	FastMoveMultiplier = 1.0f;
	PanSensitivity = 5.0f;
	ZoomSensitivity = 150.0f;
	MaxArmDistance = 4000.0f;
	EdgeMoveSpeedX = 5.0f;
	EdgeMoveSpeedY = 5.0f;
	

	BuildModeActive = false;
	SightDistance = 3000.0f;
	BuildingRotationRate = 15.0f;
	TArray<TEnumAsByte<EObjectTypeQuery>> SelectableObjectsEnum = { UEngineTypes::ConvertToObjectType(COLLISION_BUILDING), UEngineTypes::ConvertToObjectType(ECC_Pawn) };

	Treshold = 12.0f;
	SwipeSpeed = 5.0f;
	PriorLocation = FVector2D(0.0f, 0.0f);
	StartLocation = FVector2D(0.0f, 0.0f);
	StartLocation1 = FVector2D(0.0f, 0.0f);
	Tapped = false;
	TouchLocation = FVector(0.0f, 0.0f, 0.0f);

	ActorScaleFactor = FVector(1.0f, 1.0f, 1.0f);
	CursorWorldPosition = FVector(0.0f, 0.0f, 0.0f);
	IsPauseScreenShown = false;


}



void ACameraPawnController::BeginPlay()
{
	Super::BeginPlay();

	Valid = Validate();
	// on end of construction script it checks if assets are valid
	if (Valid) {
		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
		PrimaryActorTick.bCanEverTick = true;
	}
	else {
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("INVALID INIT CAMERA PAWN CONTROLLER"));
		//PrimaryActorTick.bCanEverTick = false; // ........................................................................................ TODO DISABLED FOR NOW
	}
}


void ACameraPawnController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


float ACameraPawnController::MovementSpeedCalculation() 
{
	if (!CameraPawn) return 0.0f;
	return UKismetMathLibrary::FClamp(CameraPawn->SpringArm->TargetArmLength / 100.0f, 5.0f, 20.0f);
}

float ACameraPawnController::SetSightDistance()
{
	return SightDistance + CameraPawn->SpringArm->TargetArmLength;
}

FVector ACameraPawnController::GetActorScaleFactor()
{
	return ActorScaleFactor;
}
/*
void ACameraPawnController::SpawnBuilder(const FVector InLocation)
{
	
	
	// check if android
	if (Tapped) {

	}
	// PC
	else {
		FVector CursorWorldPosition = UFunctionLibrary::SetCursorWorldPosition(this, 10000.0f);
	}

	
}*/

void ACameraPawnController::ZoomOut()
{
	CameraPawn->SpringArm->TargetArmLength = UKismetMathLibrary::FClamp(ZoomSensitivity + CameraPawn->SpringArm->TargetArmLength, 250.0f, MaxArmDistance);
}

void ACameraPawnController::ZoomIn()
{
	CameraPawn->SpringArm->TargetArmLength = UKismetMathLibrary::FClamp(CameraPawn->SpringArm->TargetArmLength - ZoomSensitivity, 250.0f, MaxArmDistance);
}



bool ACameraPawnController::Validate()
{
	// returns true if everything is setup else false
	return (

		CameraPawn->IsValidLowLevel() &&
		MainHud->IsValidLowLevel() &&
		ConstructionManager->IsValidLowLevel() &&
		GhostBuilding->IsValidLowLevel() &&
		MyGameState->IsValidLowLevel() &&
		PauseWidget->IsValidLowLevel()
		);

}
