// No copyright - copy as you please

#pragma once
#include <CoreMinimal.h>
#include <GameFramework/Actor.h>
#include "ConstructionManager.generated.h"

UCLASS()
class TD2020_API AConstructionManager : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AConstructionManager();

protected:
    // Called when the game staTD2020 or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
