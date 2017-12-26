// No copyright - copy as you please

using UnrealBuildTool;
using System.Collections.Generic;

public class TD2020EditorTarget : TargetRules
{
	public TD2020EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "TD2020" } );
	}
}
