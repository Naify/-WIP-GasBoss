// Naify

#include "GasBoss/Public/Characters/BaseCharacter.h"
#include "GAS/HeroAbilitySystemComponent.h"
#include "GAS/BaseAttributeSet.h"
#include "Components/SkeletalMeshComponent.h"

ABaseCharacter::ABaseCharacter()
{
    PrimaryActorTick.bCanEverTick = false;
    PrimaryActorTick.bStartWithTickEnabled = false;

    GetMesh()->bReceivesDecals = false;

    HeroAbilitySystemComponent = CreateDefaultSubobject<UHeroAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    HeroAttributeSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("AttributeSet"));
    HeroAbilitySystemComponent->AddSpawnedAttribute(HeroAttributeSet);
}

UAbilitySystemComponent *ABaseCharacter::GetAbilitySystemComponent() const
{
    return GetHeroAbilitySystemComponent();
}

UCombatComponent * ABaseCharacter::GetCombatComponent() const
{
    return nullptr;
}

UUIComponent * ABaseCharacter::GetUIComponent() const
{
    return nullptr;
}

void ABaseCharacter::PossessedBy(AController *NewController)
{
    Super::PossessedBy(NewController);

    if (HeroAbilitySystemComponent)
    {
        HeroAbilitySystemComponent->InitAbilityActorInfo(this, this);

        ensureMsgf(!CharacterStartupData.IsNull(),TEXT("Forgot to assign start up data to %s"),*GetName());
    }
}