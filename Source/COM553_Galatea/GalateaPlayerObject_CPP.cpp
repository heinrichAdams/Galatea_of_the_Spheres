#include "GalateaPlayerObject_CPP.h"
#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AGalateaPlayerObject_CPP::AGalateaPlayerObject_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	PhysicalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Physical Mesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	PhysicalMesh->SetupAttachment(RootComponent);
	SpringArm->SetupAttachment(PhysicalMesh);
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	SpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 800.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->CameraLagSpeed = 3.0f;



	AutoPossessPlayer = EAutoReceiveInput::Player0;
}


void AGalateaPlayerObject_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}


void AGalateaPlayerObject_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AGalateaPlayerObject_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

