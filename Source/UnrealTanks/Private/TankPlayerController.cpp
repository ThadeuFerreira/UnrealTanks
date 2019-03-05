// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "Tank.h"
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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime);
	AimTowardsCrossHair();
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("NO HIT!!!"));
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitPosition) const
{
	int32 ViewPSizeX, ViewPSizeY;
	GetViewportSize(ViewPSizeX, ViewPSizeY);
	auto ScreenLocation = FVector2D(ViewPSizeX*CrossHairXLocation, ViewPSizeY*CrossHairYLocation);

	if (GetLookVectorHitLocation(ScreenLocation, HitPosition)) {
		return true;
	}
	else
	{
		return false;
	}
	
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector2D ScreenLocation, FVector &HitPosition) const
{
	FVector CameraWorldLocation;
	FVector WorldDirection;

	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection);
	//CameraWorldLocation = PlayerCameraManager->GetCameraLocation();
		FHitResult OutHit;
		FVector FinalLineLocation = CameraWorldLocation + WorldDirection*LineTraceRange;

		if (GetWorld()->LineTraceSingleByChannel(OutHit,
			CameraWorldLocation,
			FinalLineLocation,
			ECC_Visibility
		))
		{
			HitPosition = OutHit.Location;
			return true;
		}
		else
		{
			
			return false;
		}
	

}


ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());

}


