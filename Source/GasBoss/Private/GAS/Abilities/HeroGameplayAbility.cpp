// Naify


#include "GAS/Abilities/HeroGameplayAbility.h"

#include "Characters/HeroCharacter.h"
#include "Controllers/PlayerHeroController.h"

AHeroCharacter * UHeroGameplayAbility::GetHeroCharacter()
{
    if (!CachedHeroCharacter.IsValid())
    {
        CachedHeroCharacter = Cast<AHeroCharacter>(CurrentActorInfo->AvatarActor);
    }
    return CachedHeroCharacter.IsValid() ? CachedHeroCharacter.Get() : nullptr;
}

APlayerHeroController * UHeroGameplayAbility::GetHeroController()
{
    if (!CachedHeroController.IsValid())
    {
        CachedHeroController = Cast<APlayerHeroController>(CurrentActorInfo->PlayerController);
    }
    return CachedHeroController.IsValid() ? CachedHeroController.Get() : nullptr;
}

UHeroCombatComponent * UHeroGameplayAbility::GetHeroCombatComponent()
{
    return GetHeroCharacter()->GetCombatComponent();
}