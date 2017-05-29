// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

UCLASS()
class UNREALTUTORIALS_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// handles forward backward movement
	UFUNCTION()
	void MoveForward(float Value);

	// handles side to side movement
	UFUNCTION()
	void MoveRight(float Value);
	
	// sets the jump flag for starting 
	UFUNCTION()
	void StartJump();

	// clears the jump flag for stopping
	UFUNCTION()
	void StopJump();


	// FPS Camera
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;

	// First Person mesh (arms), visible only to the player in FPS mode
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	USkeletalMeshComponent* FPSMesh;

};
