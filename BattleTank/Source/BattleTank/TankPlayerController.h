// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	ATank* GetControlledTank() const;
	// Start the tank moving the barrel so a shot would hit where the
	// crosshair intercepts the world
	void AimTowardsCrosshair();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	// Returns an OUT parameter, true if hit location
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	UPROPERTY(editanywhere) 
	float CrosshairXLocation = 0.5;
	UPROPERTY(editanywhere) 
	float CrosshairYLocation = 0.33333;

	bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& Hitlocation) const;
	
	UPROPERTY(editanywhere)
	float LineTraceRange = 1000000.f;

};
