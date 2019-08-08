// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralChairMeshComponent.h"

#include "ProceduralChair.generated.h"

UCLASS()
class TABLEANDCHAIRS_API AProceduralChair : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralChair();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
    UProceduralChairMeshComponent* ChairMesh;

    UPROPERTY(EditAnywhere)
    float BaseEdge = 100.f;
    UPROPERTY(EditAnywhere)
    float BaseHeight = 10.f;
    UPROPERTY(EditAnywhere)
    float LegHeight = 50.f;
    UPROPERTY(EditAnywhere)
    float LegEdge = 10.f;
    UPROPERTY(EditAnywhere)
    float BackHeight = 100.f;
    UPROPERTY(EditAnywhere)
    float BackThickness = 10.f;

};
