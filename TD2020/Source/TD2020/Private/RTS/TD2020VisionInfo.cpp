#include "TD2020.h"
#include "TD2020VisionInfo.h"

#include "EngineUtils.h"

#include "TD2020OwnerComponent.h"
#include "TD2020PlayerController.h"
#include "TD2020PlayerState.h"
#include "TD2020TeamInfo.h"
#include "TD2020VisionComponent.h"
#include "TD2020VisionVolume.h"
#include "Net/UnrealNetwork.h"

ATD2020VisionInfo::ATD2020VisionInfo()
{
	// Enable replication.
	SetReplicates(true);
	bAlwaysRelevant = true;
	NetUpdateFrequency = 1.0f;

	// Force ReceivedTeamIndex() on clients.
	TeamIndex = 255;

	PrimaryActorTick.bCanEverTick = true;
}

void ATD2020VisionInfo::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!VisionVolume)
	{
		return;
	}

	// Reset tiles.
	FIntVector TileSize = VisionVolume->GetTileSize();
	Tiles.SetNumZeroed(TileSize.X * TileSize.Y);

	for (int32 Index = 0; Index < Tiles.Num(); ++Index)
	{
		if (Tiles[Index] == ETD2020VisionState::VISION_Visible)
		{
			Tiles[Index] = ETD2020VisionState::VISION_Known;
		}
	}

	FIntVector WorldTileSize = VisionVolume->GetTileSize();

	// Apply vision.
	for (TActorIterator<AActor> ActorIt(GetWorld()); ActorIt; ++ActorIt)
	{
		AActor* Actor = *ActorIt;

		// Verify vision.
		UTD2020VisionComponent* VisionComponent = Actor->FindComponentByClass<UTD2020VisionComponent>();

		if (!VisionComponent)
		{
			continue;
		}

		// Verify team.
		UTD2020OwnerComponent* OwnerComponent = Actor->FindComponentByClass<UTD2020OwnerComponent>();
		ATD2020PlayerState* PlayerOwner = OwnerComponent->GetPlayerOwner();

		if (!PlayerOwner)
		{
			continue;
		}

		if (!PlayerOwner->Team)
		{
			continue;
		}

		if (PlayerOwner->Team->TeamIndex != TeamIndex)
		{
			continue;
		}

		// Convert location and sight radius to tile space.
		FVector ActorLocationWorld = Actor->GetActorLocation();
		FIntVector ActorLocationTile = VisionVolume->WorldToTile(ActorLocationWorld);
		int32 ActorSightRadiusTile = FMath::FloorToInt(VisionComponent->SightRadius / VisionVolume->SizePerTile);

		/*UE_LOG(LogTD2020, Log, TEXT("ActorLocationWorld: %s"), *ActorLocationWorld.ToString());
		UE_LOG(LogTD2020, Log, TEXT("ActorLocationTile: %s"), *ActorLocationTile.ToString());
		UE_LOG(LogTD2020, Log, TEXT("VisionComponent->SightRadius: %f"), VisionComponent->SightRadius);
		UE_LOG(LogTD2020, Log, TEXT("VisionVolume->SizePerTile: %f"), VisionVolume->SizePerTile);
		UE_LOG(LogTD2020, Log, TEXT("ActorSightRadiusTile: %i"), ActorSightRadiusTile);*/

		// XXX VERY simple circle algorithm.
		for (int32 RadiusY = -ActorSightRadiusTile; RadiusY < ActorSightRadiusTile; RadiusY++)
		{
			for (int32 RadiusX = -ActorSightRadiusTile; RadiusX < ActorSightRadiusTile; RadiusX++)
			{
				int32 TileX = ActorLocationTile.X + RadiusX;
				int32 TileY = ActorLocationTile.Y + RadiusY;

				// Check if within circle.
				if (TileX >= 0 &&
					TileY >= 0 &&
					TileX < WorldTileSize.X &&
					TileY < WorldTileSize.Y &&
					(RadiusX * RadiusX + RadiusY * RadiusY < ActorSightRadiusTile * ActorSightRadiusTile))
				{
					int32 TileIndex = GetTileIndex(TileX, TileY);
					Tiles[TileIndex] = ETD2020VisionState::VISION_Visible;

					//UE_LOG(LogTD2020, Log, TEXT("Revealed tile (%i, %i)."), TileX, TileY);
				}
			}
		}
	}
}

void ATD2020VisionInfo::SetTeamIndex(uint8 NewTeamIndex)
{
	TeamIndex = NewTeamIndex;
	NotifyPlayerVisionInfoAvailable();
}

ETD2020VisionState ATD2020VisionInfo::GetVision(int32 X, int32 Y) const
{
	int32 TileIndex = GetTileIndex(X, Y);
	return Tiles[TileIndex];
}

ATD2020VisionInfo* ATD2020VisionInfo::GetVisionInfoForTeam(UObject* WorldContextObject, uint8 InTeamIndex)
{
	UWorld* World = WorldContextObject->GetWorld();

	for (TActorIterator<ATD2020VisionInfo> It(World); It; ++It)
	{
		ATD2020VisionInfo* VisionInfo = *It;

		if (VisionInfo->TeamIndex == InTeamIndex)
		{
			return VisionInfo;
		}
	}

	return nullptr;
}

void ATD2020VisionInfo::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<ATD2020VisionVolume> It(GetWorld()); It; ++It)
	{
		VisionVolume = *It;
		break;
	}

	if (!VisionVolume)
	{
		UE_LOG(LogTD2020, Warning, TEXT("No vision volume found, won't update vision."));
		return;
	}

	FIntVector TileSize = VisionVolume->GetTileSize();
	Tiles.SetNumZeroed(TileSize.X * TileSize.Y);
}

bool ATD2020VisionInfo::GetTileCoordinates(int Index, int* OutX, int* OutY) const
{
	if (Index < 0 || Index >= Tiles.Num())
	{
		return false;
	}

	FIntVector TileSize = VisionVolume->GetTileSize();

	*OutX = Index % TileSize.X;
	*OutY = Index / TileSize.X;
	return true;
}

int32 ATD2020VisionInfo::GetTileIndex(int X, int Y) const
{
	return Y * VisionVolume->GetTileSize().X + X;
}

void ATD2020VisionInfo::NotifyPlayerVisionInfoAvailable()
{
	// Notify local player.
	UWorld* World = GetWorld();

	if (!World)
	{
		return;
	}

	ATD2020PlayerController* Player = Cast<ATD2020PlayerController>(World->GetFirstPlayerController());

	if (!Player)
	{
		return;
	}

	ATD2020TeamInfo* Team = Player->GetTeamInfo();

	if (!Team || Team->TeamIndex != TeamIndex)
	{
		return;
	}

	Player->NotifyOnVisionInfoAvailable(this);
}

void ATD2020VisionInfo::ReceivedTeamIndex()
{
	NotifyPlayerVisionInfoAvailable();
}

void ATD2020VisionInfo::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ATD2020VisionInfo, TeamIndex, COND_InitialOnly);
}
