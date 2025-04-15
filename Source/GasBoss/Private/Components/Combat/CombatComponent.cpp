// Naify


#include "Components/Combat/CombatComponent.h"

void UCombatComponent::RegisterWeapon(FGameplayTag Tag, AWeaponBase *Weapon, bool bRegisterAsEquipped)
{
    checkf(!CarriedWeaponsMap.Contains(Tag), TEXT("Weapon with this tag already exists! "), *Tag.ToString());
    check(Weapon);

    CarriedWeaponsMap.Emplace(Tag, Weapon);

    if (bRegisterAsEquipped)
    {
        CurrentEquippedWeaponTag = Tag;
    }
}

AWeaponBase* UCombatComponent::GetWeapon(FGameplayTag Tag) const
{
    if (CarriedWeaponsMap.Contains(Tag))
    {
        if (AWeaponBase* const* Weapon = CarriedWeaponsMap.Find(Tag))
        {
            return *Weapon;
        }
    }
    return nullptr;
}

AWeaponBase* UCombatComponent::GetCurrentEquippedWeapon() const
{
    if (!CurrentEquippedWeaponTag.IsValid())
    {
        return nullptr;
    }
    return GetWeapon(CurrentEquippedWeaponTag);
}