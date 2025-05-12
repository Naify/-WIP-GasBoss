// Naify


#include "FunctionLibrary.h"
#include "Components/Combat/CombatComponent.h"
#include "Interfaces/PawnCombatInterface.h"

UCombatComponent * UFunctionLibrary::NativeGetCombatComponentFromActor(AActor *Actor)
{
    check(Actor);

    if (IPawnCombatInterface* PawnCombatInterface = Cast<IPawnCombatInterface>(Actor))
    {
        return PawnCombatInterface->GetCombatComponent();
    }

    return nullptr;
}

UCombatComponent * UFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor *Actor, EValidType &OutValidType)
{
    UCombatComponent* CombatComponent = NativeGetCombatComponentFromActor(Actor);

    OutValidType = CombatComponent ? EValidType::Valid : EValidType::Invalid;

    return CombatComponent;
}