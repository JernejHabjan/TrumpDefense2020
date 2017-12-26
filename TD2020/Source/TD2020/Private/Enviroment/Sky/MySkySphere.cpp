// No copyright - copy as you please
#pragma once

#include "MySkySphere.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "Math/Color.h"
#include "Engine/DirectionalLight.h"
#include "Curves/CurveLinearColor.h"
#include "Materials/Material.h"
#include "Engine.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMySkySphere::AMySkySphere()
{

	// Our root component will be a scene
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Base"));
	RootComponent = Scene;

	// Create and position a mesh component so we can see where our sphere is,
	SkySphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sky sphere mesh"));
	SkySphereMesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereAsset(TEXT("/Game/TD2020/Materials/Sky/SM_SkySphere.SM_SkySphere"));
	SkySphereMesh->SetStaticMesh(SphereAsset.Object);
	SkySphereMesh->SetWorldScale3D(FVector(400.0f));
	
	// DEFAULTS
	SunHeight = 0.0f;
	HorizonFalloff = 3.0f;
	ZenithColor = FColor(0.03f, 0.1f, 0.3f, 1.0f);
	HorizonColor = FColor(2.0f, 2.58f, 3.0f, 1.0f);
	CloudColor = FColor(0.85f, 0.91f, 1.0f, 1.0f);
	OverallColor = FColor(1.0f, 1.0f, 1.0f, 1.0f);
	static ConstructorHelpers::FObjectFinder<UMaterial> MatObj(TEXT("Material'/Game/TD2020/Materials/Sky/M_Sky_Panning_Clouds2.M_Sky_Panning_Clouds2'"));
	SkyMaterial = MatObj.Object;
	RefreshMaterial = false;
	DirectionalLightActor = nullptr;
	ColorsDeterminedBySunPosition = true;
	SunBrightness = 50.0f;
	CloudSpeed = 1.0f;
	CloudOpacity = 0.7f;
	StarsBrightness = 0.1f;
	static ConstructorHelpers::FObjectFinder<UCurveLinearColor> HorizonColorCurve_Helper(TEXT("/Game/TD2020/Textures/Sky/C_Sky_Horizon_Color.C_Sky_Horizon_Color"));
	static ConstructorHelpers::FObjectFinder<UCurveLinearColor> ZenithColorCurve_Helper(TEXT("/Game/TD2020/Textures/Sky/C_Sky_Zenith_Color.C_Sky_Zenith_Color"));
	static ConstructorHelpers::FObjectFinder<UCurveLinearColor> CloudColorCurve_Helper(TEXT("/Game/TD2020/Textures/Sky/C_Sky_Cloud_Color.C_Sky_Cloud_Color"));
	HorizonColorCurve = HorizonColorCurve_Helper.Object;
	ZenithColorCurve = ZenithColorCurve_Helper.Object;
	CloudColorCurve = CloudColorCurve_Helper.Object;
	Valid = false;
}




// Called when the game starts or when spawned
void AMySkySphere::BeginPlay()
{
	Super::BeginPlay();

	// call of OnConstruction function - Has to be called because only editor calls onConstruction on its own - Deployed game doesn't
	OnConstruction(FTransform());
}

