#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"

UCLASS()
class FPS_BASIC_CPP_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		float Speed;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Animation")
		float Direction;

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	class ACharacter* OwnerCharacter;
};
