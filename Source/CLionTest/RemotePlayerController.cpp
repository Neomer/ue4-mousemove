// Fill out your copyright notice in the Description page of Project Settings.


#include "RemotePlayerController.h"
#include "Engine/World.h"

ARemotePlayerController::ARemotePlayerController() :
    APlayerController()
{
    bShowMouseCursor = true;
    bEnableClickEvents = true;
    bEnableMouseOverEvents = true;
}

void ARemotePlayerController::SetupInputComponent()
{
	UE_LOG(LogTemp, Warning, TEXT("ARemotePlayerController::SetupInputComponent()"));

	APlayerController::SetupInputComponent();

	check(InputComponent);
	InputComponent->BindAction("MouseLeftClicked", IE_Pressed, this, &ARemotePlayerController::MouseLeftClicked);
}

void ARemotePlayerController::locationClickedCallback(std::function<void(const FVector&)> callback)
{
	_locationClickedCallback = callback;
}

void ARemotePlayerController::MouseLeftClicked() {
    UE_LOG(LogTemp, Warning, TEXT("Left mouse button clicked."));

	FHitResult result;
	GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true, result);

	UE_LOG(LogTemp, Warning, TEXT("Clicked on: %s"), *AActor::GetDebugName(result.Actor.Get()));
	GetWorld()->SpawnActor<AActor>(LandSpotActor, result.ImpactPoint, FRotator::ZeroRotator);

	_locationClickedCallback(result.ImpactPoint);
}
