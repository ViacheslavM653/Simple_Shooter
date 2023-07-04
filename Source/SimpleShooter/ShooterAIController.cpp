// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"


void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AShooterAIController::IsDead() const
{
	AShooterCharacter* ControlledCahracher = Cast<AShooterCharacter>(GetPawn());
	if (ControlledCahracher != nullptr)
	{
		return ControlledCahracher->IsDead();
	}
	return true;
}

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		if (GetBlackboardComponent() != nullptr)
		{
			if (GetPawn() != nullptr)
			{
				GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
			}
			
			
		}
	}
	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	//SetFocus(PlayerPawn, EAIFocusPriority::Gameplay);

}