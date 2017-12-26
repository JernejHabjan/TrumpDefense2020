// No copyright - copy as you please

#include "ConstructionProxy.h"


// Sets default values
AConstructionProxy::AConstructionProxy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConstructionProxy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConstructionProxy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

