// Naify

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "HeroAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASBOSS_API UHeroAbilitySystemComponent : public UAbilitySystemComponent
{
    GENERATED_BODY()

public:
    void OnAbilityInputPressed(const FGameplayTag& InputTag);
    void OnAbilityInputReleased(const FGameplayTag& InputTag);
};