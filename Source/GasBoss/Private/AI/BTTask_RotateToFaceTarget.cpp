// Naify


#include "AI/BTTask_RotateToFaceTarget.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"

UBTTask_RotateToFaceTarget::UBTTask_RotateToFaceTarget()
{
    NodeName = TEXT("RotateToFaceTarget");

    AnglePrecision = 10.0f;
    RotationSpeed = 5.0f;

    bNotifyTick = true;
    bNotifyTaskFinished = true;
    bCreateNodeInstance = false;

    INIT_TASK_NODE_NOTIFY_FLAGS();

    TargetKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_RotateToFaceTarget, TargetKey),
                              AActor::StaticClass());
}

void UBTTask_RotateToFaceTarget::InitializeFromAsset(UBehaviorTree &Asset)
{
    Super::InitializeFromAsset(Asset);

    if (UBlackboardData *BlackboardData = GetBlackboardAsset())
    {
        TargetKey.ResolveSelectedKey(*BlackboardData);
    }
}

uint16 UBTTask_RotateToFaceTarget::GetInstanceMemorySize() const
{
    return sizeof(FRotateToFaceTarget);
}

FString UBTTask_RotateToFaceTarget::GetStaticDescription() const
{
    const FString KeyDescription = TargetKey.SelectedKeyName.ToString();
    return FString::Printf(TEXT("Rotate to face target: %s\nAngle Precision: %.2f\nRotation Speed: %.2f"),
                           *KeyDescription, AnglePrecision, RotationSpeed);
}

EBTNodeResult::Type UBTTask_RotateToFaceTarget::ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    
    UObject* ActorObject = OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetKey.SelectedKeyName);
    AActor* TargetActor = Cast<AActor>(ActorObject);

    APawn* OwningPawn = OwnerComp.GetAIOwner()->GetPawn();

    FRotateToFaceTarget* Memory = CastInstanceNodeMemory<FRotateToFaceTarget>(NodeMemory);
    check(Memory);

    Memory->OwnerPawn = OwningPawn;
    Memory->TargetActor = TargetActor;

    if (!Memory->isValid())
    {
        return EBTNodeResult::Failed;
    }

    if (HasReachedAnglePrecision(OwningPawn,TargetActor))
    {
        Memory->Reset();
        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::InProgress;
}

void UBTTask_RotateToFaceTarget::TickTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    FRotateToFaceTarget* Memory = CastInstanceNodeMemory<FRotateToFaceTarget>(NodeMemory);

    if (!Memory->isValid())
    {
        FinishLatentTask(OwnerComp,EBTNodeResult::Failed);
    }

    if (HasReachedAnglePrecision(Memory->OwnerPawn.Get(),Memory->TargetActor.Get()))
    {
        Memory->Reset();
        FinishLatentTask(OwnerComp,EBTNodeResult::Succeeded);
    }
    else
    {
        const FRotator LookAtRot = UKismetMathLibrary::FindLookAtRotation(Memory->OwnerPawn->GetActorLocation(),Memory->TargetActor->GetActorLocation());
        const FRotator TargetRot = FMath::RInterpTo(Memory->OwnerPawn->GetActorRotation(),LookAtRot,DeltaSeconds,RotationSpeed);

        Memory->OwnerPawn->SetActorRotation(TargetRot);
    }
}

bool UBTTask_RotateToFaceTarget::HasReachedAnglePrecision(APawn *QueryPawn, AActor *TargetActor) const
{
    const FVector OwnerForward = QueryPawn->GetActorForwardVector();
    const FVector OwnerToTargetNormalized = (TargetActor->GetActorLocation() - QueryPawn->GetActorLocation()).GetSafeNormal();

    const float DotResult = FVector::DotProduct(OwnerForward,OwnerToTargetNormalized);
    const float AngleDiff = UKismetMathLibrary::DegAcos(DotResult);

    return AngleDiff <= AnglePrecision;
}