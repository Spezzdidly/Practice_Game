#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"


UCLASS()
class PRACTICE_GAME_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere) // VisibleAnywhere or (EditAnywhere, BlueprintReadWrite(Only))
	class UCameraComponent* MainCamera;

	// for 3rd person camera----------------------------------------
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;

	void Sprint( float InputValue );
	void MoveForward(float InputValue );
	void MoveRight(float InputValue );

	void Turn( float InputValue );
	void LookUp( float InputValue );
};