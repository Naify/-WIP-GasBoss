// Naify

#include "GasBoss/Public/Characters/HeroCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/GasBossInputComponent.h"
#include "GasBossGameplayTags.h"
#include "DataAssets/StartUpData/DataAsset_HeroStartupData.h"
#include "Engine/LocalPlayer.h"
#include "Components/Combat/HeroCombatComponent.h"

#include "GasBoss/Public/DebugHelper.h"

AHeroCharacter::AHeroCharacter()
{
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;
    
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->TargetArmLength = 200.f;
    SpringArmComponent->SocketOffset = FVector(0.f, 55.f, 65.f);
    SpringArmComponent->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
    CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
    CameraComponent->bUsePawnControlRotation = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
    GetCharacterMovement()->MaxWalkSpeed = 400.f;
    GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

    CombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("CombatComponent"));
}

void AHeroCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AHeroCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    if (!CharacterStartupData.IsNull())
    {
        UDataAsset_StartupDataBase* LoadedData = CharacterStartupData.LoadSynchronous();
        if (LoadedData)
        {
            LoadedData->GiveToAbilitySystemComponent(GetHeroAbilitySystemComponent());
        }
    }
}

void AHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    checkf(InputConfigDataAsset, TEXT("InputConfigDataAsset is null"));
    ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

    UEnhancedInputLocalPlayerSubsystem* InputSubsys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
    check(InputSubsys);
    InputSubsys->AddMappingContext(InputConfigDataAsset->DefaultInputMappingContext, 0);

    UGasBossInputComponent* GasBossInputComponent = CastChecked<UGasBossInputComponent>(PlayerInputComponent);
    GasBossInputComponent->BindNativeInputAction(InputConfigDataAsset, GasBossGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &AHeroCharacter::MoveInput);
    GasBossInputComponent->BindNativeInputAction(InputConfigDataAsset, GasBossGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &AHeroCharacter::LookInput);
}

void AHeroCharacter::MoveInput(const FInputActionValue& Value)
{
    const FVector2D MoveVector = Value.Get<FVector2D>();
    const FRotator MoveRotation(0.0f, GetControlRotation().Yaw, 0.0f);

    if (MoveVector.Y != 0.f)
    {
        const FVector ForwardVector = MoveRotation.RotateVector(FVector::ForwardVector);
        AddMovementInput(ForwardVector, MoveVector.Y);
    }

    if (MoveVector.X != 0.f)
    {
        const FVector RightVector = MoveRotation.RotateVector(FVector::RightVector);
        AddMovementInput(RightVector, MoveVector.X);
    }
}

void AHeroCharacter::LookInput(const FInputActionValue& Value)
{
    const FVector2D LookVector = Value.Get<FVector2D>();

    if (LookVector.X != 0.f)
    {
        AddControllerYawInput(LookVector.X);
    }

    if (LookVector.Y != 0.f)
    {
        AddControllerPitchInput(LookVector.Y);
    }
}
