// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_Armor.h"

#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"


AMP_Armor::AMP_Armor()
{
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("Root"));

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>("SphereMesh");
	SphereMesh->SetupAttachment(RootComponent);
	SphereMesh->SetIsReplicated(true);

	BootMesh_L = CreateDefaultSubobject<UStaticMeshComponent>("BootMesh_L");
	BootMesh_L->SetupAttachment(RootComponent);
	BootMesh_L->SetIsReplicated(true);

	BootMesh_R = CreateDefaultSubobject<UStaticMeshComponent>("BootMesh_R");
	BootMesh_R->SetupAttachment(RootComponent);
	BootMesh_R->SetIsReplicated(true);

	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	SphereCollision->SetupAttachment(RootComponent);
}

void AMP_Armor::BeginPlay()
{
	Super::BeginPlay();
}

void AMP_Armor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMP_Armor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	ACharacter* OverlappedCharacter = Cast<ACharacter>(OtherActor);

	if (HasAuthority() && IsValid(OverlappedCharacter))
	{
		SphereMesh->AttachToComponent(OverlappedCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "S_Head");
		BootMesh_L->AttachToComponent(OverlappedCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "S_Foot_L");
		BootMesh_R->AttachToComponent(OverlappedCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "S_Foot_R");
	}
}
