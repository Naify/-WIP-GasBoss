// Naify


#include "Weapons/WeaponBase.h"
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
}