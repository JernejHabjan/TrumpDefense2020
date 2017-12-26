// No copyright - copy as you please

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Structs/NPCProfile_STRUCT.h"
#include "NPC.generated.h"

class ANPC_AI_Controller;
class USkeletalMesh;
class ACameraPawnController;
class AMyGameState;
class UTimelineComponent;



UCLASS()
class TD2020_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// PROPERTIES

	// TODO------------------------------------------------------
	UPROPERTY(EditAnywhere, Category = "NPC|Properties")
		USkeletalMesh *NPC_Mesh;
	UPROPERTY(EditAnywhere, Category = "NPC|Properties")
		UClass* ABP;



	bool IsGateOpen = false;// TODO - LOCAL GATE FOR SETTING ACTOR LOCATION
	void OpenFollowGate() { IsGateOpen = true; }
	void CloseFollowGate() { IsGateOpen = false; }



	//References
	UPROPERTY(BlueprintReadWrite, Category = "NPC|References")
	ANPC_AI_Controller* AIController;
	
	UPROPERTY(BlueprintReadWrite, Category = "NPC|References")
	ACameraPawnController* CameraPawnController;

	UPROPERTY(BlueprintReadWrite, Category = "NPC|References")
	UObject* NPC_HUD; // TODO--------------------------- CHANGE THIS TO NPC_HUD object reference -------------------------------------- TODO

	UPROPERTY(BlueprintReadWrite, Category = "NPC|References")
	AMyGameState* MyGameState;

	// Stats
	UPROPERTY(BlueprintReadWrite, Category = "NPC|Stats")
	float Stamina;

	UPROPERTY(BlueprintReadWrite, Category = "NPC|Stats")
	float Hunger;

	//Components
	//UPROPERTY(EditAnywhere, Category = "NPC|Components")
	//UTimelineComponent* LerpLocationTimeline;

	//Properties
	
	UPROPERTY(EditAnywhere, Category = "NPC")
	class UBehaviorTree *BehaviorTree;

	UPROPERTY(BlueprintReadWrite, Category = "NPC")
	//name has to be exactly the same as is in blackboard
	FName IsBusy;

	UPROPERTY(BlueprintReadWrite, Category = "NPC")
	FNPCProfile_Struct MyProfile;

	UPROPERTY(BlueprintReadWrite, Category = "NPC")
	float BaseWalkSpeed;

	UPROPERTY(BlueprintReadWrite, Category = "NPC")
	TArray<USkeletalMesh*> MaleMesh;

	UPROPERTY(BlueprintReadWrite, Category = "NPC")
	TArray<USkeletalMesh*> FemaleMesh;




	// FUNCTIONS

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// construction script
	virtual void OnConstruction(const FTransform& Transform) override;

	
	/*
	// Sets features like mesh and name according to gender
	UFUNCTION(BlueprintCallable, Category = "NPC|Personal Settings")
	void RandomNPCFeatures();
	*/

	// Retruns name according to gender
	// Parameters
	// IN Sex enum
	// OUT FString Name
	UFUNCTION(BlueprintCallable, Category = "NPC|Personal Settings")
	void GetRandomName(const ENPCSex_Enum Sex, FString &Name);
	/*
	// Sets blackboard value isBusy according to input
	// Parameters
	// IN bool IsBusy
	UFUNCTION(BlueprintCallable, Category = "NPC|Work")
	void SetIsBusy(const bool IsBusy_IN);

	
	// Returns if NPC has Job
	// Parameters
	// OUT bool SearchSuccessful
	UFUNCTION(BlueprintCallable, Category = "NPC|Work")
	bool CheckForEmployment(bool &SearchSuccessful);
	*/
	// Returns needs like Stamina, hunger...
	// Parameters
	// OUT float Stamina
	// OUT float Hunger
	UFUNCTION(BlueprintPure, Category = "NPC")
	void GetNeeds(float &Stamina_OUT, float &Hunger_OUT);

	/*

	// EVENT-------------------------------------------------------- TODO
	// max walk speed is 140 - because we have half size world - we have 70 - change in character movement component
	// Parameters
	// IN float TimeUnit
	//UFUNCTION(BlueprintNativeEvent, Category = "NPC|EVENT")
	UFUNCTION(BlueprintCallable, Category = "NPC|EVENT")
	void UpdateWalkSpeed(const float TimeUnit);

	// EVENT-------------------------------------------------------- TODO
	// Parameters
	// IN AActor* Actor
	// IN bool Bypass -bypass for selecting NPC in construction proxy
	//UFUNCTION(BlueprintNativeEvent, Category = "NPC|EVENT")
	UFUNCTION(BlueprintCallable, Category = "NPC|EVENT")
	void DisplayHUD(const AActor* Actor, const bool Bypass);
	
	*/

	/** Set owning AI controller. */
	void SetController(ANPC_AI_Controller* InOwner);

};
