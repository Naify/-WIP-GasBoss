// Naify

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GasBossTypes/GasBossStructTypes.h"
#include "HeroAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASBOSS_API UHeroAbilitySystemComponent : public UAbilitySystemComponent
{
    GENERATED_BODY()

public:
    void OnAbilityInputPressed(const FGameplayTag& InputTag);
    void OnAbilityInputReleased(const FGameplayTag& InputTag);

    UFUNCTION(BlueprintCallable, Category = "Ability", meta = (Level = "1"))
    void GrantHeroWeaponAbilities(const TArray<FHeroAbilitySet>& WeaponAbilities, int32 Level, TArray<FGameplayAbilitySpecHandle>& OutAbilityHandles);

    UFUNCTION(BlueprintCallable, Category = "Ability")
    void RemoveHeroWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& AbilityHandles);

    UFUNCTION(BlueprintCallable, Category = "Ability")
    bool TryActivateAbilityWithTag(FGameplayTag AbilityTag);
};