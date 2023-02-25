#include "CAnimNotifyState_Equip.h"
#include "CPlayer.h"
#include "CWeapon.h"

FString UCAnimNotifyState_Equip::GetNotifyName_Implementation() const
{
	return "Equip";
}

void UCAnimNotifyState_Equip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	
	if (MeshComp == nullptr) return;

	ACPlayer* player = Cast<ACPlayer>(MeshComp->GetOwner());
	if (player == nullptr) return;

	player->GetWeapon()->PreEquip();
}

void UCAnimNotifyState_Equip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	if (MeshComp == nullptr) return;

	ACPlayer* player = Cast<ACPlayer>(MeshComp->GetOwner());
	if (player == nullptr) return;

	player->GetWeapon()->PostEquip();
}
