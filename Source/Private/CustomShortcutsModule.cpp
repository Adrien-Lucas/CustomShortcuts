#include "CustomShortcutsModule.h"
#include "CustomShortcutsCommands.h"
#include "CustomShortcutsInputProcessor.h"
#include "CustomShortcutsProjectSettings.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ToolMenus.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"

IMPLEMENT_GAME_MODULE(FCustomShortcutsModule, CustomShortcuts);

DEFINE_LOG_CATEGORY(CustomShortcuts)

#define LOCTEXT_NAMESPACE "CustomShortcuts"

void FCustomShortcutsModule::StartupModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		TSharedPtr<ISettingsSection> CustomShortcutsSettings = SettingsModule->RegisterSettings("Project", "Plugins", "CustomShortcutsSettings",
			LOCTEXT("CustomShortcutsName", "Custom Shortcuts"),
			LOCTEXT("CustomShortcutsDescription", "Custom Shortcuts settings"),
			GetMutableDefault<UCustomShortcutsProjectSettings>());

		CustomShortcutsSettings->OnModified().BindLambda([]{RefreshShortcuts(); return true;});
	}

	RegisterShortcuts();

	FToolMenuOwnerScoped OwnerScoped(this);
	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Tools");
	FToolMenuSection& Section = Menu->AddSection("CustomShortcuts", LOCTEXT("CustomShortcuts", "Custom Shortcuts"));
	
	Section.AddEntry(FToolMenuEntry::InitMenuEntry(
		"CustomShortcuts",
		LOCTEXT("CustomShortcutsRefreshTitle", "Refresh custom shortcuts"),
		LOCTEXT("WorldPartitionConvertTooltip", "Refreshs the custom shortcuts if you added or removed one to CustomShortcuts project settings"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateStatic(&FCustomShortcutsModule::RefreshShortcuts))
	));
}

void FCustomShortcutsModule::ShutdownModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "CustomShortcutsSettings");
	}

	CleanShortcuts();
}

void FCustomShortcutsModule::RegisterShortcuts()
{
	CustomShortcutsCommands::Register();
	FCustomShortcutsInputProcessor::Create();
}

void FCustomShortcutsModule::CleanShortcuts()
{
	FCustomShortcutsInputProcessor::Get().Cleanup();
	CustomShortcutsCommands::Unregister();
}

void FCustomShortcutsModule::RefreshShortcuts()
{
	CleanShortcuts();
	RegisterShortcuts();
}

#undef LOCTEXT_NAMESPACE
