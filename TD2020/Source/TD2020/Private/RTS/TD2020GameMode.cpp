#include "TD2020.h"
#include "TD2020GameMode.h"

#include "CString.h"
#include "EngineUtils.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Controller.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"

#include "TD2020Character.h"
#include "TD2020ConstructionSiteComponent.h"
#include "TD2020OwnerComponent.h"
#include "TD2020PlayerAIController.h"
#include "TD2020PlayerAdvantageComponent.h"
#include "TD2020PlayerController.h"
#include "TD2020PlayerStart.h"
#include "TD2020TeamInfo.h"
#include "TD2020VisionInfo.h"


void ATD2020GameMode::BeginPlay()
{
    Super::BeginPlay();

    // Parse options.
    FString NumAIPlayersString = UGameplayStatics::ParseOption(OptionsString, TEXT("NumAIPlayers"));
    NumAIPlayers = FCString::Atoi(*NumAIPlayersString);

    UE_LOG(LogTD2020, Log, TEXT("NumAIPlayers = %i"), NumAIPlayers);

    // Spawn AI players.
    for (int32 Index = 0; Index < NumAIPlayers; ++Index)
    {
        ATD2020PlayerAIController* NewAI = StartAIPlayer();

        if (NewAI != nullptr)
        {
            NewAI->PlayerState->SetPlayerName(FString::Printf(TEXT("AI Player %i"), Index + 1));
        }
    }
}

void ATD2020GameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	AGameModeBase::InitGame(MapName, Options, ErrorMessage);

	// Set up teams.
	if (TeamClass == nullptr)
	{
		TeamClass = ATD2020TeamInfo::StaticClass();
	}

	for (uint8 TeamIndex = 0; TeamIndex < NumTeams; ++TeamIndex)
	{
		// Add team.
		ATD2020TeamInfo* NewTeam = GetWorld()->SpawnActor<ATD2020TeamInfo>(TeamClass);
		NewTeam->TeamIndex = TeamIndex;
		Teams.Add(NewTeam);

		// Setup vision.
		ATD2020VisionInfo* TeamVision = GetWorld()->SpawnActor<ATD2020VisionInfo>();
		TeamVision->SetTeamIndex(TeamIndex);
	}
}

ATD2020PlayerStart* ATD2020GameMode::FindTD2020PlayerStart(AController* Player)
{
	// Choose a player start.
	TArray<ATD2020PlayerStart*> UnOccupiedStartPoints;
	TArray<ATD2020PlayerStart*> OccupiedStartPoints;

	for (TActorIterator<ATD2020PlayerStart> It(GetWorld()); It; ++It)
	{
		ATD2020PlayerStart* PlayerStart = *It;

		if (PlayerStart->Player == nullptr)
		{
			UnOccupiedStartPoints.Add(PlayerStart);
		}
		else
		{
			OccupiedStartPoints.Add(PlayerStart);
		}
	}

	if (UnOccupiedStartPoints.Num() > 0)
	{
		return UnOccupiedStartPoints[FMath::RandRange(0, UnOccupiedStartPoints.Num() - 1)];
	}
	else if (OccupiedStartPoints.Num() > 0)
	{
		return OccupiedStartPoints[FMath::RandRange(0, OccupiedStartPoints.Num() - 1)];
	}

	return nullptr;
}

void ATD2020GameMode::RestartPlayer(AController* NewPlayer)
{
	if (NewPlayer == nullptr || NewPlayer->IsPendingKillPending())
	{
		return;
	}

	ATD2020PlayerStart* StaTD2020pot = FindTD2020PlayerStart(NewPlayer);
	RestartPlayerAtPlayerStart(NewPlayer, StaTD2020pot);
}

void ATD2020GameMode::RestartPlayerAtPlayerStart(AController* NewPlayer, AActor* StaTD2020pot)
{
	// Spawn default pawns (most likely, this will be the camera pawn in our case).
	AGameModeBase::RestartPlayerAtPlayerStart(NewPlayer, StaTD2020pot);

	// Verify parameters.
	if (NewPlayer == nullptr || NewPlayer->IsPendingKillPending())
	{
		return;
	}

	if (!StaTD2020pot)
	{
		return;
	}

	// Occupy start spot.
	ATD2020PlayerStart* PlayerStart = Cast<ATD2020PlayerStart>(StaTD2020pot);

	if (PlayerStart)
	{
		UE_LOG(LogTD2020, Log, TEXT("Start spot %s is now occupied by player %s."), *PlayerStart->GetName(), *NewPlayer->GetName());
		PlayerStart->Player = NewPlayer;
	}

	// Set team.
	if (PlayerStart->TeamIndex >= Teams.Num())
	{
		UE_LOG(LogTD2020, Warning, TEXT("Player start team index is %d, but game only has %d teams."), PlayerStart->TeamIndex, Teams.Num());
	}
	else
	{
		Teams[PlayerStart->TeamIndex]->AddToTeam(NewPlayer);
	}

	// Build spawn transform.
	// Don't allow initial actors to be spawned with any pitch or roll.
	FRotator SpawnRotation(ForceInit);
	SpawnRotation.Yaw = StaTD2020pot->GetActorRotation().Yaw;

	// Build spawn info.
	for (int32 i = 0; i < InitialActors.Num(); ++i)
	{
        TSubclassOf<AActor> ActorClass = InitialActors[i];

		// Spawn actor.
        FVector SpawnLocation = StaTD2020pot->GetActorLocation();

        if (i < InitialActorPositions.Num())
        {
            SpawnLocation += InitialActorPositions[i];
        }
        
        FTransform SpawnTransform = FTransform(SpawnRotation, SpawnLocation);
		AActor* SpawnedActor = SpawnActorForPlayer(ActorClass, NewPlayer, SpawnTransform);

        // Finish construction of initial buildings immediately.
        if (SpawnedActor != nullptr)
        {
            UTD2020ConstructionSiteComponent* ConstructionSiteComponent = SpawnedActor->FindComponentByClass<UTD2020ConstructionSiteComponent>();

            if (ConstructionSiteComponent != nullptr)
            {
                ConstructionSiteComponent->FinishConstruction();
            }
        }
	}
}

