#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoreLoopBlueprintLibrary.generated.h"

/*
 * Unreal 프로젝트용 Blueprint helper 템플릿이다.
 *
 * 프로젝트 생성 후 아래 위치로 복사한다.
 * Source/<ProjectName>/Utils/CoreLoopBlueprintLibrary.h
 *
 * CORELOOP_API는 실제 모듈 API 매크로로 바꾼다.
 * 예: MyGame -> MYGAME_API
 */
UCLASS()
class CORELOOP_API UCoreLoopBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "CoreLoop|Math")
	static float NormalizeAngleDegrees(float angleDegrees);

	UFUNCTION(BlueprintPure, Category = "CoreLoop|Math")
	static FVector GetDirectionToTarget(const FVector& fromLocation, const FVector& targetLocation);

	UFUNCTION(BlueprintPure, Category = "CoreLoop|Math")
	static float GetDistance2D(const FVector& a, const FVector& b);

	UFUNCTION(BlueprintPure, Category = "CoreLoop|Math")
	static FVector GetRandomPointInRadius(const FVector& center, float radius);

	UFUNCTION(BlueprintPure, Category = "CoreLoop|Math")
	static float MapRangeClampedSafe(float value, float inMin, float inMax, float outMin, float outMax);

	UFUNCTION(BlueprintPure, Category = "CoreLoop|Gameplay")
	static float GetHealthPercent(float currentHealth, float maxHealth);

	UFUNCTION(BlueprintPure, Category = "CoreLoop|Gameplay")
	static bool IsAlive(float currentHealth);

	UFUNCTION(BlueprintCallable, Category = "CoreLoop|Gameplay")
	static bool RollChance(float chance);

	UFUNCTION(BlueprintPure, Category = "CoreLoop|Gameplay")
	static float CalculateDamageWithMultiplier(float baseDamage, float multiplier);

	UFUNCTION(BlueprintPure, Category = "CoreLoop|UI")
	static FString FormatSecondsToTime(float seconds);

	UFUNCTION(BlueprintPure, Category = "CoreLoop|UI")
	static FString FormatScore(int32 score);

	UFUNCTION(BlueprintPure, Category = "CoreLoop|UI")
	static FText PercentToText(float percent, int32 fractionalDigits = 0);
};
