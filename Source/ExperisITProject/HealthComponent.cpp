// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	// PrimaryComponentTick.bCanEverTick = true;

	CurrentHealth = MaxHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	//if (GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString("Health: " + FString::SanitizeFloat(GetHealth())));
	//}
}

void UHealthComponent::ModifyHealth(float HealthDelta)
{
	CurrentHealth += HealthDelta;
	CurrentHealth = FMath::Clamp(CurrentHealth, 0.f, MaxHealth);

	if (CurrentHealth == 0)
	{
		OnDeath.Broadcast();
	}

}

