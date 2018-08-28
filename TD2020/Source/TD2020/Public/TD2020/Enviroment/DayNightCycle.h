// No copyright - copy as you please

#pragma once
#include "TD2020.h"
#include "Engine.h"
#include "DayNightCycle.generated.h"

class ADirectionalLight;
class AMySkySphere;
class AMyGameState;
class USceneComponent;
class UStaticMeshComponent;
class UMaterial;
class UCurveLinearColor;

UCLASS()
class TD2020_API ADayNightCycle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Components
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent *Scene;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent *Moon;

	// references
	UPROPERTY(EditAnywhere, Category = "References")
	ADirectionalLight* SunLight;

	UPROPERTY(EditAnywhere, Category = "References")
	ADirectionalLight* MoonLight;

	UPROPERTY(EditAnywhere, Category = "References")
	AMySkySphere* SkySphere;

	// properties

	// 3600 in hours
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
	float TimeUnit;

	// todo comment
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sun")
	int SunDays;

	// The hour of sun position
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sun")
	float SunDrive;

	// Default to 24h
	UPROPERTY(EditAnywhere, Category = "Sun")
	float SunDayDuration;

	// todo comment
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Properties)
	float Clockwork;

	// default to 365.25
	UPROPERTY(EditAnywhere, Category = "Sun")
	float SunYearDuration;

	// Defaults to -23.5f -> value of Sun max declination
	UPROPERTY(EditAnywhere, Category = "Sun")
	float MaxDeclination;

	// Current sun declination - if positive - Summer
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sun")
	float SunDeclination;

	// Current latitude (Ljubljana is at 46)
	UPROPERTY(EditAnywhere, Category = "Sun")
	float Latitude;

	// todo comment
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sun")
	float SunHalfDayLight;

	// todo comment
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sun")
	float SunHalfNight;

	// Highpoint of x^2 graph will be ((at midnight or midnoon)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sun")
	float Shift;

	// todo comment
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sun")
	float Length;

	// Default to -1.0f -> 1 or 0 if day or night
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sun")
	float DayNightFlip;

	// todo comment
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sun")
	float SunPitch;

	// todo comment
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sun")
	float SunYaw;

	// todo comment
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sun")
	float SunDeclinationDrive;

	// switch to turn off day night cycle
	UPROPERTY(EditAnywhere, Category = Properties)
	bool UseDayNightCycle;

	// Is -1 if on southern hemisphere or 1 on northern
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sun")
	float EquatorFlip;

	// toggle if want to use polar day and polar night
	UPROPERTY(EditAnywhere, Category = "Sun")
	bool SunPolar;

	UPROPERTY(EditAnywhere, Category = "Time")
	int Seconds;

	UPROPERTY(EditAnywhere, Category = "Time")
	int Minutes;

	UPROPERTY(EditAnywhere, Category = "Time")
	int Hours;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Time")
	TArray<int> GameTime;

	// every time (for one tick) this will be 1
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Properties)
	int DayTick;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Calendar")
	TArray<int> GameDate;

	UPROPERTY(EditAnywhere, Category = "Time")
	bool UseSystemTime;

	UPROPERTY(EditAnywhere, Category = "Calendar", meta = (UIMin = "1", UIMax = "31"))
	int Day;

	UPROPERTY(EditAnywhere, Category = "Calendar", meta = (UIMin = "1", UIMax = "12"))
	int Month;

	UPROPERTY(EditAnywhere, Category = "Calendar", meta = (UIMin = "1"))
	int Year;

	UPROPERTY(EditAnywhere, Category = "Calendar")
	bool UseSystemDate;

	UPROPERTY(EditAnywhere, Category = Properties)
	bool EarthLike;

	UPROPERTY(EditAnywhere, Category = "Moon")
	float MoonDayDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moon")
	float MoonDeclination;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moon")
	float MoonDeclinationDrive;

	// Time between two full moons
	UPROPERTY(EditAnywhere, Category = "Moon")
	float MoonYearDuration;

	// plane that moon rotates on - tilted by 5 degrees
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moon")
	float MoonInclination;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moon")
	float MoonEquatorFlip;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moon")
	float MoonDrive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moon")
	float MoonHalfDayLight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moon")
	float MoonHalfNight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moon")
	float MoonDayNightFlip;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moon")
	float MoonShift;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moon")
	float MoonLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moon")
	float MoonPitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Moon")
	float MoonYaw;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moon")
	UMaterialInstanceDynamic* MoonMaterialInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moon")
	UMaterial *MoonMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Moon")
	UCurveLinearColor* SkyColor;

	// Sets default values for this actor's properties
	ADayNightCycle();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game staTD2020 or when spawned
	virtual void BeginPlay() override;


private:
	// if init is valid
	bool Valid;



	void SunTrajectory();
	void MoonTrajectory();
	void Clock();
	void Calendar();
	bool Validate();
};
