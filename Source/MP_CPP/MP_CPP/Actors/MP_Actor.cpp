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

	if (HasAuthority())
	{
		Client_PrintActorName();
	}
}

void AMP_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMP_Actor::Client_PrintActorName_Implementation()
{
	FString MessageString = HasAuthority() ? "Server: " : "Client: ";
	MessageString += GetName();

	GEngine->AddOnScreenDebugMessage(
		-1,
		5.f,
		FColor::Yellow,
		MessageString
	);
}
