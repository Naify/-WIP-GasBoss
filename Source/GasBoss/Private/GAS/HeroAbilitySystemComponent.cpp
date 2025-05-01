// Naify


#include "GAS/HeroAbilitySystemComponent.h"

#include "GasBossTypes/GasBossStructTypes.h"
#include "GAS/Abilities/BaseGameplayAbility.h"

void UHeroAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag &InputTag)
{
    if (!InputTag.IsValid())
    {
        return;
    }

    for (const FGameplayAbilitySpec &AbilitySpec : GetActivatableAbilities())
    {
        if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
            continue;

        TryActivateAbility(AbilitySpec.Handle);
    }
}

void UHeroAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag &InputTag)
{

}

void UHeroAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FHeroAbilitySet> &WeaponAbilities, int32 Level,
                                                           TArray<FGameplayAbilitySpecHandle> &OutAbilityHandles)
{
    if (WeaponAbilities.IsEmpty())
    {
        return;
    }

    for (const FHeroAbilitySet &AbilitySet : WeaponAbilities)
    {
        if (AbilitySet.IsValid())
        {
            FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityClass);
            AbilitySpec.SourceObject = GetAvatarActor();
            AbilitySpec.Level = Level;
            AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

            OutAbilityHandles.AddUnique(GiveAbility(AbilitySpec));
        }
    }
}

void UHeroAbilitySystemComponent::RemoveHeroWeaponAbilities(TArray<FGameplayAbilitySpecHandle> &AbilityHandles)
{
    if (AbilityHandles.IsEmpty())
    {
        return;
    }

    for (const FGameplayAbilitySpecHandle &AbilityHandle : AbilityHandles)
    {
        ClearAbility(AbilityHandle);
    }

    AbilityHandles.Empty();
}