// Naify

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/PlayerController.h"
#include "PlayerHeroController.generated.h"

/**
 * 
 */
UCLASS()
class GASBOSS_API APlayerHeroController : public APlayerController, public IGenericTeamAgentInterface
{
    GENERATED_BODY()

public:
    APlayerHeroController();
    
    virtual FGenericTeamId GetGenericTeamId() const override;

private:
    FGenericTeamId PlayerGenericTeamId;
};