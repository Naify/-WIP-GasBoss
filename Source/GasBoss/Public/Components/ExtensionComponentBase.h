// Naify

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Pawn.h"
#include "ExtensionComponentBase.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GASBOSS_API UExtensionComponentBase : public UActorComponent
{
    GENERATED_BODY()

protected:
    template<class T>
    T* GetOwningPawn() const
    {
        static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "T must be convertible to APawn");
        return CastChecked<T>(GetOwner());
    }

    APawn* GetOwningPawn() const
    {
        return GetOwningPawn<APawn>();
    }

    template<class T>
    T* GetOwningController() const
    {
        static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "T must be convertible to AController");
        return Cast<T>(GetOwningPawn<APawn>()->GetController());
        // return GetOwningPawn<APawn>()->GetController<T>();
    }
};