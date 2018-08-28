#include "TD2020.h"
#include "TD2020PlayerController.h"

#include "EngineUtils.h"
#include "Landscape.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/Engine.h"
#include "Engine/LocalPlayer.h"
#include "Engine/SkeletalMesh.h"
#include "Kismet/GameplayStatics.h"

#include "TD2020AttackComponent.h"
#include "TD2020AttackableComponent.h"
#include "TD2020BuilderComponent.h"
#include "TD2020BuildingCursor.h"
#include "TD2020CameraBoundsVolume.h"
#include "TD2020Character.h"
#include "TD2020CharacterAIController.h"
#include "TD2020ConstructionSiteComponent.h"
#include "TD2020FogOfWarActor.h"
#include "TD2020GathererComponent.h"
#include "TD2020NameComponent.h"
#include "TD2020OwnerComponent.h"
#include "TD2020PlayerAdvantageComponent.h"
#include "TD2020PlayerResourcesComponent.h"
#include "TD2020PlayerState.h"
#include "TD2020ProductionComponent.h"
#include "TD2020ProductionCostComponent.h"
#include "TD2020ResourceSourceComponent.h"
#include "TD2020SelectableComponent.h"
#include "TD2020TeamInfo.h"
#include "TD2020Utilities.h"
#include "TD2020VisionInfo.h"


ATD2020PlayerController::ATD2020PlayerController()
{
    PlayerAdvantageComponent = CreateDefaultSubobject<UTD2020PlayerAdvantageComponent>(TEXT("Player Advantage"));
    PlayerResourcesComponent = CreateDefaultSubobject<UTD2020PlayerResourcesComponent>(TEXT("Player Resources"));
}

void ATD2020PlayerController::BeginPlay()
{
	APlayerController::BeginPlay();


	if (!PlayerResourcesComponent || !PlayerResourcesComponent->IsValidLowLevel()) {
		return;
	}
	//try { 
		// Allow immediate updates for interested listeners.
		for (int32 Index = 0; Index < PlayerResourcesComponent->ResourceTypes.Num(); ++Index)
		{
			PlayerResourcesComponent->OnResourcesChanged.Broadcast(
				PlayerResourcesComponent->ResourceTypes[Index],
				0.0f,
				PlayerResourcesComponent->ResourceAmounts[Index],
				true);
		}
	/*}
	catch (const std::exception e) { 
		std::exception b = e;
		UE_LOG(LogTD2020, Warning, TEXT("Exception Player controller, Begin play."));

	}*/

    
}

