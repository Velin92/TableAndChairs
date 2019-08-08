// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralChair.h"

// Sets default values
AProceduralChair::AProceduralChair()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    ChairMesh = CreateDefaultSubobject<UProceduralChairMeshComponent>("ChairMesh");
    ChairMesh->SetBaseSize(FVector(BaseEdge, BaseEdge, BaseHeight));
    ChairMesh->SetLegSize(FVector(LegEdge, LegEdge, LegHeight));
    ChairMesh->SetBackSize(FVector(BackThickness, BaseEdge, BackHeight));
    SetRootComponent(ChairMesh);
    ChairMesh->bUseAsyncCooking = true;

}

// Called when the game starts or when spawned
void AProceduralChair::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProceduralChair::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

