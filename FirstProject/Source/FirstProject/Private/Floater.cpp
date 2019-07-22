// Fill out your copyright notice in the Description page of Project Settings.

#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("MyMesh"));
	SetRootComponent(StaticMesh);

	InitialLocation = FVector(0.f);
	PlacedLocation = FVector(0.f);
	WorldOrigin = FVector(0.f);

	InitialDirection = FVector(0.f, 0.f, 0.f);

	bInitializeFloaterLocations = false;
	bShouldFloat = false;

	InitialForce = FVector(200000.f, 0.f, 0.f);
	InitialTorque = FVector(200000.f, 0.f, 0.f);

	RunningTime = 0.f;
	Amplitude = 1.f;
	Oscillations = 1.f;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();
	
	float InitialX = FMath::FRandRange(-500.f, 500.f);
	float InitialY = FMath::FRandRange(-500.f, 500.f);
	float InitialZ = FMath::FRandRange(0.f, 500.f);

	InitialLocation.X = InitialX;
	InitialLocation.Y = InitialY;
	InitialLocation.Z = InitialZ;

	PlacedLocation = GetActorLocation();

	if (bInitializeFloaterLocations)
	{
		SetActorLocation(InitialLocation);
	}
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat)
	{
		FVector NewLocation = GetActorLocation();

		NewLocation.X = NewLocation.X + (Amplitude) * FMath::Sin((Oscillations) * RunningTime);
		NewLocation.Z = NewLocation.Z + (Amplitude)* FMath::Cos((Oscillations)* RunningTime);

		SetActorLocation(NewLocation);
		RunningTime += DeltaTime;
		UE_LOG(LogTemp, Warning, TEXT("Running Time = %f"), RunningTime)
	}
}

