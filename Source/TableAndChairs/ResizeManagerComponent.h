// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProceduralTableMeshComponent.h"
#include "VerticesCoordinates.h"

#include "ResizeManagerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TABLEANDCHAIRS_API UResizeManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UResizeManagerComponent();
	float GetCurrentWidth() const {return FVector2D::Distance(CurrentBackLeftVertexPosition, CurrentBackRightVertexPosition);}
	float GetCurrentLength() const {return FVector2D::Distance(CurrentBackLeftVertexPosition, CurrentFrontLeftVertexPosition);}
	float GetCurrentDiagonal() const {return FVector2D::Distance(CurrentBackLeftVertexPosition, CurrentFrontRightVertexPosition);}
	FVector2D GetCenter() const;
	void MoveVertex(EVerticesCoordinates Vertex, float Value);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    UProceduralTableMeshComponent* TableMesh;
    UPROPERTY(VisibleAnywhere)
    FVector2D CurrentBackLeftVertexPosition = FVector2D::ZeroVector;
    UPROPERTY(VisibleAnywhere)
    FVector2D CurrentBackRightVertexPosition = FVector2D::ZeroVector;
    UPROPERTY(VisibleAnywhere)
    FVector2D CurrentFrontLeftVertexPosition = FVector2D::ZeroVector;
    UPROPERTY(VisibleAnywhere)
    FVector2D CurrentFrontRightVertexPosition = FVector2D::ZeroVector;

    UPROPERTY(VisibleAnywhere)
    float MinDiagonal = 0.f;
};
