// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle) {
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT(" %f Set Throttle %f"), Time, Throttle);
}