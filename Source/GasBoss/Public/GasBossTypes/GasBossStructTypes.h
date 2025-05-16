// Naify

#pragma once

#include "GameplayTagContainer.h"
#include "AnimInstances/Hero/HeroLinkedAnimLayer.h"
#include "ScalableFloat.h"
#include "GasBossStructTypes.generated.h"

class UInputMappingContext;
class UBaseGameplayAbility;

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

USTRUCT(BlueprintType)
struct FGasBossWeaponData
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<UHeroLinkedAnimLayer> WeaponAnimLayersToLink;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(TitleProperty = "InputTag"))
    TArray<FHeroAbilitySet> DefaultWeaponAbilities;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UInputMappingContext* WeaponInputMappingContext;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FScalableFloat  WeaponDamage;
};

