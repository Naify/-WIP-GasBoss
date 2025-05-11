// Naify

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartupDataBase.generated.h"

class UHeroAbilitySystemComponent;
class UBaseGameplayAbility;
class UGameplayEffect;
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

    UPROPERTY(EditDefaultsOnly, Category = "StartupData")
    TArray<TSubclassOf<UGameplayEffect>> StartGameplayEffects;

    void GrantAbilities(UHeroAbilitySystemComponent* AbilitySystemComponent, const TArray<TSubclassOf<UBaseGameplayAbility>>& Abilities) const;
};