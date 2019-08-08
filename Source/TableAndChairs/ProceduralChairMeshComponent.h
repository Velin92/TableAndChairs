// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralTableMeshComponent.h"
#include "ProceduralChairMeshComponent.generated.h"

/**
 * 
 */
UCLASS()
class TABLEANDCHAIRS_API UProceduralChairMeshComponent : public UProceduralTableMeshComponent
{
	GENERATED_BODY()

public:
    void SetBackSize(FVector NewBackSize){this->BackSize = NewBackSize;}

protected:
    virtual void GenerateMesh() override;

private:
    UPROPERTY(VisibleAnywhere)
    FVector BackSize = FVector(20.f, 200.f, 200.f);
	
};
