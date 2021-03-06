// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ATankPlayerController();
	// return a pointer to a ABattleTank,  
		// ABattleTank* will not be a recognised type
		// it is a const as it will not change any future member variables of this class
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaSeconds ) override;

	void AimTowardsCrosshair();

	void PerformRayCastHit();

	bool GetSightRayHitsLocation(FVector& HitLocation);

private:
	UInputComponent* InputComponent;

	
};
