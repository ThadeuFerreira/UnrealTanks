// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "Tank.h"
#include "TankBarrel.h"
#include "TankAimComponent.h"
#include "TankTurret.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimComponent = CreateDefaultSubobject<UTankAimComponent>(FName("Aiming Component"));
	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{

	TankAimComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{

	TankAimComponent->SetTurretReference(TurretToSet);
}

void ATank::AimAt(FVector HitLocation) 
{
	
	TankAimComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire() {


	if (!Barrel) return;

	FActorSpawnParameters SpawnInfo;

	//Spawn a projectile at the barrel muzzle socket location
	auto Projectile = GetWorld()->SpawnActor<AProjectile>
		(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")),
			SpawnInfo
			);

	Projectile->LaunchProjectile(LaunchSpeed);
}