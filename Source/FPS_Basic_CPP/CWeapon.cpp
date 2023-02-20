#include "CWeapon.h"
#include "Global.h"
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

	//USkeletalMesh* mesh;
	//CHelpers::FindAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Weapon/AR4/Meshes/SK_AR4.SK_AR4'");
	//Mesh->SetSkeletalMesh(mesh);
}

void ACWeapon::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

void ACWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACWeapon::Equiped()
{
	if (bEquipped == true) return;
	if (bEquipping == true)return;

	bEquipping = true;

	OwnerCharacter->PlayAnimMontage(EquipMontage);
}

// Use EquipWeapon Animation Notify State
void ACWeapon::PreEquiped()
{
	bEquipped = true;

	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HandSocket);
}

// Use EquipWeapon Animation Notify State
void ACWeapon::PostEquiped()
{
	bEquipping = false;
}

void ACWeapon::Unequiped()
{
	if (bEquipped == false) return;
	if (bEquipping == true)return;

	bEquipping = true;

	OwnerCharacter->PlayAnimMontage(EquipMontage);
}

// Use UnequipWeapon Animation Notify State
void ACWeapon::PreUnequiped()
{
	bEquipped = false;

	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

// Use UnequipWeapon Animation Notify State
void ACWeapon::PostUnequiped()
{
	bEquipping = true;
}
