// Copyright Yuki Shingaki


#include "..\..\Public\Player\Aura_PlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAura_Player_Controller::AAura_Player_Controller()
{
	bReplicates = true;
}

void AAura_Player_Controller::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
	ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAura_Player_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAura_Player_Controller::Move);
}

void AAura_Player_Controller::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector{InputActionValue.Get<FVector2D>()};
	const FRotator Rotation{GetControlRotation()};
	const FRotator YawRotation{0.f, Rotation.Yaw, 0.f};

	const FVector ForwardDirection{FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X)};
	const FVector RightDirection{FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y)};

	if (APawn* ControlledPawn{GetPawn<APawn>()})
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
