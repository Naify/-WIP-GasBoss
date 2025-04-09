// Naify

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartupDataBase.generated.h"

class UHeroAbilitySystemComponent;
class UHeroGameplayAbility;
/**
 * 
 */
UCLASS()
class GASBOSS_API UDataAsset_StartupDataBase : public UDataAsset
{
    GENERATED_BODY()

public:
    virtual void GiveToAbilitySystemComponent(UHeroAbilitySystemComponent* AbilitySystemComponent) const;
    
protected:
    UPROPERTY(EditDefaultsOnly, Category = "StartupData")
    TArray<TSubclassOf<UHeroGameplayAbility>> StartupAbilities;

    UPROPERTY(EditDefaultsOnly, Category = "StartupData")
    TArray<TSubclassOf<UHeroGameplayAbility>> ReactiveAbilities;

    void GrantAbilities(UHeroAbilitySystemComponent* AbilitySystemComponent, const TArray<TSubclassOf<UHeroGameplayAbility>>& Abilities) const;
};