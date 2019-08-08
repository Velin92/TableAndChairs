// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "ProceduralTableMeshComponent.generated.h"

/**
 * 
 */
UCLASS()
class TABLEANDCHAIRS_API UProceduralTableMeshComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()
public:
    void SetBaseSize(FVector NewBaseSize) {this->BaseSize = NewBaseSize;}
    void SetLegSize(FVector NewLegSize) {this->LegSize = NewLegSize;}
    FVector GetBaseSize() const {return BaseSize;}

protected:
    UPROPERTY(VisibleAnywhere)
    FVector BaseSize = FVector(200.f, 200.f, 20.f);
    UPROPERTY(VisibleAnywhere)
    FVector LegSize = FVector(20.f,20.f, 100.f);
    virtual void GenerateMesh();
    virtual void OnComponentCreated() override;
    void GenerateParallelepiped (int32 SectionId, FVector Size, FVector Offset);

private:
    void AddTriangle(int32 FirstVertex, int32 SecondVertex, int32 ThirdVertex, TArray<int32>& Triangles);
};
