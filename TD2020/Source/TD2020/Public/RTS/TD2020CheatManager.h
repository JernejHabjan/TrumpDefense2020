#pragma once


#include "GameFramework/CheatManager.h"
//#include "TD2020ResourceType.h"
#include "TD2020CheatManager.generated.h"




UCLASS(Blueprintable, Within = PlayerController)
class TD2020_API UTD2020CheatManager : public UCheatManager
{
    GENERATED_BODY()

public:
    /** Amount of resources to grant with the Money cheat. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cheat Manager")
    float ResourceAmount;

    /** Types of resources to grant with the Money cheat. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cheat Manager")
    TArray<TSubclassOf<class UTD2020ResourceType>> ResourceTypes;

    /** Factor to multiply all construction and production speed with. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Cheat Manager")
    float SpeedBoostFactor;


    /** Increases construction and production speed. */
    UFUNCTION(exec, BlueprintCallable, Category = "Cheat Manager")
    virtual void Boost();

    /** Invulnerability cheat. */
    //UFUNCTION(exec, BlueprintCallable, Category = "Cheat Manager")
    virtual void God() override;

    /** Adds resources. */
    UFUNCTION(exec, BlueprintCallable, Category = "Cheat Manager")
    virtual void Money();

    /** Defeat all other players. */
    UFUNCTION(exec, BlueprintCallable, Category = "Cheat Manager")
    virtual void Victory();
};
