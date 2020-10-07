// No copyright - copy as you please
#include "TD2020/Construction/ConstructionManager.h"


// Sets default values
AConstructionManager::AConstructionManager()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game staTD2020 or when spawned
void AConstructionManager::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AConstructionManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
