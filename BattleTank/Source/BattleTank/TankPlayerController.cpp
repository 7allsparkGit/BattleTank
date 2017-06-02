// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControllerTank = GetControlledTank();
	if (!ControllerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not posessing a tanl"), *(ControllerTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play %s"), *(ControllerTank->GetName()));
	}
}

// Get an ABattleTank type pointer back 
ATank* ATankPlayerController::GetControlledTank() const
{
	///how do we get the controlled tank?
	// get pawn from the TankPlayerController perspective
		// it should return the Pawn that the PlayerController is currently possessing
			// as the tank is a Pawn, we have to use Cast<ATank> not the parent class Pawn
	return Cast<ATank>(GetPawn());
}


