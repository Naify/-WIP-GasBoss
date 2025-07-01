// Naify


#include "FunctionLibrary.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Components/Combat/CombatComponent.h"
#include "GAS/HeroAbilitySystemComponent.h"
#include "Interfaces/PawnCombatInterface.h"

UCombatComponent * UFunctionLibrary::NativeGetCombatComponentFromActor(AActor *Actor)
{
    check(Actor);

    if (IPawnCombatInterface* PawnCombatInterface = Cast<IPawnCombatInterface>(Actor))
    {
        return PawnCombatInterface->GetCombatComponent();
    }

    return nullptr;
}

UCombatComponent * UFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor *Actor, EValidType &OutValidType)
{
    UCombatComponent* CombatComponent = NativeGetCombatComponentFromActor(Actor);

    OutValidType = CombatComponent ? EValidType::Valid : EValidType::Invalid;

    return CombatComponent;
}

UHeroAbilitySystemComponent* UFunctionLibrary::NativeGetHeroASCFromActor(AActor* InActor)
{   
    check(InActor);

    return CastChecked<UHeroAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UFunctionLibrary::AddGameplayTagToActorIfNone(AActor *InActor, FGameplayTag TagToAdd)
{
    UHeroAbilitySystemComponent* ASC = NativeGetHeroASCFromActor(InActor);

    if (!ASC->HasMatchingGameplayTag(TagToAdd))
    {
        ASC->AddLooseGameplayTag(TagToAdd);
    }
}

void UFunctionLibrary::RemoveGameplayFromActorIfFound(AActor *InActor, FGameplayTag TagToRemove)
{
    UHeroAbilitySystemComponent* ASC = NativeGetHeroASCFromActor(InActor);

    if (ASC->HasMatchingGameplayTag(TagToRemove))
    {
        ASC->RemoveLooseGameplayTag(TagToRemove);
    }
}

bool UFunctionLibrary::NativeDoesActorHaveTag(AActor *InActor, FGameplayTag TagToCheck)
{
    UHeroAbilitySystemComponent* ASC = NativeGetHeroASCFromActor(InActor);

    return ASC->HasMatchingGameplayTag(TagToCheck);
}