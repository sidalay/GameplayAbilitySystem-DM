// Copyright Yuki Shingaki


#include "Character/Aura_Enemy.h"

#include "..\..\Public\AbilitySystem\Aura_AttributeSet.h"
#include "AbilitySystem/Aura_AbilitySystemComponent.h"
#include "Aura/Aura.h"

AAura_Enemy::AAura_Enemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	AbilitySystemComponent = CreateDefaultSubobject<UAura_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UAura_AttributeSet>("AttributeSet");
}

void AAura_Enemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	Weapon->SetRenderCustomDepth(true);
}

void AAura_Enemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
