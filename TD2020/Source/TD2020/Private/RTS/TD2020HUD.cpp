#include "TD2020.h"
#include "TD2020HUD.h"

#include "EngineUtils.h"
#include "Components/CapsuleComponent.h"

#include "TD2020Character.h"
#include "TD2020ConstructionSiteComponent.h"
#include "TD2020FloatingCombatTextComponent.h"
#include "TD2020FloatingCombatTextData.h"
#include "TD2020HealthComponent.h"
#include "TD2020PlayerController.h"
#include "TD2020ProductionComponent.h"


void ATD2020HUD::DrawHUD()
{
	Super::DrawHUD();

    DrawFloatingCombatTexts();
	DrawSelectionFrame();
	DrawHealthBars();
	DrawConstructionProgressBars();
	DrawProductionProgressBars();
	DrawHoveredActorEffect();
}

void ATD2020HUD::NotifyDrawConstructionProgressBar(AActor* Actor, float ConstructionTime, float RemainingConstructionTime, float ProgressPercentage, float SuggestedProgressBarLeft, float SuggestedProgressBarTop, float SuggestedProgressBarWidth, float SuggestedProgressBarHeight)
{
	ReceiveDrawConstructionProgressBar(
		Actor,
		ConstructionTime,
		RemainingConstructionTime,
		ProgressPercentage,
		SuggestedProgressBarLeft,
		SuggestedProgressBarTop,
		SuggestedProgressBarWidth,
		SuggestedProgressBarHeight);
}

void ATD2020HUD::NotifyDrawFloatingCombatText(AActor* Actor, const FString& Text, const FLinearColor& Color, float Scale, float Lifetime, float RemainingLifetime, float LifetimePercentage, float SuggestedTextLeft, float SuggestedTextTop)
{
    ReceiveDrawFloatingCombatText(
        Actor,
        Text,
        Color,
        Scale,
        Lifetime,
        RemainingLifetime,
        LifetimePercentage,
        SuggestedTextLeft,
        SuggestedTextTop);
}

void ATD2020HUD::NotifyDrawHoveredActorEffect(AActor* HoveredActor)
{
	ReceiveDrawHoveredActorEffect(HoveredActor);
}

void ATD2020HUD::NotifyDrawHealthBar(
	AActor* Actor,
	float CurrentHealth,
	float MaximumHealth,
	float HealthPercentage,
	float SuggestedHealthBarLeft,
	float SuggestedHealthBarTop,
	float SuggestedHealthBarWidth,
	float SuggestedHealthBarHeight)
{
	ReceiveDrawHealthBar(
		Actor,
		CurrentHealth,
		MaximumHealth,
		HealthPercentage,
		SuggestedHealthBarLeft,
		SuggestedHealthBarTop,
		SuggestedHealthBarWidth,
		SuggestedHealthBarHeight);
}

void ATD2020HUD::NotifyDrawProductionProgressBar(AActor* Actor, float ProductionTime, float RemainingProductionTime, float ProgressPercentage, float SuggestedProgressBarLeft, float SuggestedProgressBarTop, float SuggestedProgressBarWidth, float SuggestedProgressBarHeight)
{
	ReceiveDrawProductionProgressBar(
		Actor,
		ProductionTime,
		RemainingProductionTime,
		ProgressPercentage,
		SuggestedProgressBarLeft,
		SuggestedProgressBarTop,
		SuggestedProgressBarWidth,
		SuggestedProgressBarHeight);
}

void ATD2020HUD::NotifyDrawSelectionFrame(float ScreenX, float ScreenY, float Width, float Height)
{
	ReceiveDrawSelectionFrame(ScreenX, ScreenY, Width, Height);
}

FVector2D ATD2020HUD::GetActorCenterOnScreen(AActor* Actor) const
{
	FVector ProjectedLocation = Project(Actor->GetActorLocation());
	return FVector2D(ProjectedLocation.X, ProjectedLocation.Y);
}

FVector2D ATD2020HUD::GetActorSizeOnScreen(AActor* Actor) const
{
	// Get actor position projected on HUD.
	UCapsuleComponent* CapsuleComponent = Actor->FindComponentByClass<UCapsuleComponent>();

	if (!CapsuleComponent)
	{
		return FVector2D::ZeroVector;
	}

	FCollisionShape CollisionShape = CapsuleComponent->GetCollisionShape();

	FVector ActorTopPosition = Project(Actor->GetActorLocation() + (Actor->GetActorForwardVector() * CollisionShape.Capsule.HalfHeight));
	FVector ActorBottomPosition = Project(Actor->GetActorLocation() - (Actor->GetActorForwardVector() * CollisionShape.Capsule.HalfHeight));
	FVector ActorLeftPosition = Project(Actor->GetActorLocation() - (Actor->GetActorRightVector() * CollisionShape.Capsule.Radius));
	FVector ActorRightPosition = Project(Actor->GetActorLocation() + (Actor->GetActorRightVector() * CollisionShape.Capsule.Radius));

	float Width = FVector(ActorRightPosition - ActorLeftPosition).Size();
	float Height = FVector(ActorTopPosition - ActorBottomPosition).Size();

	return FVector2D(Width, Height);
}

