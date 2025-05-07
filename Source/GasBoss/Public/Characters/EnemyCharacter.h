// Naify

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "EnemyCharacter.generated.h"

class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class GASBOSS_API AEnemyCharacter : public ABaseCharacter
{
    GENERATED_BODY()

public:
    AEnemyCharacter();

    FORCEINLINE UEnemyCombatComponent* GetCombatComponent() const { return EnemyCombatComponent; }

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UEnemyCombatComponent* EnemyCombatComponent;

    virtual void PossessedBy(AController* NewController) override;

private:
    void InitEnemyData();
};