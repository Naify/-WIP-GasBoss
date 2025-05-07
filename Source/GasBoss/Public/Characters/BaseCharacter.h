// Naify

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "BaseCharacter.generated.h"

class UDataAsset_StartupDataBase;
class UHeroAbilitySystemComponent;
class UBaseAttributeSet;

UCLASS()
class GASBOSS_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    ABaseCharacter();

    virtual UAbilitySystemComponent *GetAbilitySystemComponent() const override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
    UHeroAbilitySystemComponent *HeroAbilitySystemComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
    UBaseAttributeSet *HeroAttributeSet;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharData")
    TSoftObjectPtr<UDataAsset_StartupDataBase> CharacterStartupData;

    virtual void PossessedBy(AController *NewController) override;

public:
    FORCEINLINE UHeroAbilitySystemComponent *GetHeroAbilitySystemComponent() const {return HeroAbilitySystemComponent;}

    FORCEINLINE UBaseAttributeSet *GetHeroAttributeSet() const {return HeroAttributeSet;}
};