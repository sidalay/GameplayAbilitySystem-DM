// Copyright Yuki Shingaki


#include "Character/Aura_BaseCharacter.h"

AAura_BaseCharacter::AAura_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AAura_BaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAura_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

