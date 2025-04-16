// Naify

#pragma once

#include "CoreMinimal.h"
#include "GasBoss/Public/Characters/BaseCharacter.h"
#include "HeroCharacter.generated.h"

struct FGameplayTag;
struct FInputActionValue;
class UCameraComponent;
class USpringArmComponent;
class UDataAsset_InputConfig;
class HeroCombatComponent;
/**
 * 
 */
UCLASS()
class GASBOSS_API AHeroCharacter : public ABaseCharacter
{
    GENERATED_BODY()
public:
    AHeroCharacter();

protected:
    virtual void BeginPlay() override;

    virtual void PossessedBy(AController* NewController) override;

    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
#pragma region Components
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
    class UHeroCombatComponent* CombatComponent;
#pragma endregion
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharData", meta = (AllowPrivateAccess = "true"))
    UDataAsset_InputConfig* InputConfigDataAsset;
    
    void MoveInput(const FInputActionValue& Value);
    void LookInput(const FInputActionValue& Value);

    void Input_AbilityInputPressed(const FGameplayTag Tag);
    void Input_AbilityInputReleased(const FGameplayTag Tag);
    
public:
    FORCEINLINE UHeroCombatComponent* GetCombatComponent() const { return CombatComponent; }
};
