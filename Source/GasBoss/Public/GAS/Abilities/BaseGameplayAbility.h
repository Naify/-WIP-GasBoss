// Naify

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BaseGameplayAbility.generated.h"

class UHeroAbilitySystemComponent;
class UCombatComponent;

UENUM(BlueprintType)
enum class EHeroAbilityActivationPolicy : uint8
{
    OnTriggered,
    OnGiven
};

/**
 * 
 */
UCLASS()
class GASBOSS_API UBaseGameplayAbility : public UGameplayAbility
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, Category="HeroAbility")
    EHeroAbilityActivationPolicy ActivationPolicy = EHeroAbilityActivationPolicy::OnTriggered;

    virtual void OnGiveAbility(const FGameplayAbilityActorInfo *ActorInfo, const FGameplayAbilitySpec &Spec) override;
    virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo *ActorInfo,
                            const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility,
                            bool bWasCancelled) override;

    UFUNCTION(BlueprintPure, Category = "HeroAbility")
    UCombatComponent *GetCombatComponent() const;

    UFUNCTION(BlueprintPure, Category = "HeroAbility")
    UHeroAbilitySystemComponent* GetHeroAbilitySystemComponent() const;
};