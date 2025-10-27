// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_PlayerState.h"
#include "Net/UnrealNetwork.h"

void AMP_PlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, NumPickups)
}
