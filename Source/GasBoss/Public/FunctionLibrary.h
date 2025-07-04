// Naify

#pragma once

#include "CoreMinimal.h"
#include "GAS/HeroAbilitySystemComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Types/EnumTypes.h"
#include "FunctionLibrary.generated.h"


UENUM()
enum class EGasBossConfirmType : uint8
{
    Yes,
    No
};

class UCombatComponent;
/**
 * 
 */
UCLASS()
class GASBOSS_API UFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    static UCombatComponent* NativeGetCombatComponentFromActor(AActor* Actor);

    UFUNCTION(BlueprintCallable, Category = "FunctionLibrary", meta = (DisplayName = "Get Pawn Combat Component From Actor", ExpandEnumAsExecs = "OutValidType"))
    static UCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* Actor, EValidType& OutValidType);
    
    static UHeroAbilitySystemComponent *NativeGetHeroASCFromActor(AActor *InActor);

    UFUNCTION(BlueprintCallable, Category = "FunctionLibrary")
    static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

    UFUNCTION(BlueprintCallable, Category = "FunctionLibrary")
    static void RemoveGameplayFromActorIfFound(AActor* InActor,FGameplayTag TagToRemove);
    
    static bool NativeDoesActorHaveTag(AActor* InActor,FGameplayTag TagToCheck);

    UFUNCTION(BlueprintCallable, Category = "FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
    static void BP_DoesActorHaveTag(AActor* InActor,FGameplayTag TagToCheck,EGasBossConfirmType& OutConfirmType);

    UFUNCTION(BlueprintPure, Category = "FunctionLibrary")
    static bool IsTargetPawnHostile(APawn* TargetPawn, APawn* QueryPawn);
};