// Naify

#pragma once

#include "CoreMinimal.h"
#include "GAS/Abilities/BaseGameplayAbility.h"
#include "EnemyGameplayAbility.generated.h"

class AEnemyCharacter;
/**
 * 
 */
UCLASS()
class GASBOSS_API UEnemyGameplayAbility : public UBaseGameplayAbility
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category = "EnemyAbility")
    AEnemyCharacter *GetEnemyCharacter();

    UFUNCTION(BlueprintPure, Category = "EnemyAbility")
    UEnemyCombatComponent *GetEnemyCombatComponent();

    UFUNCTION(BlueprintPure, Category = "EnemyAbility")
    FGameplayEffectSpecHandle MakeEnemyEffectSpecHanle(TSubclassOf<UGameplayEffect> EffectClass,
                                                       const FScalableFloat &DamageAmount);

private:
    TWeakObjectPtr<AEnemyCharacter> CachedEnemyCharacter;
};