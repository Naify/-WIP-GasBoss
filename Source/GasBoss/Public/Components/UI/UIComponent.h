// Naify

#pragma once

#include "CoreMinimal.h"
#include "Components/ExtensionComponentBase.h"
#include "UIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPercentChangedDelegate, float, NewPercent);
/**
 * 
 */
UCLASS()
class GASBOSS_API UUIComponent : public UExtensionComponentBase
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category = "UI")
    FOnPercentChangedDelegate OnHealthPercentChanged;
};