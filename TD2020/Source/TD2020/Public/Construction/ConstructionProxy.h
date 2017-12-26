// No copyright - copy as you please

#pragma once

#include "GameFramework/Actor.h"
#include "ConstructionProxy.generated.h"

UCLASS()
class TD2020_API AConstructionProxy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConstructionProxy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
