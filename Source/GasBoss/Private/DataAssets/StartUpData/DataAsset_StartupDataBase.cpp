// Naify


#include "DataAssets/StartUpData/DataAsset_StartupDataBase.h"

#include "GAS/HeroAbilitySystemComponent.h"
#include "GAS/Abilities/BaseGameplayAbility.h"

void UDataAsset_StartupDataBase::GiveToAbilitySystemComponent(UHeroAbilitySystemComponent *AbilitySystemComponent) const
{
    check(AbilitySystemComponent);

    GrantAbilities(AbilitySystemComponent, StartupAbilities);
    GrantAbilities(AbilitySystemComponent, ReactiveAbilities);
}

void UDataAsset_StartupDataBase::GrantAbilities(UHeroAbilitySystemComponent *AbilitySystemComponent,
    const TArray<TSubclassOf<UBaseGameplayAbility>> &Abilities) const
{
    if (Abilities.Num() == 0)
    {
        return;
    }

    for (const auto& Ability : Abilities)
    {
        if (Ability)
        {
            FGameplayAbilitySpec AbilitySpec(Ability);
            AbilitySpec.SourceObject = AbilitySystemComponent->GetAvatarActor();
            AbilitySpec.Level = 1;
            AbilitySystemComponent->GiveAbility(AbilitySpec);
        }
    }
}