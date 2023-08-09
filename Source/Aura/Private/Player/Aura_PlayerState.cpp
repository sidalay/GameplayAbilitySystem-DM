// Copyright Yuki Shingaki


#include "Player/Aura_PlayerState.h"

#include "AbilitySystem/Aura_AbilitySystemComponent.h"
#include "AbilitySystem/Aura_AttributeSet.h"

AAura_PlayerState::AAura_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAura_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UAura_AttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AAura_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
