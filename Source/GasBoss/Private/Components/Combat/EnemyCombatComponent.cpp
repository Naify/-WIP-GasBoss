// Naify


#include "Components/Combat/EnemyCombatComponent.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "DebugHelper.h"
#include "GasBossGameplayTags.h"
#include "Abilities/GameplayAbilityTypes.h"

void UEnemyCombatComponent::OnHitTarget(AActor *HitActor)
{
    if (OverlapedActors.Contains(HitActor))
    {
        return;
    }

    OverlapedActors.AddUnique(HitActor);

    //TODO: Block ability check
    bool bIsValidBlock = false;

    FGameplayEventData EventData;
    EventData.Instigator = GetOwningPawn();
    EventData.Target = HitActor;

    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
        GetOwningPawn(),
        GasBossGameplayTags::Shared_Event_MeeleHit,
        EventData
    );
}

void UEnemyCombatComponent::OnEndHitTarget(AActor *HitActor)
{
}