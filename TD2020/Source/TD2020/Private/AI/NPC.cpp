// No copyright - copy as you please
#pragma once

#include "NPC.h"
#include "TD2020_Helpers.h"
#include "AI/NPC_AI_Controller.h"
#include "Camera/CameraPawnController.h"
#include "Game/MyGameState.h"
#include "Engine/SkeletalMesh.h"
#include "Components/TimelineComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "TD2020.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Engine/World.h"
#include "Engine.h"
#include "Enums/ENPCNameFemale.h"
#include "Enums/ENPCNameMale.h"
#include "Animation/AnimBlueprint.h"

// Sets default values
ANPC::ANPC()
{

	

	// COMPONENTS
	
	// #1 Capsule component properties
	GetCapsuleComponent()->InitCapsuleSize(34.0f, 88.0f);
	// collision properties
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_LANDSCAPE, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_BUILDING, ECR_Ignore);
	
	// #2 Mesh component properties
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> GenericMesh_HELPER(TEXT("SkeletalMesh'/Game/TD2020/Meshes/SkeletalMeshes/Generic.Generic'"));
	const ConstructorHelpers::FObjectFinder<UClass> GenericABP_HELPER(TEXT("Class'/Game/TD2020/Meshes/SkeletalMeshes/TD_Generic_ABP.TD_Generic_ABP_C'"));
	NPC_Mesh = GenericMesh_HELPER.Object;
	ABP = GenericABP_HELPER.Object;

	// Set mesh 
	GetMesh()->SetSkeletalMesh(NPC_Mesh);
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -93.0f));
	GetMesh()->RelativeRotation = FRotator(0.0f, -90.f, 0.0f);
	// set generic ABP
	GetMesh()->SetAnimInstanceClass(ABP);

	


	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// DEFAULTS
	AIController = nullptr;
	CameraPawnController = nullptr;
	NPC_HUD = nullptr;
	MyGameState = nullptr;
	Stamina = 80.0f;
	Hunger = 80.0f;
	//LerpLocationTimeline = nullptr; // -------------------------------------- TODO UNCOMMENT
	BehaviorTree = nullptr;
	IsBusy = FName("IsBusy");
	MyProfile = FNPCProfile_Struct();
	BaseWalkSpeed = 70.0f;
	//Add Female Meshes
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> Female_01_HELPER(TEXT("SkeletalMesh'/Game/TD2020/Meshes/SkeletalMeshes/Female_01.Female_01'"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> Female_02_HELPER(TEXT("SkeletalMesh'/Game/TD2020/Meshes/SkeletalMeshes/Female_02.Female_02'"));
	FemaleMesh.Add(Female_01_HELPER.Object);
	FemaleMesh.Add(Female_02_HELPER.Object);
	//Add Male Meshes
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> Male_01_HELPER(TEXT("SkeletalMesh'/Game/TD2020/Meshes/SkeletalMeshes/Male_01.Male_01'"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> Male_02_HELPER(TEXT("SkeletalMesh'/Game/TD2020/Meshes/SkeletalMeshes/Male_02.Male_02'"));
	MaleMesh.Add(Male_01_HELPER.Object);
	MaleMesh.Add(Male_02_HELPER.Object);


}



// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();

	// INIT NPC

	/*// Set mesh 
	GetMesh()->SetSkeletalMesh(NPC_Mesh);
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -93.0f));
	GetMesh()->RelativeRotation = FRotator(0.0f, -90.f, 0.0f);
	// set generic ABP
	GetMesh()->SetAnimInstanceClass(ABP);
	*/


	// controller gets set from Possess function in NPC_AI_Controller ---------------------- TODO IS THIS GOOOD????? DOES IT WORK?????

	CameraPawnController = Cast<ACameraPawnController>(UGameplayStatics::GetPlayerController(GEngine->GetWorld(), 0));

	// BIND EVENT TO HUD REQUEST AND CREATE NPC HUD WIDGET ------- TODO-------------------------------------------------------- TODO

	// BIND EVENT TO UPADE GAME SPEED ----------------------------------- TODO---------------------------------------------------TODO




	//UpdateWalkSpeed(0.0f);


}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Check against gate if its open
	/*if (IsGateOpen) {

		CameraPawnController->CameraPawn->SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, CameraPawnController->CameraPawn->GetActorLocation().Z));
	}*/



}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}







