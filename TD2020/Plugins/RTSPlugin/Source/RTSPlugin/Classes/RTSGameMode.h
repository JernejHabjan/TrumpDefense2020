#pragma once

#include "RTSPluginPCH.h"

#include "GameFramework/GameModeBase.h"

#include "RTSGameMode.generated.h"


class AController;

class ARTSPlayerAIController;
class ARTSPlayerController;
class ARTSPlayerStart;
class ARTSTeamInfo;


/**
* Game mode with RTS features, such as spawning initial units for each player.
*/
UCLASS()
class RTSPLUGIN_API ARTSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	/** Actors to spawn for each player in the game. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RTS")
	TArray<TSubclassOf<AActor>> InitialActors;

    /** Relative locations of the actors to spawn for each player in the game, relative to their respetive start spot. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RTS")
    TArray<FVector> InitialActorPositions;

	/** Optional type of actor that is required for a player to be alive. As soon as no actor of the specified type is alive, the player is defeated. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RTS")
	TSubclassOf<AActor> DefeatConditionActor;

	/** Number of teams to create. */
	UPROPERTY(EditDefaultsOnly, Category = "Team")
	uint8 NumTeams;

	/** Teams of the current match. */
	UPROPERTY(BlueprintReadOnly, Category = "Team")
	TArray<ARTSTeamInfo*> Teams;

	/** Class of TeamInfo to spawn. */
	UPROPERTY(EditDefaultsOnly, Category = "Team")
	TSubclassOf<ARTSTeamInfo> TeamClass;

    /** AIController class to spawn for AI players. */
    UPROPERTY(EditDefaultsOnly, Category = AI)
    TSubclassOf<ARTSPlayerAIController> PlayerAIControllerClass;

    
    virtual void BeginPlay() override;
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	ARTSPlayerStart* FindRTSPlayerStart(AController* Player);

	virtual void RestartPlayer(AController* NewPlayer) override;
	virtual void RestartPlayerAtPlayerStart(AController* NewPlayer, AActor* StartSpot) override;

    virtual ARTSPlayerAIController* StartAIPlayer();

	/** Spawns an actor of the specified type and transfers ownership to the specified player. */
	virtual AActor* SpawnActorForPlayer(TSubclassOf<AActor> ActorClass, AController* ActorOwner, const FTransform& SpawnTransform);

    /** Sets the specified player as the owner of the passed actor. */
    UFUNCTION(BlueprintCallable)
    void TransferOwnership(AActor* Actor, AController* NewOwner);

	/** Event when an actor has been killed. */
	virtual void NotifyOnActorKilled(AActor* Actor, AController* ActorOwner);

	/** Event when a player has been defeated. */
	virtual void NotifyOnPlayerDefeated(AController* Player);

	/** Event when a player has been defeated. */
	UFUNCTION(BlueprintImplementableEvent, Category = "RTS", meta = (DisplayName = "OnPlayerDefeated"))
	void ReceiveOnPlayerDefeated(AController* Player);

private:
    /** Number of AI players to spawn. */
    int32 NumAIPlayers;
};
