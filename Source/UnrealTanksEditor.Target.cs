// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UnrealTanksEditorTarget : TargetRules
{
	public UnrealTanksEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("UnrealTanks");
	}

}
