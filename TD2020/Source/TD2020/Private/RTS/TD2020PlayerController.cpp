#include "TD2020.h"
#include "TD2020PlayerController.h"


ATD2020PlayerController::ATD2020PlayerController()
{
  
}

void ATD2020PlayerController::BeginPlay()
{
	

    
}

void ATD2020PlayerController::SetupInputComponent()
{
	
}

void ATD2020PlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
}

AActor* ATD2020PlayerController::GetHoveredActor()
{
	return nullptr;
}

ATD2020PlayerState* ATD2020PlayerController::GetPlayerState()
{
	return nullptr;
}


bool ATD2020PlayerController::GetObjectsAtScreenPosition(FVector2D ScreenPosition, TArray<FHitResult>& OutHitResults)
{
	// Get ray.
	return nullptr;
}

bool ATD2020PlayerController::GetObjectsAtWorldPosition(const FVector& WorldPositionXY, TArray<FHitResult>& OutHitResults)
{
	return nullptr;
}

bool ATD2020PlayerController::GetSelectionFrame(FIntRect& OutSelectionFrame)
{

	
	return true;
}

ATD2020TeamInfo* ATD2020PlayerController::GetTeamInfo() const
{

	
	return nullptr;
}

bool ATD2020PlayerController::GetObjectsAtPointerPosition(TArray<FHitResult>& OutHitResults)
{

	return false;
}

bool ATD2020PlayerController::GetObjectsInSelectionFrame(TArray<FHitResult>& HitResults)
{
	
	return false;
}

bool ATD2020PlayerController::TraceObjects(const FVector& WorldOrigin, const FVector& WorldDirection, TArray<FHitResult>& OutHitResults)
{
	return false;
}


bool ATD2020PlayerController::IsSelectableActor(AActor* Actor)
{


	return true;
}

void ATD2020PlayerController::IssueOrder()
{


}

void ATD2020PlayerController::IssueOrderTargetingObjects(TArray<FHitResult>& HitResults)
{
	
}

bool ATD2020PlayerController::IssueAttackOrder(AActor* Target)
{
	
	return false;
}

void ATD2020PlayerController::ServerIssueAttackOrder_Implementation(APawn* OrderedPawn, AActor* Target)
{
	
}

bool ATD2020PlayerController::ServerIssueAttackOrder_Validate(APawn* OrderedPawn, AActor* Target)
{
	return true;
}

bool ATD2020PlayerController::IssueBeginConstructionOrder(TSubclassOf<AActor> BuildingClass, const FVector& TargetLocation)
{
	

	return false;
}

bool ATD2020PlayerController::ServerIssueContinueConstructionOrder_Validate(APawn* OrderedPawn, AActor* ConstructionSite)
{
	// Verify owner to prevent cheating.
	return false;
}

void ATD2020PlayerController::ServerIssueBeginConstructionOrder_Implementation(APawn* OrderedPawn, TSubclassOf<AActor> BuildingClass, const FVector& TargetLocation)
{

}

bool ATD2020PlayerController::IssueContinueConstructionOrder(AActor* ConstructionSite)
{
	

	return false;
}

bool ATD2020PlayerController::IssueGatherOrder(AActor* ResourceSource)
{
	
	return false;
}

void ATD2020PlayerController::ServerIssueGatherOrder_Implementation(APawn* OrderedPawn, AActor* ResourceSource)
{
	
}

bool ATD2020PlayerController::ServerIssueGatherOrder_Validate(APawn* OrderedPawn, AActor* ResourceSourc)
{
	return false;
}

void ATD2020PlayerController::ServerIssueContinueConstructionOrder_Implementation(APawn* OrderedPawn, AActor* ConstructionSite)
{
	
}

bool ATD2020PlayerController::ServerIssueBeginConstructionOrder_Validate(APawn* OrderedPawn, TSubclassOf<AActor> BuildingClass, const FVector& TargetLocation)
{
	return false;
}

bool ATD2020PlayerController::IssueMoveOrder(const FVector& TargetLocation)
{
    // Issue move orders.
	bool bSuccess = false;

    
	return bSuccess;
}

void ATD2020PlayerController::ServerIssueMoveOrder_Implementation(APawn* OrderedPawn, const FVector& TargetLocation)
{
	
}

