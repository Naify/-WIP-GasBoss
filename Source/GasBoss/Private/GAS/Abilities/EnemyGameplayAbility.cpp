// Naify


#include "GAS/Abilities/EnemyGameplayAbility.h"

#include "Characters/EnemyCharacter.h"
#include "Components/Combat/EnemyCombatComponent.h"

AEnemyCharacter * UEnemyGameplayAbility::GetEnemyCharacter()
{
    if (!CachedEnemyCharacter.IsValid())
    {
        CachedEnemyCharacter = Cast<AEnemyCharacter>(CurrentActorInfo->AvatarActor);
    }
    return CachedEnemyCharacter.IsValid() ? CachedEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent * UEnemyGameplayAbility::GetEnemyCombatComponent()
{
    return Cast<UEnemyCombatComponent>(GetEnemyCharacter()->GetCombatComponent());
}