void ATD2020HUD::DrawSelectionFrame()
{
	// Get selection frame.
	ATD2020PlayerController* PlayerController = Cast<ATD2020PlayerController>(PlayerOwner);

	if (!PlayerController)
	{
		return;
	}

	FIntRect SelectionFrame;

	if (!PlayerController->GetSelectionFrame(SelectionFrame))
	{
		return;
	}

	// Draw selection frame.
	NotifyDrawSelectionFrame(
		SelectionFrame.Min.X,
		SelectionFrame.Min.Y,
		SelectionFrame.Width(),
		SelectionFrame.Height());
}

void ATD2020HUD::DrawFloatingCombatTexts()
{
    if (!bShowFloatingCombatTexts)
    {
        return;
    }

    for (TActorIterator<AActor> ActorIt(GetWorld()); ActorIt; ++ActorIt)
    {
        AActor* Actor = *ActorIt;

        if (!IsValid(Actor))
        {
            return;
        }

        // Check floating combat texts.
        UTD2020FloatingCombatTextComponent* FloatingCombatTextComponent = Actor->FindComponentByClass<UTD2020FloatingCombatTextComponent>();

        if (!FloatingCombatTextComponent)
        {
            continue;
        }

        for (FTD2020FloatingCombatTextData& TextData : FloatingCombatTextComponent->Texts)
        {
            // Calculate lifetime.
            float ElapsedLifetime = TextData.Lifetime - TextData.RemainingLifetime;
            float LifetimePercentage = ElapsedLifetime / TextData.Lifetime;

            // Calculate position.
            FVector2D Center = GetActorCenterOnScreen(Actor);
            FVector2D Size = GetActorSizeOnScreen(Actor);

            // Calculate color.
            FLinearColor TextColor = TextData.Color;

            if (bFadeOutFloatingCombatTexts)
            {
                TextColor.A = 1 - LifetimePercentage;
            }

            // Draw text.
            NotifyDrawFloatingCombatText(
                Actor,
                TextData.Text,
                TextColor,
                TextData.Scale,
                TextData.Lifetime,
                TextData.RemainingLifetime,
                LifetimePercentage,
                Center.X,
                Center.Y - (Size.Y / 2) - (FloatingCombatTextSpeed * ElapsedLifetime));
        }
    }
}

void ATD2020HUD::DrawHealthBars()
{
	ATD2020PlayerController* PlayerController = Cast<ATD2020PlayerController>(PlayerOwner);

	if (!PlayerController)
	{
		return;
	}

	// Check override conditions.
	if (bAlwaysShowHealthBars || (bShowHotkeyHealthBars && PlayerController->IsHealthBarHotkeyPressed()))
	{
		// Draw all health bars.
		for (TActorIterator<AActor> ActorIt(GetWorld()); ActorIt; ++ActorIt)
		{
			AActor* Actor = *ActorIt;
			DrawHealthBar(Actor);
		}

		return;
	}

	// Draw health bar for hovered actor.
	if (bShowHoverHealthBars)
	{
		AActor* HoveredActor = PlayerController->GetHoveredActor();
		DrawHealthBar(HoveredActor);
	}


}

void ATD2020HUD::DrawHealthBar(AActor* Actor)
{
	if (!IsValid(Actor))
	{
		return;
	}

	// Check health.
	UTD2020HealthComponent* HealthComponent = Actor->FindComponentByClass<UTD2020HealthComponent>();

	if (!HealthComponent)
	{
		return;
	}

	const float HealthPercentage = HealthComponent->CurrentHealth / HealthComponent->MaximumHealth;

	// Suggest health bar size.
	float SuggestedHealthBarLeft;
	float SuggestedHealthBarTop;
	float SuggestedHealthBarWidth;
	float SuggestedHealthBarHeight;

	SuggestUnitBarSize(Actor, SuggestedHealthBarLeft, SuggestedHealthBarTop, SuggestedHealthBarWidth, SuggestedHealthBarHeight);

	// Draw health bar.
	NotifyDrawHealthBar(
		Actor,
		HealthComponent->CurrentHealth,
		HealthComponent->MaximumHealth,
		HealthPercentage,
		SuggestedHealthBarLeft,
		SuggestedHealthBarTop,
		SuggestedHealthBarWidth,
		SuggestedHealthBarHeight);
}

void ATD2020HUD::DrawConstructionProgressBars()
{
	ATD2020PlayerController* PlayerController = Cast<ATD2020PlayerController>(PlayerOwner);

	if (!PlayerController)
	{
		return;
	}

	// Check override conditions.
	if (bAlwaysShowConstructionProgressBars || (bShowHotkeyConstructionProgressBars && PlayerController->IsConstructionProgressBarHotkeyPressed()))
	{
		// Draw all progress bars.
		for (TActorIterator<AActor> ActorIt(GetWorld()); ActorIt; ++ActorIt)
		{
			AActor* Actor = *ActorIt;
			DrawConstructionProgressBar(Actor);
		}

		return;
	}

	// Draw progress bar for hovered actor.
	if (bShowHoverConstructionProgressBars)
	{
		AActor* HoveredActor = PlayerController->GetHoveredActor();
		DrawConstructionProgressBar(HoveredActor);
	}


}

