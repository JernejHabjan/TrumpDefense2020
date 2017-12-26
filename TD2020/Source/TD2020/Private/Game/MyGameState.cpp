// No copyright - copy as you please
#pragma once

#include "MyGameState.h"
#include "Resources/ResourcesMaster.h"
#include "Buildings/BuildingMaster.h"
#include "Camera/CameraPawnController.h"

AMyGameState::AMyGameState()
{

	// DEFAULTS
	ControllerRef = nullptr;
	MainUIRef = nullptr;

	ResidentialBuildings = TArray<ABuildingMaster*>();
	OccupationalBuildings = TArray<ABuildingMaster*>();

	DayTick = 0;
	Seconds = 0;
	Minutes = 0;
	Hours = 0;
	Day = 1;
	Month = 1;
	Year = 1;
	GameTime = TArray<int>();
	GameDate = TArray<int>();
	TimeUnit = 150.0f;
	Clockwork = 0.0f;

	DefaultGameSpeed = 150.0f;
	SpeedMultiplier = 1.0f;
	Resources = TArray<AResourcesMaster*>();
	VisibleResourceProximity = TArray<AResourcesMaster*>();

}