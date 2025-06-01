// Naify


#include "GAS/BaseAttributeSet.h"

#include "DebugHelper.h"
#include "FunctionLibrary.h"
#include "GameplayEffectExtension.h"
#include "GasBossGameplayTags.h"
#include "Components/UI/HeroUIComponent.h"
#include "Components/UI/UIComponent.h"
#include "Interfaces/UIInterface.h"

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
    if (!UIInterface.IsValid())
    {
        UIInterface = Cast<IUIInterface>(Data.Target.GetAvatarActor());
    }
    checkf(UIInterface.IsValid(), TEXT("UIInterface is not valid in %s"), *GetName());
    
    UUIComponent* UIComponent =  UIInterface->GetUIComponent();
    checkf(UIComponent, TEXT("UIComponent is not valid in %s"), *GetName());
    
    if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
    {
        const float NewHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());
        SetCurrentHealth(NewHealth);

        UIComponent->OnHealthPercentChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());
    }
    else if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
    {
        const float NewRage = FMath::Clamp(GetCurrentRage(), 0.f, GetMaxRage());
        SetCurrentRage(NewRage);

        if (UHeroUIComponent* HeroUIComponent = UIInterface->GetHeroUIComponent())
        {
            HeroUIComponent->OnRagePercentChanged.Broadcast(GetCurrentRage() / GetMaxRage());
        }
    }
    else if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
    {
        const float OldHealth = GetCurrentHealth();
        const float Damage = GetDamageTaken();
        const float NewHealth = FMath::Clamp(OldHealth - Damage, 0.f, GetMaxHealth());
        SetCurrentHealth(NewHealth);

        const FString DebugString = FString::Printf(TEXT("Damage: %f, OldHealth: %f, NewHealth: %f"), Damage, OldHealth, NewHealth);
        // Debug::Print(DebugString, FColor::Red);

        UIComponent->OnHealthPercentChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());
        
        if (NewHealth == 0.f)
        {
            UFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), GasBossGameplayTags::Shared_Status_Death);
        }
    }
}