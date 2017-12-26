// No copyright - copy as you please

#pragma once

#include "GameFramework/GameStateBase.h"
#include "Enums/EProximityType.h"
#include "MyGameState.generated.h"

class ACameraPawnController;
class ABuildingMaster;
class AResourcesMaster;

// EVENT DISPATCHER - declaration
//DECLARE_DYNAMIC_DELEGATE_OneParam(FUpdateGameSpeed, float, TimeUnit); ------------------------------- TODO

UCLASS()
class TD2020_API AMyGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	// REFERENCES
	
	// Camera pawn controller object reference
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|References")
	ACameraPawnController* ControllerRef;
	
	// Main UI Hud object reference
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|References")
	UObject* MainUIRef;


	// BUILDINGS

	// Array of building master bp object references 
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Buildings")
	TArray<ABuildingMaster*> ResidentialBuildings;

	// Array of building master bp object references - Buildings that have jobs
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Buildings")
	TArray<ABuildingMaster*> OccupationalBuildings;


	// TIME

	// todo comment
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Time")
	int DayTick;

	// todo comment
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Time")
	int Seconds;

	// todo comment
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Time")
	int Minutes;

	// todo comment
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Time")
	int Hours;

	// default to 1
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Time")
	int Day;

	// default to 1
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Time")
	int Month;

	// default to 1
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Time")
	int Year;

	// todo comment
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Time")
	TArray<int> GameTime;

	// todo comment
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Time")
	TArray<int> GameDate;

	// 150 - 1 minute for 1 day -> default to 150
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Time")
	float TimeUnit;

	// todo comment
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState|Time")
	float Clockwork;


	// PROPERTIES

	// 150 - 1h for 1 day
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState")
	float DefaultGameSpeed;

	// default 1.0
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState")
	float SpeedMultiplier;

	// more resources within world
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState")
	TArray<AResourcesMaster*> Resources; 

	// to show the decal will be in here
	UPROPERTY(BlueprintReadWrite, Category = "MyGameState")
	TArray<AResourcesMaster*> VisibleResourceProximity;



	// EVENT DISPATCHER - property
	//UPROPERTY(BlueprintAssignable, Category = "EventDispatchers") // TODO UNCOMMENT THIS AFTER event dispatcher declaration
	//FUpdateGameSpeed UpdateGameSpeed; // TODO UNCOMMENT THIS AFTER event dispatcher declaration
	// https://goo.gl/HSUU5v
	//UpdateGameSpeed.Broadcast(MyCustomTimeUnit); // --- this is how we call in my game state ----------------------- TODO


	// INTERFACES
	//UPROPERTY(EditAnywhere, Category = Properties) ----------------------------------------------- TODO INTERFACES


	
	
	// FUNCTIONS
	AMyGameState();

	// Updates clock
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Cpp")
	// Parameters
	// OUT - unused - should be void but it creates event in blueprint
	bool Clock();

	// Updates Calendar
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Cpp")
		// Parameters
		// OUT - unused - should be void but it creates event in blueprint
		bool Calendar();
	
	// Gets Time unit
	// Parameters
	// OUT float Timeunit
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintPure, Category = "Cpp")
	void GetCurrentTimeUnit(float &TimeUnit_OUT);
	
	// Adds building to arrays
	// Parameters
	// IN Building master object reference Building
	// OUT - unused - should be void but it creates event in blueprint
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Cpp")
	bool AddBuildingToGame(const ABuildingMaster* Building);

	// Gets Jobs as Building master object references array and if any jobs are avaliable
	// Parameters
	// OUT bool Is job avaliable
	// OUT TArray<BuildingMaster object reference> Jobs avaliable
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Cpp")
	void GetAvaliableJobs(bool &IsJobAvaliable, TArray<ABuildingMaster*> &JobsAvaliable); 
	

	// Toggles visibility of decals for particular resource
	// Parameters
	// IN Proximity type ProximityType
	//UFUNCTION(BlueprintImplementableEvent, Category = "Cpp")
	//void ShowProximity(const BYTE ProximityType); 
	//void ShowProximity(EProximityType_Enum ProximityType);
	

	// Sets visibility of decal to false
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Cpp")
	// Parameters
	// OUT - unused - should be void but it creates event in blueprint
	bool HideProximity();

	// Adds resource to Resources array
	// Parameters
	// IN ResourceMaster object reference Resource
	// OUT - unused - should be void but it creates event in blueprint
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Cpp")
	bool AddResource(const AResourcesMaster* Resource);


	
};
