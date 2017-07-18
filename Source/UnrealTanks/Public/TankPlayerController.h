// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALTANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;

	//Comment
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Move the barrel to the screen crosshair location
	virtual void AimAtCrossHair() const;

};
