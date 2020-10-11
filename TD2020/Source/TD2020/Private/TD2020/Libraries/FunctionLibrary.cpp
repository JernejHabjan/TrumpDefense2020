// No copyright - copy as you please
#pragma once
#include "TD2020/Libraries/FunctionLibrary.h"
#include "TD2020/TD2020.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/KismetMathLibrary.h>
#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>
#include <Engine/World.h>


// void UFunctionLibrary::SetCursorWorldPosition(const ACameraPawnController* CameraPawnController,
//                                               const float SightDistance, FVector& Location)
// {
//     // get world location and world direction from camera pawn controller
//     FVector WorldLocation, WorldDirection;
//     CameraPawnController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);
// 
//     FHitResult OutHit;
//     UKismetSystemLibrary::LineTraceSingle(nullptr, WorldLocation, WorldDirection * SightDistance + WorldLocation,
//                                           UEngineTypes::ConvertToTraceType(COLLISION_LANDSCAPE), false,
//                                           TArray<AActor*>(), EDrawDebugTrace::None, OutHit, true, FLinearColor::Red,
//                                           FLinearColor::Green, 5.0f);
// 
//     if (OutHit.Actor != nullptr)
//         Location = OutHit.Location;
// }

// void UFunctionLibrary::Pan(const ACameraPawn* PawnRef, const float MinPanY, const float MaxPanY,
//                            const float Sensitivity, const float CameraX, const float CameraY)
// {
//     FRotator ActorRotation = PawnRef->GetActorRotation(); // Roll - x, Pitch - y, Yaw - z
// 
//     float TempRoll = ActorRotation.Roll;
//     float TempPitch = UKismetMathLibrary::FClamp(Sensitivity * CameraY + ActorRotation.Roll, MinPanY, MaxPanY);
//     float TempYaw = Sensitivity * CameraX + ActorRotation.Yaw;
// 
//     /////////////////////////////////////////////////// TODO
//     //PawnRef->SetActorRotation(FRotator(TempRoll, TempPitch, TempYaw)); 
// }

void UFunctionLibrary::GridSnap(const float Axis, const int GridSize, float& AxisOut)
{
    //floor because we want it to snap on grid
    AxisOut = floor((Axis + (GridSize / 2)) / GridSize) * GridSize;
}

void UFunctionLibrary::SetClockwork(const float DeltaSeconds, const float TimeUnit, const float ClockworkIn,
                                    float& ClockworkOut, int& DayTick)
{
    DayTick = UKismetMathLibrary::FMod(DeltaSeconds / TimeUnit + ClockworkIn, 24.0f, ClockworkOut);
}

void UFunctionLibrary::CalculateSlope(AActor* Actor, const FVector Extent, bool& BadLocation)
{
    if (!Actor) return;


    //variables
    TArray<float> Differences;
    //Slope angle - difference between corners
    float MaxDifference = 20.0f;

    //part 1 - Calculate 4 sides of actor + middle
    FVector ActorLocation, ForwardVector, RightVector;
    float Difference = 0.0f;
    GetVectors(Actor, ActorLocation, ForwardVector, RightVector);

    //#1
    SlopeTrace(Actor, (ForwardVector + RightVector) * Extent + ActorLocation, Difference);
    Differences.Add(Difference);

    //#2
    SlopeTrace(Actor, (-ForwardVector + RightVector) * Extent + ActorLocation, Difference);
    Differences.Add(Difference);

    //#3
    SlopeTrace(Actor, (ForwardVector - RightVector) * Extent + ActorLocation, Difference);
    Differences.Add(Difference);

    //#4
    SlopeTrace(Actor, (-ForwardVector - RightVector) * Extent + ActorLocation, Difference);
    Differences.Add(Difference);

    //#5
    SlopeTrace(Actor, ActorLocation, Difference);
    Differences.Add(Difference);

    //part 2

    int IndexOfMinValue, IndexOfMaxValue;
    float MinValue, MaxValue;

    UKismetMathLibrary::MinOfFloatArray(Differences, IndexOfMinValue, MinValue);
    UKismetMathLibrary::MaxOfFloatArray(Differences, IndexOfMaxValue, MaxValue);

    // if both are present
    if (IndexOfMinValue > -1 && IndexOfMaxValue > -1)
    {
        AActor* ActorToIgnore = Actor;
        FVector Start = ActorLocation + FVector(0.0f, 0.0f, 1000.0f);
        FVector End = ActorLocation - FVector(0.0f, 0.0f, 1000.0f);
        FQuat Rotation = FQuat(Actor->GetActorRotation());
        FVector Shape = FVector(Extent.X, Extent.Y, 1.0f);
        FHitResult HitOut;
        ECollisionChannel TraceChannel = COLLISION_LANDSCAPE;


        FCollisionQueryParams TraceParams(FName(TEXT("Debug Trace")), true, ActorToIgnore);
        TraceParams.bReturnPhysicalMaterial = false;
        TraceParams.AddIgnoredActor(ActorToIgnore);
        HitOut = FHitResult(ForceInit);


        //if it hits something
        if (Actor->GetWorld()->SweepSingleByChannel(HitOut, Start, End, Rotation, TraceChannel,
                                                    FCollisionShape::MakeBox(Shape), TraceParams))
        {
            // Set mesh to proper height
            Actor->SetActorLocation(FVector(ActorLocation.X, ActorLocation.Y, HitOut.ImpactPoint.Z));
        }
    }

    // #part 3
    //if either of them is true - return true
    BadLocation = UKismetMathLibrary::Abs(MinValue) > MaxDifference || UKismetMathLibrary::Abs(MaxValue) >
        MaxDifference;
}

