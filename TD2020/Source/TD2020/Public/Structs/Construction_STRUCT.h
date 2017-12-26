// No copyright - copy as you please

#pragma once

#include "Engine/UserDefinedStruct.h"
#include "Construction_STRUCT.generated.h"

class ABuildingMaster;
class AConstructionProxy;
class UStaticMesh;
class AResourcesMaster;


USTRUCT(BlueprintType)
struct FConstruction_Struct
{
	GENERATED_BODY()

	// Building Master class reference
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TSubclassOf<class ABuildingMaster> BuildingClass;

	// Construction Proxy class reference
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TSubclassOf<class AConstructionProxy> ProxyClass;

	// Construction transform
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		FTransform Transform;

	// Construction display static mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		UStaticMesh* DisplayMesh;

	// Work hours required to construct building
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float WorkHoursRequired;

	// What resource is building collecting
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		AResourcesMaster* Resource;
	

	// defaults 
	FConstruction_Struct(
		TSubclassOf<class ABuildingMaster> BuildingClass = nullptr,
		TSubclassOf<class AConstructionProxy> ProxyClass = nullptr,
		FTransform Transform = FTransform(),
		UStaticMesh* DisplayMesh = nullptr,
		float WorkHoursRequired = 0.0f,
		AResourcesMaster* Resource = nullptr)
	{
		this->BuildingClass = BuildingClass;
		this->ProxyClass = ProxyClass;
		this->Transform = Transform;
		this->DisplayMesh = DisplayMesh;
		this->WorkHoursRequired = WorkHoursRequired;
		this->Resource = Resource;
	}
};




UCLASS()
class TD2020_API UConstruction : public UUserDefinedStruct
{
	GENERATED_BODY()
	

	
};
