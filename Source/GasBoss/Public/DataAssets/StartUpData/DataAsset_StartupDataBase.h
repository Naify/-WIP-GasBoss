// Naify

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartupDataBase.generated.h"

class UHeroAbilitySystemComponent;
class UBaseGameplayAbility;
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
    TArray<TSubclassOf<UBaseGameplayAbility>> StartupAbilities;

    UPROPERTY(EditDefaultsOnly, Category = "StartupData")
    TArray<TSubclassOf<UBaseGameplayAbility>> ReactiveAbilities;

    void GrantAbilities(UHeroAbilitySystemComponent* AbilitySystemComponent, const TArray<TSubclassOf<UBaseGameplayAbility>>& Abilities) const;
};