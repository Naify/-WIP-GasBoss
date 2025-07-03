// Naify


#include "GAS/Abilities/EnemyGameplayAbility.h"

#include "GasBossGameplayTags.h"
#include "Characters/EnemyCharacter.h"
#include "Components/Combat/EnemyCombatComponent.h"

AEnemyCharacter * UEnemyGameplayAbility::GetEnemyCharacter()
{
    if (!CachedEnemyCharacter.IsValid())
    {
        CachedEnemyCharacter = Cast<AEnemyCharacter>(CurrentActorInfo->AvatarActor);
    }
    return CachedEnemyCharacter.IsValid() ? CachedEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent * UEnemyGameplayAbility::GetEnemyCombatComponent()
{
    return Cast<UEnemyCombatComponent>(GetEnemyCharacter()->GetCombatComponent());
}

FGameplayEffectSpecHandle UEnemyGameplayAbility::MakeEnemyEffectSpecHanle(TSubclassOf<UGameplayEffect> EffectClass,
    const FScalableFloat &DamageAmount)
{
    check (EffectClass);

    FGameplayEffectContextHandle ContextHandle =  GetAbilitySystemComponentFromActorInfo()->MakeEffectContext();
    ContextHandle.SetAbility(this);
    ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
    ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());
    
    FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(
        EffectClass, GetAbilityLevel(), ContextHandle);

    SpecHandle.Data->SetSetByCallerMagnitude(GasBossGameplayTags::Shared_SetByCaller_Damage, DamageAmount.GetValueAtLevel(GetAbilityLevel()));

    
    return SpecHandle;
}