void ATD2020PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Enable mouse input.
	APlayerController::bShowMouseCursor = true;
	APlayerController::bEnableClickEvents = true;
	APlayerController::bEnableMouseOverEvents = true;

	// Bind actions.
	InputComponent->BindAction(TEXT("Select"), IE_Pressed, this, &ATD2020PlayerController::StaTD2020electActors);
	InputComponent->BindAction(TEXT("Select"), IE_Released, this, &ATD2020PlayerController::FinishSelectActors);
	InputComponent->BindAction(TEXT("AddSelection"), IE_Pressed, this, &ATD2020PlayerController::StartAddSelection);
	InputComponent->BindAction(TEXT("AddSelection"), IE_Released, this, &ATD2020PlayerController::StopAddSelection);
	InputComponent->BindAction(TEXT("ToggleSelection"), IE_Pressed, this, &ATD2020PlayerController::StartToggleSelection);
	InputComponent->BindAction(TEXT("ToggleSelection"), IE_Released, this, &ATD2020PlayerController::StopToggleSelection);

	InputComponent->BindAction(TEXT("IssueOrder"), IE_Released, this, &ATD2020PlayerController::IssueOrder);
	InputComponent->BindAction(TEXT("IssueStopOrder"), IE_Released, this, &ATD2020PlayerController::IssueStopOrder);

	InputComponent->BindAction(TEXT("SaveControlGroup0"), IE_Released, this, &ATD2020PlayerController::SaveControlGroup0);
	InputComponent->BindAction(TEXT("SaveControlGroup1"), IE_Released, this, &ATD2020PlayerController::SaveControlGroup1);
	InputComponent->BindAction(TEXT("SaveControlGroup2"), IE_Released, this, &ATD2020PlayerController::SaveControlGroup2);
	InputComponent->BindAction(TEXT("SaveControlGroup3"), IE_Released, this, &ATD2020PlayerController::SaveControlGroup3);
	InputComponent->BindAction(TEXT("SaveControlGroup4"), IE_Released, this, &ATD2020PlayerController::SaveControlGroup4);
	InputComponent->BindAction(TEXT("SaveControlGroup5"), IE_Released, this, &ATD2020PlayerController::SaveControlGroup5);
	InputComponent->BindAction(TEXT("SaveControlGroup6"), IE_Released, this, &ATD2020PlayerController::SaveControlGroup6);
	InputComponent->BindAction(TEXT("SaveControlGroup7"), IE_Released, this, &ATD2020PlayerController::SaveControlGroup7);
	InputComponent->BindAction(TEXT("SaveControlGroup8"), IE_Released, this, &ATD2020PlayerController::SaveControlGroup8);
	InputComponent->BindAction(TEXT("SaveControlGroup9"), IE_Released, this, &ATD2020PlayerController::SaveControlGroup9);

	InputComponent->BindAction(TEXT("LoadControlGroup0"), IE_Released, this, &ATD2020PlayerController::LoadControlGroup0);
	InputComponent->BindAction(TEXT("LoadControlGroup1"), IE_Released, this, &ATD2020PlayerController::LoadControlGroup1);
	InputComponent->BindAction(TEXT("LoadControlGroup2"), IE_Released, this, &ATD2020PlayerController::LoadControlGroup2);
	InputComponent->BindAction(TEXT("LoadControlGroup3"), IE_Released, this, &ATD2020PlayerController::LoadControlGroup3);
	InputComponent->BindAction(TEXT("LoadControlGroup4"), IE_Released, this, &ATD2020PlayerController::LoadControlGroup4);
	InputComponent->BindAction(TEXT("LoadControlGroup5"), IE_Released, this, &ATD2020PlayerController::LoadControlGroup5);
	InputComponent->BindAction(TEXT("LoadControlGroup6"), IE_Released, this, &ATD2020PlayerController::LoadControlGroup6);
	InputComponent->BindAction(TEXT("LoadControlGroup7"), IE_Released, this, &ATD2020PlayerController::LoadControlGroup7);
	InputComponent->BindAction(TEXT("LoadControlGroup8"), IE_Released, this, &ATD2020PlayerController::LoadControlGroup8);
	InputComponent->BindAction(TEXT("LoadControlGroup9"), IE_Released, this, &ATD2020PlayerController::LoadControlGroup9);

	InputComponent->BindAxis(TEXT("MoveCameraLeftRight"), this, &ATD2020PlayerController::MoveCameraLeftRight);
	InputComponent->BindAxis(TEXT("MoveCameraUpDown"), this, &ATD2020PlayerController::MoveCameraUpDown);

	InputComponent->BindAction(TEXT("ShowConstructionProgressBars"), IE_Pressed, this, &ATD2020PlayerController::StaTD2020howingConstructionProgressBars);
	InputComponent->BindAction(TEXT("ShowConstructionProgressBars"), IE_Released, this, &ATD2020PlayerController::StopShowingConstructionProgressBars);
	InputComponent->BindAction(TEXT("ShowHealthBars"), IE_Pressed, this, &ATD2020PlayerController::StaTD2020howingHealthBars);
	InputComponent->BindAction(TEXT("ShowHealthBars"), IE_Released, this, &ATD2020PlayerController::StopShowingHealthBars);
	InputComponent->BindAction(TEXT("ShowProductionProgressBars"), IE_Pressed, this, &ATD2020PlayerController::StaTD2020howingProductionProgressBars);
	InputComponent->BindAction(TEXT("ShowProductionProgressBars"), IE_Released, this, &ATD2020PlayerController::StopShowingProductionProgressBars);

	InputComponent->BindAction(TEXT("BeginDefaultBuildingPlacement"), IE_Released, this, &ATD2020PlayerController::BeginDefaultBuildingPlacement);
	InputComponent->BindAction(TEXT("ConfirmBuildingPlacement"), IE_Released, this, &ATD2020PlayerController::ConfirmBuildingPlacement);
	InputComponent->BindAction(TEXT("CancelBuildingPlacement"), IE_Released, this, &ATD2020PlayerController::CancelBuildingPlacement);

	InputComponent->BindAction(TEXT("CancelConstruction"), IE_Released, this, &ATD2020PlayerController::CancelConstruction);

	InputComponent->BindAction(TEXT("StartDefaultProduction"), IE_Released, this, &ATD2020PlayerController::StartDefaultProduction);
	InputComponent->BindAction(TEXT("CancelProduction"), IE_Released, this, &ATD2020PlayerController::CancelProduction);

	// Get camera bounds.
	for (TActorIterator<ATD2020CameraBoundsVolume> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		CameraBoundsVolume = *ActorItr;
		break;
	}

	if (!CameraBoundsVolume)
	{
		UE_LOG(LogTD2020, Warning, TEXT("No TD2020CameraBoundsVolume found. Camera will be able to move anywhere."));
	}

	// Setup control groups.
	ControlGroups.SetNum(10);
}

void ATD2020PlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

AActor* ATD2020PlayerController::GetHoveredActor()
{
	return HoveredActor;
}

ATD2020PlayerState* ATD2020PlayerController::GetPlayerState()
{
	return Cast<ATD2020PlayerState>(PlayerState);
}

TArray<AActor*> ATD2020PlayerController::GetSelectedActors()
{
	return SelectedActors;
}

bool ATD2020PlayerController::GetObjectsAtScreenPosition(FVector2D ScreenPosition, TArray<FHitResult>& OutHitResults)
{
	// Get ray.
	FVector WorldOrigin;
	FVector WorldDirection;
	if (!UGameplayStatics::DeprojectScreenToWorld(this, ScreenPosition, WorldOrigin, WorldDirection))
	{
		return false;
	}

	// Cast ray.
	return TraceObjects(WorldOrigin, WorldDirection, OutHitResults);
}

