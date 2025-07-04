// Naify

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/PawnCombatInterface.h"
#include "GAS/BaseAttributeSet.h"
#include "Interfaces/UIInterface.h"
#include "BaseCharacter.generated.h"

class UDataAsset_StartupDataBase;
class UHeroAbilitySystemComponent;
class UMotionWarpingComponent;

UCLASS()
class GASBOSS_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface, public IPawnCombatInterface,
                                   public IUIInterface
{
    GENERATED_BODY()

public:
    ABaseCharacter();

    virtual UAbilitySystemComponent *GetAbilitySystemComponent() const override;

    virtual UCombatComponent *GetCombatComponent() const override;

    virtual UUIComponent* GetUIComponent() const override;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
    UHeroAbilitySystemComponent *HeroAbilitySystemComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
    UBaseAttributeSet *HeroAttributeSet;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharData")
    TSoftObjectPtr<UDataAsset_StartupDataBase> CharacterStartupData;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MotionWarping")
    UMotionWarpingComponent* MotionWarpingComponent;

    virtual void PossessedBy(AController *NewController) override;

public:
    FORCEINLINE UHeroAbilitySystemComponent *GetHeroAbilitySystemComponent() const
    {
        return HeroAbilitySystemComponent;
    }

    FORCEINLINE UBaseAttributeSet *GetHeroAttributeSet() const
    {
        return HeroAttributeSet;
    }
};