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


        
        bUseUnity = false;
        
        		PublicIncludePaths.AddRange(
        			new string[]
        			{
        				// ... add public include paths required here ...
        			}
        		);
        
        		PrivateIncludePaths.AddRange(
        			new string[]
        			{
        				// ... add other private include paths required here ...
        			}
        		);
        
        
        		PublicDependencyModuleNames.AddRange(
        			new string[]
        			{
        				"Core",
        				// ... add other public dependencies that you statically link with here ...
        			}
        		);
        
        
        		PrivateDependencyModuleNames.AddRange(
        			new string[]
        			{
        				"CoreUObject",
        				"Engine",
        				"Slate",
        				"SlateCore",
        				// ... add private dependencies that you statically link with here ...
        				"GraphEditor",
        				"Kismet",
        				"KismetWidgets",
        				"InputCore",
        				"BlueprintGraph",
        				"AssetTools",
        				"EditorStyle",
        				"EditorWidgets",
        				"UnrealEd",
        				"Projects",
        				"Json",
        				"JsonUtilities",
        				"EngineSettings",
        				"AssetRegistry",
        			}
        		);
        
        		if (Target.Type == TargetType.Editor)
        		{
        			PrivateDependencyModuleNames.Add("MessageLog");
        		}
        
        		if (Target.bWithLiveCoding)
        		{
        			PrivateIncludePathModuleNames.Add("LiveCoding");
        		}
        
        		if (Target.Version.MajorVersion == 5)
        		{
        			PrivateDependencyModuleNames.Add("ContentBrowserData");
        			PrivateDependencyModuleNames.Add("SubobjectEditor");
        			PrivateDependencyModuleNames.Add("SubobjectDataInterface");
        		}
        
        		DynamicallyLoadedModuleNames.AddRange(
        			new string[]
        			{
        				// ... add any modules that your module loads dynamically here ...
        			}
        		);
    }
}