void ANPC::GetRandomName(const ENPCSex_Enum Sex, FString & Name)
{
	switch (Sex) {
	case ENPCSex_Enum::Male:
		Name = GetEnumValueToString<ENPCNameMale_Enum>("ENPCNameMale_Enum", ENPCNameMale_Enum(UKismetMathLibrary::RandomIntegerInRange(0, (int)ENPCNameMale_Enum::ENPCNameMale_MAX - 1)));
		break;
	case ENPCSex_Enum::Female:
		Name = GetEnumValueToString<ENPCNameFemale_Enum>("ENPCNameFemale_Enum", ENPCNameFemale_Enum(UKismetMathLibrary::RandomIntegerInRange(0, (int)ENPCNameFemale_Enum::ENPCNameFemale_MAX - 1)));
		break;
	}
}

/*


void ANPC::SetIsBusy(const bool IsBusy_IN)
{
}

bool ANPC::CheckForEmployment(bool & SearchSuccessful)
{
	return false; 
}
*/
void ANPC::GetNeeds(float & Stamina_OUT, float & Hunger_OUT)
{
	Stamina_OUT = Stamina;
	Hunger_OUT = Hunger;
}

/*

void ANPC::UpdateWalkSpeed(const float TimeUnit)
{
	//spremenil smo tud animacijo na 5 interpolacij ker imamo 5 game speedov
	//new max walk speed
	GetCharacterMovement()->MaxWalkSpeed = BaseWalkSpeed / MyGameState->SpeedMultiplier;
}

void ANPC::DisplayHUD(const AActor * Actor, const bool Bypass)
{
	// if is constructing and is invisible
	
	
	bool Hidden = false;  // -------------------------------------------------- TODO SET THIS TO --- GET ACTOR HIDDEN IN GAME
	

	//Gets called on selected, if not selected this class, ignore it
	if (Actor == this && (Bypass || !Hidden)) {

		// MANAGE HUD AND LERP------------------------------------------------- TODO
	}
	CameraPawnController->DisableCamNav = true;

	OpenFollowGate();
}*/

void ANPC::SetController(ANPC_AI_Controller * InOwner)
{
	AIController = InOwner;
}

void ANPC::OnConstruction(const FTransform & Transform)
{

	/*
	
	// Set mesh 
	GetMesh()->SetSkeletalMesh(NPC_Mesh);
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -93.0f));
	GetMesh()->RelativeRotation = FRotator(0.0f, -90.f, 0.0f);
	// set generic ABP
	GetMesh()->SetAnimInstanceClass(ABP);


	RandomNPCFeatures();

	*/
		
}
/*
void ANPC::RandomNPCFeatures()
{
	// Set temp local variables to simplify code
	TArray<USkeletalMesh*> SelectedGender_Meshes;
	ENPCSex::Type SelectedGender_Sex;

	// Get random sex
	ENPCSex::Type NPC_Sex = ENPCSex::Type(UKismetMathLibrary::Conv_IntToByte(UKismetMathLibrary::RandomIntegerInRange(0, 1)));
	switch (NPC_Sex) {
	case ENPCSex::Male:
		SelectedGender_Meshes = MaleMesh;
		SelectedGender_Sex = ENPCSex::Male;
		break;
	case ENPCSex::Female:
		SelectedGender_Meshes = FemaleMesh;
		SelectedGender_Sex = ENPCSex::Female;
		break;
	}

	// Set properties according to gender // TODO--------------------------------------------------- TODO

	int index = UKismetMathLibrary::RandomIntegerInRange(0, SelectedGender_Meshes.Num()-1);
	GetMesh()->SetSkeletalMesh(SelectedGender_Meshes[index]);
	// make profile
	FString NPC_Name;
	GetRandomName(SelectedGender_Sex, NPC_Name);
	MyProfile = FNPCProfile_STRUCT(NPC_Name, SelectedGender_Sex);
	
}

*/