ATD2020PlayerAIController* ATD2020GameMode::StartAIPlayer()
{
    FActorSpawnParameters SpawnInfo;
    SpawnInfo.Instigator = Instigator;
    SpawnInfo.ObjectFlags |= RF_Transient;	// We never want to save player controllers into a map
    SpawnInfo.bDeferConstruction = true;
    ATD2020PlayerAIController* NewAI = GetWorld()->SpawnActor<ATD2020PlayerAIController>(PlayerAIControllerClass, FVector::ZeroVector, FRotator::ZeroRotator, SpawnInfo);
    if (NewAI)
    {
        UGameplayStatics::FinishSpawningActor(NewAI, FTransform(FRotator::ZeroRotator, FVector::ZeroVector));

        UE_LOG(LogTD2020, Log, TEXT("Spawned AI player %s."), *NewAI->GetName());
    }
    else
    {
        UE_LOG(LogTD2020, Error, TEXT("Failed to spawn AI player."));
        return nullptr;
    }

    RestartPlayer(NewAI);
    return NewAI;
}

AActor* ATD2020GameMode::SpawnActorForPlayer(TSubclassOf<AActor> ActorClass, AController* ActorOwner, const FTransform& SpawnTransform)
{
	// Spawn actor.
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorClass->GetDefaultObject()->GetClass(), SpawnTransform, SpawnParams);

	// Set owning player.
	if (SpawnedActor && ActorOwner)
	{
		UE_LOG(LogTD2020, Log, TEXT("Spawned %s for player %s at %s."), *SpawnedActor->GetName(), *ActorOwner->GetName(), *SpawnTransform.GetLocation().ToString());

		// Set owning player.
		TransferOwnership(SpawnedActor, ActorOwner);
	}

	return SpawnedActor;
}

void ATD2020GameMode::TransferOwnership(AActor* Actor, AController* NewOwner)
{
    if (!Actor || !NewOwner)
    {
        return;
    }

    // Set owning player.
    Actor->SetOwner(NewOwner);

    UTD2020OwnerComponent* OwnerComponent = Actor->FindComponentByClass<UTD2020OwnerComponent>();

    if (OwnerComponent)
    {
        OwnerComponent->SetPlayerOwner(NewOwner);
    }

    UE_LOG(LogTD2020, Log, TEXT("Player %s is now owning %s."), *NewOwner->GetName(), *Actor->GetName());

    // Check for god mode.
    UTD2020PlayerAdvantageComponent* PlayerAdvantageComponent = NewOwner->FindComponentByClass<UTD2020PlayerAdvantageComponent>();

    if (PlayerAdvantageComponent)
    {
        APawn* Pawn = Cast<APawn>(Actor);

        if (Pawn)
        {
            Pawn->bCanBeDamaged = !PlayerAdvantageComponent->bGodModeEnabled;
        }
    }

    // Notify listeners.
    ATD2020PlayerController* NewPlayerOwner = Cast<ATD2020PlayerController>(NewOwner);
    
    if (NewPlayerOwner != nullptr)
    {
        NewPlayerOwner->NotifyOnActorOwnerChanged(Actor);
    }    
}

void ATD2020GameMode::NotifyOnActorKilled(AActor* Actor, AController* ActorOwner)
{
	if (DefeatConditionActor == nullptr)
	{
		return;
	}

	ATD2020PlayerController* OwningPlayer = Cast<ATD2020PlayerController>(ActorOwner);

	if (OwningPlayer == nullptr)
	{
        ATD2020PlayerAIController* OwningAIPlayer = Cast<ATD2020PlayerAIController>(ActorOwner);

        if (OwningAIPlayer == nullptr)
        {
            return;
        }
	}

	// Check if any required actors are still alive.
	for (AActor* OwnedActor : ActorOwner->Children)
	{
		if (OwnedActor->GetClass() == DefeatConditionActor)
		{
			return;
		}
	}

	UE_LOG(LogTD2020, Log, TEXT("Player %s does not control any %s anymore and has been defeated."), *ActorOwner->GetName(), *DefeatConditionActor->GetName());

	// Notify listeners.
	NotifyOnPlayerDefeated(ActorOwner);
}

void ATD2020GameMode::NotifyOnPlayerDefeated(AController* Player)
{
	ReceiveOnPlayerDefeated(Player);
}
