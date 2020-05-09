// No copyright - copy as you please

using UnrealBuildTool;

public class TD2020EditorTarget : TargetRules
{
    public TD2020EditorTarget(TargetInfo target) : base(target)
    {
        Type = TargetType.Editor;

        ExtraModuleNames.AddRange(new string[] {"TD2020"});
    }
}