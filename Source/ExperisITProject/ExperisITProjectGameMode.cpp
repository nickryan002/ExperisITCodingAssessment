// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExperisITProjectGameMode.h"
#include "ExperisITProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AExperisITProjectGameMode::AExperisITProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
