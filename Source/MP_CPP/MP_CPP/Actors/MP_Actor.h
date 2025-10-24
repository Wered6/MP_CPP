// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MP_Actor.generated.h"

UCLASS()
class MP_CPP_API AMP_Actor : public AActor
{
	GENERATED_BODY()

public:
	AMP_Actor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(Client, Reliable)
	void Client_PrintActorName();
};
