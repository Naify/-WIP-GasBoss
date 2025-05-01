// Naify

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpecHandle.h"
#include "Weapons/WeaponBase.h"
#include "GasBossTypes/GasBossStructTypes.h"
#include "GameplayAbilitySpecHandle.h"
#include "HeroWeapon.generated.h"

/**
 * 
 */
UCLASS()
class GASBOSS_API AHeroWeapon : public AWeaponBase
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponData")
    FGasBossWeaponData HeroWeaponData;

    UFUNCTION(BlueprintCallable)
    void AssignAbilitiesSpecHandles(const TArray<FGameplayAbilitySpecHandle>& AbilitySpecHandles);

    UFUNCTION(BlueprintCallable)
    void RemoveAbilitySpecHandle(const FGameplayAbilitySpecHandle &AbilitySpecHandle);

    UFUNCTION(BlueprintPure)
    const TArray<FGameplayAbilitySpecHandle>& GetWeaponAbilityHandles() const;

private:
    TArray<FGameplayAbilitySpecHandle> WeaponAbilityHandles;
};