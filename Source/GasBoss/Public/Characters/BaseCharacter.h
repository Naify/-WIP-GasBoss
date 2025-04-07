// Naify

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "BaseCharacter.generated.h"

class UHeroAbilitySystemComponent;
class UHeroAttributeSet;

UCLASS()
class GASBOSS_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	UHeroAbilitySystemComponent* HeroAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	UHeroAttributeSet* HeroAttributeSet;

	virtual void PossessedBy(AController* NewController) override;
	
public:
	FORCEINLINE UHeroAbilitySystemComponent* GetHeroAbilitySystemComponent() const { return HeroAbilitySystemComponent; }

	FORCEINLINE UHeroAttributeSet* GetHeroAttributeSet() const { return HeroAttributeSet; }
};
