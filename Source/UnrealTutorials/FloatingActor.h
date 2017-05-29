// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class UNREALTUTORIALS_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AFloatingActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

private:

	float RunningTime;

	UPROPERTY(EditAnywhere)
	float MovementMagnitude;

};
