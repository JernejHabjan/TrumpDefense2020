// No copyright - copy as you please

using UnrealBuildTool;

public class TD2020Target : TargetRules
{
    public TD2020Target(TargetInfo target) : base(target)
    {
        Type = TargetType.Game;
        bUsesSteam = true;
        bUseUnityBuild = false;
        bUsePCHFiles = false;

        ExtraModuleNames.AddRange(new[] {"TD2020"});
        DefaultBuildSettings = BuildSettingsVersion.V2;
    }
}
