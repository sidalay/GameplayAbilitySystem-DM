// Copyright Yuki Shingaki

#pragma once

#include "CoreMinimal.h"
#include "Character/Aura_BaseCharacter.h"
#include "Aura_Character.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAura_Character : public AAura_BaseCharacter
{
	GENERATED_BODY()

public:
	AAura_Character();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};
