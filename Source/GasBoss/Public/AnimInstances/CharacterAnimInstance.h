// Naify

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/BaseAnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class ABaseCharacter;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class GASBOSS_API UCharacterAnimInstance : public UBaseAnimInstance
{
    GENERATED_BODY()

protected:
    UPROPERTY()
    ABaseCharacter *OwningCharacter;

    UPROPERTY()
    UCharacterMovementComponent *OwningMovementComponent;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anims")
    float Speed;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anims")
    bool bHasAcceleration;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Anims")
    float LocomotionDirection;
    
public:
    virtual void NativeInitializeAnimation() override;
    virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
};