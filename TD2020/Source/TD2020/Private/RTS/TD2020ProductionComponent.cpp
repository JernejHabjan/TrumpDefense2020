#include "TD2020.h"
#include "TD2020ProductionComponent.h"

#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Engine/SCS_Node.h"
#include "Kismet/GameplayStatics.h"

#include "TD2020GameMode.h"
#include "TD2020ProductionCostComponent.h"
#include "TD2020PlayerController.h"
#include "TD2020PlayerAdvantageComponent.h"
#include "TD2020PlayerResourcesComponent.h"
#include "TD2020Utilities.h"
#include "Net/UnrealNetwork.h"

UTD2020ProductionComponent::UTD2020ProductionComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;

	SetIsReplicated(true);
}

void UTD2020ProductionComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UTD2020ProductionComponent, ProductionQueues);
}

void UTD2020ProductionComponent::BeginPlay()
{
	UActorComponent::BeginPlay();

	// Setup queues.
	for (int32 QueueIndex = 0; QueueIndex < QueueCount; ++QueueIndex)
	{
		FTD2020ProductionQueue NewQueue;
		ProductionQueues.Add(NewQueue);
	}
}

void UTD2020ProductionComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	UActorComponent::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Check for speed boosts.
    float SpeedBoostFactor = 1.0f;
    AActor* OwningActor = GetOwner();

    if (OwningActor)
    {
        AActor* OwningPlayer = OwningActor->GetOwner();

        if (OwningPlayer)
        {
            UTD2020PlayerAdvantageComponent* PlayerAdvantageComponent = OwningPlayer->FindComponentByClass<UTD2020PlayerAdvantageComponent>();

            if (PlayerAdvantageComponent)
            {
                SpeedBoostFactor = PlayerAdvantageComponent->SpeedBoostFactor;
            }
        }
    }

	// Process all queues.
	for (int32 QueueIndex = 0; QueueIndex < QueueCount; ++QueueIndex)
	{
		if (ProductionQueues[QueueIndex].Num() <= 0)
		{
			continue;
		}

		// Check production costs.
		auto ProductClass = GetCurrentProduction(QueueIndex);
		auto ProductionCostComponent = UTD2020Utilities::FindDefaultComponentByClass<UTD2020ProductionCostComponent>(ProductClass);

		bool bProductionCostPaid = false;

		if (ProductionCostComponent && ProductionCostComponent->ProductionCostType == ETD2020ProductionCostType::COST_PayOverTime)
		{
			auto Owner = GetOwner()->GetOwner();

			if (!Owner)
			{
				UE_LOG(LogTD2020, Error, TEXT("%s needs to pay for production, but has no owner."), *GetOwner()->GetName());
				continue;
			}

            auto PlayerResourcesComponent = Owner->FindComponentByClass<UTD2020PlayerResourcesComponent>();

            if (!PlayerResourcesComponent)
            {
                UE_LOG(LogTD2020, Error, TEXT("%s needs to pay for production, but has no PlayerResourcesComponent."), *Owner->GetName());
                continue;
            }

			bool bCanPayAllProductionCosts = true;

			for (auto& Resource : ProductionCostComponent->Resources)
			{
				float ResourceAmount = Resource.Value * SpeedBoostFactor * DeltaTime / ProductionCostComponent->ProductionTime;

				if (!PlayerResourcesComponent->CanPayResources(Resource.Key, ResourceAmount))
				{
					// Production stopped until resources become available again.
					bCanPayAllProductionCosts = false;
					break;
				}
			}

			if (bCanPayAllProductionCosts)
			{
				// Pay production costs.
				for (auto& Resource : ProductionCostComponent->Resources)
				{
					float ResourceAmount = Resource.Value * SpeedBoostFactor * DeltaTime / ProductionCostComponent->ProductionTime;
                    PlayerResourcesComponent->PayResources(Resource.Key, ResourceAmount);
				}

				bProductionCostPaid = true;
			}
		}
		else
		{
			bProductionCostPaid = true;
		}

		if (!bProductionCostPaid)
		{
			continue;
		}

		// Update production progress.
		ProductionQueues[QueueIndex].RemainingProductionTime -= SpeedBoostFactor * DeltaTime;

		// Check if finished.
		if (ProductionQueues[QueueIndex].RemainingProductionTime <= 0)
		{
			FinishProduction(QueueIndex);
		}
	}
}

