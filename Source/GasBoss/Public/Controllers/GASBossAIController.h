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

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UAIPerceptionComponent* EnemyPerceptionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UAISenseConfig_Sight* SightConfig;

    UFUNCTION()
    virtual  void OnEnemyPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
};