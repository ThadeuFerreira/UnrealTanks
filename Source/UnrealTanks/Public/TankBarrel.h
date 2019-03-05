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
	UPROPERTY(EditAnyWhere, Category = SetUp)
		float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnyWhere, Category = SetUp)
		float MaxElevationDegree = 45;

	UPROPERTY(EditAnyWhere, Category = SetUp)
		float MinElevationDegree = 0;
	
};
