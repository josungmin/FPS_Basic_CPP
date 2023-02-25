#include "CWeapon.h"
#include "Global.h"
#include "CPlayer.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimMontage.h"

ACWeapon* ACWeapon::Spawn(UWorld* InWorld, ACharacter* InOwner)
{
	FActorSpawnParameters params;
	params.Owner = InOwner;

	return InWorld->SpawnActor<ACWeapon>(params);
}

ACWeapon::ACWeapon()
{
	PrimaryActorTick.bCanEverTick = true;
	CHelpers::CreateComponent<USkeletalMeshComponent>(this, &Mesh, "Mesh");

	USkeletalMesh* mesh;
	CHelpers::FindAsset<USkeletalMesh>(&mesh, "SkeletalMesh'/Game/Weapon/AR4/Meshes/SK_AR4.SK_AR4'");
	Mesh->SetSkeletalMesh(mesh);

	CHelpers::FindAsset<UAnimMontage>(&EquipAndUnequipMontage, "AnimMontage'/Game/Player/Montages/Aemed_Grab_And_Ungrab_Montage.Aemed_Grab_And_Ungrab_Montage'");
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

void ACWeapon::Equip()
{
	if (bEquipped == true) return;
	if (bEquipping == true)return;

	bEquipping = true;

	OwnerCharacter->PlayAnimMontage(EquipAndUnequipMontage, 1.0f, "Equip");
}

// Use EquipWeapon Animation Notify State
void ACWeapon::PreEquip()
{
	bEquipped = true;

	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HandSocket);
}

// Use EquipWeapon Animation Notify State
void ACWeapon::PostEquip()
{
	bEquipping = false;
}

void ACWeapon::Unequip()
{
	if (bEquipped == false) return;
	if (bEquipping == true)return;

	bEquipping = true;

	OwnerCharacter->PlayAnimMontage(EquipAndUnequipMontage, 1.0f, "Unequip");
}

// Use UnequipWeapon Animation Notify State
void ACWeapon::PreUnequip()
{
	bEquipped = false;

	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);
}

// Use UnequipWeapon Animation Notify State
void ACWeapon::PostUnequip()
{
	bEquipping = false;
}

void ACWeapon::OnAim()
{
	bAimed = true;
}

void ACWeapon::OffAim()
{
	bAimed = false;
}
