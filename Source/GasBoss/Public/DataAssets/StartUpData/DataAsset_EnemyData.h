// Naify

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartupDataBase.h"
#include "DataAsset_EnemyData.generated.h"

class UEnemyGameplayAbility;
/**
 * 
 */
UCLASS()
class GASBOSS_API UDataAsset_EnemyData : public UDataAsset_StartupDataBase
{
    GENERATED_BODY()

public:
    virtual void GiveToAbilitySystemComponent(UHeroAbilitySystemComponent* ASC) const override;
    
private:
    UPROPERTY(EditDefaultsOnly, Category = "StartupData")
    TArray<TSubclassOf<UEnemyGameplayAbility>> EnemyAbilities;
};