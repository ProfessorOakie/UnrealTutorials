// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn.h"


// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this pawn to be controlled by the player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	// Create a camera and a visible object
	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	// Attach our camera and visible object to our root component. Offset and rotate the camera.
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(CameraStartingAngle, 0.0f, 0.0f));
	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	OurCamera->SetRelativeRotation(FRotator(CameraStartingAngle, 0.0f, 0.0f));
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Change scale based on growing or not
	{
		float CurrentScale = OurVisibleComponent->GetComponentScale().X;
		if (bGrowing)
			CurrentScale += DeltaTime;
		else
			CurrentScale -= DeltaTime;
		// Make sure scale is within 1 and 2
		CurrentScale = FMath::Clamp(CurrentScale, 1.0f, 2.0f);
		// Set object scale
		OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));
	}

	// Handle movement based on our "MoveX" and "MoveY" axes
	{
		if (!CurrentVelocity.IsZero())
		{
			FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
			SetActorLocation(NewLocation);
		}
	}


}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Respond when "Grow" key is pressed
	InputComponent->BindAction("Grow", IE_Pressed, this, &AMyPawn::StartGrowing);
	InputComponent->BindAction("Grow", IE_Released, this, &AMyPawn::StopGrowing);

	// Respond when we press our movement axis
	InputComponent->BindAxis("MoveX", this, &AMyPawn::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &AMyPawn::Move_YAxis);

}

void AMyPawn::Move_XAxis(float AxisValue) {
	// Move forward or backward at speed
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * MovementSpeed;
}

void AMyPawn::Move_YAxis(float AxisValue) {
	// Move side to side
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * MovementSpeed;
}

void AMyPawn::StartGrowing() {
	bGrowing = true;
}

void AMyPawn::StopGrowing() {
	bGrowing = false;
}