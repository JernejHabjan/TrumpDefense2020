// No copyright - copy as you please

#pragma once

#include "GameFramework/Actor.h"
#include "Enums/EProximityType.h"
#include "Structs/Building_STRUCT.h"
#include "BuildingMaster.generated.h"

class ACameraPawnController;
class AResourcesMaster;
class ANPC;
class UTimelineComponent;
class UStaticMeshComponent;
class USceneComponent;
class UBoxComponent;

UCLASS()
class TD2020_API ABuildingMaster : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABuildingMaster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*// COMPONENTS
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|Components")
	USceneComponent *Scene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|Components")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|Components")
	UBoxComponent* Collision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|Components")
	USceneComponent *Entrance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|Components")
	UStaticMeshComponent* Sphere;

	// PROPERTIES

	// References
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|References")
	ACameraPawnController* CameraPawnController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|References")
	UStaticMesh* DisplayMesh;

	// TODO ------------------------------------------------------------------------------------- CHANGE THIS TO BUILDING HUD ----------- TODO
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|References")
	UObject* BuildingHUD;

	// Building info
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|Building Info")
	FBuilding_Struct BuildingStruct;

	// Properies
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master")
	UTimelineComponent* LerpLocationTimeline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master")
	TSubclassOf<class AConstructionProxy> ConstructionProxy;

	// This is how long to take for building to construct (in hours)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master")
	float ConstructionTime;

	//Not every building child uses this variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|")
	TArray<ANPC*> Employees;

	//This is the array of current residents
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|")
	TArray<ANPC*> Residents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|")
	EProximityType_Enum ProximityType;

	//keeping track of this particular resource - particular mineshack is mining only particular rocks
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Master|")
	AResourcesMaster *Resource;

	*/


};
