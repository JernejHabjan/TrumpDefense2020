
// No copyright - copy as you please

using UnrealBuildTool;
using System.Collections.Generic;

public class TD2020Target : TargetRules
{
	public TD2020Target(TargetInfo Target) : base(Target)
	{
        Type = TargetType.Game;
        bUsesSteam = true;

		ExtraModuleNames.AddRange( new string[] { "TD2020" } );
	}
}