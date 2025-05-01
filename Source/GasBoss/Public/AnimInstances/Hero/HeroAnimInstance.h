// Naify

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/CharacterAnimInstance.h"
#include "HeroAnimInstance.generated.h"

class AHeroCharacter;
/**
 * 
 */
UCLASS()
class GASBOSS_API UHeroAnimInstance : public UCharacterAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anims")
	AHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anims")
	bool bShouldEnterRelaxedState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Anims")
	float EnterRelaxStateThreshold = 5.0f;

	float IdleElapsedTime = 0.0f;

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
};