bool ATD2020PlayerController::GetObjectsAtWorldPosition(const FVector& WorldPositionXY, TArray<FHitResult>& OutHitResults)
{
	// Get ray.
	FVector WorldOrigin = FVector(WorldPositionXY.X, WorldPositionXY.Y, HitResultTraceDistance / 2);
	FVector WorldDirection = -FVector::UpVector;

	// Cast ray.
	return TraceObjects(WorldOrigin, WorldDirection, OutHitResults);
}

bool ATD2020PlayerController::GetSelectionFrame(FIntRect& OutSelectionFrame)
{

	if (!bCreatingSelectionFrame)
	{
		return false;
	}

	// Get mouse input.
	float MouseX;
	float MouseY;

	if (!GetMousePosition(MouseX, MouseY))
	{
		return false;
	}

	OutSelectionFrame = FIntRect(
		FIntPoint(SelectionFrameMouseStartPosition.X, SelectionFrameMouseStartPosition.Y),
		FIntPoint(MouseX, MouseY));

	return true;
}

ATD2020TeamInfo* ATD2020PlayerController::GetTeamInfo() const
{
	ATD2020PlayerState* CurrentPlayerState = Cast<ATD2020PlayerState>(PlayerState);

	if (CurrentPlayerState)
	{
		return CurrentPlayerState->Team;
	}
	
	return nullptr;
}

bool ATD2020PlayerController::GetObjectsAtPointerPosition(TArray<FHitResult>& OutHitResults)
{

    // Get local player viewport.
    ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);

    if (!LocalPlayer || !LocalPlayer->ViewportClient)
    {
        return false;
    }

    // Get mouse position.
    FVector2D MousePosition;
    if (!LocalPlayer->ViewportClient->GetMousePosition(MousePosition))
    {
        return false;
    }

	return GetObjectsAtScreenPosition(MousePosition, OutHitResults);
}

bool ATD2020PlayerController::GetObjectsInSelectionFrame(TArray<FHitResult>& HitResults)
{
	UWorld* World = GetWorld();

	if (!World)
	{
		return false;
	}

	// Get selection frame.
	FIntRect SelectionFrame;
	
	if (!GetSelectionFrame(SelectionFrame))
	{
		return false;
	}

	if (SelectionFrame.Area() < 10)
	{
		// Selection frame too small - just consider left-click.
		return GetObjectsAtPointerPosition(HitResults);
	}

	// Iterate all actors.
	HitResults.Reset();

	for (TActorIterator<AActor> ActorIt(GetWorld()); ActorIt; ++ActorIt)
	{
		AActor* Actor = *ActorIt;

		FVector2D ActorScreenPosition;

		if (UGameplayStatics::ProjectWorldToScreen(this, Actor->GetActorLocation(), ActorScreenPosition))
		{
			if (SelectionFrame.Contains(FIntPoint(ActorScreenPosition.X, ActorScreenPosition.Y)))
			{
				FHitResult HitResult(Actor, nullptr, Actor->GetActorLocation(), FVector());
				HitResults.Add(HitResult);
			}
		}
	}

	return HitResults.Num() > 0;
}

bool ATD2020PlayerController::TraceObjects(const FVector& WorldOrigin, const FVector& WorldDirection, TArray<FHitResult>& OutHitResults)
{
	UWorld* World = GetWorld();

	if (!World)
	{
		return false;
	}

	FCollisionObjectQueryParams Params(FCollisionObjectQueryParams::InitType::AllObjects);

	return World->LineTraceMultiByObjectType(
		OutHitResults,
		WorldOrigin,
		WorldOrigin + WorldDirection * HitResultTraceDistance,
		Params);
}


bool ATD2020PlayerController::IsSelectableActor(AActor* Actor)
{
	// Check if valid.
	if (!IsValid(Actor))
	{
		return false;
	}

	// Check if selectable.
	auto SelectableComponent = Actor->FindComponentByClass<UTD2020SelectableComponent>();

	if (!SelectableComponent)
	{
		return false;
	}

	return true;
}

void ATD2020PlayerController::IssueOrder()
{
    // Get objects at pointer position.
    TArray<FHitResult> HitResults;

    if (!GetObjectsAtPointerPosition(HitResults))
    {
        return;
    }

	IssueOrderTargetingObjects(HitResults);
}

void ATD2020PlayerController::IssueOrderTargetingObjects(TArray<FHitResult>& HitResults)
{
	// Check if there's anybody to receive the order.
	if (SelectedActors.Num() == 0)
	{
		return;
	}

	// Get target location.
	for (auto& HitResult : HitResults)
	{
		if (HitResult.Actor != nullptr)
		{
			// Issue attack order.
			if (IssueAttackOrder(HitResult.Actor.Get()))
			{
				return;
			}
			
			// Issue gather order.
			if (IssueGatherOrder(HitResult.Actor.Get()))
			{
				return;
			}

			// Issue construct order.
			if (IssueContinueConstructionOrder(HitResult.Actor.Get()))
			{
				return;
			}

            ALandscape* Landscape = Cast<ALandscape>(HitResult.Actor.Get());

            if (Landscape != nullptr)
            {
                // Issue move order.
                IssueMoveOrder(HitResult.Location);
                return;
            }

			continue;
		}

		// Issue move order.
		IssueMoveOrder(HitResult.Location);
		return;
	}
}

