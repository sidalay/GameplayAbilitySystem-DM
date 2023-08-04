// Copyright Yuki Shingaki

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Aura_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class AURA_API AAura_Player_Controller : public APlayerController
{
	GENERATED_BODY()

public:
	AAura_Player_Controller();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
};
