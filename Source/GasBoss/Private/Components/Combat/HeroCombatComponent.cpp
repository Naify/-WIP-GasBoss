// Naify


#include "Components/Combat/HeroCombatComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GAS/BaseAttributeSet.h"
#include "Weapons/HeroWeapon.h"
#include "GasBoss/Public/GasBossGameplayTags.h"

AHeroWeapon *UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
    return Cast<AHeroWeapon>(GetWeapon(InWeaponTag));
}

void UHeroCombatComponent::OnHitTarget(AActor *HitActor)
{
    if (OverlapedActors.Contains(HitActor))
    {
        return;
    }

    OverlapedActors.AddUnique(HitActor);

    FGameplayEventData EventData;
    EventData.Instigator = GetOwningPawn();
    EventData.Target = HitActor;

    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(),
                                                             GasBossGameplayTags::Shared_Event_MeeleHit,
                                                             EventData);
}

void UHeroCombatComponent::OnEndHitTarget(AActor *HitActor)
{

}