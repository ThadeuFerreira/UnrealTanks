// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "TankAIController.h"


// Called when the game starts or when spawned
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* FirstTank = GetControlledTank();

	if (!FirstTank) {
		UE_LOG(LogTemp, Error, TEXT("No TankAIContorller"));
	}
	else {
		auto te = FirstTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankAIController Begin Play - the Tank Contoller is %s"), *te);
	}

}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

