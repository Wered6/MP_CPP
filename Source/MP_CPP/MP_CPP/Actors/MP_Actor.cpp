// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_Actor.h"


AMP_Actor::AMP_Actor()
{
	PrimaryActorTick.bCanEverTick = true;

	bNetLoadOnClient = true;
	bReplicates = true;
	SetReplicatingMovement(true);
}

void AMP_Actor::BeginPlay()
{
	Super::BeginPlay();
}

void AMP_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
