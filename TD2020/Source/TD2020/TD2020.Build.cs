// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TD2020 : ModuleRules
{
    public TD2020(ReadOnlyTargetRules target) : base(target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnforceIWYU = true;
        PublicDependencyModuleNames.AddRange(
            new[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "RHI",
                "UMG", "Slate", "SlateCore",
                "RealTimeStrategy", // "UnrealEnginePython", "TensorFlow", "SocketIOClient",
                "RenderCore", "Landscape"
            }
        );

        PublicDependencyModuleNames.AddRange(new[]
        {
            "OnlineSubsystem",
            "OnlineSubsystemUtils"
        });

        DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
    }
}