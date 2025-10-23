// Fill out your copyright notice in the Description page of Project Settings.


#include "MP_MultiplayerUtils.h"

void UMP_MultiplayerUtils::PrintLocalNetRole(AActor* Actor)
{
	if (Actor->HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Has Authority."), *Actor->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Does Not Have Authority."), *Actor->GetName())
	}

	switch (Actor->GetLocalRole())
	{
		case ROLE_None:
			UE_LOG(LogTemp, Warning, TEXT("Actor Role: None - No networking"))
			break;
		case ROLE_SimulatedProxy:
			UE_LOG(LogTemp, Warning, TEXT("Actor Role: Simulated Proxy - Network client receiving updates from server"))
			break;
		case ROLE_AutonomousProxy:
			UE_LOG(LogTemp, Warning, TEXT("Actor Role: Autonomous Proxy - Network client, controlled locally"))
			break;
		case ROLE_Authority:
			UE_LOG(LogTemp, Warning, TEXT("Actor Role: Authority - Server or single player"))
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT("Actor Role: Unknown role value"))
			break;
	}
}

void UMP_MultiplayerUtils::PrintRemoteNetRole(AActor* Actor)
{
	if (Actor->HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Has Authority."), *Actor->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor [%s] Does Not Have Authority."), *Actor->GetName())
	}

	switch (Actor->GetRemoteRole())
	{
		case ROLE_None:
			UE_LOG(LogTemp, Warning, TEXT("Actor Remote Role: None - No networking"))
			break;
		case ROLE_SimulatedProxy:
			UE_LOG(LogTemp, Warning, TEXT("Actor Remote Role: Simulated Proxy - Network client receiving updates from server"))
			break;
		case ROLE_AutonomousProxy:
			UE_LOG(LogTemp, Warning, TEXT("Actor Remote Role: Autonomous Proxy - Network client, controlled locally"))
			break;
		case ROLE_Authority:
			UE_LOG(LogTemp, Warning, TEXT("Actor Remote Role: Authority - Server or single player"))
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT("Actor Remote Role: Unknown role value"))
			break;
	}
}
