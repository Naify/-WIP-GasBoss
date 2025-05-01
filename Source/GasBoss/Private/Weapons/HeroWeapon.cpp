// Naify


#include "Weapons/HeroWeapon.h"

void AHeroWeapon::AssignAbilitiesSpecHandles(const TArray<FGameplayAbilitySpecHandle>& AbilitySpecHandles)
{
    WeaponAbilityHandles = AbilitySpecHandles;
}

void AHeroWeapon::RemoveAbilitySpecHandle(const FGameplayAbilitySpecHandle& AbilitySpecHandle)
{
    WeaponAbilityHandles.Remove(AbilitySpecHandle);
}

const TArray<FGameplayAbilitySpecHandle> & AHeroWeapon::GetWeaponAbilityHandles() const
{
    return WeaponAbilityHandles;
}