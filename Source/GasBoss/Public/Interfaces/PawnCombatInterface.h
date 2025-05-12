// Naify

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnCombatInterface.generated.h"

class UCombatComponent;

UINTERFACE(MinimalAPI)
class UPawnCombatInterface : public UInterface
{
    GENERATED_BODY()
};

/**
 * 
 */
class GASBOSS_API IPawnCombatInterface
{
    GENERATED_BODY()

public:
    virtual UCombatComponent* GetCombatComponent() const = 0;
};