void ATD2020HUD::DrawConstructionProgressBar(AActor* Actor)
{
	if (!IsValid(Actor))
	{
		return;
	}

	// Check progress.
	UTD2020ConstructionSiteComponent* ConstructionSiteComponent = Actor->FindComponentByClass<UTD2020ConstructionSiteComponent>();

	if (!ConstructionSiteComponent)
	{
		return;
	}

	if (!ConstructionSiteComponent->IsConstructing())
	{
		return;
	}

	const float ProgressPercentage = ConstructionSiteComponent->GetProgressPercentage();

	// Suggest progress bar size.
	float SuggestedProgressBarLeft;
	float SuggestedProgressBarTop;
	float SuggestedProgressBarWidth;
	float SuggestedProgressBarHeight;
	
	SuggestUnitBarSize(Actor, SuggestedProgressBarLeft, SuggestedProgressBarTop, SuggestedProgressBarWidth, SuggestedProgressBarHeight);

	// Draw progress bar.
	NotifyDrawConstructionProgressBar(
		Actor,
		ConstructionSiteComponent->ConstructionTime,
		ConstructionSiteComponent->RemainingConstructionTime,
		ProgressPercentage,
		SuggestedProgressBarLeft,
		SuggestedProgressBarTop,
		SuggestedProgressBarWidth,
		SuggestedProgressBarHeight);
}

void ATD2020HUD::DrawHoveredActorEffect()
{
	ATD2020PlayerController* PlayerController = Cast<ATD2020PlayerController>(PlayerOwner);

	if (!PlayerController)
	{
		return;
	}

	AActor* HoveredActor = PlayerController->GetHoveredActor();

	if (HoveredActor == nullptr)
	{
		return;
	}

	// Draw hovered actor effect.
	NotifyDrawHoveredActorEffect(HoveredActor);
}

void ATD2020HUD::DrawProductionProgressBars()
{
	ATD2020PlayerController* PlayerController = Cast<ATD2020PlayerController>(PlayerOwner);

	if (!PlayerController)
	{
		return;
	}

	// Check override conditions.
	if (bAlwaysShowProductionProgressBars || (bShowHotkeyProductionProgressBars && PlayerController->IsProductionProgressBarHotkeyPressed()))
	{
		// Draw all progress bars.
		for (TActorIterator<AActor> ActorIt(GetWorld()); ActorIt; ++ActorIt)
		{
			AActor* Actor = *ActorIt;
			DrawProductionProgressBar(Actor);
		}

		return;
	}

	// Draw progress bar for hovered actor.
	if (bShowHoverProductionProgressBars)
	{
		AActor* HoveredActor = PlayerController->GetHoveredActor();
		DrawProductionProgressBar(HoveredActor);
	}


}

void ATD2020HUD::DrawProductionProgressBar(AActor* Actor)
{
	if (!IsValid(Actor))
	{
		return;
	}

	// Check progress.
	UTD2020ProductionComponent* ProductionComponent = Actor->FindComponentByClass<UTD2020ProductionComponent>();

	if (!ProductionComponent)
	{
		return;
	}

	if (!ProductionComponent->IsProducing())
	{
		return;
	}

	const float ProgressPercentage = ProductionComponent->GetProgressPercentage();

	// Suggest progress bar size.
	float SuggestedProgressBarLeft;
	float SuggestedProgressBarTop;
	float SuggestedProgressBarWidth;
	float SuggestedProgressBarHeight;

	SuggestUnitBarSize(Actor, SuggestedProgressBarLeft, SuggestedProgressBarTop, SuggestedProgressBarWidth, SuggestedProgressBarHeight);

	// Draw progress bar.
	NotifyDrawProductionProgressBar(
		Actor,
		ProductionComponent->GetProductionTime(),
		ProductionComponent->GetRemainingProductionTime(),
		ProgressPercentage,
		SuggestedProgressBarLeft,
		SuggestedProgressBarTop,
		SuggestedProgressBarWidth,
		SuggestedProgressBarHeight);
}

void ATD2020HUD::SuggestUnitBarSize(AActor* Actor, float& OutLeft, float& OutTop, float& OutWidth, float& OutHeight) const
{
	FVector2D Center = GetActorCenterOnScreen(Actor);
	FVector2D Size = GetActorSizeOnScreen(Actor);

	OutWidth = Size.X * 2;
	OutHeight = 15.0f;

	OutLeft = Center.X - (OutWidth / 2);
	OutTop = Center.Y - (Size.Y / 2) - (OutHeight * 2);
}
