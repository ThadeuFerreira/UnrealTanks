// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "TankAIController.h"


ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!PlayerPawn) {
		return nullptr;
	}
	
	return Cast<ATank>(PlayerPawn);
}

// Called when the game starts or when spawned
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* FirstTank = GetPlayerTank();

	if (!FirstTank) {
		UE_LOG(LogTemp, Error, TEXT("AI Controler cant find player tank"));
	}
	else {
		auto te = FirstTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankAIController Found Player Tank - the Tank Contoller is %s"), *te);
	}

}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

