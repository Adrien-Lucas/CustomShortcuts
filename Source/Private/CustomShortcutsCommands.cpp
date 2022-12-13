#include "CustomShortcutsCommands.h"
#include "FileHelpers.h"
#include "CustomShortcutsProjectSettings.h"

#define LOCTEXT_NAMESPACE "CustomShortcutsCommands"

void CustomShortcutsCommandsImpl::RegisterCommands()
{
	TArray<TSubclassOf<UCustomShortcutObject>> ShortcutsClasses = GetDefault<UCustomShortcutsProjectSettings>()->
		CustomShortcuts;

	for (TSubclassOf<UCustomShortcutObject> CustomShortcutClass : ShortcutsClasses)
	{
		if (!IsValid(CustomShortcutClass))
		{
			continue;
		}

		UCustomShortcutObject* CustomShortcutObject = Cast<UCustomShortcutObject>(
			NewObject<UObject>(GetTransientPackage(), CustomShortcutClass));

		CustomCommands.Add(nullptr);

		FUICommandInfo::MakeCommandInfo(
			this->AsShared(),
			CustomCommands.Last(),
			FName(CustomShortcutObject->Name),
			FText::FromString(CustomShortcutObject->Name),
			FText::FromString(CustomShortcutObject->Description),
			FSlateIcon(),
			EUserInterfaceActionType::Button,
			CustomShortcutObject->DefaultInputChord
		);

		CustomShortcutsClasses.Add(CustomCommands.Last(), CustomShortcutClass);
	}
}

void CustomShortcutsCommands::Register()
{
	CustomShortcutsCommandsImpl::Register();
	UE_LOG(LogTemp, Log, TEXT("Registered Custom Shortcuts Commands"));
}

const CustomShortcutsCommandsImpl& CustomShortcutsCommands::Get()
{
	return CustomShortcutsCommandsImpl::Get();
}

void CustomShortcutsCommands::Unregister()
{
	CustomShortcutsCommandsImpl::Unregister();
	UE_LOG(LogTemp, Log, TEXT("Unregistered Custom Shortcuts Commands"));
}

#undef LOCTEXT_NAMESPACE