bool ATD2020PlayerController::IssueAttackOrder(AActor* Target)
{
	if (!Target)
	{
		return false;
	}

	if (!Target->FindComponentByClass<UTD2020AttackableComponent>())
	{
		return false;
	}

	ATD2020TeamInfo* MyTeam = GetPlayerState()->Team;

	// Issue attack orders.
	bool bSuccess = false;

	for (auto SelectedActor : SelectedActors)
	{
		APawn* SelectedPawn = Cast<APawn>(SelectedActor);

		if (!SelectedPawn)
		{
			continue;
		}

		if (SelectedPawn->GetOwner() != this)
		{
			continue;
		}

		// Verify target.
		auto TargetOwnerComponent = Target->FindComponentByClass<UTD2020OwnerComponent>();

		if (TargetOwnerComponent && TargetOwnerComponent->IsSameTeamAsActor(SelectedActor))
		{
			continue;
		}

		if (SelectedActor->FindComponentByClass<UTD2020AttackComponent>() == nullptr)
		{
			continue;
		}

		// Send attack order to server.
		ServerIssueAttackOrder(SelectedPawn, Target);

        if (IsNetMode(NM_Client))
        {
            UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to attack %s."), *SelectedActor->GetName(), *Target->GetName());

            // Notify listeners.
            NotifyOnIssuedAttackOrder(SelectedPawn, Target);
        }

		bSuccess = true;
	}

	return bSuccess;
}

void ATD2020PlayerController::ServerIssueAttackOrder_Implementation(APawn* OrderedPawn, AActor* Target)
{
	auto PawnController = Cast<ATD2020CharacterAIController>(OrderedPawn->GetController());

	if (!PawnController)
	{
		return;
	}

	// Issue attack order.
	PawnController->IssueAttackOrder(Target);
	UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to attack %s."), *OrderedPawn->GetName(), *Target->GetName());

	// Notify listeners.
	NotifyOnIssuedAttackOrder(OrderedPawn, Target);
}

bool ATD2020PlayerController::ServerIssueAttackOrder_Validate(APawn* OrderedPawn, AActor* Target)
{
	// Verify owner to prevent cheating.
	return OrderedPawn->GetOwner() == this;
}

bool ATD2020PlayerController::IssueBeginConstructionOrder(TSubclassOf<AActor> BuildingClass, const FVector& TargetLocation)
{
	// Find suitable selected builder.
	for (auto SelectedActor : SelectedActors)
	{
		APawn* SelectedPawn = Cast<APawn>(SelectedActor);

		if (!SelectedPawn)
		{
			continue;
		}

		if (SelectedPawn->GetOwner() != this)
		{
			continue;
		}

		// Check if builder.
		auto BuilderComponent = SelectedPawn->FindComponentByClass<UTD2020BuilderComponent>();

		if (!BuilderComponent)
		{
			continue;
		}

		// Check if builder knows about building.
		if (!BuilderComponent->ConstructibleBuildingClasses.Contains(BuildingClass))
		{
			continue;
		}

		// Send construction order to server.
		ServerIssueBeginConstructionOrder(SelectedPawn, BuildingClass, TargetLocation);

        if (IsNetMode(NM_Client))
        {
            UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to begin constructing %s at %s."), *SelectedPawn->GetName(), *BuildingClass->GetName(), *TargetLocation.ToString());

            // Notify listeners.
            NotifyOnIssuedBeginConstructionOrder(SelectedPawn, BuildingClass, TargetLocation);
        }

		// Just send one builder.
		return true;
	}

	return false;
}

bool ATD2020PlayerController::ServerIssueContinueConstructionOrder_Validate(APawn* OrderedPawn, AActor* ConstructionSite)
{
	// Verify owner to prevent cheating.
	return OrderedPawn->GetOwner() == this;
}

void ATD2020PlayerController::ServerIssueBeginConstructionOrder_Implementation(APawn* OrderedPawn, TSubclassOf<AActor> BuildingClass, const FVector& TargetLocation)
{
	auto PawnController = Cast<ATD2020CharacterAIController>(OrderedPawn->GetController());

	if (!PawnController)
	{
		return;
	}

	// Issue construction order.
	PawnController->IssueBeginConstructionOrder(BuildingClass, TargetLocation);
	UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to begin constructing %s at %s."), *OrderedPawn->GetName(), *BuildingClass->GetName(), *TargetLocation.ToString());

	// Notify listeners.
	NotifyOnIssuedBeginConstructionOrder(OrderedPawn, BuildingClass, TargetLocation);
}