bool ATD2020PlayerController::ServerIssueMoveOrder_Validate(APawn* OrderedPawn, const FVector& TargetLocation)
{
	return false;
}

AActor* ATD2020PlayerController::GetSelectedProductionActor()
{
   
    return nullptr;
}

bool ATD2020PlayerController::CheckCanIssueProductionOrder(int32 ProductIndex)
{
    
    return true;
}

void ATD2020PlayerController::IssueProductionOrder(int32 ProductIndex)
{
    
}

void ATD2020PlayerController::IssueStopOrder()
{
	
}

void ATD2020PlayerController::ServerIssueStopOrder_Implementation(APawn* OrderedPawn)
{
	
}

bool ATD2020PlayerController::ServerIssueStopOrder_Validate(APawn* OrderedPawn)
{
	return false;
}

void ATD2020PlayerController::SelectActors(TArray<AActor*> Actors)
{
	
}

void ATD2020PlayerController::SaveControlGroup(int32 Index)
{
	if (Index < 0 || Index > 9)
	{
		return;
	}

	// Save control group.
	ControlGroups[Index] = SelectedActors;

	UE_LOG(LogTD2020, Log, TEXT("Saved selection to control group %d."), Index);
}

void ATD2020PlayerController::SaveControlGroup0() { SaveControlGroup(0); }
void ATD2020PlayerController::SaveControlGroup1() { SaveControlGroup(1); }
void ATD2020PlayerController::SaveControlGroup2() { SaveControlGroup(2); }
void ATD2020PlayerController::SaveControlGroup3() { SaveControlGroup(3); }
void ATD2020PlayerController::SaveControlGroup4() { SaveControlGroup(4); }
void ATD2020PlayerController::SaveControlGroup5() { SaveControlGroup(5); }
void ATD2020PlayerController::SaveControlGroup6() { SaveControlGroup(6); }
void ATD2020PlayerController::SaveControlGroup7() { SaveControlGroup(7); }
void ATD2020PlayerController::SaveControlGroup8() { SaveControlGroup(8); }
void ATD2020PlayerController::SaveControlGroup9() { SaveControlGroup(9); }

void ATD2020PlayerController::LoadControlGroup(int32 Index)
{
	if (Index < 0 || Index > 9)
	{
		return;
	}

	SelectActors(ControlGroups[Index]);

	UE_LOG(LogTD2020, Log, TEXT("Loaded selection from control group %d."), Index);
}

void ATD2020PlayerController::LoadControlGroup0() { LoadControlGroup(0); }
void ATD2020PlayerController::LoadControlGroup1() { LoadControlGroup(1); }
void ATD2020PlayerController::LoadControlGroup2() { LoadControlGroup(2); }
void ATD2020PlayerController::LoadControlGroup3() { LoadControlGroup(3); }
void ATD2020PlayerController::LoadControlGroup4() { LoadControlGroup(4); }
void ATD2020PlayerController::LoadControlGroup5() { LoadControlGroup(5); }
void ATD2020PlayerController::LoadControlGroup6() { LoadControlGroup(6); }
void ATD2020PlayerController::LoadControlGroup7() { LoadControlGroup(7); }
void ATD2020PlayerController::LoadControlGroup8() { LoadControlGroup(8); }
void ATD2020PlayerController::LoadControlGroup9() { LoadControlGroup(9); }

bool ATD2020PlayerController::IsConstructionProgressBarHotkeyPressed()
{
	return bConstructionProgressBarHotkeyPressed;
}

bool ATD2020PlayerController::IsHealthBarHotkeyPressed()
{
	return bHealthBarHotkeyPressed;
}

bool ATD2020PlayerController::IsProductionProgressBarHotkeyPressed()
{
	return bProductionProgressBarHotkeyPressed;
}

bool ATD2020PlayerController::CheckCanBeginBuildingPlacement(TSubclassOf<AActor> BuildingClass)
{
    
    return true;
}

void ATD2020PlayerController::BeginBuildingPlacement(TSubclassOf<AActor> BuildingClass)
{
	
}

bool ATD2020PlayerController::CanPlaceBuilding_Implementation(TSubclassOf<AActor> BuildingClass, const FVector& Location) const
{
	return false;
}

