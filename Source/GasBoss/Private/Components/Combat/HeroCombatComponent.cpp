// Naify


#include "Components/Combat/HeroCombatComponent.h"
#include "Weapons/HeroWeapon.h"

AHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
    return Cast<AHeroWeapon>(GetWeapon(InWeaponTag));
}