// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	class UParticleSystem* MuzzleFlash;
	
	UPROPERTY(EditAnywhere)
	class USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere)
	class UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere)
	class USoundBase* ImpactSound;
	/**
	 *  @param  MaxRange     Maximum shooting distance;
	 */
	UPROPERTY(EditAnywhere)
	float MaxRange = 10000.f;

	UPROPERTY(EditAnywhere)
	float Damage = 10.f;

	/** Is Hit by Gun
	 * @param Hit - struct FHitResult
	 * @param ShotDirection - FVector for storage direction from hit to Gun.
	 */
	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);
	//Get Controller from Gun Owner.
	AController* GetOwnerController() const;
};
