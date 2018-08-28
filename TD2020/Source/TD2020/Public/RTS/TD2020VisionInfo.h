#pragma once


#include "GameFramework/Info.h"

#include "TD2020VisionState.h"

#include "TD2020VisionInfo.generated.h"


class UWorld;

class ATD2020VisionVolume;


/**
* Defines the visible areas for a player or team.
*/
UCLASS()
class TD2020_API ATD2020VisionInfo : public AInfo
{
	GENERATED_BODY()

	ATD2020VisionInfo();

public:
	virtual void Tick(float DeltaSeconds) override;

	/** Index of the team this actor keeps track of the vision for. */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = ReceivedTeamIndex, Category = "Team")
	uint8 TeamIndex;

	/** Sets the index of the team this actor keeps track of the vision for. */
	void SetTeamIndex(uint8 NewTeamIndex);

	/** Gets the state of the tile with the specified coordinates. */
	ETD2020VisionState GetVision(int32 X, int32 Y) const;
	
	/** Gets vision information for the specified team. */
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static ATD2020VisionInfo* GetVisionInfoForTeam(UObject* WorldContextObject, uint8 InTeamIndex);

protected:
	virtual void BeginPlay() override;

private:
	ATD2020VisionVolume* VisionVolume;

	/** Which tiles are currently unknown, known and visible. */
	TArray<ETD2020VisionState> Tiles;

	bool GetTileCoordinates(int Index, int* OutX, int* OutY) const;
	int32 GetTileIndex(int X, int Y) const;

	void NotifyPlayerVisionInfoAvailable();

	UFUNCTION()
	virtual void ReceivedTeamIndex();
};
