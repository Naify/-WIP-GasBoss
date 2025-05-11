// Naify


#include "Characters/EnemyCharacter.h"

#include "AbilitySystemComponent.h"
#include "DebugHelper.h"
#include "Components/Combat/EnemyCombatComponent.h"
#include "DataAssets/StartUpData/DataAsset_EnemyData.h"
#include "Engine/AssetManager.h"
#include "GAS/BaseAttributeSet.h"
#include "GameFramework/CharacterMovementComponent.h"

AEnemyCharacter::AEnemyCharacter()
{
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    GetCharacterMovement()->bUseControllerDesiredRotation = false;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 180.f, 0.f);
    GetCharacterMovement()->MaxWalkSpeed = 300.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

    EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>(TEXT("EnemyCombatComponent"));
}

void AEnemyCharacter::PossessedBy(AController *NewController)
{
    Super::PossessedBy(NewController);

    InitEnemyData();
}

void AEnemyCharacter::InitEnemyData()
{
    if (CharacterStartupData.IsNull())
    {
        return;
    }

    UAssetManager::GetStreamableManager().RequestAsyncLoad(
        CharacterStartupData.ToSoftObjectPath(),
        FStreamableDelegate::CreateLambda(
            [this]()
            {
                if (UDataAsset_StartupDataBase *Data = CharacterStartupData.Get())
                {
                    Data->GiveToAbilitySystemComponent(HeroAbilitySystemComponent);
                    Debug::Print(TEXT("Enemy Data Loaded"), FColor::Green, 5.f);

                    GetAbilitySystemComponent()->PrintDebug();
                    GetAbilitySystemComponent()->PrintAllGameplayEffects();
                }
            }
            )
        );

}