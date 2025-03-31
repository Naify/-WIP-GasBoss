#pragma once

namespace Debug
{
    static void Print(const FString& Message, const FColor& Color = FColor::White, float Duration = 5.f)
    {
        GEngine->AddOnScreenDebugMessage(-1, Duration, Color, Message);

        UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
    }
}