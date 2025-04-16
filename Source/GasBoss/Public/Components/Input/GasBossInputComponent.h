// Naify

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "GasBossInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASBOSS_API UGasBossInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
    template<class UserObject, typename CallBackFunction>
    void BindNativeInputAction(const UDataAsset_InputConfig* Config, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallBackFunction Func);

    template<class UserObject, typename CallBackFunction>
    void BindAbilityInputAction(const UDataAsset_InputConfig* Config, UserObject* ContextObject, CallBackFunction InputFunc, CallBackFunction ReleasedFunc);
};

template <class UserObject, typename CallBackFunction>
void UGasBossInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* Config,
    const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallBackFunction Func)
{
    checkf(Config, TEXT("InputConfig is null"));
    if (UInputAction* FoundAction = Config->FindNativeInputActionByTag(InputTag))
    {
        BindAction(FoundAction, TriggerEvent, ContextObject, Func);
    }
}

template <class UserObject, typename CallBackFunction>
void UGasBossInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig *Config, UserObject *ContextObject,
    CallBackFunction InputFunc, CallBackFunction ReleasedFunc)
{
    checkf(Config, TEXT("InputConfig is null"));
    for (const FGasBossInputConfig& AbilityInputActionConfig : Config->AbilitiesInputActions)
    {
        if(!AbilityInputActionConfig.IsValid()) continue;
 
        BindAction(AbilityInputActionConfig.InputAction,ETriggerEvent::Started,ContextObject,InputFunc,AbilityInputActionConfig.InputTag);
        BindAction(AbilityInputActionConfig.InputAction,ETriggerEvent::Completed,ContextObject,ReleasedFunc,AbilityInputActionConfig.InputTag);
    }
}



