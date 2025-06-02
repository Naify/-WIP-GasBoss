// Naify


#include "Widgets/WidgetBase.h"

#include "Components/UI/EnemyUIComponent.h"
#include "Interfaces/UIInterface.h"

void UWidgetBase::InitEnemyWidget(AActor *OwningEnemy)
{
    if (IUIInterface* UIInterface = Cast<IUIInterface>(OwningEnemy))
    {
        UEnemyUIComponent* EnemyUIComponent = UIInterface->GetEnemyUIComponent();

        checkf(EnemyUIComponent, TEXT("EnemyUIComponent is not valid in %s"), *GetName());

        BP_OnOwningUIComponentInitialized_Enemy(EnemyUIComponent);
    }
}

void UWidgetBase::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (IUIInterface* UIInterface = Cast<IUIInterface>(GetOwningPlayerPawn()))
    {
        if (UHeroUIComponent* UIComponent = UIInterface->GetHeroUIComponent())
        {
            BP_OnOwningUIComponentInitialized(UIComponent);
        }
    }
}