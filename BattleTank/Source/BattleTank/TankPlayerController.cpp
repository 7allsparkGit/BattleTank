// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine.h"
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

	FVector HitLocation;  // out parameter
	if (GetSightRayHitsLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
	// 
}

void ATankPlayerController::PerformRayCastHit()
{
	InputComponent->BindAction("Raycast", IE_Pressed, this, &ATankPlayerController::PerformRayCastHit);
	FHitResult* HitResult = new FHitResult();
	FVector StartTrace = PlayerCameraManager->GetCameraLocation();
	FVector ForwardVector = PlayerCameraManager->GetActorForwardVector();
	FVector EndTrace = ((ForwardVector * 5000.f) + StartTrace);
	FCollisionQueryParams* TraceParams = new FCollisionQueryParams();
	
	if (GetWorld()->LineTraceSingleByChannel(*HitResult, StartTrace, EndTrace, ECC_Visibility, *TraceParams))
	{
		DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor(255, 0, 0), true);
	}

}

bool ATankPlayerController::GetSightRayHitsLocation(FVector& HitLocation)
{
	HitLocation = FVector(1.0);
	return true;
}
