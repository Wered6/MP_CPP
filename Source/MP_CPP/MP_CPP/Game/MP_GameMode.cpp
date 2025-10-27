// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_GameMode.h"
#include "MP_GameState.h"

AMP_GameMode::AMP_GameMode()
{
	bDelayedStart = true;
	MatchStartDelay = 5.f;
	bUseSeamlessTravel = true;
}

void AMP_GameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MatchStartTimer, this, &ThisClass::StartDelayFinished, MatchStartDelay, false);
}

void AMP_GameMode::StartMatch()
{
	Super::StartMatch();

	GEngine->AddOnScreenDebugMessage(
		1,
		5.f,
		FColor::Orange,
		"The match has started."
	);
}

void AMP_GameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	AMP_GameState* MP_GameState = GetGameState<AMP_GameState>();
	if (IsValid(MP_GameState))
	{
		MP_GameState->AddTeamMember(NewPlayer);
	}
}

void AMP_GameMode::StartDelayFinished()
{
	StartMatch();
}
