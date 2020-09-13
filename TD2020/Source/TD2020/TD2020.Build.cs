// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
using UnrealBuildTool;

public class TD2020 : ModuleRules
{
	public TD2020(ReadOnlyTargetRules Target) : base(Target)
	{
        
        MinFilesUsingPrecompiledHeaderOverride = 1;
        bFasterWithoutUnity = true;
        
        PublicDependencyModuleNames.AddRange(
            new string[] { 
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "RHI",
                "UMG", "Slate", "SlateCore", "RealTimeStrategy", // "UnrealEnginePython", "TensorFlow", "SocketIOClient",
                "RenderCore", "ShaderCore","Landscape"
            }
        );
        
        PublicDependencyModuleNames.AddRange(new string[] { 
            "OnlineSubsystem",
            "OnlineSubsystemUtils"
        });
        
        DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
	}
}
