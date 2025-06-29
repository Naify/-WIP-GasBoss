// Naify


#include "Controllers/GASBossAIController.h"

#include "DebugHelper.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

AGASBossAIController::AGASBossAIController(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
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

void AGASBossAIController::BeginPlay()
{
    Super::BeginPlay();

    if (UCrowdFollowingComponent* CrowdComponent = Cast<UCrowdFollowingComponent>(GetPathFollowingComponent()))
    {
        CrowdComponent->SetCrowdSimulationState(bEnableCrowdAvoidance ? ECrowdSimulationState::Enabled : ECrowdSimulationState::Disabled);

        switch (CrowdAvoidanceQuality)
        {
            case 1: 
                CrowdComponent->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Low);
                break;
            case 2:
                CrowdComponent->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Medium);
                break;
            case 3:
                CrowdComponent->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::Good);
                break;
            case 4:
                CrowdComponent->SetCrowdAvoidanceQuality(ECrowdAvoidanceQuality::High);
                break;
            default:
                break;
        }
        
        CrowdComponent->SetAvoidanceGroup(1);
        CrowdComponent->SetGroupsToAvoid(1);
        CrowdComponent->SetCrowdCollisionQueryRange(CrowdAvoidanceRadius);
    }
}

void AGASBossAIController::OnEnemyPerceptionUpdated(AActor *Actor, FAIStimulus Stimulus)
{
    if (Stimulus.WasSuccessfullySensed() && Actor)
    {
        if (UBlackboardComponent* BlackboardAI = GetBlackboardComponent())
        {
            BlackboardAI->SetValueAsObject(FName("TargetActor"), Actor);
        }
    }
}