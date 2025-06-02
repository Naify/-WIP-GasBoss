// Naify

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "EnemyCharacter.generated.h"

class UEnemyCombatComponent;
class UEnemyUIComponent;
/**
 * 
 */
UCLASS()
class GASBOSS_API AEnemyCharacter : public ABaseCharacter
{
    GENERATED_BODY()

public:
    AEnemyCharacter();

    virtual void BeginPlay() override;

    virtual UCombatComponent *GetCombatComponent() const override;

    FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent;}

    virtual UUIComponent* GetUIComponent() const override;

    virtual UEnemyUIComponent* GetEnemyUIComponent() const override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UEnemyCombatComponent* EnemyCombatComponent;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UEnemyUIComponent* EnemyUIComponent;

    virtual void PossessedBy(AController* NewController) override;

private:
    void InitEnemyData();
};