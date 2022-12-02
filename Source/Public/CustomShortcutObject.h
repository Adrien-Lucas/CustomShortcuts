#pragma once

#include "CustomShortcutObject.generated.h"

UCLASS(BlueprintType, Blueprintable, Abstract)
class UCustomShortcutObject : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category="Custom Shortcuts")
	FInputChord DefaultInputChord;

	UPROPERTY(EditAnywhere, Category="Custom Shortcuts")
	FString Name = "Name";

	UPROPERTY(EditAnywhere, Category="Custom Shortcuts")
	FString Description = "Description";

	UFUNCTION(BlueprintImplementableEvent)
	void OnShortcutExecuted();

	UFUNCTION(BlueprintNativeEvent)
	bool CanExecuteShortcut();
	
};
