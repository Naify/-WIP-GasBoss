// Naify

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/CombatComponent.h"
#include "HeroCombatComponent.generated.h"

class AHeroWeapon;
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
};