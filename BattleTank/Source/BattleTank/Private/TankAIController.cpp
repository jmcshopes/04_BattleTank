// Copyright John McFarlane-Shopes 2017

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AITank = GetAITank();
	if (!AITank) {
		UE_LOG(LogTemp, Warning, TEXT("No AI Tanks"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s is an AI Tank"), (*AITank->GetName()));
	}
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI controller can't find player Tank!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI found player tank: %s"), (*PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr;}
	else {
		return Cast<ATank>(PlayerPawn);
	}
}

