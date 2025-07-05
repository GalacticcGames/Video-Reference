// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEThirdPartyExample : ModuleRules
{
	public UEThirdPartyExample(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		AddEngineThirdPartyPrivateStaticDependencies(Target, "Kiss_FFT");
	}
}
