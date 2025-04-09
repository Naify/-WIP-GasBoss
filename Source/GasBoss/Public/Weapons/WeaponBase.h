// Naify

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class GASBOSS_API AWeaponBase : public AActor
{
    GENERATED_BODY()

public:
    AWeaponBase();

    FORCEINLINE UBoxComponent* GetWeaponCollision() const { return WeaponCollision; }

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
    UStaticMeshComponent* WeaponMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
    UBoxComponent* WeaponCollision;
};