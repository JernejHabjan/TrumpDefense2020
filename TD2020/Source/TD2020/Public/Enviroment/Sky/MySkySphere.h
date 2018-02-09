// No copyright - copy as you please

#pragma once
#include "Engine.h"
#include "MySkySphere.generated.h"

class USceneComponent;
class UStaticMeshComponent;
struct FLinearColor;
class UMaterialInstanceDynamic;
class ADirectionalLight;
class UCurveLinearColor;
class UMaterial;
class AActor;
UCLASS()
class TD2020_API AMySkySphere : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// PROPERTIES

	// Skydome
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Skydome)
	USceneComponent *Scene;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Skydome)
	UStaticMeshComponent* SkySphereMesh;


	// Override settings
	
	// If no directional light is assigned, this value determines the height of the sun - Slider range -> -1 to 1
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Override Settings")
	float SunHeight;

	// Affects the size of the gradient from zenith color to horizon color
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Override Settings")
	float HorizonFalloff;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Override Settings")
	FLinearColor ZenithColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Override Settings")
	FLinearColor HorizonColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Override Settings")
	FLinearColor CloudColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Override Settings")
	FLinearColor OverallColor;


	// Other properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstanceDynamic* SkyMaterialInstance;

	//Use this to update the sky material after moving  a directional light
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool RefreshMaterial;

	//Assign your level's directional light actor to this variable to  match the sky's sun position and color
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ADirectionalLight *DirectionalLightActor;

	//If enabled, sky colors will change according to the sun's position
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ColorsDeterminedBySunPosition;

	//Brightness multiplier for the sun disk
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SunBrightness;

	//Panning speed for the clouds
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CloudSpeed;

	//Opacity of the panning clouds
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CloudOpacity;

	//Multiplier for the brightness of the stars when the sun is below the horizon
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StarsBrightness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveLinearColor* HorizonColorCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveLinearColor* ZenithColorCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveLinearColor* CloudColorCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterial *SkyMaterial;

	


	// FUNCTIONS

	// Sets default values for this actor's properties
	AMySkySphere();

	AMySkySphere(const FObjectInitializer & ObjectInitializer);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called by DayNightCycle class object
	UFUNCTION(Category = SunDirection, BlueprintCallable)
	bool UpdateSunDirection();

	// Construction script
	virtual void OnConstruction(const FTransform& Transform) override;


private:
	// if init is valid
	bool Valid;

	// FUNCTIONS


	// validates if all assets are properly loaded and not null
	bool Validate();
};
