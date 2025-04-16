// Naify

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartupDataBase.h"
#include "GameplayTagContainer.h"
#include "DataAsset_HeroStartupData.generated.h"

USTRUCT(BlueprintType)
struct FHeroAbilitySet
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
    FGameplayTag InputTag;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<UBaseGameplayAbility> AbilityClass;

    bool IsValid() const;
};

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