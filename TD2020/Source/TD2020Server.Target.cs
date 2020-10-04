// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

//[SupportedPlatforms(UnrealPlatformClass.Server)]
public class TD2020ServerTarget : TargetRules
{
    public TD2020ServerTarget(TargetInfo target) : base(target)
    {
        Type = TargetType.Server;
        ExtraModuleNames.AddRange(new string[] {"TD2020"});
    }
}
