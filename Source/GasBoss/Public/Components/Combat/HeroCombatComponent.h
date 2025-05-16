// Naify

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/CombatComponent.h"
#include "Weapons/HeroWeapon.h"
#include "HeroCombatComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASBOSS_API UHeroCombatComponent : public UCombatComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Weapons")
    AHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;

    UFUNCTION(BlueprintCallable, Category = "Weapons")
    AHeroWeapon* GetHeroCurrentEquippedWeapon() const;

    UFUNCTION(BlueprintCallable, Category = "Weapons")
    float GetHeroCurrentEquippedWeaponDamage(float Level) const;

    virtual void OnHitTarget(AActor* HitActor);
    virtual void OnEndHitTarget(AActor* HitActor);

};