// Naify


#include "GAS/BaseAttributeSet.h"

#include "DebugHelper.h"
#include "FunctionLibrary.h"
#include "GameplayEffectExtension.h"
#include "GasBossGameplayTags.h"

UBaseAttributeSet::UBaseAttributeSet()
{
    InitCurrentHealth(100.f);
    InitMaxHealth(100.f);
    InitCurrentRage(1.f);
    InitMaxRage(1.f);
    InitAttackPower(1.5f);
    InitDefensePower(1.5f);
}

void UBaseAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData &Data)
{
    if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
    {
        const float NewHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());
        SetCurrentHealth(NewHealth);
    }
    else if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
    {
        const float NewRage = FMath::Clamp(GetCurrentRage(), 0.f, GetMaxRage());
        SetCurrentRage(NewRage);
    }
    else if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
    {
        const float OldHealth = GetCurrentHealth();
        const float Damage = GetDamageTaken();
        const float NewHealth = FMath::Clamp(OldHealth - Damage, 0.f, GetMaxHealth());
        SetCurrentHealth(NewHealth);

        const FString DebugString = FString::Printf(TEXT("Damage: %f, OldHealth: %f, NewHealth: %f"), Damage, OldHealth, NewHealth);
        Debug::Print(DebugString, FColor::Red);

        if (NewHealth == 0.f)
        {
            UFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), GasBossGameplayTags::Shared_Status_Death);
        }
    }
}