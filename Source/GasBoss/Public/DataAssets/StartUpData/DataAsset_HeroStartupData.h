// Naify

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartupDataBase.h"
#include "GasBossTypes/GasBossStructTypes.h"
#include "DataAsset_HeroStartupData.generated.h"

/**
 * 
 */
UCLASS()
class GASBOSS_API UDataAsset_HeroStartupData : public UDataAsset_StartupDataBase
{
    GENERATED_BODY()
    
public:
    virtual void GiveToAbilitySystemComponent(UHeroAbilitySystemComponent* AbilitySystemComponent) const override;
    
private:
    UPROPERTY(EditDefaultsOnly, Category = "StartupData", meta = (TitleProperty = "InputTag"))
    TArray<FHeroAbilitySet> HeroAbilities;
};