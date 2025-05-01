// Naify


#include "DataAssets/StartUpData/DataAsset_HeroStartupData.h"

#include "GAS/HeroAbilitySystemComponent.h"
#include "GAS/Abilities/BaseGameplayAbility.h"

void UDataAsset_HeroStartupData::GiveToAbilitySystemComponent(UHeroAbilitySystemComponent *AbilitySystemComponent) const
{
    Super::GiveToAbilitySystemComponent(AbilitySystemComponent);

    for (const FHeroAbilitySet &AbilitySet : HeroAbilities)
    {
        if (AbilitySet.IsValid())
        {
            FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityClass);
            AbilitySpec.SourceObject = AbilitySystemComponent->GetAvatarActor();
            AbilitySpec.Level = 1;
            AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
            
            AbilitySystemComponent->GiveAbility(AbilitySpec);
        }
    }
}