// Called every frame
void AMySkySphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMySkySphere::OnConstruction(const FTransform& Transform) {

	//Updating bool in details panel causes construction script to run again
	RefreshMaterial = false;

	// Create Material instance
	SkyMaterialInstance = UMaterialInstanceDynamic::Create(SkyMaterial, NULL);
	SkySphereMesh->SetMaterial(0, SkyMaterialInstance);

	//Has a directional light been assigned?
	if (UKismetSystemLibrary::IsValid(DirectionalLightActor)) {
		SkyMaterialInstance->SetVectorParameterValue("Light direction", FLinearColor(UKismetMathLibrary::Conv_RotatorToVector(DirectionalLightActor->GetActorRotation())));
		SkyMaterialInstance->SetVectorParameterValue("Sun color", FLinearColor(DirectionalLightActor->GetLightComponent()->GetLightColor()));
		SunHeight = UKismetMathLibrary::MapRangeUnclamped(DirectionalLightActor->GetActorRotation().Pitch, 0.0f, -18.0f, 0.0f, 1.0f);
	}
	else {
		SkyMaterialInstance->SetVectorParameterValue("Light direction", FLinearColor(UKismetMathLibrary::Conv_RotatorToVector(UKismetMathLibrary::MakeRotator(0.0f, UKismetMathLibrary::MapRangeUnclamped(SunHeight, -1.0f, 1.0f, 90.0f, -90.0f), DirectionalLightActor->GetActorRotation().Yaw))));
		SkyMaterialInstance->SetVectorParameterValue("Sun color", UKismetMathLibrary::LinearColorLerp(FLinearColor(1.0f, 0.221f, 0.04f, 1.0f), FLinearColor(1.0f, 0.9f, 0.744f, 1.0f), UKismetMathLibrary::FClamp(SunHeight + 0.2f, 0.0f, 1.0f)));
	}

	if (ColorsDeterminedBySunPosition) {
		SkyMaterialInstance->SetVectorParameterValue("Horizon color", HorizonColorCurve->GetLinearColorValue(SunHeight));
		SkyMaterialInstance->SetVectorParameterValue("Zenith color", ZenithColorCurve->GetLinearColorValue(SunHeight));
		SkyMaterialInstance->SetVectorParameterValue("Cloud color", CloudColorCurve->GetLinearColorValue(SunHeight));
		SkyMaterialInstance->SetScalarParameterValue("Horizon falloff", UKismetMathLibrary::Lerp(3.0f, 7.0f, UKismetMathLibrary::Abs(SunHeight)));
	}
	else {
		SkyMaterialInstance->SetVectorParameterValue("Horizon color", HorizonColor);
		SkyMaterialInstance->SetVectorParameterValue("Zenith color", ZenithColor);
		SkyMaterialInstance->SetVectorParameterValue("Overall color", OverallColor);
		SkyMaterialInstance->SetVectorParameterValue("Cloud color", CloudColor);
		SkyMaterialInstance->SetScalarParameterValue("Horizon falloff", HorizonFalloff);
	}

	SkyMaterialInstance->SetScalarParameterValue("Cloud speed", CloudSpeed);
	SkyMaterialInstance->SetScalarParameterValue("Sun brightness", SunBrightness);
	//Is sun height is negative, this value is used to blend in stars
	SkyMaterialInstance->SetScalarParameterValue("Sun height", UKismetMathLibrary::SelectFloat(UKismetMathLibrary::Abs(SunHeight), 0.0f, SunHeight < 0.0f));
	SkyMaterialInstance->SetScalarParameterValue("Cloud opacity", CloudOpacity);
	SkyMaterialInstance->SetScalarParameterValue("Stars brightness", StarsBrightness);

	// Check if everything is ok
	Valid = Validate();
}

bool AMySkySphere::Validate()
{
	// if everything is valid -> return true, else return false
	return (
		Scene->IsValidLowLevel() &&
		SkySphereMesh->IsValidLowLevel() &&
		SkyMaterial->IsValidLowLevel() &&
		SkyMaterialInstance->IsValidLowLevel() &&
		HorizonColorCurve->IsValidLowLevel() &&
		ZenithColorCurve->IsValidLowLevel() &&
		CloudColorCurve->IsValidLowLevel()
		);
}


bool AMySkySphere::UpdateSunDirection() {
	
	if (!Valid) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("INVALID INIT MY SKY SPHERE - unable to update sky material properties and sun height"));
		return false;
	}

	SkyMaterialInstance->SetVectorParameterValue("Light direction", FLinearColor(UKismetMathLibrary::Conv_RotatorToVector(DirectionalLightActor->GetActorRotation())));
	SkyMaterialInstance->SetVectorParameterValue("Sun color", FLinearColor(DirectionalLightActor->GetLightComponent()->GetLightColor()));
	SunHeight = UKismetMathLibrary::MapRangeUnclamped(DirectionalLightActor->GetActorRotation().Pitch, 0.0f, -18.0f, 0.0f, 1.0f);

	SkyMaterialInstance->SetVectorParameterValue("Horizon color", HorizonColorCurve->GetLinearColorValue(SunHeight));
	SkyMaterialInstance->SetVectorParameterValue("Zenith color", ZenithColorCurve->GetLinearColorValue(SunHeight));
	SkyMaterialInstance->SetVectorParameterValue("Cloud color", CloudColorCurve->GetLinearColorValue(SunHeight));
	SkyMaterialInstance->SetScalarParameterValue("Horizon falloff", UKismetMathLibrary::Lerp(3.0f, 7.0f, UKismetMathLibrary::Abs(SunHeight)));

	SkyMaterialInstance->SetScalarParameterValue("Sun height", UKismetMathLibrary::SelectFloat(UKismetMathLibrary::Abs(SunHeight), 0.0f, SunHeight < 0.0f));
	return true;
	
}