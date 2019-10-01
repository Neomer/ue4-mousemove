// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <functional>
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RemotePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CLIONTEST_API ARemotePlayerController : public APlayerController
{
	GENERATED_BODY()

public:

    ARemotePlayerController();

	void SetupInputComponent() override;

    bool CanRestartPlayer() override { return false; }

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AActor> LandSpotActor;

	void locationClickedCallback(std::function<void(const FVector&)> callback);

private:
    void MouseLeftClicked();
	std::function<void(const FVector&)> _locationClickedCallback;
};
