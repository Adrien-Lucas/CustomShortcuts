#pragma once

#include "CoreMinimal.h"
#include "Framework/Application/IInputProcessor.h"

class UCustomShortcutObject;
class FUICommandList;

class FCustomShortcutsInputProcessor
	: public TSharedFromThis<FCustomShortcutsInputProcessor>
	  , public IInputProcessor
{
public:
	virtual ~FCustomShortcutsInputProcessor() override {}

	static void Create();

	static FCustomShortcutsInputProcessor& Get();

	void Cleanup();

	virtual bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override;

	FCustomShortcutsInputProcessor();

	virtual void Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor) override {}

protected:
	TSharedPtr<FUICommandList> CustomShortcutsCommands;

	UCustomShortcutObject* GetCustomShortcutObjectByCommandID(int32 CommandID) const;
};
