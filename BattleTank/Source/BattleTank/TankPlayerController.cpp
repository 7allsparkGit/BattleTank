// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "BattleTank.h"
#include "TankPlayerController.h"

ATankPlayerController::ATankPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::Tick(float DeltaTime )
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}

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

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return;  }

	// 
}
