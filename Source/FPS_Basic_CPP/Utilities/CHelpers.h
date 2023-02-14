#pragma once

#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"

class FPS_BASIC_CPP_API CHelpers
{
public:
	template<typename T>
	static void FindAsset(T** OutObject, FString Inpath)
	{
		ConstructorHelpers::FObjectFinder<T> asset(*Inpath);
		verifyf(asset.Succeeded(), TEXT("Find Asset Fail"));

		*OutObject = asset.Object;
	}

	template<typename T>
	static void FindClass(TSubclassOf<T>* OutClass, FString Inpath)
	{
		ConstructorHelpers::FClassFinder<T> asset(*Inpath);
		verifyf(asset.Succeeded(), TEXT("Find Class Fail"));

		*OutClass = asset.Class;
	}

	template<typename T>
	static void CreateComponent(AActor* InActor, T** InComponent, FName InName, USceneComponent* InParent = NULL)
	{
		*InComponent = InActor->CreateDefaultSubobject<T>(InName);

		if (!!InParent)
		{
			(*InComponent)->SetupAttachment(InParent);
			return;
		}

		InActor->SetRootComponent((*InComponent));
	}
};
