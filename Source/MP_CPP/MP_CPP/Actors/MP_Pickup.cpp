// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_Pickup.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "MP_CPP/Interaction/MP_Player.h"
#include "MP_CPP/Player/MP_PlayerState.h"


AMP_Pickup::AMP_Pickup()
{
	PrimaryActorTick.bCanEverTick = false;
	bNetLoadOnClient = true;
	bReplicates = true;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("Root"));

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>("SphereMesh");
	SphereMesh->SetupAttachment(RootComponent);
	SphereMesh->SetIsReplicated(true);

	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	SphereCollision->SetupAttachment(RootComponent);
}

void AMP_Pickup::BeginPlay()
{
	Super::BeginPlay();
}

void AMP_Pickup::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (!OtherActor->HasAuthority())
	{
		return;
	}

	// This will only happen on the server.
	if (!OtherActor->Implements<UMP_Player>())
	{
		return;
	}
	IMP_Player::Execute_IncreaseHealth(OtherActor, HealthValue);

	ACharacter* OtherCharacter = Cast<ACharacter>(OtherActor);
	if (!IsValid(OtherCharacter))
	{
		return;
	}

	AMP_PlayerState* MP_PlayerState = OtherCharacter->GetPlayerState<AMP_PlayerState>();
	if (!IsValid(MP_PlayerState))
	{
		return;
	}

	MP_PlayerState->SetNumPickups(MP_PlayerState->GetNumPickups() + 1);

	Destroy();
}
