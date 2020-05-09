// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

//[SupportedPlatforms(UnrealPlatformClass.Server)]
public class TD2020ServerTarget : TargetRules
{
    public TD2020ServerTarget(TargetInfo target) : base(target)
    {
        Type = TargetType.Server;
        //BuildEnvironment = TargetBuildEnvironment.Shared;
        //bOutputToEngineBinaries = true;
        ExtraModuleNames.AddRange(new string[] {"TD2020"});
    }

    //
    // TargetRules interface.
    //

    //public override void SetupGlobalEnvironment(
    //    TargetInfo Target,
    //    ref LinkEnvironmentConfiguration OutLinkEnvironmentConfiguration,
    //    ref CPPEnvironmentConfiguration OutCPPEnvironmentConfiguration
    //    )
    //{
    //}
}