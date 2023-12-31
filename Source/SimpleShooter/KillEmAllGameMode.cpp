// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"
#include "Kismet\GameplayStatics.h"
#include "ShooterCharacter.h"


void AKillEmAllGameMode::PawnKilled(APawn* PanwKilled)
{
	Super::PawnKilled(PanwKilled);

	APlayerController* PlayerController = Cast<APlayerController>(PanwKilled->GetController());
	if (PlayerController != nullptr)
	{
		EndGame(false);
	}
	AShooterAIController* ShooterController = Cast<AShooterAIController>(PanwKilled->GetController());
	if (ShooterController != nullptr)
	{
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		AShooterCharacter* PlayerCharacter = Cast<AShooterCharacter>(PlayerPawn);
		if (PlayerCharacter != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("ADD HELING!!"));
			PlayerCharacter->AddHealth(HealingValue);
		}
	}
	for (AShooterAIController* ShooterAIController : TActorRange<AShooterAIController>(GetWorld()))
	{
		if (!ShooterAIController->IsDead())
		{
			return;
		}
	}
	EndGame(true);

}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);

	}
}
