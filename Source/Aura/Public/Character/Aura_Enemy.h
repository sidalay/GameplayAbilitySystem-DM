// Copyright Yuki Shingaki

#pragma once

#include "CoreMinimal.h"
#include "Character/Aura_BaseCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "Aura_Enemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAura_Enemy : public AAura_BaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAura_Enemy();

	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted{false};
};
