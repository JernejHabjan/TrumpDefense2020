#pragma once


#include "GameFramework/GameModeBase.h"

#include "TD2020GameMode.generated.h"


class AController;

class ATD2020PlayerAIController;
class ATD2020PlayerController;
class ATD2020PlayerStart;
class ATD2020TeamInfo;


/**
* Game mode with TD2020 features, such as spawning initial units for each player.
*/
UCLASS()
class TD2020_API ATD2020GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	/** Actors to spawn for each player in the game. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	TArray<TSubclassOf<AActor>> InitialActors;

    /** Relative locations of the actors to spawn for each player in the game, relative to their respetive start spot. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
    TArray<FVector> InitialActorPositions;

	/** Optional type of actor that is required for a player to be alive. As soon as no actor of the specified type is alive, the player is defeated. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "TD2020")
	TSubclassOf<AActor> DefeatConditionActor;

	/** Number of teams to create. */
	UPROPERTY(EditDefaultsOnly, Category = "Team")
	uint8 NumTeams;

	/** Teams of the current match. */
	UPROPERTY(BlueprintReadOnly, Category = "Team")
	TArray<ATD2020TeamInfo*> Teams;

	/** Class of TeamInfo to spawn. */
	UPROPERTY(EditDefaultsOnly, Category = "Team")
	TSubclassOf<ATD2020TeamInfo> TeamClass;

    /** AIController class to spawn for AI players. */
    UPROPERTY(EditDefaultsOnly, Category = AI)
    TSubclassOf<ATD2020PlayerAIController> PlayerAIControllerClass;

    
    virtual void BeginPlay() override;
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	ATD2020PlayerStart* FindTD2020PlayerStart(AController* Player);

	virtual void RestartPlayer(AController* NewPlayer) override;
	virtual void RestartPlayerAtPlayerStart(AController* NewPlayer, AActor* StaTD2020pot) override;

    virtual ATD2020PlayerAIController* StartAIPlayer();

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
	UFUNCTION(BlueprintImplementableEvent, Category = "TD2020", meta = (DisplayName = "OnPlayerDefeated"))
	void ReceiveOnPlayerDefeated(AController* Player);

private:
    /** Number of AI players to spawn. */
    int32 NumAIPlayers;
};
