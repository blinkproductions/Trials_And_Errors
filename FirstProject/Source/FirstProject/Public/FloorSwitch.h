// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "FloorSwitch.generated.h"

UCLASS()
class FIRSTPROJECT_API AFloorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorSwitch();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	void OnvOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Switch")
	void RaiseDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Switch")
	void LowerDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Switch")
	void RaiseFloorSwitch();

	UFUNCTION(BlueprintImplementableEvent, Category = "Floor Switch") // BlueprintImplementable means the function was created in CPP but will be implemented in BP in Unreal
	void LowerFloorSwitch();

	UFUNCTION(BlueprintCallable, Category = "Floor Switch") // BlueprintCallable means the BP can call it but the function was implemented in CPP
	void UpdateDoorLocation(float Z);

	UFUNCTION(BlueprintCallable, Category = "Floor Switch")
	void UpdateFloorSwitchLocation(float Z);

	/** Overlap volume for functionality to be triggered */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Floor Switch")
	UBoxComponent* TriggerBox;

	/** Switch for the character to step on */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Floor Switch")
	UStaticMeshComponent* FloorSwitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Floor Switch")
	UStaticMeshComponent* Door;

	UPROPERTY(BlueprintReadWrite, Category = "Floor Switch")
	FVector InitialDoorLocation;

	UPROPERTY(BlueprintReadWrite, Category = "Floor Switch")
	FVector InitialSwitchLocation;

	FTimerHandle SwitchHandle;

	void ClosedDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floor Switch")
	float SwitchTime;

	bool bCharacterOnSwitch;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
