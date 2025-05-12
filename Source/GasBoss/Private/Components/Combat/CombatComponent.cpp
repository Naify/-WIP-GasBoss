// Naify


#include "Components/Combat/CombatComponent.h"

#include "DebugHelper.h"
#include "Components/BoxComponent.h"
#include "Weapons/WeaponBase.h"

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

AWeaponBase *UCombatComponent::GetWeapon(FGameplayTag Tag) const
{
    if (CarriedWeaponsMap.Contains(Tag))
    {
        if (AWeaponBase *const*Weapon = CarriedWeaponsMap.Find(Tag))
        {
            return *Weapon;
        }
    }
    return nullptr;
}

AWeaponBase *UCombatComponent::GetCurrentEquippedWeapon() const
{
    if (!CurrentEquippedWeaponTag.IsValid())
    {
        return nullptr;
    }
    return GetWeapon(CurrentEquippedWeaponTag);
}

void UCombatComponent::ToggleWeaponCollison(bool bEnable, EToggleDamageType DamageType)
{
    if (DamageType == EToggleDamageType::CurrentEquippedWeapon)
    {
        AWeaponBase *Weapon = GetCurrentEquippedWeapon();

        check(Weapon);

        Weapon->GetWeaponCollision()->SetCollisionEnabled(
            bEnable ? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision);
        FString MSG = bEnable ? TEXT("Weapon Collision Enabled") : TEXT("Weapon Collision Disabled");
        Debug::Print(MSG, FColor::Green, 5.f);
    }
    else if (DamageType == EToggleDamageType::LeftHand)
    {

    }
    else if (DamageType == EToggleDamageType::RightHand)
    {

    }
}