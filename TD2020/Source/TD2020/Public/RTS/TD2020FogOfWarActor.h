#pragma once


#include "GameFramework/Actor.h"

#include "TD2020FogOfWarActor.generated.h"


class UTexture2D;
struct FUpdateTextureRegion2D;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class APostProcessVolume;

class ATD2020VisionInfo;
class ATD2020VisionVolume;


/** Renders fog of war in 3D space. */
UCLASS()
class TD2020_API ATD2020FogOfWarActor : public AActor
{
	GENERATED_BODY()

public:
	ATD2020FogOfWarActor(const FObjectInitializer& ObjectInitializer);

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	/** Sets the vision info to render in 3D space. */
	void SetupVisionInfo(ATD2020VisionInfo* VisionInfo);

	void UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD2020")
		bool Enable;
private:



	/** Material to instance for rendering the fog of war effect. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UMaterialInterface* FogOfWarMaterial;

	/** Renders the fog of war. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	APostProcessVolume* FogOfWarVolume;

	/** Provides visibility information for how to render the fog of war. */
	ATD2020VisionInfo* VisionInfo;

	/** Provides world size information for how to render the fog of war. */
	ATD2020VisionVolume* VisionVolume;

	/** Texture containing visibility information to be rendered in 3D space. */
	UTexture2D* FogOfWarTexture; 

	/** Buffer for updating the contents of the fog of war texture. */
	uint8* FogOfWarTextureBuffer;

	/** Update region for updating the contents of the fog of war texture. */
	FUpdateTextureRegion2D* FogOfWarUpdateTextureRegion;

	/** Post-process material instance for rendering fog of war in 3D space. */
	UMaterialInstanceDynamic* FogOfWarMaterialInstance;
};
