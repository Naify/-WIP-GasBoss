// Naify

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEExecCalc_Damage.generated.h"

/**
 * 
 */
UCLASS()
class GASBOSS_API UGEExecCalc_Damage : public UGameplayEffectExecutionCalculation
{
    GENERATED_BODY()

public:
    UGEExecCalc_Damage();

    virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters &ExecutionParams,
                                        FGameplayEffectCustomExecutionOutput &OutExecutionOutput) const override;
};