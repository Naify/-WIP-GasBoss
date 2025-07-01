// Naify


#include "AnimInstances/BaseAnimInstance.h"
#include "GameFramework/Pawn.h"

#include "FunctionLibrary.h"

bool UBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag Tag) const
{
    if (APawn* OwningPawn = TryGetPawnOwner())
    {
        AActor* OwnerActor = Cast<AActor>(OwningPawn);
        return UFunctionLibrary::NativeDoesActorHaveTag(OwnerActor, Tag);
    }
    return false;
}