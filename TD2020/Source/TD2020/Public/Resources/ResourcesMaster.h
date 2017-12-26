// No copyright - copy as you please

#pragma once

#include "GameFramework/Actor.h"
#include "ResourcesMaster.generated.h"

UCLASS()
class TD2020_API AResourcesMaster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResourcesMaster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
