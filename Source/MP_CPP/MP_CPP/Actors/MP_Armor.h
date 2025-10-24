// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MP_Armor.generated.h"

class USphereComponent;

UCLASS()
class MP_CPP_API AMP_Armor : public AActor
{
	GENERATED_BODY()

public:
	AMP_Armor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> SphereMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BootMesh_L;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BootMesh_R;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereCollision;
};
