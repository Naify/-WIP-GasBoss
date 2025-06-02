// Naify

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UIInterface.generated.h"

class UEnemyUIComponent;
class UHeroUIComponent;
class UUIComponent;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UUIInterface : public UInterface
{
    GENERATED_BODY()
};

/**
 * 
 */
class GASBOSS_API IUIInterface
{
    GENERATED_BODY()

public:
    virtual UUIComponent* GetUIComponent() const = 0;

    virtual UHeroUIComponent* GetHeroUIComponent() const;

    virtual UEnemyUIComponent* GetEnemyUIComponent() const;
};