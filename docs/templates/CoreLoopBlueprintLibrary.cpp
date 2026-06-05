#include "CoreLoopBlueprintLibrary.h"

float UCoreLoopBlueprintLibrary::NormalizeAngleDegrees(float angleDegrees)
{
	return FRotator::NormalizeAxis(angleDegrees);
}

FVector UCoreLoopBlueprintLibrary::GetDirectionToTarget(const FVector& fromLocation, const FVector& targetLocation)
{
	const FVector offset = targetLocation - fromLocation;
	return offset.GetSafeNormal();
}

float UCoreLoopBlueprintLibrary::GetDistance2D(const FVector& a, const FVector& b)
{
	return FVector::Dist2D(a, b);
}

FVector UCoreLoopBlueprintLibrary::GetRandomPointInRadius(const FVector& center, float radius)
{
	if (radius <= 0.0f)
	{
		return center;
	}

	// XY 평면에서만 무작위 오프셋을 만들고 Z 높이는 유지한다.
	const FVector2D randomOffset = FMath::RandPointInCircle(radius);
	return center + FVector(randomOffset.X, randomOffset.Y, 0.0f);
}

float UCoreLoopBlueprintLibrary::MapRangeClampedSafe(float value, float inMin, float inMax, float outMin, float outMax)
{
	if (FMath::IsNearlyEqual(inMin, inMax))
	{
		return outMin;
	}

	// 입력 범위가 정상일 때만 Unreal 기본 매핑 함수를 사용한다.
	return FMath::GetMappedRangeValueClamped(FVector2D(inMin, inMax), FVector2D(outMin, outMax), value);
}

float UCoreLoopBlueprintLibrary::GetHealthPercent(float currentHealth, float maxHealth)
{
	if (maxHealth <= 0.0f)
	{
		return 0.0f;
	}

	// UI ProgressBar에 바로 넣을 수 있도록 0~1 사이로 고정한다.
	return FMath::Clamp(currentHealth / maxHealth, 0.0f, 1.0f);
}

bool UCoreLoopBlueprintLibrary::IsAlive(float currentHealth)
{
	return currentHealth > 0.0f;
}

bool UCoreLoopBlueprintLibrary::RollChance(float chance)
{
	const float clampedChance = FMath::Clamp(chance, 0.0f, 1.0f);
	return FMath::FRand() <= clampedChance;
}

float UCoreLoopBlueprintLibrary::CalculateDamageWithMultiplier(float baseDamage, float multiplier)
{
	if (baseDamage <= 0.0f || multiplier <= 0.0f)
	{
		return 0.0f;
	}

	return baseDamage * multiplier;
}

FString UCoreLoopBlueprintLibrary::FormatSecondsToTime(float seconds)
{
	const int32 totalSeconds = FMath::Max(0, FMath::FloorToInt(seconds));
	const int32 minutes = totalSeconds / 60;
	const int32 remainingSeconds = totalSeconds % 60;

	return FString::Printf(TEXT("%02d:%02d"), minutes, remainingSeconds);
}

FString UCoreLoopBlueprintLibrary::FormatScore(int32 score)
{
	return FString::FromInt(FMath::Max(0, score));
}

FText UCoreLoopBlueprintLibrary::PercentToText(float percent, int32 fractionalDigits)
{
	const float clampedPercent = FMath::Clamp(percent, 0.0f, 1.0f) * 100.0f;
	const int32 safeFractionalDigits = FMath::Max(0, fractionalDigits);

	// 소수점 자릿수를 고정해서 UI 표시가 흔들리지 않게 한다.
	FNumberFormattingOptions options;
	options.MinimumFractionalDigits = safeFractionalDigits;
	options.MaximumFractionalDigits = safeFractionalDigits;

	return FText::Format(NSLOCTEXT("CoreLoop", "PercentFormat", "{0}%"), FText::AsNumber(clampedPercent, &options));
}
