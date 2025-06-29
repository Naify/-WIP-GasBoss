// Naify

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GASBossAIController.generated.h"

struct FAIStimulus;
class UAISenseConfig_Sight;
class UAIPerceptionComponent;
/**
 * 
 */
UCLASS()
class GASBOSS_API AGASBossAIController : public AAIController
{
    GENERATED_BODY()

public:
    AGASBossAIController(const FObjectInitializer& ObjectInitializer);

    virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor &Other) const override;

protected:
    virtual void BeginPlay() override;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UAIPerceptionComponent* EnemyPerceptionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UAISenseConfig_Sight* SightConfig;

    UFUNCTION()
    virtual  void OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

private:
    UPROPERTY(EditDefaultsOnly, Category = "Crowd Avoidance")
    bool bEnableCrowdAvoidance = true;

    UPROPERTY(EditDefaultsOnly, Category = "Crowd Avoidance", meta = (EditCondition = "bEnableCrowdAvoidance", UIMin = "1", UIMax = "4"))
    int32 CrowdAvoidanceQuality = 4;

    UPROPERTY(EditDefaultsOnly, Category = "Crowd Avoidance", meta = (EditCondition = "bEnableCrowdAvoidance"))
    float CrowdAvoidanceRadius = 600.f;
};