void ATD2020PlayerController::StaTD2020electActors()
{
	if (BuildingCursor)
	{
		// We're selecting a building location instead.
		return;
	}

	// Get mouse input.
	float MouseX;
	float MouseY;

	if (GetMousePosition(MouseX, MouseY))
	{
		SelectionFrameMouseStartPosition = FVector2D(MouseX, MouseY);
		bCreatingSelectionFrame = true;
	}
}

void ATD2020PlayerController::FinishSelectActors()
{
    // Get objects at pointer position.
    TArray<FHitResult> HitResults;
    
    if (!GetObjectsInSelectionFrame(HitResults))
    {
		bCreatingSelectionFrame = false;
        return;
    }

    // Check results.
	TArray<AActor*> ActorsToSelect;

	if (bAddSelectionHotkeyPressed || bToggleSelectionHotkeyPressed)
	{
		ActorsToSelect = SelectedActors;
	}

    for (auto& HitResult : HitResults)
    {
		if (!IsSelectableActor(HitResult.Actor.Get()))
		{
			continue;
		}

		// Check how to apply selection.
		if (bToggleSelectionHotkeyPressed)
		{
			if (SelectedActors.Contains(HitResult.Actor))
			{
				// Deselect actor.
				ActorsToSelect.Remove(HitResult.Actor.Get());

				UE_LOG(LogTD2020, Log, TEXT("Deselected actor %s."), *HitResult.Actor->GetName());
			}
			else if (!ActorsToSelect.Contains(HitResult.Actor))
			{
				// Select actor.
				ActorsToSelect.Add(HitResult.Actor.Get());

				UE_LOG(LogTD2020, Log, TEXT("Selected actor %s."), *HitResult.Actor->GetName());
			}
		}
		else
		{
			if (ActorsToSelect.Contains(HitResult.Actor))
			{
				continue;
			}

			// Select actor.
			ActorsToSelect.Add(HitResult.Actor.Get());

			UE_LOG(LogTD2020, Log, TEXT("Selected actor %s."), *HitResult.Actor->GetName());
		}
    }

	SelectActors(ActorsToSelect);

	bCreatingSelectionFrame = false;
}

void ATD2020PlayerController::StaTD2020howingConstructionProgressBars()
{
	bConstructionProgressBarHotkeyPressed = true;
}

void ATD2020PlayerController::StopShowingConstructionProgressBars()
{
	bConstructionProgressBarHotkeyPressed = false;
}

void ATD2020PlayerController::StaTD2020howingHealthBars()
{
	bHealthBarHotkeyPressed = true;
}

void ATD2020PlayerController::StopShowingHealthBars()
{
	bHealthBarHotkeyPressed = false;
}

void ATD2020PlayerController::StaTD2020howingProductionProgressBars()
{
	bProductionProgressBarHotkeyPressed = true;
}

void ATD2020PlayerController::StopShowingProductionProgressBars()
{
	bProductionProgressBarHotkeyPressed = false;
}

void ATD2020PlayerController::StartAddSelection()
{
	bAddSelectionHotkeyPressed = true;
}

void ATD2020PlayerController::StopAddSelection()
{
	bAddSelectionHotkeyPressed = false;
}

void ATD2020PlayerController::StartToggleSelection()
{
	bToggleSelectionHotkeyPressed = true;
}

void ATD2020PlayerController::StopToggleSelection()
{
	bToggleSelectionHotkeyPressed = false;
}

void ATD2020PlayerController::BeginDefaultBuildingPlacement()
{

}

void ATD2020PlayerController::ConfirmBuildingPlacement()
{
	
}

void ATD2020PlayerController::CancelBuildingPlacement()
{
	
}

void ATD2020PlayerController::CancelConstruction()
{
	
}

void ATD2020PlayerController::ServerCancelConstruction_Implementation(AActor* ConstructionSite)
{
	
}

bool ATD2020PlayerController::ServerCancelConstruction_Validate(AActor* ConstructionSite)
{
	// Verify owner to prevent cheating.
	return ConstructionSite->GetOwner() == this;
}

void ATD2020PlayerController::StartDefaultProduction()
{
    IssueProductionOrder(0);
}

void ATD2020PlayerController::CancelProduction()
{
	
}

void ATD2020PlayerController::ServerCancelProduction_Implementation(AActor* ProductionActor)
{
	
}

