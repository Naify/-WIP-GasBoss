// Naify

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetBase.generated.h"

class UEnemyUIComponent;
class UHeroUIComponent;
/**
 * 
 */
UCLASS

()
class GASBOSS_API UWidgetBase : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void InitEnemyWidget(AActor* OwningEnemy);

protected:
    virtual void NativeOnInitialized() override;

    UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName = "OnOwningUIComponentInitialized"))
    void BP_OnOwningUIComponentInitialized(UHeroUIComponent *UIComponent);
    
    UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName = "OnOwningUIComponentInitialized Enemy"))
    void BP_OnOwningUIComponentInitialized_Enemy(UEnemyUIComponent *UIComponent);
};