bool ATD2020PlayerController::IssueContinueConstructionOrder(AActor* ConstructionSite)
{
	if (!ConstructionSite)
	{
		return false;
	}

	auto ConstructionSiteComponent = ConstructionSite->FindComponentByClass<UTD2020ConstructionSiteComponent>();

	if (!ConstructionSiteComponent || ConstructionSiteComponent->IsFinished())
	{
		return false;
	}

	ATD2020TeamInfo* MyTeam = GetPlayerState()->Team;

	// Issue construction orders.
	bool bSuccess = false;

	for (auto SelectedActor : SelectedActors)
	{
		APawn* SelectedPawn = Cast<APawn>(SelectedActor);

		if (!SelectedPawn)
		{
			continue;
		}

		if (SelectedPawn->GetOwner() != this)
		{
			continue;
		}

		// Verify target.
		auto TargetOwnerComponent = ConstructionSite->FindComponentByClass<UTD2020OwnerComponent>();

		if (TargetOwnerComponent && !TargetOwnerComponent->IsSameTeamAsActor(SelectedActor))
		{
			continue;
		}

		if (SelectedActor->FindComponentByClass<UTD2020BuilderComponent>() == nullptr)
		{
			continue;
		}

		// Send construction order to server.
		ServerIssueContinueConstructionOrder(SelectedPawn, ConstructionSite);

        if (IsNetMode(NM_Client))
        {
            UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to continue constructing %s."), *SelectedActor->GetName(), *ConstructionSite->GetName());

            // Notify listeners.
            NotifyOnIssuedContinueConstructionOrder(SelectedPawn, ConstructionSite);
        }

		bSuccess = true;
	}

	return bSuccess;
}

bool ATD2020PlayerController::IssueGatherOrder(AActor* ResourceSource)
{
	if (!ResourceSource)
	{
		return false;
	}

	auto ResourceSourceComponent = ResourceSource->FindComponentByClass<UTD2020ResourceSourceComponent>();

	if (!ResourceSourceComponent)
	{
		return false;
	}

	// Issue gather orders.
	bool bSuccess = false;

	for (auto SelectedActor : SelectedActors)
	{
		APawn* SelectedPawn = Cast<APawn>(SelectedActor);

		if (!SelectedPawn)
		{
			continue;
		}

		if (SelectedPawn->GetOwner() != this)
		{
			continue;
		}

		// Verify gatherer.
		auto GathererComponent = SelectedActor->FindComponentByClass<UTD2020GathererComponent>();
		if (!GathererComponent || !GathererComponent->CanGatherFrom(ResourceSource))
		{
			continue;
		}

		// Send gather order to server.
		ServerIssueGatherOrder(SelectedPawn, ResourceSource);

        if (IsNetMode(NM_Client))
        {
            UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to gather resources from %s."), *SelectedActor->GetName(), *ResourceSource->GetName());

            // Notify listeners.
            NotifyOnIssuedGatherOrder(SelectedPawn, ResourceSource);
        }

		bSuccess = true;
	}

	return bSuccess;
}

void ATD2020PlayerController::ServerIssueGatherOrder_Implementation(APawn* OrderedPawn, AActor* ResourceSource)
{
	auto PawnController = Cast<ATD2020CharacterAIController>(OrderedPawn->GetController());

	if (!PawnController)
	{
		return;
	}

	// Issue gather order.
	PawnController->IssueGatherOrder(ResourceSource);
	UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to gather resources from %s."), *OrderedPawn->GetName(), *ResourceSource->GetName());

	// Notify listeners.
	NotifyOnIssuedGatherOrder(OrderedPawn, ResourceSource);
}

bool ATD2020PlayerController::ServerIssueGatherOrder_Validate(APawn* OrderedPawn, AActor* ResourceSourc)
{
	// Verify owner to prevent cheating.
	return OrderedPawn->GetOwner() == this;
}

void ATD2020PlayerController::ServerIssueContinueConstructionOrder_Implementation(APawn* OrderedPawn, AActor* ConstructionSite)
{
	auto PawnController = Cast<ATD2020CharacterAIController>(OrderedPawn->GetController());

	if (!PawnController)
	{
		return;
	}

	// Issue construction order.
	PawnController->IssueContinueConstructionOrder(ConstructionSite);
	UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to continue constructing %s."), *OrderedPawn->GetName(), *ConstructionSite->GetName());

	// Notify listeners.
	NotifyOnIssuedContinueConstructionOrder(OrderedPawn, ConstructionSite);
}

bool ATD2020PlayerController::ServerIssueBeginConstructionOrder_Validate(APawn* OrderedPawn, TSubclassOf<AActor> BuildingClass, const FVector& TargetLocation)
{
	// Verify owner to prevent cheating.
	return OrderedPawn->GetOwner() == this;
}

