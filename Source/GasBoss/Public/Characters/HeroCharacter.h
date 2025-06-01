// Naify

#pragma once

#include "CoreMinimal.h"
#include "GasBoss/Public/Characters/BaseCharacter.h"
#include "HeroCharacter.generated.h"

class UHeroUIComponent;
class UHeroCombatComponent;
struct FGameplayTag;
struct FInputActionValue;
class UCameraComponent;
class USpringArmComponent;
class UDataAsset_InputConfig;
/**
 * 
 */
UCLASS()
class GASBOSS_API AHeroCharacter : public ABaseCharacter
{
    GENERATED_BODY()
public:
    AHeroCharacter();

    virtual UCombatComponent *GetCombatComponent() const override;

    FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const { return CombatComponent;}

    virtual UUIComponent* GetUIComponent() const override;
    virtual UHeroUIComponent* GetHeroUIComponent() const override;

protected:
    virtual void BeginPlay() override;

    virtual void PossessedBy(AController* NewController) override;

    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
#pragma region Components
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
    UHeroCombatComponent* CombatComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
    UHeroUIComponent* UIComponent;
#pragma endregion

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharData", meta = (AllowPrivateAccess = "true"))
    UDataAsset_InputConfig* InputConfigDataAsset;
    
    void MoveInput(const FInputActionValue& Value);
    void LookInput(const FInputActionValue& Value);

    void Input_AbilityInputPressed(const FGameplayTag Tag);
    void Input_AbilityInputReleased(const FGameplayTag Tag);
};