void UFunctionLibrary::GetVectors(const AActor* Actor, FVector& ActorLocation, FVector& ForwardVector,
                                  FVector& RightVector)
{
    ActorLocation = Actor->GetActorLocation();
    ForwardVector = UKismetMathLibrary::GetForwardVector(Actor->GetActorRotation());
    RightVector = UKismetMathLibrary::GetRightVector(Actor->GetActorRotation());
}

void UFunctionLibrary::SlopeTrace(const AActor* Actor, const FVector TraceLocation, float& Difference)
{
    if (!Actor) return;

    const FName TraceTag("DebugTraceTag");
    FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(TraceTag, false, Actor);
    RV_TraceParams.bReturnPhysicalMaterial = false;

    //Actor->GetWorld()->DebugDrawTraceTag = TraceTag;

    FHitResult OutHit(ForceInit);
    Actor->GetWorld()->LineTraceSingleByChannel(OutHit, TraceLocation + FVector(0.0f, 0.0f, 1000.0f),
                                                TraceLocation - FVector(0.0f, 0.0f, 1000.0f), COLLISION_LANDSCAPE,
                                                RV_TraceParams, FCollisionResponseParams());
    Difference = Actor->GetActorLocation().Z - OutHit.ImpactPoint.Z;
}

void UFunctionLibrary::HUD_LerpLocation(const FVector CurrentLocation, const FVector DestinationLocation,
                                        const float Speed, FVector& NewLocation)
{
    const FVector LerpVector = UKismetMathLibrary::VLerp(CurrentLocation, DestinationLocation, Speed);
    NewLocation = FVector(LerpVector.X, LerpVector.Y, CurrentLocation.Z);
}

void UFunctionLibrary::SetBuildingEntrance(USceneComponent* Entrance, const UStaticMeshComponent* Mesh)
{
    //Variables
    //distance from how far up front entrance is going to be - dont make it too close to building for NPC to enter
    const float EntranceDistance = 0.0f;

    FVector Min, Max;
    Mesh->GetLocalBounds(Min, Max);
    Entrance->SetRelativeLocation(FVector(0.0f, UKismetMathLibrary::Abs(Min.Y) + EntranceDistance, 0.0f));
}

void UFunctionLibrary::SetBuildingCollisionBox(UBoxComponent* Collision, const UStaticMeshComponent* Mesh)
{
    const float DisplaceX = 20.0f;
    const float DisplaceY = 98.0f;
    const float DisplaceZ = 10.0f;
    FVector Min, Max;
    Mesh->GetLocalBounds(Min, Max);

    // Hardcoded values for box extent, Update Overlaps is set to true
    // size of our collision box, requires extent, that is half size (so if Z = 10 its 20 in real world)
    Collision->SetBoxExtent(FVector(UKismetMathLibrary::Abs(Min.X) - DisplaceX, DisplaceY, DisplaceZ), true);
    Collision->SetRelativeLocation(FVector(0.0f, UKismetMathLibrary::Abs(Min.Y) + DisplaceY, DisplaceZ));
}