bool ATD2020PlayerController::IssueMoveOrder(const FVector& TargetLocation)
{
    // Issue move orders.
	bool bSuccess = false;

    for (auto SelectedActor : SelectedActors)
    {
        // Verify pawn and owner.
        auto SelectedPawn = Cast<APawn>(SelectedActor);

        if (!SelectedPawn)
        {
            continue;
        }

		if (SelectedPawn->GetOwner() != this)
		{
			continue;
		}

		// Send move order to server.
		ServerIssueMoveOrder(SelectedPawn, TargetLocation);

        if (IsNetMode(NM_Client))
        {
            UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to move to %s."), *SelectedActor->GetName(), *TargetLocation.ToString());

            // Notify listeners.
            NotifyOnIssuedMoveOrder(SelectedPawn, TargetLocation);
        }

		bSuccess = true;
    }

	return bSuccess;
}

void ATD2020PlayerController::ServerIssueMoveOrder_Implementation(APawn* OrderedPawn, const FVector& TargetLocation)
{
	auto PawnController = Cast<ATD2020CharacterAIController>(OrderedPawn->GetController());

	if (!PawnController)
	{
		return;
	}

	// Issue move order.
	PawnController->IssueMoveOrder(TargetLocation);
	UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to move to %s."), *OrderedPawn->GetName(), *TargetLocation.ToString());

	// Notify listeners.
	NotifyOnIssuedMoveOrder(OrderedPawn, TargetLocation);
}

bool ATD2020PlayerController::ServerIssueMoveOrder_Validate(APawn* OrderedPawn, const FVector& TargetLocation)
{
	// Verify owner to prevent cheating.
	return OrderedPawn->GetOwner() == this;
}

AActor* ATD2020PlayerController::GetSelectedProductionActor()
{
    // Find suitable selected actor.
    for (auto SelectedActor : SelectedActors)
    {
        // Verify owner.
        if (SelectedActor->GetOwner() != this)
        {
            continue;
        }

        // Check if production actor.
        auto ProductionComponent = SelectedActor->FindComponentByClass<UTD2020ProductionComponent>();

        if (!ProductionComponent)
        {
            continue;
        }

        if (ProductionComponent->AvailableProducts.Num() <= 0)
        {
            continue;
        }

        return SelectedActor;
    }

    return nullptr;
}

bool ATD2020PlayerController::CheckCanIssueProductionOrder(int32 ProductIndex)
{
    AActor* SelectedActor = GetSelectedProductionActor();

    if (!SelectedActor)
    {
        return true;
    }

    UTD2020ProductionComponent* ProductionComponent = SelectedActor->FindComponentByClass<UTD2020ProductionComponent>();

    if (ProductIndex >= ProductionComponent->AvailableProducts.Num())
    {
        return true;
    }

    TSubclassOf<AActor> ProductClass = ProductionComponent->AvailableProducts[ProductIndex];

    // Check costs.
    UTD2020ProductionCostComponent* ProductionCostComponent = UTD2020Utilities::FindDefaultComponentByClass<UTD2020ProductionCostComponent>(ProductClass);

    if (ProductionCostComponent && !PlayerResourcesComponent->CanPayAllResources(ProductionCostComponent->Resources))
    {
        NotifyOnErrorOccurred(TEXT("Not enough resources."));
        return false;
    }

    // Check requirements.
    TSubclassOf<AActor> MissingRequirement;

    if (UTD2020Utilities::GetMissingRequirementFor(this, SelectedActor, ProductClass, MissingRequirement))
    {
        UTD2020NameComponent* NameComponent = UTD2020Utilities::FindDefaultComponentByClass<UTD2020NameComponent>(MissingRequirement);

        if (NameComponent)
        {
            FString ErrorMessage = TEXT("Missing requirement: ");
            ErrorMessage.Append(NameComponent->Name.ToString());
            NotifyOnErrorOccurred(ErrorMessage);
        }
        else
        {
            NotifyOnErrorOccurred("Missing requirement.");
        }

        return false;
    }

    return true;
}

void ATD2020PlayerController::IssueProductionOrder(int32 ProductIndex)
{
    AActor* SelectedActor = GetSelectedProductionActor();

    if (!SelectedActor)
    {
        return;
    }

    // Begin production.
    ServerStartProduction(SelectedActor, ProductIndex);

    if (IsNetMode(NM_Client))
    {
        UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to start production %i."), *SelectedActor->GetName(), ProductIndex);

        // Notify listeners.
        NotifyOnIssuedProductionOrder(SelectedActor, ProductIndex);
    }
}

void ATD2020PlayerController::IssueStopOrder()
{
	// Issue stop orders.
	for (auto SelectedActor : SelectedActors)
	{
		// Verify pawn and owner.
		auto SelectedPawn = Cast<APawn>(SelectedActor);

		if (!SelectedPawn)
		{
			continue;
		}

		if (SelectedPawn->GetOwner() != this)
		{
			continue;
		}

		// Send stop order to server.
		ServerIssueStopOrder(SelectedPawn);

        if (IsNetMode(NM_Client))
        {
            UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to stop."), *SelectedActor->GetName());

            // Notify listeners.
            NotifyOnIssuedStopOrder(SelectedPawn);
        }
	}
}

