// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CLionTestGameMode.h"
#include "CLionTestCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "RemotePlayerController.h"

ACLionTestGameMode::ACLionTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
    PlayerControllerClass = ARemotePlayerController::StaticClass();
}
