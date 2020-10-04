// No copyright - copy as you please

using UnrealBuildTool;

public class TD2020Target : TargetRules
{
    public TD2020Target(TargetInfo target) : base(target)
    {
        Type = TargetType.Game;
        bUsesSteam = true;

        ExtraModuleNames.AddRange(new string[] {"TD2020"});
    }
}
