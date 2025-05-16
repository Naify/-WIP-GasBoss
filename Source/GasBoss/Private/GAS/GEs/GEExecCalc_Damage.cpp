// Naify


#include "GAS/GEs/GEExecCalc_Damage.h"

#include "DebugHelper.h"
#include "GasBossGameplayTags.h"
#include "GAS/BaseAttributeSet.h"

struct FDamageCapture
{
    DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);
    DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower);
    DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken);

    FDamageCapture()
    {
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet, AttackPower, Source, false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet, DefensePower, Target, false);
        DEFINE_ATTRIBUTE_CAPTUREDEF(UBaseAttributeSet, DamageTaken, Target, false);
    }
};

static const FDamageCapture &GetDamageCapture()
{
    static const FDamageCapture DamageCapture;
    return DamageCapture;
}

UGEExecCalc_Damage::UGEExecCalc_Damage()
{
    // FProperty* AttackPower = FindFieldChecked<FProperty>(
    //     UBaseAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UBaseAttributeSet, AttackPower)
    // );
    //
    // FGameplayEffectAttributeCaptureDefinition AttackPowerCaptureDef(
    //     AttackPower, EGameplayEffectAttributeCaptureSource::Source, false
    // );
    //
    // RelevantAttributesToCapture.Add(AttackPowerCaptureDef);

    RelevantAttributesToCapture.Add(GetDamageCapture().AttackPowerDef);
    RelevantAttributesToCapture.Add(GetDamageCapture().DefensePowerDef);
    RelevantAttributesToCapture.Add(GetDamageCapture().DamageTakenDef);
}

void UGEExecCalc_Damage::Execute_Implementation(const FGameplayEffectCustomExecutionParameters &ExecutionParams,
                                                FGameplayEffectCustomExecutionOutput &OutExecutionOutput) const
{
    Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

    FAggregatorEvaluateParameters EvaluationParameters;
    EvaluationParameters.SourceTags = ExecutionParams.GetOwningSpec().CapturedSourceTags.GetAggregatedTags();
    EvaluationParameters.TargetTags = ExecutionParams.GetOwningSpec().CapturedTargetTags.GetAggregatedTags();

    float SourceAttackPower = 1.f;

    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
        GetDamageCapture().AttackPowerDef, EvaluationParameters, SourceAttackPower);
    Debug::Print(TEXT("SourceAttackPower"), SourceAttackPower);

    float BaseDamage = 10.f;
    int32 ComboCount = 1;

    for (const TTuple<FName, float> &TagMagnitude : ExecutionParams.GetOwningSpec().SetByCallerNameMagnitudes)
    {
        FGameplayTag GameplayTag = FGameplayTag::RequestGameplayTag(TagMagnitude.Key);

        if (GameplayTag.MatchesTagExact(GasBossGameplayTags::Shared_SetByCaller_Damage))
        {
            BaseDamage += TagMagnitude.Value;
            Debug::Print(TEXT("BaseDamage"), ComboCount);
        }

        if (GameplayTag.MatchesTagExact(GasBossGameplayTags::Player_SetByCaller_AttackType_Light))
        {
            ComboCount = TagMagnitude.Value;
            Debug::Print(TEXT("ComboCount"), ComboCount);
        }
    }

    float TargetDefensePower = 1.f;
    ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
        GetDamageCapture().DefensePowerDef, EvaluationParameters, TargetDefensePower);
    Debug::Print(TEXT("TargetDefensePower"), TargetDefensePower);

    if (ComboCount != 0)
    {
        const float DamageIncrease = (ComboCount - 1) * 0.1f + 1.f;
        BaseDamage *= DamageIncrease;
        Debug::Print(TEXT("IncreasedBaseDamage"), BaseDamage);
    }

    const float FinalDamage = BaseDamage * SourceAttackPower / TargetDefensePower;
    Debug::Print(TEXT("FinalDamage"), FinalDamage);

    if (FinalDamage > 0.f)
    {
        OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(
            GetDamageCapture().DamageTakenProperty, EGameplayModOp::Override, FinalDamage));
    }
}