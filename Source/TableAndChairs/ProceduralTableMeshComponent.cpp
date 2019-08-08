// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralTableMeshComponent.h"

void UProceduralTableMeshComponent::OnComponentCreated()
{
    Super::OnComponentCreated();
    GenerateMesh();
}

void UProceduralTableMeshComponent::GenerateParallelepiped(int32 SectionId, FVector Size, FVector Offset)
{
    TArray<FVector> Vertices;
    Vertices.Add(Offset + FVector(-Size.X/2, -Size.Y/2, -Size.Z/2)); //lower left - 0
    Vertices.Add(Offset + FVector(-Size.X/2, -Size.Y/2, Size.Z/2)); //upper left - 1
    Vertices.Add(Offset + FVector(-Size.X/2, Size.Y/2, -Size.Z/2)); //lower right - 2
    Vertices.Add(Offset + FVector(-Size.X/2, Size.Y/2, Size.Z/2)); //upper right - 3

    Vertices.Add(Offset + FVector(Size.X/2, -Size.Y/2, -Size.Z/2)); //lower front left - 4
    Vertices.Add(Offset + FVector(Size.X/2, -Size.Y/2, Size.Z/2)); //upper front left - 5
    Vertices.Add(Offset + FVector(Size.X/2, Size.Y/2, Size.Z/2)); //upper front right - 6
    Vertices.Add(Offset + FVector(Size.X/2, Size.Y/2, -Size.Z/2)); //lower front right - 7

    TArray<int32> Triangles;
    //Back face
    AddTriangle(0, 2, 3, Triangles);
    AddTriangle(3, 1, 0, Triangles);

    //Left face of cube
    AddTriangle(0, 1, 4, Triangles);
    AddTriangle(4, 1, 5, Triangles);

    //Front face of cube
    AddTriangle(4, 5, 7, Triangles);
    AddTriangle(7, 5, 6, Triangles);

    //Right face of cube
    AddTriangle(7, 6, 3, Triangles);
    AddTriangle(3, 2, 7, Triangles);

    //Top face
    AddTriangle(1, 3, 5, Triangles);
    AddTriangle(6, 5, 3, Triangles);

    //bottom face
    AddTriangle(2, 0, 4, Triangles);
    AddTriangle(4, 7, 2, Triangles);

    CreateMeshSection_LinearColor(SectionId, Vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FLinearColor>(), TArray<FProcMeshTangent>(),true);
}

void UProceduralTableMeshComponent::GenerateMesh()
{
    GenerateParallelepiped(0, BaseSize, FVector::ZeroVector);

    float ZLegPosition = -BaseSize.Z/2 -LegSize.Z/2;
    float XLegPosition = BaseSize.X/2 - LegSize.X/2;
    float YLegPosition = BaseSize.Y/2 - LegSize.Y/2;

    FVector BackLeftLegOffset = FVector (-XLegPosition, -YLegPosition, ZLegPosition);
    GenerateParallelepiped(1, LegSize, BackLeftLegOffset);

    FVector BackRightLegOffset = FVector (-XLegPosition, YLegPosition, ZLegPosition);
    GenerateParallelepiped(2, LegSize, BackRightLegOffset);

    FVector FrontLeftLegOffset = FVector (XLegPosition, -YLegPosition, ZLegPosition);
    GenerateParallelepiped(3, LegSize, FrontLeftLegOffset);

    FVector FrontRightLegOffset = FVector (XLegPosition, YLegPosition, ZLegPosition);
    GenerateParallelepiped(4, LegSize, FrontRightLegOffset);
}

//the order must be in counterclockwise according to the showed surface (RIGHT HAND RULE SHOWS VISIBLE SURFACE)
void UProceduralTableMeshComponent::AddTriangle(int32 FirstVertex, int32 SecondVertex, int32 ThirdVertex, TArray<int32> &Triangles)
{
    Triangles.Add(FirstVertex);
    Triangles.Add(SecondVertex);
    Triangles.Add(ThirdVertex);
}
