#pragma once
#include "CoreMinimal.h"
#include "CustomShortcutObject.h"
#include "UObject/NoExportTypes.h"
#include "CustomShortcutsProjectSettings.generated.h"

UCLASS(config = CustomShortcuts, DefaultConfig)
class CUSTOMSHORTCUTS_API UCustomShortcutsProjectSettings : public UObject
{
	GENERATED_BODY()

public:
	UCustomShortcutsProjectSettings(const FObjectInitializer& obj) {}

	UPROPERTY(Config, EditAnywhere)
	TArray<TSubclassOf<UCustomShortcutObject>> CustomShortcuts;

	UFUNCTION(CallInEditor)
	void RefreshShortcuts();
};
