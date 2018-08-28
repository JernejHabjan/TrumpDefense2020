#pragma once
#include "Templates/SubclassOf.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TD2020Utilities.generated.h"


class AActor;
class UWorld;
class UShapeComponent;


/**
* Various utility functions.
*/
UCLASS()
class TD2020_API UTD2020Utilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UTD2020Utilities(const FObjectInitializer & ObjectInitializer);


    /** Gets the distance between the two specified actors, optionally subtracting their collision sizes. */
    UFUNCTION(BlueprintPure, Category = "TD2020")
	static float GetActorDistance(AActor* First, AActor* Second, bool bConsiderCollisionSize);

    /** Gets the approximated collision size of actors of the specified class. */
    UFUNCTION(BlueprintPure, Category = "TD2020")
    static float GetCollisionSize(TSubclassOf<AActor> ActorClass);

    /** Gets the approximated collision height of actors of the specified class. */
    UFUNCTION(BlueprintPure, Category = "TD2020")
    static float GetCollisionHeight(TSubclassOf<AActor> ActorClass);

    /** Gets the approximated collision size of the specified actor. */
    UFUNCTION(BlueprintPure, Category = "TD2020")
    static float GetActorCollisionSize(AActor* Actor);

    /** Gets the approximated collision height of the specified actor. */
    UFUNCTION(BlueprintPure, Category = "TD2020")
    static float GetActorCollisionHeight(AActor* Actor);

    /** Gets the approximated collision size of the specified shape. */
    UFUNCTION(BlueprintPure, Category = "TD2020")
    static float GetShapeCollisionSize(UShapeComponent* ShapeComponent);

    /** Gets the approximated collision height of the specified shape. */
    UFUNCTION(BlueprintPure, Category = "TD2020")
    static float GetShapeCollisionHeight(UShapeComponent* ShapeComponent);

    /** Casts a ray to determine the z coordinate of the specified location on ground level. */
    UFUNCTION(BlueprintPure, Category = "TD2020", meta = (WorldContext = "WorldContextObject"))
    static FVector GetGroundLocation(UObject* WorldContextObject, FVector Location);

    /** Checks whether the specified actor is owned by an AI player. */
    UFUNCTION(BlueprintPure, Category = "TD2020")
    static bool IsAIUnit(AActor* Actor);

	/** Checks whether the specified actor is ready to use (e.g. finished construction). */
    UFUNCTION(BlueprintPure, Category = "TD2020")
	static bool IsReadyToUse(AActor* Actor);

    /**
    * Checks whether the specified actor can be placed at the passed location.
    */
    UFUNCTION(BlueprintCallable, Category = "TD2020")
    static bool IsSuitableLocationForActor(UWorld* World, TSubclassOf<AActor> ActorClass, const FVector& Location);

	/** Searches the components attached to the specified actor class and returns the first encountered component of the specified class. */
	template<class T>
	static T* FindDefaultComponentByClass(const TSubclassOf<AActor> InActorClass)
	{
		return (T*)FindDefaultComponentByClass(InActorClass, T::StaticClass());
	}

	/** Searches the components attached to the specified actor class and returns the first encountered component of the specified class. */
	UFUNCTION(BlueprintCallable, Category = "TD2020")
	static UActorComponent* FindDefaultComponentByClass(const TSubclassOf<AActor> InActorClass, const TSubclassOf<UActorComponent> InComponentClass);

    /** Checks if the owner of the specified actor meets all requirements for producing the desired new actor. */
    UFUNCTION(BlueprintCallable, Category = "TD2020", meta = (WorldContext = "WorldContextObject"))
    static bool OwnerMeetsAllRequirementsFor(UObject* WorldContextObject, AActor* OwnedActor, TSubclassOf<AActor> DesiredProduct);

    /** Checks if the owner of the specified actor meets all requirements for producing the desired new actor. */
    static bool GetMissingRequirementFor(UObject* WorldContextObject, AActor* OwnedActor, TSubclassOf<AActor> DesiredProduct, TSubclassOf<AActor>& OutMissingRequirement);
};
