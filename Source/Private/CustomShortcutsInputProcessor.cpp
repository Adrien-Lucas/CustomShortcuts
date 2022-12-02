#include "CustomShortcutsInputProcessor.h"
#include "EditorBuildUtils.h"
#include "CustomShortcutsCommands.h"
#include "CustomShortcutsProjectSettings.h"
#include "Engine.h"

static TSharedPtr<FCustomShortcutsInputProcessor> CustomShortcutsInputProcessorInstance;

void FCustomShortcutsInputProcessor::Create()
{
	CustomShortcutsInputProcessorInstance = MakeShareable(new FCustomShortcutsInputProcessor());
	if (!FEditorBuildUtils::IsBuildCurrentlyRunning() && FSlateApplication::IsInitialized())
	{
		if (FSlateApplication* SlateApplication = &FSlateApplication::Get())
		{
			SlateApplication->RegisterInputPreProcessor(CustomShortcutsInputProcessorInstance);
		}
	}
}

FCustomShortcutsInputProcessor& FCustomShortcutsInputProcessor::Get()
{
	return *CustomShortcutsInputProcessorInstance;
}

void FCustomShortcutsInputProcessor::Cleanup()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().UnregisterInputPreProcessor(CustomShortcutsInputProcessorInstance);
	}

	CustomShortcutsInputProcessorInstance.Reset();
}

bool FCustomShortcutsInputProcessor::HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
	if (SlateApp.IsInitialized())
	{
		if (CustomShortcutsCommands->ProcessCommandBindings(
			InKeyEvent.GetKey(),
			SlateApp.GetModifierKeys(),
			InKeyEvent.IsRepeat()))
		{
			return true;
		}
	}

	return IInputProcessor::HandleKeyDownEvent(SlateApp, InKeyEvent);
}

FCustomShortcutsInputProcessor::FCustomShortcutsInputProcessor()
{
	CustomShortcutsCommands = MakeShareable(new FUICommandList());

	if (!CustomShortcutsCommandsImpl::IsRegistered())
	{
		return;
	}

	if (CustomShortcutsCommands::Get().CustomCommands.IsEmpty())
	{
		return;
	}

	for (int32 i = 0; i < CustomShortcutsCommands::Get().CustomCommands.Num(); i++)
	{
		TSharedPtr<FUICommandInfo> Command = CustomShortcutsCommands::Get().CustomCommands[i];
		
		CustomShortcutsCommands->MapAction(
			Command,
			FExecuteAction::CreateLambda([this, i]
			{
				UCustomShortcutObject* CustomShortcutObject = GetCustomShortcutObjectByCommandID(i);
				if(IsValid(CustomShortcutObject))
					CustomShortcutObject->OnShortcutExecuted();
			}),
			FCanExecuteAction::CreateLambda([this, i]
			{
				UCustomShortcutObject* CustomShortcutObject = GetCustomShortcutObjectByCommandID(i);
				if(IsValid(CustomShortcutObject))
					return CustomShortcutObject->CanExecuteShortcut();
				return false;
			})
		);
	}
}

UCustomShortcutObject* FCustomShortcutsInputProcessor::GetCustomShortcutObjectByCommandID(int32 CommandID) const
{
	const TSharedPtr<FUICommandInfo> Command = CustomShortcutsCommands::Get().CustomCommands[CommandID];

	if(!Command)
		return nullptr;
	
	const TSubclassOf<UCustomShortcutObject> CustomShortcutClass = CustomShortcutsCommands::Get().
		CustomShortcutObjects[Command];

	if(!IsValid((CustomShortcutClass)))
		return nullptr;
	
	UCustomShortcutObject* CustomShortcutObject = Cast<UCustomShortcutObject>(
		NewObject<UObject>(GetTransientPackage(), CustomShortcutClass));

	return CustomShortcutObject;
}
