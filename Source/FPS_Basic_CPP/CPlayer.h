#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlayer.generated.h"

UCLASS()
class FPS_BASIC_CPP_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly)
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleDefaultsOnly)
		class UCameraComponent* Camera;

public:
	ACPlayer();

	FORCEINLINE class ACWeapon* GetWeapon() { return Weapon; }

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void OnMoveFrontAndBack(float Axis);
	void OnMoveLeftAndRight(float Axis);
	void OnHorizontalLook(float Axis);
	void OnVerticalLook(float Axis);

private:
	void OnRunning();
	void OffRunning();

	void OnAim();
	void OffAim();

private:
	void EquipWeapon();
		
private:
	class ACWeapon* Weapon;
};
