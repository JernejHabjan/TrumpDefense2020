#include "TD2020.h"
#include "TD2020FloatingCombatTextData.h"
#include "TD2020FloatingCombatTextComponent.h"


UTD2020FloatingCombatTextComponent::UTD2020FloatingCombatTextComponent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTD2020FloatingCombatTextComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    for (int32 Index = Texts.Num() - 1; Index >= 0; --Index)
    {
        FTD2020FloatingCombatTextData& TextData = Texts[Index];
        TextData.RemainingLifetime -= DeltaTime;

        if (TextData.RemainingLifetime <= 0.0f)
        {
            Texts.RemoveAt(Index);
        }
    }
}

void UTD2020FloatingCombatTextComponent::AddText(const FString& Text, const FLinearColor& Color, float Scale, float Lifetime)
{
    FTD2020FloatingCombatTextData TextData;
    TextData.Text = Text;
    TextData.Color = Color;
    TextData.Scale = Scale;
    TextData.Lifetime = Lifetime;
    TextData.RemainingLifetime = Lifetime;

    Texts.Add(TextData);
}
