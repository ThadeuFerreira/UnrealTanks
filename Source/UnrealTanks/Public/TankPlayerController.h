// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class UNREALTANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;

	//Comment
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Move the barrel to the screen crosshair location
	virtual void AimTowardsCrossHair();

	virtual bool GetSightRayHitLocation(FVector &HitPosition) const;

	virtual bool GetLookVectorHitLocation(FVector2D ScreenLocation, FVector &HitPosition) const;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333f;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 10000;
};
