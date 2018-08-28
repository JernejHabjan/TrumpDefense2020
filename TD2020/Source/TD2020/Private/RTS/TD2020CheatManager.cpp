#include "TD2020.h"
#include "TD2020CheatManager.h"

#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

#include "TD2020GameMode.h"
#include "TD2020PlayerController.h"
#include "TD2020PlayerAIController.h"
#include "TD2020PlayerAdvantageComponent.h"
#include "TD2020PlayerResourcesComponent.h"


void UTD2020CheatManager::Boost()
{
    APlayerController* Player = GetOuterAPlayerController();

    if (!Player)
    {
        return;
    }

    UTD2020PlayerAdvantageComponent* PlayerAdvantageComponent = Player->FindComponentByClass<UTD2020PlayerAdvantageComponent>();

    if (!PlayerAdvantageComponent)
    {
        return;
    }

    PlayerAdvantageComponent->SpeedBoostFactor *= SpeedBoostFactor;
    UE_LOG(LogTD2020, Log, TEXT("Cheat: Set speed boost factor to %f."), PlayerAdvantageComponent->SpeedBoostFactor);
}

void UTD2020CheatManager::God()
{
    Super::God();

    APlayerController* Player = GetOuterAPlayerController();

    if (!Player)
    {
        return;
    }

    UTD2020PlayerAdvantageComponent* PlayerAdvantageComponent = Player->FindComponentByClass<UTD2020PlayerAdvantageComponent>();

    if (!PlayerAdvantageComponent)
    {
        return;
    }

    // Toggle god mode.
    PlayerAdvantageComponent->bGodModeEnabled = !PlayerAdvantageComponent->bGodModeEnabled;

    for (TActorIterator<APawn> PawnItr(GetWorld()); PawnItr; ++PawnItr)
    {
        APawn* Pawn = *PawnItr;

        if (!IsValid(Pawn) || Pawn->GetOwner() != Player)
        {
            continue;
        }

        Pawn->bCanBeDamaged = !PlayerAdvantageComponent->bGodModeEnabled;
    }
}

void UTD2020CheatManager::Money()
{
    APlayerController* Player = GetOuterAPlayerController();

    if (!Player)
    {
        return;
    }

    UTD2020PlayerResourcesComponent* PlayerResourcesComponent = Player->FindComponentByClass<UTD2020PlayerResourcesComponent>();

    if (!PlayerResourcesComponent)
    {
        return;
    }

    for (TSubclassOf<UTD2020ResourceType> ResourceType : ResourceTypes)
    {
        PlayerResourcesComponent->AddResources(ResourceType, ResourceAmount);
        UE_LOG(LogTD2020, Log, TEXT("Cheat: Added %f %s."), ResourceAmount, *ResourceType->GetName());
    }
}

void UTD2020CheatManager::Victory()
{
    APlayerController* Player = GetOuterAPlayerController();

    if (!Player)
    {
        return;
    }

    ATD2020GameMode* GameMode = Cast<ATD2020GameMode>(UGameplayStatics::GetGameMode(Player));

    if (!GameMode)
    {
        return;
    }

    for (TActorIterator<AController> ControllerItr(GetWorld()); ControllerItr; ++ControllerItr)
    {
        AController* Controller = *ControllerItr;

        if (!IsValid(Controller) || Controller == Player)
        {
            continue;
        }

        if (Cast<ATD2020PlayerController>(Controller) == nullptr &&
            Cast <ATD2020PlayerAIController>(Controller) == nullptr)
        {
            continue;
        }

        GameMode->NotifyOnPlayerDefeated(Controller);
    }
}
