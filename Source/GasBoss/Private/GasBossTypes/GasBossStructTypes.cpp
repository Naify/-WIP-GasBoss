// Naify


#include "GasBossTypes/GasBossStructTypes.h"

#include "GAS/Abilities/BaseGameplayAbility.h"


bool FHeroAbilitySet::IsValid() const
{
    return InputTag.IsValid() && AbilityClass != nullptr;
}