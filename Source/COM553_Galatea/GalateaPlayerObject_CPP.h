#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GalateaPlayerObject_CPP.generated.h"

UCLASS()
class COM553_GALATEA_API AGalateaPlayerObject_CPP : public APawn
{
	GENERATED_BODY()



public:
	AGalateaPlayerObject_CPP();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* PhysicalMesh;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

};
