#include "CAnimNotifyState_Unequip.h"
#include "CPlayer.h"
#include "CWeapon.h"

FString UCAnimNotifyState_Unequip::GetNotifyName_Implementation() const
{
	return "Unequip";
}

void UCAnimNotifyState_Unequip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);

	if (MeshComp == nullptr) return;

	ACPlayer* player = Cast<ACPlayer>(MeshComp->GetOwner());
	if (player == nullptr) return;

	player->GetWeapon()->PreUnequip();
}

void UCAnimNotifyState_Unequip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	if (MeshComp == nullptr) return;

	ACPlayer* player = Cast<ACPlayer>(MeshComp->GetOwner());
	if (player == nullptr) return;

	player->GetWeapon()->PostUnequip();
}
