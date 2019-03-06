// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTanks.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimComponent.h"


// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAimComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) return;

	Barrel = BarrelToSet;
}

void UTankAimComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) return;

	Turret = TurretToSet;
}
void UTankAimComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	auto isPossibleToReach = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (isPossibleToReach)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);	
		auto Time = GetWorld()->GetTimeSeconds();
	}
	else {
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT(" %f Cant Reach"), Time);
	}

	
}

void UTankAimComponent::MoveBarrelTowards(FVector AimDiretion) {
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDiretion.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT(" %s Delta"), *DeltaRotator.ToString());
	UE_LOG(LogTemp, Error, TEXT(" %s Aim"), *AimAsRotator.ToString());
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);

}

// Called every frame
void UTankAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

