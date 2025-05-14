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

    Weapon->OnWeaponHitTarget.BindUObject(this, &UCombatComponent::OnHitTarget);
    Weapon->OnWeaponEndHitTarget.BindUObject(this, &UCombatComponent::OnEndHitTarget);

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

        if (bEnable)
        {
            Weapon->GetWeaponCollision()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
        }
        else
        {
            Weapon->GetWeaponCollision()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
            OverlapedActors.Empty();
        }
    }
}

void UCombatComponent::OnHitTarget(AActor *HitActor)
{
}

void UCombatComponent::OnEndHitTarget(AActor *HitActor)
{
}