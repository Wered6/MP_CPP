// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_PlayerState.h"
#include "Net/UnrealNetwork.h"

AMP_PlayerState::AMP_PlayerState()
{
	SetNetUpdateFrequency(10.f);
}

void AMP_PlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, NumPickups)
}

void AMP_PlayerState::SetNumPickups(int32 Amount)
{
	NumPickups = Amount;
	OnPickupCountChanged.Broadcast(NumPickups);
}

void AMP_PlayerState::OnRep_NumPickups()
{
	OnPickupCountChanged.Broadcast(NumPickups);
}
