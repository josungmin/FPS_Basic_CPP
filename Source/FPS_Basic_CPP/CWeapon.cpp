#include "CWeapon.h"
#include "GameFramework/Character.h"

ACWeapon* ACWeapon::Spawn(UWorld* InWorld, ACharacter* InOwner)
{
	FActorSpawnParameters params;
	params.Owner = InOwner;

	return InWorld->SpawnActor<ACWeapon>(params);
}

ACWeapon::ACWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACWeapon::Equiped()
{

}

void ACWeapon::PreEquiped()
{
	if (bEquiped == true) return;
	if (bEquiping == true)return;


}

void ACWeapon::PostEquiped()
{

}

void ACWeapon::Unequiped()
{

}

void ACWeapon::PreUnequiped()
{

}

void ACWeapon::PostUnequiped()
{

}