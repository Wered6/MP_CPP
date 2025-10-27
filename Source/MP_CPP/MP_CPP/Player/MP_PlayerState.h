// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MP_PlayerState.generated.h"

/**
 *
 */
UCLASS()
class MP_CPP_API AMP_PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	int32 GetNumPickups() const
	{
		return NumPickups;
	}

	void SetNumPickups(int32 Amount)
	{
		NumPickups = Amount;
	}

private:

	UPROPERTY(Replicated)
	int32 NumPickups;
};
