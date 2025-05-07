// Naify


#include "DataAssets/StartUpData/DataAsset_EnemyData.h"

#include "GameplayAbilitySpec.h"
#include "GAS/HeroAbilitySystemComponent.h"
#include "GAS/Abilities/EnemyGameplayAbility.h"

void UDataAsset_EnemyData::GiveToAbilitySystemComponent(UHeroAbilitySystemComponent *ASC) const
{
    Super::GiveToAbilitySystemComponent(ASC);

    if (EnemyAbilities.IsEmpty())
    {
        return;
    }
    
    for (const TSubclassOf<UEnemyGameplayAbility> &AbilityClass : EnemyAbilities)
    {
        if (AbilityClass)
        {
            FGameplayAbilitySpec AbilitySpec(AbilityClass);
            AbilitySpec.SourceObject = ASC->GetAvatarActor();
            AbilitySpec.Level = 1;

            ASC->GiveAbility(AbilitySpec);
        }
    }
}