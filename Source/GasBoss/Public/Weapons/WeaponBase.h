// Naify

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class UBoxComponent;

DECLARE_DELEGATE_OneParam(FOnTargetInteractedDelegate, AActor*);

UCLASS()
class GASBOSS_API AWeaponBase : public AActor
{
    GENERATED_BODY()

public:
    AWeaponBase();

    FOnTargetInteractedDelegate OnWeaponHitTarget;
    FOnTargetInteractedDelegate OnWeaponEndHitTarget;

    FORCEINLINE UBoxComponent *GetWeaponCollision() const
    {
        return WeaponCollision;
    }

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
    UStaticMeshComponent* WeaponMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
    UBoxComponent* WeaponCollision;

    UFUNCTION()
    virtual void OnCollosionBeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor,
                                         UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                         const FHitResult &SweepResult);

    UFUNCTION()
    virtual void OnCollosionEndOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor,
                                       UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);
};