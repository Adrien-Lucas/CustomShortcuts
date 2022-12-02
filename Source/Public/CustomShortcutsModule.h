#pragma once

#include "Engine.h"
#include "Modules/ModuleInterface.h"
#include "UnrealEd.h"

DECLARE_LOG_CATEGORY_EXTERN(CustomShortcuts, All, All)

class FCustomShortcutsModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static void RegisterShortcuts();
	static void CleanShortcuts();
	static void RefreshShortcuts();
};
