// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

//[SupportedPlatforms(UnrealPlatformClass.Server)]
public class TD2020ServerTarget : TargetRules
{
    public TD2020ServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		//BuildEnvironment = TargetBuildEnvironment.Shared;
        //bOutputToEngineBinaries = true;
		ExtraModuleNames.Add("TD2020");
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
