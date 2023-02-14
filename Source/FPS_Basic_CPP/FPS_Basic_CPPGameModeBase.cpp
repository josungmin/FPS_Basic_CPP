#include "FPS_Basic_CPPGameModeBase.h"
#include "Global.h"

AFPS_Basic_CPPGameModeBase::AFPS_Basic_CPPGameModeBase()
{
	/*
	ConstructorHelpers::FClassFinder<APawn> pawn(TEXT("Blueprint'/Game/BP_CPlayer.BP_CPlayer_C'"));
	if (pawn.Succeeded())
	{
		DefaultPawnClass = pawn.Class;
	}
	*/

	CHelpers::FindClass<APawn>(&DefaultPawnClass, TEXT("Blueprint'/Game/BP_CPlayer.BP_CPlayer_C'"));
}