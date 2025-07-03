// Naify

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/CombatComponent.h"
#include "EnemyCombatComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASBOSS_API UEnemyCombatComponent : public UCombatComponent
{
    GENERATED_BODY()

public:
    virtual void OnHitTarget(AActor *HitActor);
    virtual void OnEndHitTarget(AActor *HitActor);
};