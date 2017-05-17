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
	
public:

	ATank* GetControlledTank() const;
	// Start the tank moving the barrel so a shot would hit where the
	// crosshair intercepts the world
	void AimTowardsCrosshair();
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	// Returns an OUT parameter, true if hit location
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

};
