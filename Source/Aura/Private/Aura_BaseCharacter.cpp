// Copyright Yuki Shingaki


#include "Aura_BaseCharacter.h"

// Sets default values
AAura_BaseCharacter::AAura_BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAura_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAura_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAura_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

