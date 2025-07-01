// Naify

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Animation/AnimInstance.h"
#include "BaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GASBOSS_API UBaseAnimInstance : public UAnimInstance
{
    GENERATED_BODY()

protected:
    UFUNCTION(BlueprintPure, meta=(BlueprintThreadSafe))
    bool DoesOwnerHaveTag(FGameplayTag Tag) const;
};