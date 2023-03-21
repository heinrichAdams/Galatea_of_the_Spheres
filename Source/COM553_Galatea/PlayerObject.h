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

	// <--- Added 14/03/2023 Edited 15/03/2023 --->

	// Camera and Spring arm for smooth mouse movment
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UCameraComponent* Camera;
	

	// Player Object Meshes
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* PhysicalMesh;

	// Input variables
	FVector2D MovementInput;
	FVector2D CameraInput;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Torque;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Mass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsCube;

	// <--- Added 14/03/2023 Edited 15/03/2023 --->


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// <--- Added 14/03/2023 Edited 17/03/2023 --->
	
	

	// Input functions
	UFUNCTION(BlueprintNativeEvent, Category = "Input")
	void ObjectPitch(float Axis);
	UFUNCTION(BlueprintNativeEvent, Category = "Input")
	void ObjectRoll(float Axis);
	UFUNCTION(BlueprintNativeEvent, Category = "Input")
	void MousePitch(float Axis);
	UFUNCTION(BlueprintNativeEvent, Category = "Input")
	void MouseYaw(float Axis);


	// Getters
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetTorque(){ return Torque; }

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetMass() { return Mass; }

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool GetIsCube() { return IsCube; }

	

	// Setters
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetTorque(float _Torque) { this->Torque = _Torque; }
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetMass(float _Mass) { this->Mass = _Mass; }
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetIsCube(bool _IsCube) { this->IsCube = _IsCube; }

	// <--- Added 14/03/2023 Edited 17/03/2023 --->
};