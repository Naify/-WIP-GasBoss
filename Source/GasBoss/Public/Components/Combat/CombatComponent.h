// Naify

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ExtensionComponentBase.h"
#include "CombatComponent.generated.h"

class AWeaponBase;
/**
 * 
 */
UCLASS()
class GASBOSS_API UCombatComponent : public UExtensionComponentBase
{
	GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Category = "Combat")
    FGameplayTag CurrentEquippedWeaponTag;
    
    UFUNCTION(BlueprintCallable, Category = "Combat")
    void RegisterWeapon(FGameplayTag Tag, AWeaponBase* Weapon, bool bRegisterAsEquipped = false);

    UFUNCTION(BlueprintCallable, Category = "Combat")
    AWeaponBase* GetWeapon(FGameplayTag Tag) const;

    UFUNCTION(BlueprintCallable, Category = "Combat")
    AWeaponBase* GetCurrentEquippedWeapon() const;

private:
    TMap<FGameplayTag, AWeaponBase*> CarriedWeaponsMap;
};
