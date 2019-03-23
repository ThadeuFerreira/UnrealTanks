// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALTANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = SetUp)
		float MaxDegreesPerSecond = 25;

	UPROPERTY(EditDefaultsOnly, Category = SetUp)
		float MaxElevationDegree = 50;

	UPROPERTY(EditDefaultsOnly, Category = SetUp)
		float MinElevationDegree = 0;
	
};
