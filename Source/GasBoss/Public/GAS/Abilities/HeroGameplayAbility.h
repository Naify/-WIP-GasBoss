// Naify

#pragma once

#include "CoreMinimal.h"
#include "GAS/Abilities/BaseGameplayAbility.h"
#include "HeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class APlayerHeroController;
class AHeroCharacter;
/**
 * 
 */
UCLASS()
class GASBOSS_API UHeroGameplayAbility : public UBaseGameplayAbility
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category = "HeroAbility")
    AHeroCharacter *GetHeroCharacter();

    UFUNCTION(BlueprintPure, Category = "HeroAbility")
    APlayerHeroController *GetHeroController();

    UFUNCTION(BlueprintPure, Category = "HeroAbility")
    UHeroCombatComponent *GetHeroCombatComponent();

    UFUNCTION(BlueprintPure, Category = "HeroAbility")
    FGameplayEffectSpecHandle MakeHeroDamageGameplayEffectSpecHandle(TSubclassOf<UGameplayEffect> InGameplayEffectClass,
                                                             float InWeaponDamage,
                                                             FGameplayTag InCurrentAttackTypeTag,
                                                             int32 InComboCount) const;

private:
    TWeakObjectPtr<AHeroCharacter> CachedHeroCharacter;
    TWeakObjectPtr<APlayerHeroController> CachedHeroController;
};