// Naify


#include "GAS/HeroAbilitySystemComponent.h"

void UHeroAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag &InputTag)
{
    if (!InputTag.IsValid())
    {
        return;
    }

    for (const FGameplayAbilitySpec &AbilitySpec : GetActivatableAbilities())
    {
        if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag)) continue;

        TryActivateAbility(AbilitySpec.Handle);
    }
}

void UHeroAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag &InputTag)
{
    
}