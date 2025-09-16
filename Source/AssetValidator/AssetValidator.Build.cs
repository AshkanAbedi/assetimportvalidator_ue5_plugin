using UnrealBuildTool;
public class AssetValidator : ModuleRules
{
	public AssetValidator(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		// Core dependencies
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });

		// Editor-specific dependencies
		if (Target.bBuildEditor)
		{
			PublicDependencyModuleNames.AddRange(new string[] 
			{ 
				"UnrealEd",          // For editor utilities
				"DataValidation",    // For UEditorValidatorBase
				"Slate",             // For notifications
				"SlateCore",         // Core Slate features
				"EditorStyle"        // For styles like success/error icons
			});
		}
	}
}