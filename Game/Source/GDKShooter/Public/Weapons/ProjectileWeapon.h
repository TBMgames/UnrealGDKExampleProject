// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Weapon.h"
#include "ProjectileWeapon.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class GDKSHOOTER_API AProjectileWeapon : public AWeapon
{
	GENERATED_BODY()

public:
	AProjectileWeapon();

	virtual void StartFire() override;
	
protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Weapons")
		void OnShot();

	// Minimum time between shots in seconds.
	UPROPERTY(EditAnywhere, Category = "Weapons")
		float ShotCooldown;

	// Projectile class to fire.
	UPROPERTY(EditAnywhere, Category = "Weapons")
		TSubclassOf<class AProjectile> ProjectileClass;

	// Socket name of where to spawn projectiles
	UPROPERTY(EditAnywhere, Category = "Weapons")
		FName BarrelSocket = FName(TEXT("WP_Barrel"));

	// Time (in seconds since start of level) of the last shot. Used for limiting fire rate.
	float LastShotTime;

	UFUNCTION(reliable, server, WithValidation)
		void FireProjectile(FVector Origin, FVector_NetQuantizeNormal Direction);
	
};
