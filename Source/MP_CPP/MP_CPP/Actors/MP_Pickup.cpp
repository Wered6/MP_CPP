// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_Pickup.h"
#include "Components/SphereComponent.h"
#include "MP_CPP/Interaction/MP_Player.h"


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
	if (OtherActor->Implements<UMP_Player>())
	{
		IMP_Player::Execute_IncrementPickupCount(OtherActor);
		Destroy();
	}
}