bool UTD2020ProductionComponent::CanAssignProduction(TSubclassOf<AActor> ProductClass) const
{
	return UTD2020Utilities::IsReadyToUse(GetOwner()) && FindQueueForProduct(ProductClass) >= 0;
}

int32 UTD2020ProductionComponent::FindQueueForProduct(TSubclassOf<AActor> ProductClass) const
{
	// Find queue with least products that is not at capacity limit.
	int32 QueueWithLeastProducts = -1;
	int32 ProductsInShortestQueue = CapacityPerQueue;

	for (int32 QueueIndex = 0; QueueIndex < QueueCount; ++QueueIndex)
	{
		const FTD2020ProductionQueue& Queue = ProductionQueues[QueueIndex];

		if (Queue.Num() < ProductsInShortestQueue)
		{
			QueueWithLeastProducts = QueueIndex;
			ProductsInShortestQueue = Queue.Num();
		}
	}

	return QueueWithLeastProducts;
}

TSubclassOf<AActor> UTD2020ProductionComponent::GetCurrentProduction(int32 QueueIndex /*= 0*/) const
{
	if (QueueIndex < 0 || QueueIndex >= QueueCount)
	{
		return nullptr;
	}

	const FTD2020ProductionQueue& Queue = ProductionQueues[QueueIndex];

	return Queue.Num() > 0 ? Queue[0] : nullptr;
}

float UTD2020ProductionComponent::GetProductionTime(int32 QueueIndex /*= 0*/) const
{
	TSubclassOf<AActor> CurrentProduction = GetCurrentProduction(QueueIndex);

	if (!CurrentProduction)
	{
		return 0.0f;
	}

	return GetProductionTimeForProduct(CurrentProduction);
}

float UTD2020ProductionComponent::GetProductionTimeForProduct(TSubclassOf<AActor> ProductClass) const
{
	UTD2020ProductionCostComponent* ProductionCostComponent =
		UTD2020Utilities::FindDefaultComponentByClass<UTD2020ProductionCostComponent>(ProductClass);
	return ProductionCostComponent ? ProductionCostComponent->ProductionTime : 0.0f;
}

float UTD2020ProductionComponent::GetProgressPercentage(int32 QueueIndex /*= 0*/) const
{
	float TotalProductionTime = GetProductionTime(QueueIndex);

	if (TotalProductionTime <= 0.0f)
	{
		return 1.0f;
	}

	float RemainingProductionTime = GetRemainingProductionTime(QueueIndex);

	if (RemainingProductionTime <= 0.0f)
	{
		return 1.0f;
	}

	return 1 - (RemainingProductionTime / TotalProductionTime);
}

float UTD2020ProductionComponent::GetRemainingProductionTime(int32 QueueIndex /*= 0*/) const
{
	if (QueueIndex < 0 || QueueIndex >= QueueCount)
	{
		return 0.0f;
	}

	return ProductionQueues[QueueIndex].RemainingProductionTime;
}

bool UTD2020ProductionComponent::IsProducing() const
{
	for (int32 QueueIndex = 0; QueueIndex < QueueCount; ++QueueIndex)
	{
		const FTD2020ProductionQueue& Queue = ProductionQueues[QueueIndex];

		if (Queue.Num() > 0)
		{
			return true;
		}
	}
	
	return false;
}

