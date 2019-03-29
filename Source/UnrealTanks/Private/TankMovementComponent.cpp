// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "TankMovementComponent.h"



void UTankMovementComponent::IntendMoveForward(float Throw) {
	auto ComponentName = GetName();
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT(" %f %s --- Force Location = %f"), Time, *ComponentName, Throw);

}