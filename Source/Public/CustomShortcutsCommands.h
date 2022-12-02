// Copyright 2021 fpwong. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorStyleSet.h"
#include "CustomShortcutObject.h"
#include "Framework/Commands/Commands.h"

/**
 * 
 */
class CustomShortcutsCommandsImpl : public TCommands<CustomShortcutsCommandsImpl>
{
public:
	CustomShortcutsCommandsImpl()
		: TCommands<CustomShortcutsCommandsImpl>(
			TEXT("Custom Shortcuts Commands"),
			NSLOCTEXT("Contexts", "CustomShortcutsCommands", "Custom Shortcuts Commands"),
			NAME_None,
			FEditorStyle::GetStyleSetName())
	{
	}

	virtual ~CustomShortcutsCommandsImpl() override
	{
	}

	virtual void RegisterCommands() override;

	TSharedPtr<FUICommandInfo> CustomSave;

	TArray<TSharedPtr<FUICommandInfo>> CustomCommands;

	TMap<TSharedPtr<FUICommandInfo>, TSubclassOf<UCustomShortcutObject>> CustomShortcutObjects;
};

class CustomShortcutsCommands
{
public:
	static void Register();

	static const CustomShortcutsCommandsImpl& Get();

	static void Unregister();
};
