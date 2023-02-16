#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CWeapon.generated.h"

UCLASS()
class FPS_BASIC_CPP_API ACWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ACWeapon();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleDefaultsOnly)
		FName HandSocket = "Hand_Gun";

	UPROPERTY(VisibleDefaultsOnly)
		FName HolsterSocket = "Holster_Rifle_R";


public:
	static ACWeapon* Spawn(class UWorld* InWorld, class ACharacter* InOwner);

	FORCEINLINE bool GetEquiped(){ return bEquiped; }
	FORCEINLINE bool GetEquiping(){ return bEquiping; }

public:
	void PreEquiped();
	void Equiped();
	void PostEquiped();

	void PreUnequiped();
	void Unequiped();
	void PostUnequiped();

private:
	bool bEquiped;
	bool bEquiping;
};
