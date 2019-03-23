// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "Tank.h"
#include "TankAIController.h"



// Called when the game starts or when spawned
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* FirstTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

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


void ATankAIController::AimAtPlayer()
{
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank) {
		auto HitLocation = PlayerTank->GetActorLocation();
		ControlledTank->AimAt(HitLocation);

		ControlledTank->Fire();
	}

}

