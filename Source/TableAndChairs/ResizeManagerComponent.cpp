// Fill out your copyright notice in the Description page of Project Settings.

#include "ResizeManagerComponent.h"

// Sets default values for this component's properties
UResizeManagerComponent::UResizeManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UResizeManagerComponent::BeginPlay()
{
	Super::BeginPlay();
    TableMesh = GetOwner()->FindComponentByClass<UProceduralTableMeshComponent>();
    if (!TableMesh)
    {
        UE_LOG(LogTemp, Error, TEXT("ProceduralTableMeshComponent Not Found"))
        return;
    }

    FVector StartPosition = GetOwner()->GetTransform().GetLocation();
    CurrentBackLeftVertexPosition = FVector2D(StartPosition.X - TableMesh->GetBaseSize().X/2,
            StartPosition.Y - TableMesh->GetBaseSize().Y/2);
    CurrentBackRightVertexPosition = FVector2D(StartPosition.X - TableMesh->GetBaseSize().X/2,
            StartPosition.Y + TableMesh->GetBaseSize().Y/2);
    CurrentFrontLeftVertexPosition = FVector2D(StartPosition.X + TableMesh->GetBaseSize().X/2,
            StartPosition.Y - TableMesh->GetBaseSize().Y/2);
    CurrentFrontRightVertexPosition = FVector2D(StartPosition.X + TableMesh->GetBaseSize().X/2,
            StartPosition.Y + TableMesh->GetBaseSize().Y/2);
    MinDiagonal =  GetCurrentDiagonal();
	// ...
}

FVector2D UResizeManagerComponent::GetCenter() const
{
    float X = (CurrentFrontRightVertexPosition.X + CurrentBackLeftVertexPosition.X)/2;
    float Y = (CurrentFrontRightVertexPosition.Y + CurrentBackLeftVertexPosition.Y)/2;
    return FVector2D(X,Y);
}

// Called every frame
void UResizeManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UResizeManagerComponent::MoveVertex(EVerticesCoordinates Vertex, float Value)
{
    switch (Vertex)
    {
        case EVerticesCoordinates::BackLeft:{
            FVector2D NewBackLeftVertexPosition = CurrentBackLeftVertexPosition + FVector2D(-Value, -Value);
            if (FVector2D::Distance(NewBackLeftVertexPosition, CurrentFrontRightVertexPosition) <= MinDiagonal) {
                return;
            }
            CurrentBackLeftVertexPosition = NewBackLeftVertexPosition;
            CurrentBackRightVertexPosition = CurrentBackRightVertexPosition + FVector2D(0.f, -Value);
            CurrentFrontLeftVertexPosition = CurrentFrontLeftVertexPosition + FVector2D(-Value, 0.f);
            break;
        }

        case EVerticesCoordinates::BackRight:{
            FVector2D NewBackRightVertexPosition = CurrentBackRightVertexPosition + FVector2D(-Value, Value);
            if (FVector2D::Distance(NewBackRightVertexPosition, CurrentFrontLeftVertexPosition) <= MinDiagonal) {
                return;
            }
            CurrentBackRightVertexPosition = NewBackRightVertexPosition;
            CurrentBackLeftVertexPosition = CurrentBackLeftVertexPosition + FVector2D(0.f, Value);
            CurrentFrontRightVertexPosition = CurrentFrontRightVertexPosition + FVector2D(-Value, 0.f);
            break;
        }

        case EVerticesCoordinates::FrontLeft: {
            FVector2D NewFrontLeftVertexPosition = CurrentFrontLeftVertexPosition + FVector2D(Value, -Value);
            if (FVector2D::Distance(NewFrontLeftVertexPosition, CurrentBackRightVertexPosition) <= MinDiagonal) {
                return;
            }
            CurrentFrontLeftVertexPosition = NewFrontLeftVertexPosition;
            CurrentBackLeftVertexPosition = CurrentBackLeftVertexPosition + FVector2D(0.f, -Value);
            CurrentFrontRightVertexPosition = CurrentBackRightVertexPosition + FVector2D(Value, 0.f);
            break;
        }
        case EVerticesCoordinates::FrontRight: {
            FVector2D NewFrontRightVertexPosition = CurrentFrontRightVertexPosition + FVector2D(Value, Value);
            if (FVector2D::Distance(NewFrontRightVertexPosition, CurrentBackLeftVertexPosition) <= MinDiagonal) {
                return;
            }
            CurrentFrontRightVertexPosition = NewFrontRightVertexPosition;
            CurrentBackRightVertexPosition = CurrentBackRightVertexPosition + FVector2D(0.f, Value);
            CurrentFrontLeftVertexPosition = CurrentFrontRightVertexPosition + FVector2D(Value, 0.f);
            break;
        }
    }
}

