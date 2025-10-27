// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_GameMode.h"

AMP_GameMode::AMP_GameMode()
{
	bDelayedStart = true;
	MatchStartDelay = 5.f;
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

void AMP_GameMode::StartDelayFinished()
{
	StartMatch();
}
