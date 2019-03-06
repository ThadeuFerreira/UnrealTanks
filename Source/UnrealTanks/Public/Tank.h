// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //Put includes above this line

class UTankBarrel;
class UTankTurret;
class UTankAimComponent;

UCLASS()
class UNREALTANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = SetUp)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = SetUp)
	void SetTurretReference(UTankTurret* TurretToSet);

protected:
	
	UTankAimComponent* TankAimComponent = nullptr;
private:
	// Sets default values for this pawn's properties
	ATank();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000;


	
};
