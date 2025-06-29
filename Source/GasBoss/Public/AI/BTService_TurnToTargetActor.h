// Naify

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_TurnToTargetActor.generated.h"

/**
 * 
 */
UCLASS()
class GASBOSS_API UBTService_TurnToTargetActor : public UBTService
{
    GENERATED_BODY()

public:
    UBTService_TurnToTargetActor();

    virtual void InitializeFromAsset(UBehaviorTree &Asset) override;
    virtual FString GetStaticDescription() const override;
    virtual void TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds) override;

    UPROPERTY(EditAnywhere, Category = "Target")
    FBlackboardKeySelector TargetActorKey;
    
    UPROPERTY(EditAnywhere, Category = "Target")
    float RotationSpeed = 5.0f;

    
};