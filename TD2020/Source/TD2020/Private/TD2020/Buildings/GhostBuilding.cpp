// No copyright - copy as you please
#include "GhostBuilding.h"
#include "TD2020.h"

// Sets default values
AGhostBuilding::AGhostBuilding()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game staTD2020 or when spawned
void AGhostBuilding::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AGhostBuilding::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
