// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSGameMode.h"
#include "Engine.h"

void AFPSGameMode::StartPlay()
{
	Super::StartPlay();

	if (GEngine) {
		//displays a debug message on the screen for 5 seconds
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("This is the FPS Game Mode!"));
	}
}


