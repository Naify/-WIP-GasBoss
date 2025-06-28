// Naify


#include "Controllers/PlayerHeroController.h"

APlayerHeroController::APlayerHeroController()
{
    PlayerGenericTeamId = FGenericTeamId(0);
}

FGenericTeamId APlayerHeroController::GetGenericTeamId() const
{
    return PlayerGenericTeamId;
}