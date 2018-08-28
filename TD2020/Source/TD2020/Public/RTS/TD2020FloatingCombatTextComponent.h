#pragma once


#include "Components/ActorComponent.h"

#include "TD2020FloatingCombatTextData.h"

#include "TD2020FloatingCombatTextComponent.generated.h"


/**
* Stores floating texts to be displayed above the actor.
*/
UCLASS(meta = (BlueprintSpawnableComponent))
class TD2020_API UTD2020FloatingCombatTextComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    /** Floating combat texts currently being displayed to the player. */
    TArray<FTD2020FloatingCombatTextData> Texts;


    UTD2020FloatingCombatTextComponent(const FObjectInitializer& ObjectInitializer);


    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;


    /** Adds the specified text to be displayed above the actor in the HUD for a short time. */
    UFUNCTION(BlueprintCallable)
    void AddText(const FString& Text, const FLinearColor& Color, float Scale, float Lifetime);
};
