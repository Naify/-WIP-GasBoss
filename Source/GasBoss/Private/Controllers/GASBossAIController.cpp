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
}

void AGASBossAIController::OnEnemyPerceptionUpdated(AActor *Actor, FAIStimulus Stimulus)
{
    
}