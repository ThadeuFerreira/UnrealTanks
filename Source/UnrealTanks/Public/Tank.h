// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //Put includes above this line

UCLASS()
class UNREALTANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = SetUp)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

protected:
	
	UTankAimComponent* TankAimComponent = nullptr;
private:
	// Sets default values for this pawn's properties
	ATank();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	
};
