// Naify

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_RotateToFaceTarget.generated.h"

struct FRotateToFaceTarget
{
    TWeakObjectPtr<AActor> TargetActor;
    TWeakObjectPtr<APawn> OwnerPawn;

    bool isValid() const
    {
        return TargetActor.IsValid() && OwnerPawn.IsValid();
    }

    void Reset()
    {
        TargetActor.Reset();
        OwnerPawn.Reset();
    }
};
/**
 * 
 */
UCLASS()
class GASBOSS_API UBTTask_RotateToFaceTarget : public UBTTaskNode
{
    GENERATED_BODY()

    UBTTask_RotateToFaceTarget();

    virtual void InitializeFromAsset(UBehaviorTree& Asset) override;
    virtual uint16 GetInstanceMemorySize() const override;
    virtual FString GetStaticDescription() const override;
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
    virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

    bool HasReachedAnglePrecision(APawn* QueryPawn, AActor* TargetActor) const;
    
    UPROPERTY(EditAnywhere, Category = "Target")
    float AnglePrecision;
    
    UPROPERTY(EditAnywhere, Category = "Target")
    float RotationSpeed;

    UPROPERTY(EditAnywhere, Category = "Target")
    FBlackboardKeySelector TargetKey;
};