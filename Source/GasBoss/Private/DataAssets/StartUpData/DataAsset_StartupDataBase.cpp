// Naify


#include "DataAssets/StartUpData/DataAsset_StartupDataBase.h"

#include "GAS/HeroAbilitySystemComponent.h"
#include "GAS/Abilities/BaseGameplayAbility.h"

void UDataAsset_StartupDataBase::GiveToAbilitySystemComponent(UHeroAbilitySystemComponent *AbilitySystemComponent) const
{
    check(AbilitySystemComponent);

    GrantAbilities(AbilitySystemComponent, StartupAbilities);
    GrantAbilities(AbilitySystemComponent, ReactiveAbilities);

    if (!StartGameplayEffects.IsEmpty())
    {
        for (const TSubclassOf<UGameplayEffect>& Effect : StartGameplayEffects)
        {
            if (Effect)
            {
                FGameplayEffectSpecHandle EffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(Effect, 1.f, AbilitySystemComponent->MakeEffectContext());
                
                if (EffectSpecHandle.IsValid())
                {
                    AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
                }

                // UGameplayEffect* EffectCDO = Effect->GetDefaultObject<UGameplayEffect>();
                //
                // AbilitySystemComponent->ApplyGameplayEffectToSelf(
                //     EffectCDO,
                //     1.f,
                //     AbilitySystemComponent->MakeEffectContext()
                // );
            }
        }
    }
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