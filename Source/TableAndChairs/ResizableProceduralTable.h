// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralTableMeshComponent.h"

#include "ResizableProceduralTable.generated.h"

UCLASS()
class TABLEANDCHAIRS_API AResizableProceduralTable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResizableProceduralTable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
    UProceduralTableMeshComponent* TableMesh;

    UPROPERTY(EditAnywhere)
    float BaseEdge = 200.f;
    UPROPERTY(EditAnywhere)
    float BaseHeight = 20.f;
    UPROPERTY(EditAnywhere)
    float LegHeight = 100.f;
    UPROPERTY(EditAnywhere)
    float LegEdge = 20.f;

};
