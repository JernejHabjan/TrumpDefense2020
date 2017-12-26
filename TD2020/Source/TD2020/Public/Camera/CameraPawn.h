// No copyright - copy as you please

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "ConstructorHelpers.h"
#include "CameraPawn.generated.h"

class UStaticMeshComponent;
class USceneComponent;
class UCameraComponent;
class UStaticMesh;
class USpringArmComponent;

UCLASS()
class TD2020_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	USceneComponent *Scene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	UStaticMeshComponent* Sphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	UCameraComponent* Camera;




};
