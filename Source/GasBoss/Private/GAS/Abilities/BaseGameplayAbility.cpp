// Naify


#include "GAS/Abilities/BaseGameplayAbility.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Components/Combat/CombatComponent.h"
#include "GAS/HeroAbilitySystemComponent.h"

void UBaseGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
    Super::OnGiveAbility(ActorInfo, Spec);

    if (ActivationPolicy == EHeroAbilityActivationPolicy::OnGiven)
    {
        if (ActorInfo && !Spec.IsActive())
        {
            ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle, true);
        }
    }
}

void UBaseGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle,
    const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
    bool bReplicateEndAbility, bool bWasCancelled)
{
    Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

    if (ActivationPolicy == EHeroAbilityActivationPolicy::OnGiven)
    {
        if (ActorInfo)
        {
            ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
        }
    }
}

UCombatComponent * UBaseGameplayAbility::GetCombatComponent() const
{
    return GetAvatarActorFromActorInfo()->FindComponentByClass<UCombatComponent>();
}

UHeroAbilitySystemComponent * UBaseGameplayAbility::GetHeroAbilitySystemComponent() const
{
    return Cast<UHeroAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());
}

FActiveGameplayEffectHandle UBaseGameplayAbility::NativeApplyGameplayEffectToTarget(AActor *TargetActor,
    const FGameplayEffectSpecHandle &EffectSpecHandle)
{
    UAbilitySystemComponent* ASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
    return GetHeroAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data, ASC);
}

FActiveGameplayEffectHandle UBaseGameplayAbility::BPApplyGameplayEffectToTarget(AActor *TargetActor,
    const FGameplayEffectSpecHandle &EffectSpecHandle, ESuccessType &OutSuccessType)
{
    FActiveGameplayEffectHandle ActiveGameplayEffectHandle = NativeApplyGameplayEffectToTarget(TargetActor, EffectSpecHandle);
    OutSuccessType = ActiveGameplayEffectHandle.WasSuccessfullyApplied() ?  ESuccessType::Success :  ESuccessType::Fail;
    return ActiveGameplayEffectHandle;
}
