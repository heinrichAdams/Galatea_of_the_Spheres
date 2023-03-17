// Fill out your copyright notice in the Description page of Project Settings.
// Created 14/03/2023 by Heinrich Adams

#include "PlayerObject.h"

// Added Includes 14/03/2023
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
// Added Includes 14/03/2023

// Sets default values
APlayerObject::APlayerObject()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// <--- Added 14/03/2023 Edited 15/03/2023 --->
	
	Torque = 50.0f;
	Mass = 1000000.0f;
	IsCube = true;

	// Setting Up Components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	PhysicalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Physical Mesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	PhysicalMesh->SetupAttachment(RootComponent);
	SpringArm->SetupAttachment(PhysicalMesh);
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 800.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->CameraLagSpeed = 3.0f;

	// Auto Posess Pawn
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// <--- Added 14/03/2023 Edited 15/03/2023 --->

}

// Called when the game starts or when spawned
void APlayerObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// <--- Added 14/03/2023 Edited 17/03/2023 --->

// Input
void APlayerObject::ObjectPitch_Implementation(float Axis)
{
}

void APlayerObject::ObjectRoll_Implementation(float Axis)
{
}

void APlayerObject::MousePitch_Implementation(float Axis)
{
}

void APlayerObject::MouseYaw_Implementation(float Axis)
{
}



// End Input

// <--- Added 14/03/2023 Edited 17/03/2023 --->

// Called every frame
void APlayerObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// <--- Added 14/03/2023 --->

	// Set Mass
	

	// <--- Added 14/03/2023 --->

}

// Called to bind functionality to input
void APlayerObject::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// <--- Added 14/03/2023 --->

	// Input Setup
	InputComponent->BindAxis("ObjectPitch", this, &APlayerObject::ObjectPitch);
	InputComponent->BindAxis("ObjectRoll", this, &APlayerObject::ObjectRoll);
	InputComponent->BindAxis("MousePitch", this, &APlayerObject::MousePitch);
	InputComponent->BindAxis("MouseYaw", this, &APlayerObject::MouseYaw);
	

	// <--- Added 14/03/2023 --->
}




