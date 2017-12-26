// No copyright - copy as you please

#include "BuildingMaster.h"
#include "TD2020.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/TimelineComponent.h"
#include "Camera/CameraPawnController.h"
#include "Resources/ResourcesMaster.h"
#include "AI/NPC.h"



class ACameraPawnController;
class AResourcesMaster;
class ANPC;
class UTimelineComponent;

// Sets default values
ABuildingMaster::ABuildingMaster()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	/*



	//#1 Our root component will be a scene
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;


	//#2 Create and position a mesh component that will be mesh of our building
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->SetupAttachment(RootComponent);

	// collision properties
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	StaticMesh->SetCollisionObjectType(COLLISION_BUILDING);
	StaticMesh->SetCollisionResponseToAllChannels(ECR_Block);
	StaticMesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	StaticMesh->SetCollisionResponseToChannel(COLLISION_LANDSCAPE, ECR_Ignore);


	// #3 Create collision box
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);
	Collision->SetBoxExtent(FVector(1.0f, 1.0f, 10.0f));

	// collision properties
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	StaticMesh->SetCollisionObjectType(ECC_WorldDynamic);
	StaticMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	StaticMesh->SetCollisionResponseToChannel(COLLISION_LANDSCAPE, ECR_Ignore);

	// #4 Create Entrance scene
	Entrance = CreateDefaultSubobject<USceneComponent>(TEXT("Entrance"));
	Entrance->SetupAttachment(RootComponent);

	// #5 Create Sphere in entrance scene
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereAsset(TEXT("/Game/StarterContent/Props/MaterialSphere.MaterialSphere"));
	if (SphereAsset.Succeeded())
	{
	Sphere->SetStaticMesh(SphereAsset.Object);
	Sphere->SetWorldScale3D(FVector(0.35f));
	}

	// collision properties
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	StaticMesh->SetCollisionObjectType(ECC_WorldDynamic);
	StaticMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	StaticMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	// setup parent
	Sphere->SetupAttachment(Entrance);

	*/

}

// Called when the game starts or when spawned
void ABuildingMaster::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABuildingMaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