bool ATD2020PlayerController::ServerCancelProduction_Validate(AActor* ProductionActor)
{
	// Verify owner to prevent cheating.
	return ProductionActor->GetOwner() == this;
}

void ATD2020PlayerController::ServerStartProduction_Implementation(AActor* ProductionActor, int32 ProductIndex)
{
}

bool ATD2020PlayerController::ServerStartProduction_Validate(AActor* ProductionActor, int32 ProductIndex)
{
	// Verify owner to prevent cheating.
	return ProductionActor->GetOwner() == this;
}

void ATD2020PlayerController::MoveCameraLeftRight(float Value)
{
    CameraLeftRightAxisValue = Value;
}

void ATD2020PlayerController::MoveCameraUpDown(float Value)
{
    CameraUpDownAxisValue = Value;
}

void ATD2020PlayerController::NotifyOnActorOwnerChanged(AActor* Actor)
{
	ReceiveOnActorOwnerChanged(Actor);
}

void ATD2020PlayerController::NotifyOnBuildingPlacementStarted(TSubclassOf<AActor> BuildingClass)
{
	ReceiveOnBuildingPlacementStarted(BuildingClass);
}

void ATD2020PlayerController::NotifyOnBuildingPlacementConfirmed(TSubclassOf<AActor> BuildingClass, const FVector& Location)
{
	ReceiveOnBuildingPlacementConfirmed(BuildingClass, Location);
}

void ATD2020PlayerController::NotifyOnBuildingPlacementError(TSubclassOf<AActor> BuildingClass, const FVector& Location)
{
	ReceiveOnBuildingPlacementError(BuildingClass, Location);
}

void ATD2020PlayerController::NotifyOnBuildingPlacementCancelled(TSubclassOf<AActor> BuildingClass)
{
	ReceiveOnBuildingPlacementCancelled(BuildingClass);
}

void ATD2020PlayerController::NotifyOnErrorOccurred(const FString& ErrorMessage)
{
    ReceiveOnErrorOccurred(ErrorMessage);
}

void ATD2020PlayerController::NotifyOnIssuedAttackOrder(APawn* OrderedPawn, AActor* Target)
{
	ReceiveOnIssuedAttackOrder(OrderedPawn, Target);
}

void ATD2020PlayerController::NotifyOnIssuedBeginConstructionOrder(APawn* OrderedPawn, TSubclassOf<AActor> BuildingClass, const FVector& TargetLocation)
{
	ReceiveOnIssuedBeginConstructionOrder(OrderedPawn, BuildingClass, TargetLocation);
}

void ATD2020PlayerController::NotifyOnIssuedContinueConstructionOrder(APawn* OrderedPawn, AActor* ConstructionSite)
{
	ReceiveOnIssuedContinueConstructionOrder(OrderedPawn, ConstructionSite);
}

void ATD2020PlayerController::NotifyOnIssuedGatherOrder(APawn* OrderedPawn, AActor* ResourceSource)
{
	ReceiveOnIssuedGatherOrder(OrderedPawn, ResourceSource);
}

void ATD2020PlayerController::NotifyOnIssuedMoveOrder(APawn* OrderedPawn, const FVector& TargetLocation)
{
    ReceiveOnIssuedMoveOrder(OrderedPawn, TargetLocation);
}

void ATD2020PlayerController::NotifyOnIssuedProductionOrder(AActor* OrderedActor, int32 ProductIndex)
{
    ReceiveOnIssuedProductionOrder(OrderedActor, ProductIndex);
}

void ATD2020PlayerController::NotifyOnIssuedStopOrder(APawn* OrderedPawn)
{
	ReceiveOnIssuedStopOrder(OrderedPawn);
}

void ATD2020PlayerController::NotifyOnSelectionChanged(const TArray<AActor*>& Selection)
{
    ReceiveOnSelectionChanged(Selection);
}

void ATD2020PlayerController::NotifyOnTeamChanged(ATD2020TeamInfo* NewTeam)
{
	
}

void ATD2020PlayerController::NotifyOnVisionInfoAvailable(ATD2020VisionInfo* VisionInfo)
{
	
}

