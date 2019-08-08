// Fill out your copyright notice in the Description page of Project Settings.

#include "ResizableProceduralTable.h"

// Sets default values
AResizableProceduralTable::AResizableProceduralTable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    TableMesh = CreateDefaultSubobject<UProceduralTableMeshComponent>("TableMesh");
    TableMesh->SetLegSize(FVector(LegEdge, LegEdge, LegHeight));
    TableMesh->SetBaseSize(FVector(BaseEdge,BaseEdge,BaseHeight));

    SetRootComponent(TableMesh);
    TableMesh->bUseAsyncCooking = true;

}

// Called when the game starts or when spawned
void AResizableProceduralTable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AResizableProceduralTable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

