// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Delegates/Delegate.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXPERISITPROJECT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

	UFUNCTION(BlueprintCallable, Category = "Health")
	void ModifyHealth(float HealthDelta);

	UFUNCTION(BlueprintCallable, Category = "Health")
	FORCEINLINE	float GetHealth() { return CurrentHealth; }

	//Testing purposes only
	UFUNCTION(BlueprintCallable, Category = "Health")
	FORCEINLINE void SetHealth(float NewHealth) { CurrentHealth = NewHealth; }

protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth = 20.f;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnDeath OnDeath;

private:


		
};
