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

	// <--- Added 14/03/2023 --->
	
	Torque = 10000000000.0f;
	Mass = 700.0f;

	// Setting Up Components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	PhysicalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Physical Mesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	PhysicalMesh->SetupAttachment(RootComponent);
	SpringArm->SetupAttachment(PhysicalMesh);
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 1000.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	// Auto Posess Pawn
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// <--- Added 14/03/2023 --->

}

// Called when the game starts or when spawned
void APlayerObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// <--- Added 14/03/2023 --->

// Input
void APlayerObject::ObjectPitch(float Axis)
{
	MovementInput.X = FMath::Clamp<float>(Axis, -1.0f, 1.0f);
}

void APlayerObject::ObjectRoll(float Axis)
{
	MovementInput.Y = FMath::Clamp<float>(Axis, -1.0f, 1.0f);
}

void APlayerObject::MousePitch(float Axis)
{
	CameraInput.Y = Axis;
}

void APlayerObject::MouseYaw(float Axis)
{
	CameraInput.X = Axis;
}
// End Input

// <--- Added 14/03/2023 --->

// Called every frame
void APlayerObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// <--- Added 14/03/2023 --->

	// Set Mass
	

	// Camera Control
	FRotator NewRotation = SpringArm->GetComponentRotation();
	NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + CameraInput.Y, -80.0f,-15.0f);
	NewRotation.Yaw = NewRotation.Yaw + CameraInput.X;
	SpringArm->SetWorldRotation(NewRotation);

	// Movement  Control
	if (!MovementInput.IsZero())
	{
		MovementInput = MovementInput.GetSafeNormal() * Torque;
		PhysicalMesh->AddForce(FVector( ((MovementInput.X)/8 * DeltaTime) , 0.0f, 0.0f) );
		PhysicalMesh->AddTorque(FVector( (MovementInput.X * DeltaTime) , 0.0f, 0.0f ) );
		PhysicalMesh->AddForce(FVector(0.0f, -((MovementInput.Y)/8 * DeltaTime), 0.0f) );
		PhysicalMesh->AddTorque(FVector( 0.0f, -(MovementInput.Y * DeltaTime), 0.0f) );
	}

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

