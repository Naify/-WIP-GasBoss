// Naify


#include "DataAssets/Input/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InTag) const
{
    for (const FGasBossInputConfig& InputConfig : NativeInputActions)
    {
        if (InputConfig.InputTag == InTag && InputConfig.InputAction)
        {
            return InputConfig.InputAction;
        }
    }
    return nullptr;
}
