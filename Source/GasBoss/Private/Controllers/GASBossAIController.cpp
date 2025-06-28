// Naify


#include "Controllers/GASBossAIController.h"

#include "DebugHelper.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AGASBossAIController::AGASBossAIController(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
    UCrowdFollowingComponent* CrowdComponent = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent());

    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
    SightConfig->DetectionByAffiliation.bDetectEnemies = true;
    SightConfig->DetectionByAffiliation.bDetectFriendlies = false;
    SightConfig->DetectionByAffiliation.bDetectNeutrals = false;
    SightConfig->SightRadius = 5000.f;
    SightConfig->LoseSightRadius = 0.f;
    SightConfig->PeripheralVisionAngleDegrees = 360.f;

    EnemyPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("EnemyPerceptionComponent"));
    EnemyPerceptionComponent->ConfigureSense(*SightConfig);
    EnemyPerceptionComponent->SetDominantSense(UAISenseConfig_Sight::StaticClass());
    EnemyPerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &ThisClass::OnEnemyPerceptionUpdated);

    SetGenericTeamId(FGenericTeamId(1));
}

ETeamAttitude::Type AGASBossAIController::GetTeamAttitudeTowards(const AActor &Other) const
{
    const APawn* PawnToCheck = Cast<const APawn>(&Other);

    const IGenericTeamAgentInterface* OtherTeamMember =  Cast<const IGenericTeamAgentInterface>(PawnToCheck->GetController());

    if (OtherTeamMember && OtherTeamMember->GetGenericTeamId() != GetGenericTeamId())
    {
        return ETeamAttitude::Hostile;
    }
    
    return ETeamAttitude::Friendly;
}

void AGASBossAIController::OnEnemyPerceptionUpdated(AActor *Actor, FAIStimulus Stimulus)
{
    if (Stimulus.WasSuccessfullySensed())
    {
        Debug::Print(FString::Printf(TEXT("Enemy %s has been perceived"), *Actor->GetName()), FColor::Green);
    }
    else if (Stimulus.WasSuccessfullySensed() == false && Stimulus.IsExpired())
    {
        Debug::Print(FString::Printf(TEXT("Enemy %s has lost sight"), *Actor->GetName()), FColor::Red);
    }
}