// Naify


#include "AI/BTService_TurnToTargetActor.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"

UBTService_TurnToTargetActor::UBTService_TurnToTargetActor()
{
    NodeName = TEXT("Turn Rotation To Target Actor");

    INIT_SERVICE_NODE_NOTIFY_FLAGS();

    RotationSpeed = 5.f;
    Interval = 0.f;
    RandomDeviation = 0.f;

    TargetActorKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UBTService_TurnToTargetActor, TargetActorKey),
                                   AActor::StaticClass());
}

void UBTService_TurnToTargetActor::InitializeFromAsset(UBehaviorTree &Asset)
{
    Super::InitializeFromAsset(Asset);

    if (UBlackboardData *BBData = GetBlackboardAsset())
    {
        TargetActorKey.ResolveSelectedKey(*BBData);
    }
}

FString UBTService_TurnToTargetActor::GetStaticDescription() const
{
    const FString ActorKeyName = TargetActorKey.SelectedKeyName.ToString();

    return FString::Printf(TEXT("Turn Rotation To Target Actor: %s, Key: %.s"),
                           *ActorKeyName, *GetStaticServiceDescription());
}

void UBTService_TurnToTargetActor::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    UObject *TargetActorObj = OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetActorKey.SelectedKeyName);
    AActor *TargetActor = Cast<AActor>(TargetActorObj);

    APawn *OwningPawn = OwnerComp.GetAIOwner()->GetPawn();
    if (OwningPawn && TargetActor)
    {
        const FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(OwningPawn->GetActorLocation(),
                                                                               TargetActor->GetActorLocation());

        const FRotator NewRotation = FMath::RInterpTo(OwningPawn->GetActorRotation(), LookAtRotation, DeltaSeconds,
                                                      RotationSpeed);

        OwningPawn->SetActorRotation(NewRotation);
    }
}