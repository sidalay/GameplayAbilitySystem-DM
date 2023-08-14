// Copyright Yuki Shingaki

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Aura_EffectActor.generated.h"

class USphereComponent;

UCLASS()
class AURA_API AAura_EffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAura_EffectActor();

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;
};
