// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

//[SupportedPlatforms(UnrealPlatformClass.Server)]
public class TD2020ServerTarget : TargetRules
{
    public TD2020ServerTarget(TargetInfo target) : base(target)
    {
        Type = TargetType.Server;
        bUseUnityBuild = false;
        bUsePCHFiles = false;
        ExtraModuleNames.AddRange(new[] {"TD2020"});
        DefaultBuildSettings = BuildSettingsVersion.V2;
    }
}