void ATD2020PlayerController::ServerIssueStopOrder_Implementation(APawn* OrderedPawn)
{
	auto PawnController = Cast<ATD2020CharacterAIController>(OrderedPawn->GetController());

	if (!PawnController)
	{
		return;
	}

	// Issue stop order.
	PawnController->IssueStopOrder();
	UE_LOG(LogTD2020, Log, TEXT("Ordered actor %s to stop."), *OrderedPawn->GetName());

	// Notify listeners.
	NotifyOnIssuedStopOrder(OrderedPawn);
}

bool ATD2020PlayerController::ServerIssueStopOrder_Validate(APawn* OrderedPawn)
{
	// Verify owner to prevent cheating.
	return OrderedPawn->GetOwner() == this;
}

void ATD2020PlayerController::SelectActors(TArray<AActor*> Actors)
{
	// Clear selection.
	for (AActor* SelectedActor : SelectedActors)
	{
		UTD2020SelectableComponent* SelectableComponent = SelectedActor->FindComponentByClass<UTD2020SelectableComponent>();

		if (SelectableComponent)
		{
			SelectableComponent->DeselectActor();
		}
	}

	// Apply new selection.
	SelectedActors = Actors;

	for (AActor* SelectedActor : SelectedActors)
	{
		UTD2020SelectableComponent* SelectableComponent = SelectedActor->FindComponentByClass<UTD2020SelectableComponent>();

		if (SelectableComponent)
		{
			SelectableComponent->SelectActor();
		}
	}

	// Notify listeners.
	NotifyOnSelectionChanged(SelectedActors);
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
    // Check resources.
    UTD2020ConstructionSiteComponent* ConstructionSiteComponent = UTD2020Utilities::FindDefaultComponentByClass<UTD2020ConstructionSiteComponent>(BuildingClass);

    if (ConstructionSiteComponent && !PlayerResourcesComponent->CanPayAllResources(ConstructionSiteComponent->ConstructionCosts))
    {
        NotifyOnErrorOccurred(TEXT("Not enough resources."));
        return false;
    }

    // Check requirements.
    if (SelectedActors.Num() > 0)
    {
        TSubclassOf<AActor> MissingRequirement;

        if (UTD2020Utilities::GetMissingRequirementFor(this, SelectedActors[0], BuildingClass, MissingRequirement))
        {
            UTD2020NameComponent* NameComponent = UTD2020Utilities::FindDefaultComponentByClass<UTD2020NameComponent>(MissingRequirement);

            if (NameComponent)
            {
                FString ErrorMessage = TEXT("Missing requirement: ");
                ErrorMessage.Append(NameComponent->Name.ToString());
                NotifyOnErrorOccurred(ErrorMessage);
            }
            else
            {
                NotifyOnErrorOccurred("Missing requirement.");
            }

            return false;
        }
    }
    
    return true;
}

void ATD2020PlayerController::BeginBuildingPlacement(TSubclassOf<AActor> BuildingClass)
{
	// Spawn dummy building.
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AActor* DefaultBuilding = BuildingClass->GetDefaultObject<AActor>();
	USkeletalMeshComponent* SkeletalMeshComponent = DefaultBuilding->FindComponentByClass<USkeletalMeshComponent>();

	BuildingCursor = GetWorld()->SpawnActor<ATD2020BuildingCursor>(BuildingCursorClass, SpawnParams);
	BuildingCursor->SetMesh(SkeletalMeshComponent->SkeletalMesh, DefaultBuilding->GetActorRelativeScale3D());
	BuildingCursor->SetInvalidLocation();

	BuildingBeingPlacedClass = BuildingClass;

	UE_LOG(LogTD2020, Log, TEXT("Beginning placement of building %s."), *BuildingClass->GetName());

	// Notify listeners.
	NotifyOnBuildingPlacementStarted(BuildingClass);
}

bool ATD2020PlayerController::CanPlaceBuilding_Implementation(TSubclassOf<AActor> BuildingClass, const FVector& Location) const
{
	UWorld* World = GetWorld();
    return UTD2020Utilities::IsSuitableLocationForActor(World, BuildingClass, Location);
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
	// Find suitable selected builder.
	for (auto SelectedActor : SelectedActors)
	{
		// Verify owner.
		if (SelectedActor->GetOwner() != this)
		{
			continue;
		}

		// Check if builder.
		auto BuilderComponent = SelectedActor->FindComponentByClass<UTD2020BuilderComponent>();

		if (!BuilderComponent)
		{
			continue;
		}

		// Check if builder knows about building.
		if (BuilderComponent->ConstructibleBuildingClasses.Num() <= 0)
		{
			continue;
		}

		// Begin placement.
		BeginBuildingPlacement(BuilderComponent->ConstructibleBuildingClasses[0]);
		return;
	}
}

