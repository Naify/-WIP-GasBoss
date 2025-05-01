// Naify

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/BaseAnimInstance.h"
#include "HeroLinkedAnimLayer.generated.h"

class UHeroAnimInstance;
/**
 * 
 */
UCLASS()
class GASBOSS_API UHeroLinkedAnimLayer : public UBaseAnimInstance
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, meta=(BlueprintThreadSafe))
    UHeroAnimInstance* GetHeroAnimInstance() const;
};