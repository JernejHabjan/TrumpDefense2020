// No copyright - copy as you please

#pragma once
#include "TD2020/TD2020.h"
#include <CoreMinimal.h>
#include <Kismet/BlueprintFunctionLibrary.h>
#include "FunctionLibrary.generated.h"

class ACameraPawnController;
class APlayerController;
class ACameraPawn;
class UBoxComponent;
class UStaticMeshComponent;
class USceneComponent;


UCLASS()
class TD2020_API UFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    // todo comment
    // Parameters
    // IN Camera Pawn Controller object reference
    // IN float Sight Distance
    // OUT FVector Location
    //UFUNCTION(Category = FunctionLibrary, BlueprintPure)
    //static void SetCursorWorldPosition(const ACameraPawnController* CameraPawnController, const float SightDistance, FVector &Location);


    // Controlls camera pan around pawn
    // Parameters
    // IN Camera Pawn
    // IN float Min Pan Y - set to -180 if don't want to use it
    // IN float Max Pan Y - set to 180 if don't want to use it
    // IN float Sensitivity
    // IN float Camera X - Mouse X movement [0 - 1]
    // IN float Camera Y - Mouse Y movement [0 - 1]
    //UFUNCTION(Category = FunctionLibrary, BlueprintCallable)
    //static void Pan(const ACameraPawn* PawnRef, const float MinPanY, const float MaxPanY, const float Sensitivity, const float CameraX, const float CameraY);

    // Makes mouse snap on grid in block increments
    // Parameters
    // IN float Axis
    // IN int GridSize
    // OUT float AxisOut
    UFUNCTION(Category = FunctionLibrary, BlueprintPure)
    static void GridSnap(float Axis, int GridSize, float& AxisOut);

    // todo comment
    // Parameters
    // IN float Delta Seconds
    // IN float Time Unit
    // IN float Clockwork
    // OUT float Clockwork
    // OUT int Day Tick
    UFUNCTION(Category = FunctionLibrary, BlueprintPure)
    static void SetClockwork(float DeltaSeconds, float TimeUnit, float ClockworkIn,
                             float& ClockworkOut, int& DayTick);

    // Returns if Actor is placed on slope terrain
    // Parameters
    // IN AActor* Actor
    // IN FVector Extent
    // OUT bool BadLocation
    UFUNCTION(Category = FunctionLibrary, BlueprintCallable)
    static void CalculateSlope(AActor* Actor, FVector Extent, bool& BadLocation);

    // Returns location, forward vector and right vector
    // Parameters
    // IN AActor* Actor
    // OUT FVector ActorLocation
    // OUT FVector ForwardVector
    // OUT FVector RightVector
    UFUNCTION(Category = FunctionLibrary, BlueprintPure)
    static void GetVectors(const AActor* Actor, FVector& ActorLocation, FVector& ForwardVector, FVector& RightVector);

    // Traces landscape to return difference between mesh and landscape
    // Parameters
    // IN AActor* Actor
    // IN FVector TraceLocation
    // OUT float Difference
    UFUNCTION(Category = FunctionLibrary, BlueprintCallable)
    static void SlopeTrace(const AActor* Actor, FVector TraceLocation, float& Difference);

    // Lerps from current location to destination by speed
    // Parameters
    // IN FVector Current Location (location of actor - Camera pawn)
    // IN FVector Destination Location (location of actor - Building, NPC...)
    // IN float Speed
    // OUT FVector NewLocation
    UFUNCTION(Category = FunctionLibrary, BlueprintPure)
    static void HUD_LerpLocation(FVector CurrentLocation, FVector DestinationLocation, float Speed,
                                 FVector& NewLocation);

    // Sets location of Entrance
    // Parameters
    // IN USceneComponent* Entrance
    // IN Static mesh component* Mesh
    UFUNCTION(Category = FunctionLibrary, BlueprintCallable)
    static void SetBuildingEntrance(USceneComponent* Entrance, const UStaticMeshComponent* Mesh);


    UFUNCTION(Category = FunctionLibrary, BlueprintCallable)
    static void SetBuildingCollisionBox(UBoxComponent* Collision, const UStaticMeshComponent* Mesh);
};
