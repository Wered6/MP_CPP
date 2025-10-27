// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MP_GameState.generated.h"

/**
 *
 */
UCLASS()
class MP_CPP_API AMP_GameState : public AGameState
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void AddTeamMember(APlayerController* PlayerController);

	bool IsTeamOne(APlayerController* PlayerController) const;

private:
	UPROPERTY(Replicated)
	TArray<TObjectPtr<APlayerController>> TeamOne;

	UPROPERTY(Replicated)
	TArray<TObjectPtr<APlayerController>> TeamTwo;
};
