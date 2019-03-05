// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "Tank.h"
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

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtPlayer();
}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}



void ATankAIController::AimAtPlayer()
{
	auto PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		auto HitLocation = PlayerTank->GetActorLocation();
		GetControlledTank()->AimAt(HitLocation);
	}

}

