// Copyright PufStudio 2021-2022. All Rights Reserved.
using UnrealBuildTool;
using System.IO;

public class CustomShortcuts : ModuleRules
{
    public CustomShortcuts(ReadOnlyTargetRules Target) : base(Target)
    {
        DefaultBuildSettings = BuildSettingsVersion.V2;
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core"
			}
            );
        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "InputCore",
                "UnrealEd",
                "Slate",
                "SlateCore",
                "EditorStyle",
                "ToolMenus"
            }
            );
    }
}
