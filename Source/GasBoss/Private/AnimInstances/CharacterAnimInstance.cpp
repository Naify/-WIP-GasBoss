// Naify


#include "AnimInstances/CharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GasBoss/Public/Characters/BaseCharacter.h"
#include "KismetAnimationLibrary.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
    OwningCharacter = Cast<ABaseCharacter>(TryGetPawnOwner());

    if (OwningCharacter)
    {
        OwningMovementComponent = OwningCharacter->GetCharacterMovement();
    }
}

void UCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
    if (!OwningCharacter || !OwningMovementComponent)
    {
        return;
    }

    Speed = OwningCharacter->GetVelocity().Size2D();

    bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.0f;

    LocomotionDirection = UKismetAnimationLibrary::CalculateDirection(OwningCharacter->GetVelocity(),
                                                                      OwningCharacter->GetActorRotation());
}