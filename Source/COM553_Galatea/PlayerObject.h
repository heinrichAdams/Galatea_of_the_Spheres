// Fill out your copyright notice in the Description page of Project Settings.
// Created 14/03/2023 by Heinrich Adams
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerObject.generated.h"

UCLASS()
class COM553_GALATEA_API APlayerObject : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// <--- Added 14/03/2023 --->

	// Camera and Spring arm for smooth mouse movment
	UPROPERTY(EditAnywhere)
		class USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere)
		class UCameraComponent* Camera;
	

	// Player Object Meshes
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PhysicalMesh;

	// Input variables
	FVector2D MovementInput;
	FVector2D CameraInput;
	UPROPERTY(EditAnywhere)
		float Torque;
	UPROPERTY(EditAnywhere)
		float Mass;

	
	// Input functions
	void ObjectPitch(float Axis);
	void ObjectRoll(float Axis);
	void MousePitch(float Axis);
	void MouseYaw(float Axis);

	// <--- Added 14/03/2023 --->


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
