// Naify


#include "Weapons/WeaponBase.h"

#include "DebugHelper.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

AWeaponBase::AWeaponBase()
{
    PrimaryActorTick.bCanEverTick = false;

    WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
    SetRootComponent(WeaponMesh);

    WeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollision"));
    WeaponCollision->SetupAttachment(WeaponMesh);
    WeaponCollision->SetBoxExtent(FVector(20.f));
    WeaponCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    WeaponCollision->OnComponentBeginOverlap.AddUniqueDynamic(this, &AWeaponBase::OnCollosionBeginOverlap);
    WeaponCollision->OnComponentEndOverlap.AddUniqueDynamic(this, &AWeaponBase::OnCollosionEndOverlap);
}

void AWeaponBase::OnCollosionBeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor,
    UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
    APawn* WeaponOwner = GetInstigator<APawn>();
    if (APawn* HittedPawn = Cast<APawn>(OtherActor))
    {
        if (WeaponOwner != HittedPawn)
        {
            OnWeaponHitTarget.ExecuteIfBound(OtherActor);
        }

        // if (UCombatComponent* CombatComponent = UFunctionLibrary::NativeGetCombatComponentFromActor(HittedPawn))
        // {
        //     if (AWeaponBase* Weapon = Cast<AWeaponBase>(OverlappedComponent->GetOwner()))
        //     {
        //         CombatComponent->ToggleWeaponCollison(true);
        //     }
        // }
    }
    else
    {
        return;
    }
}

void AWeaponBase::OnCollosionEndOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor,
    UPrimitiveComponent *OtherComp, int32 OtherBodyIndex)
{
    APawn* WeaponOwner = GetInstigator<APawn>();
    if (APawn* HittedPawn = Cast<APawn>(OtherActor))
    {
        if (WeaponOwner != HittedPawn)
        {
            OnWeaponEndHitTarget.ExecuteIfBound(OtherActor);
        }
    }
}