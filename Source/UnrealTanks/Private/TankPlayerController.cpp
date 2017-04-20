// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "TankPlayerController.h"


// Called when the game starts or when spawned
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* FirstTank = GetControlledTank();

	if (!FirstTank) {
		UE_LOG(LogTemp, Error, TEXT("No TankContorller"));
	}
	else {
		auto te = FirstTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Begin Play - the Tank Contoller is %s"), *te);
	}
	
}

ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}


