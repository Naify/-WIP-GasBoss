// Naify


#include "GAS/Abilities/HeroGameplayAbility.h"

#include "AbilitySystemComponent.h"
#include "GasBossGameplayTags.h"
#include "Characters/HeroCharacter.h"
#include "Components/Combat/HeroCombatComponent.h"
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
    return Cast<UHeroCombatComponent>(GetHeroCharacter()->GetCombatComponent());
}

FGameplayEffectSpecHandle UHeroGameplayAbility::MakeHeroDamageGameplayEffectSpecHandle(
    TSubclassOf<UGameplayEffect> InGameplayEffectClass, float InWeaponDamage, FGameplayTag InCurrentAttackTypeTag,
    int32 InComboCount) const
{
    check(InGameplayEffectClass);

    FGameplayEffectContextHandle ContextHandle =  GetAbilitySystemComponentFromActorInfo()->MakeEffectContext();
    ContextHandle.SetAbility(this);
    ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
    ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());
    
    FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(
        InGameplayEffectClass, GetAbilityLevel(), ContextHandle);

    SpecHandle.Data->SetSetByCallerMagnitude(GasBossGameplayTags::Shared_SetByCaller_Damage, InWeaponDamage);

    if (InCurrentAttackTypeTag.IsValid())
    {
        SpecHandle.Data->SetSetByCallerMagnitude(InCurrentAttackTypeTag, InComboCount);
    }
    
    return SpecHandle;
}