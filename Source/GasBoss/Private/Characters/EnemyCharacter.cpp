// Naify


#include "Characters/EnemyCharacter.h"

#include "AbilitySystemComponent.h"
#include "DebugHelper.h"
#include "Components/WidgetComponent.h"
#include "Components/Combat/EnemyCombatComponent.h"
#include "Components/UI/EnemyUIComponent.h"
#include "DataAssets/StartUpData/DataAsset_EnemyData.h"
#include "Engine/AssetManager.h"
#include "GAS/BaseAttributeSet.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Widgets/WidgetBase.h"

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
    EnemyUIComponent = CreateDefaultSubobject<UEnemyUIComponent>(TEXT("EnemyUIComponent"));
    WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
    WidgetComponent->SetupAttachment(GetMesh());
    // GetHeroAbilitySystemComponent()->RegisterComponent(); 
}

void AEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();
    
    if (UWidgetBase* HealthWidget = Cast<UWidgetBase>(WidgetComponent->GetUserWidgetObject()))
    {
        HealthWidget->InitEnemyWidget(this);
    }
}

UCombatComponent * AEnemyCharacter::GetCombatComponent() const
{
    return EnemyCombatComponent;
}

UUIComponent * AEnemyCharacter::GetUIComponent() const
{
    return EnemyUIComponent;
}

UEnemyUIComponent * AEnemyCharacter::GetEnemyUIComponent() const
{
    return EnemyUIComponent;
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

    UDataAsset_StartupDataBase* LoadedData = CharacterStartupData.LoadSynchronous();
    if (LoadedData)
    {
        LoadedData->GiveToAbilitySystemComponent(GetHeroAbilitySystemComponent());
        GetAbilitySystemComponent()->PrintDebug();
        GetAbilitySystemComponent()->PrintAllGameplayEffects();
    }

    // float Health = GetHeroAttributeSet()->GetMaxHealth();
    // Debug::Print(TEXT("MaxHealth"), Health);

    // UAssetManager::GetStreamableManager().RequestAsyncLoad(
    //     CharacterStartupData.ToSoftObjectPath(),
    //     FStreamableDelegate::CreateLambda(
    //         [this]()
    //         {
    //             if (UDataAsset_StartupDataBase *Data = CharacterStartupData.Get())
    //             {
    //                 Data->GiveToAbilitySystemComponent(HeroAbilitySystemComponent);
    //
    //                 GetAbilitySystemComponent()->PrintDebug();
    //                 GetAbilitySystemComponent()->PrintAllGameplayEffects();
    //             }
    //         }
    //         )
    // );

}