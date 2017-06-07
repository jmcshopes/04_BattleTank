// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s is being controlled"), (*ControlledTank->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}


// Tick
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	else {
		FVector HitLocation; // Out parameter
		if (GetSightRayHitLocation(HitLocation)) 
		{ // Has "side-effect", is going to line trace
		// UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"),*HitLocation.ToString());
			// TODO unsuppress if necessary
		// Get world location through linetrace from crosshair
		// If hits the landscape
			// TODO Tell controlled tank to aim at this point
		}
	}
}

// Get world location of linetract through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	// "De-project" the screen position of the crosshair to a world dircetions
	// Line-trace along that direction and see what we hit (up to max range)

	// Get world location of linetrace through crosshair, true if hits landscape
		// Define starting point using player viewpoint location using separate method
		// Another method to cast a raytrace out from that viewpoint perpendicular,
		// maybe using the weird wizardry bullshit from earlier.
		// Get the object hit by it.
		// Get that object's location. Is this going to be weird if it's hitting the landscape?

	return true; // TODO change this to actual return value
}