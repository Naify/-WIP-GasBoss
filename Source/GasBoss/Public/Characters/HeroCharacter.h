// Naify

#pragma once

#include "CoreMinimal.h"
#include "GasBoss/Public/Characters/BaseCharacter.h"
#include "HeroCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
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

private:
#pragma region Components
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent* SpringArmComponent;
#pragma endregion
};
