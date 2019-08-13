// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "Public/Critter.h"
#include "SpawnVolume.generated.h"

UCLASS()
class FIRSTPROJECT_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	UBoxComponent* SpawningBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	TSubclassOf<class ACritter> PawnToSpawn;

	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetSpawnPoint();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawning")
	void SpawnOurPawn(UClass* ToSpawn, const FVector& Location);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
