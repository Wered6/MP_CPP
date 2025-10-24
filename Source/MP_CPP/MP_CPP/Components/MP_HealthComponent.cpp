// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_HealthComponent.h"
#include "Net/UnrealNetwork.h"


UMP_HealthComponent::UMP_HealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMP_HealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UMP_HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UMP_HealthComponent::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ThisClass, Health)
}

void UMP_HealthComponent::OnRep_Health()
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.f,
		FColor::Green,
		FString::Printf(TEXT("Health: %f"), Health)
	);
}
