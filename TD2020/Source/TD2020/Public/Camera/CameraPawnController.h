// No copyright - copy as you please

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CameraPawnController.generated.h"

class AConstructionManager;
class AGhostBuilding;
class AMyGameState;
class ACameraPawn;
UCLASS()
class TD2020_API ACameraPawnController : public APlayerController
{
	GENERATED_BODY()

public:
	// PROPERTIES

	// REFERENCES
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|References")
	ACameraPawn* CameraPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|References")
	UObject* MainHud; // TODO CHANGE THIS TO MAIN UI HUD REFERENCE------- TODO

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|References")
	AConstructionManager* ConstructionManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|References")
	AGhostBuilding* GhostBuilding;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|References")
	AMyGameState* MyGameState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|References")
	UObject* PauseWidget; // TODO CHANGE THIS TO PAUSE MENU OBJECT REFERENCE ---- TODO

	// CAMERA NAVIGATION

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Camera Navigation")
	bool DisableCamNav;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Camera Navigation")
	float FastMoveMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Camera Navigation")
	float PanSensitivity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Camera Navigation")
	float ZoomSensitivity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Camera Navigation")
	float MaxArmDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Camera Navigation")
	float EdgeMoveSpeedX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Camera Navigation")
	float EdgeMoveSpeedY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Camera Navigation")
	bool EnableActionInput;


	// CONSTRUCTION
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Construction")
	bool BuildModeActive;

	// how far from camera center can we build buildings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Construction")
	float SightDistance;

	// for how many degrees does the building rotate when pressing rotation buttons
	//Make sure its divisable by 360 degrees
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Construction")
	float BuildingRotationRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Construction")
	TArray<TEnumAsByte<EObjectTypeQuery>> SelectableObjectsEnum;

	// TOUCH
	//amount of pixels to ignore for not swiping(if only tap)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Touch")
	float Treshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Touch")
	float SwipeSpeed;

	//on how much to move the camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Touch")
	FVector2D PriorLocation;

	//location of starting finger position
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Touch")
	FVector2D StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Touch")
	FVector2D StartLocation1;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Touch")
	bool Tapped;

	//Only used for touch - spawn builder
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController|Touch")
	FVector TouchLocation;

	// DEFAULT
	//defines how big are actors
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController")
	FVector ActorScaleFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController")
	FVector CursorWorldPosition;

	//if overlay pause screen is shown
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraPawnController")
	bool IsPauseScreenShown;


	// FUNCTIONS

	// Sets default values for this actor's properties
	ACameraPawnController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "CameraPawnController")
	float MovementSpeedCalculation();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "CameraPawnController")
	float SetSightDistance();

	// gets actor default scale factor
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "CameraPawnController")
	FVector GetActorScaleFactor();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "TODO")
	void SpawnBuilder(const FVector InLocation);

	UFUNCTION(BlueprintCallable, Category = "CameraPawnController")
	void ZoomOut();

	UFUNCTION(BlueprintCallable, Category = "CameraPawnController")
	void ZoomIn();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// check if references are set
	bool Valid;
	bool Validate();



};
