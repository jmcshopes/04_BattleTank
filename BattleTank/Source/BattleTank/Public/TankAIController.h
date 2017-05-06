// Copyright John McFarlane-Shopes 2017

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	
private:
	ATank* GetAITank() const;
	ATank* GetPlayerTank() const;
	void BeginPlay() override; // NB if we want to inherit from this class, BeginPlay should be public!!
};