void UTD2020ProductionComponent::StartProduction(TSubclassOf<AActor> ProductClass)
{
	// Check production state.
	if (!CanAssignProduction(ProductClass))
	{
		return;
	}

	int32 QueueIndex = FindQueueForProduct(ProductClass);

	if (QueueIndex < 0)
	{
		return;
	}

    // Check requirements.
    TSubclassOf<AActor> MissingRequirement;

    if (UTD2020Utilities::GetMissingRequirementFor(this, GetOwner(), ProductClass, MissingRequirement))
    {
        UE_LOG(LogTD2020, Error, TEXT("%s wants to produce %s, but is missing requirement %s."), *GetOwner()->GetName(), *ProductClass->GetName(), *MissingRequirement->GetName());
        return;
    }

	// Check production cost.
	UTD2020ProductionCostComponent* ProductionCostComponent =
		UTD2020Utilities::FindDefaultComponentByClass<UTD2020ProductionCostComponent>(ProductClass);

	if (ProductionCostComponent && ProductionCostComponent->ProductionCostType == ETD2020ProductionCostType::COST_PayImmediately)
	{
		auto Owner = GetOwner()->GetOwner();

		if (!Owner)
		{
			UE_LOG(LogTD2020, Error, TEXT("%s needs to pay for production, but has no owner."), *GetOwner()->GetName());
			return;
		}

        auto PlayerResourcesComponent = Owner->FindComponentByClass<UTD2020PlayerResourcesComponent>();

        if (!PlayerResourcesComponent)
        {
            UE_LOG(LogTD2020, Error, TEXT("%s needs to pay for production, but has no PlayerResourcesComponent."), *Owner->GetName());
            return;
        }

		if (!PlayerResourcesComponent->CanPayAllResources(ProductionCostComponent->Resources))
		{
			UE_LOG(LogTD2020, Error, TEXT("%s needs to pay for producing %s, but does not have enough resources."),
				*Owner->GetName(),
				*ProductClass->GetName());
			return;
		}

		// Pay production costs.
        PlayerResourcesComponent->PayAllResources(ProductionCostComponent->Resources);
	}
	
	// Insert into queue.
	FTD2020ProductionQueue& Queue = ProductionQueues[QueueIndex];
	Queue.Add(ProductClass);

	UE_LOG(LogTD2020, Log, TEXT("%s queued %s for production in queue %i."), *GetOwner()->GetName(), *ProductClass->GetName(), QueueIndex);

	// Notify listeners.
	OnProductQueued.Broadcast(ProductClass, QueueIndex);

	if (Queue.Num() == 1)
	{
		// Start production.
		StartProductionInQueue(QueueIndex);
	}
}

void UTD2020ProductionComponent::FinishProduction(int32 QueueIndex /*= 0*/)
{
	if (QueueIndex < 0 || QueueIndex >= QueueCount)
	{
		return;
	}

	FTD2020ProductionQueue& Queue = ProductionQueues[QueueIndex];
	Queue.RemainingProductionTime = 0.0f;

	// Get game.
	ATD2020GameMode* GameMode = Cast<ATD2020GameMode>(UGameplayStatics::GetGameMode(this));

	if (!GameMode)
	{
		return;
	}

    TSubclassOf<AActor> ProductClass = Queue[0];

    // Determine spawn location: Start at producing actor location.
    FVector SpawnLocation = GetOwner()->GetActorLocation();

    // Spawn next to production actor.
    float SpawnOffset = 0.0f;
    SpawnOffset += UTD2020Utilities::GetActorCollisionSize(GetOwner()) / 2;
    SpawnOffset += UTD2020Utilities::GetCollisionSize(ProductClass) / 2;
    SpawnOffset *= 1.05f;
    SpawnLocation.X -= SpawnOffset;

    // Calculate location on the ground.
    SpawnLocation = UTD2020Utilities::GetGroundLocation(this, SpawnLocation);

    // Prevent spawn collision or spawning at wrong side of the world.
    SpawnLocation.Z += UTD2020Utilities::GetCollisionHeight(ProductClass) * 1.1f;

	// Spawn product.
	AActor* Product = GameMode->SpawnActorForPlayer(
		ProductClass,
		Cast<AController>(GetOwner()->GetOwner()),
		FTransform(FRotator::ZeroRotator, SpawnLocation));

	if (!Product)
	{
		return;
	}

	UE_LOG(LogTD2020, Log, TEXT("%s finished producing %s in queue %i."), *GetOwner()->GetName(), *Product->GetName(), QueueIndex);

	// Notify listeners.
	OnProductionFinished.Broadcast(Product, QueueIndex);

	// Remove product from queue.
	DequeueProduct(QueueIndex);
}