void ATD2020PlayerController::ConfirmBuildingPlacement()
{
	if (!BuildingCursor)
	{
		return;
	}

	if (!CanPlaceBuilding(BuildingBeingPlacedClass, HoveredWorldPosition))
	{
		UE_LOG(LogTD2020, Log, TEXT("Can't place building %s at %s."), *BuildingBeingPlacedClass->GetName(), *HoveredWorldPosition.ToString());

		// Notify listeners.
		NotifyOnBuildingPlacementError(BuildingBeingPlacedClass, HoveredWorldPosition);
		return;
	}

	UE_LOG(LogTD2020, Log, TEXT("Placed building %s at %s."), *BuildingBeingPlacedClass->GetName(), *HoveredWorldPosition.ToString());

	// Remove dummy building.
	BuildingCursor->Destroy();
	BuildingCursor = nullptr;

	// Notify listeners.
	NotifyOnBuildingPlacementConfirmed(BuildingBeingPlacedClass, HoveredWorldPosition);

	// Start construction.
	IssueBeginConstructionOrder(BuildingBeingPlacedClass, HoveredWorldPosition);
}

void ATD2020PlayerController::CancelBuildingPlacement()
{
	if (!BuildingCursor)
	{
		return;
	}

	// Remove dummy building.
	BuildingCursor->Destroy();
	BuildingCursor = nullptr;

	UE_LOG(LogTD2020, Log, TEXT("Cancelled placement of building %s."), *BuildingBeingPlacedClass->GetName());

	// Notify listeners.
	NotifyOnBuildingPlacementCancelled(BuildingBeingPlacedClass);
}

void ATD2020PlayerController::CancelConstruction()
{
	for (auto SelectedActor : SelectedActors)
	{
		// Verify construction site and owner.
		auto ConstructionSiteComponent = SelectedActor->FindComponentByClass<UTD2020ConstructionSiteComponent>();

		if (!ConstructionSiteComponent)
		{
			continue;
		}

		if (SelectedActor->GetOwner() != this)
		{
			continue;
		}

		// Send message to server.
		ServerCancelConstruction(SelectedActor);

		// Only cancel one construction at a time.
		return;
	}
}

void ATD2020PlayerController::ServerCancelConstruction_Implementation(AActor* ConstructionSite)
{
	auto ConstructionSiteComponent = ConstructionSite->FindComponentByClass<UTD2020ConstructionSiteComponent>();

	if (!ConstructionSiteComponent)
	{
		return;
	}

	// Cancel construction.
	ConstructionSiteComponent->CancelConstruction();
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
	for (auto SelectedActor : SelectedActors)
	{
		// Verify production actor.
		auto ProductionComponent = SelectedActor->FindComponentByClass<UTD2020ProductionComponent>();

		if (!ProductionComponent)
		{
			continue;
		}

		if (SelectedActor->GetOwner() != this)
		{
			continue;
		}

		if (!UTD2020Utilities::IsReadyToUse(SelectedActor))
		{
			continue;
		}

		// Send message to server.
		ServerCancelProduction(SelectedActor);

		// Only cancel one production at a time.
		return;
	}
}

void ATD2020PlayerController::ServerCancelProduction_Implementation(AActor* ProductionActor)
{
	auto ProductionComponent = ProductionActor->FindComponentByClass<UTD2020ProductionComponent>();

	if (!ProductionComponent)
	{
		return;
	}

	// Cancel production.
	ProductionComponent->CancelProduction();
}

bool ATD2020PlayerController::ServerCancelProduction_Validate(AActor* ProductionActor)
{
	// Verify owner to prevent cheating.
	return ProductionActor->GetOwner() == this;
}

void ATD2020PlayerController::ServerStartProduction_Implementation(AActor* ProductionActor, int32 ProductIndex)
{
	auto ProductionComponent = ProductionActor->FindComponentByClass<UTD2020ProductionComponent>();

	if (!ProductionComponent)
	{
		return;
	}

	if (ProductionComponent->AvailableProducts.Num() <= ProductIndex)
	{
		return;
	}

	// Begin production.
	TSubclassOf<AActor> ProductClass = ProductionComponent->AvailableProducts[ProductIndex];
	ProductionComponent->StartProduction(ProductClass);
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
	if (NewTeam)
	{
		// Notify listeners that new vision info is available now.
		ATD2020VisionInfo* VisionInfo = ATD2020VisionInfo::GetVisionInfoForTeam(GetWorld(), NewTeam->TeamIndex);
		NotifyOnVisionInfoAvailable(VisionInfo);
	}
}

void ATD2020PlayerController::NotifyOnVisionInfoAvailable(ATD2020VisionInfo* VisionInfo)
{
	// On server side, we're only interested in our own vision info.
	// Other player controllers that exist on the server for replication to the clients
	// should not affect rendering vision for the local player.
	if (this != GetWorld()->GetFirstPlayerController())
	{
		return;
	}

	// Setup fog of war.
	for (TActorIterator<ATD2020FogOfWarActor> ActorIt(GetWorld()); ActorIt; ++ActorIt)
	{
		ATD2020FogOfWarActor* FogOfWarActor = *ActorIt;
		FogOfWarActor->SetupVisionInfo(VisionInfo);
		break;
	}

	// Allow others to setup vision.
	ReceiveOnVisionInfoAvailable(VisionInfo);
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
