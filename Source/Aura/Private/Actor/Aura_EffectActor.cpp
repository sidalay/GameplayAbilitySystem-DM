// Copyright Yuki Shingaki


#include "Actor/Aura_EffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/Aura_AttributeSet.h"
#include "Components/SphereComponent.h"

AAura_EffectActor::AAura_EffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");

	SetRootComponent(Mesh);
	Sphere->SetupAttachment(GetRootComponent());

}

void AAura_EffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAura_AttributeSet* AuraAttributeSet{Cast<UAura_AttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAura_AttributeSet::StaticClass()))};
		UAura_AttributeSet* MutableAuraAttributeSet{const_cast<UAura_AttributeSet*>(AuraAttributeSet)};
		MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void AAura_EffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AAura_EffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAura_EffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAura_EffectActor::EndOverlap);
}