void ATD2020PlayerController::NotifyOnMinimapClicked(const FPointerEvent& InMouseEvent, const FVector2D& MinimapPosition, const FVector& WorldPosition)
{
	APawn* PlayerPawn = GetPawn();

	if (!PlayerPawn)
	{
		return;
	}

	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		// Move camera.

		MinimapLeftClick(InMouseEvent, MinimapPosition, WorldPosition);
		// old - this code below doesnt work on client because its not ROS
		/*FVector NewCameraLocation = FVector(WorldPosition.X, WorldPosition.Y, PlayerPawn->GetActorLocation().Z);
		PlayerPawn->SetActorLocation(NewCameraLocation);*/
	}
	else if (InMouseEvent.IsMouseButtonDown(EKeys::RightMouseButton))
	{
		// Get objects at pointer position.
		TArray<FHitResult> HitResults;

		if (!GetObjectsAtWorldPosition(WorldPosition, HitResults))
		{
			return;
		}

		IssueOrderTargetingObjects(HitResults);
	}
	
	// Notify listeners.
	ReceiveOnMinimapClicked(InMouseEvent, MinimapPosition, WorldPosition);
}

void ATD2020PlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);
	/*
    APawn* PlayerPawn = GetPawn();

    if (!PlayerPawn)
    {
        return;
    }
	
    // Get mouse input.
    float MouseX;
    float MouseY;

    const FVector2D ViewpoTD2020ize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());

    const float ScrollBorderRight = ViewpoTD2020ize.X - CameraScrollThreshold;
    const float ScrollBorderTop = ViewpoTD2020ize.Y - CameraScrollThreshold;

    if (GetMousePosition(MouseX, MouseY))
    {
        if (MouseX <= CameraScrollThreshold)
        {
            CameraLeftRightAxisValue -= 1 - (MouseX / CameraScrollThreshold);
        }
        else if (MouseX >= ScrollBorderRight)
        {
            CameraLeftRightAxisValue += (MouseX - ScrollBorderRight) / CameraScrollThreshold;
        }

        if (MouseY <= CameraScrollThreshold)
        {
            CameraUpDownAxisValue += 1 - (MouseY / CameraScrollThreshold);
        }
        else if (MouseY >= ScrollBorderTop)
        {
            CameraUpDownAxisValue -= (MouseY - ScrollBorderTop) / CameraScrollThreshold;
        }
    }

    // Apply input.
    CameraLeftRightAxisValue = FMath::Clamp(CameraLeftRightAxisValue, -1.0f, +1.0f);
    CameraUpDownAxisValue = FMath::Clamp(CameraUpDownAxisValue, -1.0f, +1.0f);
    
    FVector Location = PlayerPawn->GetActorLocation();
    Location += FVector::RightVector * CameraSpeed * CameraLeftRightAxisValue * DeltaTime;
    Location += FVector::ForwardVector * CameraSpeed * CameraUpDownAxisValue * DeltaTime;

    // Enforce camera bounds.
    if (!CameraBoundsVolume || CameraBoundsVolume->EncompassesPoint(Location))
    {
        PlayerPawn->SetActorLocation(Location);
    }
	
	// Get hovered actors.
	HoveredActor = nullptr;

	TArray<FHitResult> HitResults;

	if (GetObjectsAtPointerPosition(HitResults))
	{
		for (auto& HitResult : HitResults)
		{
			// Check if hit any actor.
			if (HitResult.Actor == nullptr || Cast<ALandscape>(HitResult.Actor.Get()) != nullptr)
			{
				// Store hovered world position.
				HoveredWorldPosition = HitResult.Location;

				// Update position of building being placed.
				if (BuildingCursor)
				{
					BuildingCursor->SetActorLocation(HoveredWorldPosition);

					if (CanPlaceBuilding(BuildingBeingPlacedClass, HoveredWorldPosition))
					{
						BuildingCursor->SetValidLocation();
					}
					else
					{
						BuildingCursor->SetInvalidLocation();
					}
				}
				continue;
			}

			// Check if hit selectable actor.
			auto SelectableComponent = HitResult.Actor->FindComponentByClass<UTD2020SelectableComponent>();

			if (!SelectableComponent)
			{
				continue;
			}

			// Set hovered actor.
			HoveredActor = HitResult.Actor.Get();
		}
	}

	// Verify selection.
	SelectedActors.RemoveAll([=](AActor* SelectedActor) { return SelectedActor->bHidden; });
	*/
}
