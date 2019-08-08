// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralChairMeshComponent.h"

void UProceduralChairMeshComponent::GenerateMesh()
{
    Super::GenerateMesh();

    FVector BackOffset = FVector(-BaseSize.X/2 + BackSize.X/2, 0.f, BaseSize.Z/2 + BackSize.Z/2);
    GenerateParallelepiped(5, BackSize, BackOffset);
}