// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Grabs the Camera from the MyCharacter.h file then creates an object with a camera component
	// and gives it the name "Player_Camera"
	Camera = CreateDefaultSubobject<UCameraComponent>( TEXT( "Player_Camera" ) );
	Camera->SetupAttachment(RootComponent); // Creates an attachment and uses to attach to the actor
	Camera->bUsePawnControlRotation = true; // sets PawnControlRotation to true inside the camera component
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	

	// Binds the action "Jump" to a key press (Spacebar) and uses the jump function from the
	// ACharacter class to make the player jump when the key is pressed
	PlayerInputComponent->BindAction( "Jump", IE_Pressed, this, &ACharacter::Jump );

	// bind the action "MoveForward" and "MoveRight" to the associated key press and access the
	// member functions in order to execute that code on the key press
	PlayerInputComponent->BindAxis( "MoveForward", this, &AMyCharacter::MoveForward );
	PlayerInputComponent->BindAxis( "MoveRight", this, &AMyCharacter::MoveRight );

	PlayerInputComponent->BindAxis( "TurnCamera", this, &AMyCharacter::Turn );
	PlayerInputComponent->BindAxis( "LookUp", this, &AMyCharacter::LookUp );

	PlayerInputComponent->BindAxis( "Sprint", this, &AMyCharacter::Sprint );
}

void AMyCharacter::Sprint( float InputValue )
{
	FVector SprintDirection = GetActorForwardVector();
	AddMovementInput( SprintDirection, InputValue );
}

void AMyCharacter::MoveForward( float InputValue )
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput( ForwardDirection, InputValue );
}

void AMyCharacter::MoveRight( float InputValue )
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput( RightDirection, InputValue );
}

void AMyCharacter::Turn( float InputValue )
{
	AddControllerYawInput( InputValue );
}

void AMyCharacter::LookUp( float InputValue )
{
	AddControllerPitchInput( InputValue );
}