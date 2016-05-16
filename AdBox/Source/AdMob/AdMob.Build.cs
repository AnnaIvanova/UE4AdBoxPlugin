// Copyright 2014-1016, 2Scars Games. All Rights Reserved.


using System.IO;

namespace UnrealBuildTool.Rules
{
	public class AdMob : ModuleRules
	{
		public AdMob(TargetInfo Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					"AdMob/Private",
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{					
					// ... add other public dependencies that you statically link with here ...                  
                }
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
                    "Core",
                    "CoreUObject",                   
                    "Engine"                              
					// ... add private dependencies that you statically link with here ...
				}
				);
           
            DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
            if (Target.Platform == UnrealTargetPlatform.Android)
            {
                PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "Launch"
                }
                );

                string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, BuildConfiguration.RelativeEnginePath);
                AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "AdMob_APL.xml")));
            }
        }
	}
}