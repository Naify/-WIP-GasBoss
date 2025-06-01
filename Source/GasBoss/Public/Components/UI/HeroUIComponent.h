// Naify

#pragma once

#include "CoreMinimal.h"
#include "Components/UI/UIComponent.h"
#include "HeroUIComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASBOSS_API UHeroUIComponent : public UUIComponent
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
    FOnPercentChangedDelegate OnRagePercentChanged;
};