void UTD2020ProductionComponent::CancelProduction(int32 QueueIndex /*= 0*/, int32 ProductIndex /*= 0*/)
{
	// Get queue.
	if (QueueIndex < 0 || QueueIndex >= QueueCount)
	{
		return;
	}

	FTD2020ProductionQueue& Queue = ProductionQueues[QueueIndex];

	// Get product.
	if (ProductIndex < 0 || ProductIndex >= Queue.Num())
	{
		return;
	}

	TSubclassOf<AActor> ProductClass = Queue[ProductIndex];

	// Get elapsed production time.
	float TotalProductionTime = GetProductionTimeForProduct(ProductClass);
	float RemainingProductionTime = ProductIndex == 0 ? ProductionQueues[QueueIndex].RemainingProductionTime : TotalProductionTime;
	float ElapsedProductionTime = TotalProductionTime - RemainingProductionTime;

	UE_LOG(LogTD2020, Log, TEXT("%s canceled producing product %i of class %s in queue %i after %f seconds."),
		*GetOwner()->GetName(),
		ProductIndex,
		*ProductClass->GetName(),
		QueueIndex,
		ElapsedProductionTime);

	// Notify listeners.
	OnProductionCanceled.Broadcast(ProductClass, QueueIndex, ElapsedProductionTime);

	// Remove product from queue.
	DequeueProduct(QueueIndex, ProductIndex);

	// Refund resources.
	UTD2020ProductionCostComponent* ProductionCostComponent =
		UTD2020Utilities::FindDefaultComponentByClass<UTD2020ProductionCostComponent>(ProductClass);

	if (ProductionCostComponent)
	{
		auto Owner = GetOwner()->GetOwner();

		if (!Owner)
		{
			return;
		}

        auto PlayerResourcesComponent = Owner->FindComponentByClass<UTD2020PlayerResourcesComponent>();

        if (!PlayerResourcesComponent)
        {
            return;
        }

		float TimeRefundFactor = 0.0f;

		if (ProductionCostComponent->ProductionCostType == ETD2020ProductionCostType::COST_PayImmediately)
		{
			TimeRefundFactor = 1.0f;
		}
		else if (ProductionCostComponent->ProductionCostType == ETD2020ProductionCostType::COST_PayOverTime)
		{
			TimeRefundFactor = ElapsedProductionTime / TotalProductionTime;
		}

		float ActualRefundFactor = ProductionCostComponent->RefundFactor * TimeRefundFactor;

		// Refund production costs.
		for (auto& Resource : ProductionCostComponent->Resources)
		{
			TSubclassOf<UTD2020ResourceType> ResourceType = Resource.Key;
			float ResourceAmount = Resource.Value * ActualRefundFactor;

            PlayerResourcesComponent->AddResources(ResourceType, ResourceAmount);

			UE_LOG(LogTD2020, Log, TEXT("%f %s of production costs refunded."), ResourceAmount, *ResourceType->GetName());

			// Notify listeners.
			OnProductionCostRefunded.Broadcast(ResourceType, ResourceAmount);
		}
	}
}

void UTD2020ProductionComponent::DequeueProduct(int32 QueueIndex /*= 0*/, int32 ProductIndex /*= 0*/)
{
	// Get queue.
	if (QueueIndex < 0 || QueueIndex >= QueueCount)
	{
		return;
	}

	FTD2020ProductionQueue& Queue = ProductionQueues[QueueIndex];

	if (ProductIndex < 0 || ProductIndex >= Queue.Num())
	{
		return;
	}

	Queue.RemoveAt(ProductIndex);
	
	// Check if need to start next production.
	if (ProductIndex == 0 && Queue.Num() > 0)
	{
		StartProductionInQueue(QueueIndex);
	}
}

void UTD2020ProductionComponent::StartProductionInQueue(int32 QueueIndex /*= 0*/)
{
	// Get queue.
	if (QueueIndex < 0 || QueueIndex >= QueueCount)
	{
		return;
	}

	FTD2020ProductionQueue& Queue = ProductionQueues[QueueIndex];

	// Get product.
	if (Queue.Num() <= 0)
	{
		return;
	}

	TSubclassOf<AActor> ProductClass = Queue[0];

	// Start production.
	float ProductionTime = GetProductionTimeForProduct(ProductClass);
	Queue.RemainingProductionTime = ProductionTime;

	UE_LOG(LogTD2020, Log, TEXT("%s started producing %s in queue %i."), *GetOwner()->GetName(), *ProductClass->GetName(), QueueIndex);

	// Notify listeners.
	OnProductionStarted.Broadcast(ProductClass, QueueIndex, ProductionTime);
}
