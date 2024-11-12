#include "GarbageCharacter.h"

#include "GCTest/Private/Garbage/GarbageObject.h"

AGarbageCharacter::AGarbageCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGarbageCharacter::BeginPlay()
{
	Super::BeginPlay();

	CreateGarbageObjects();
	SetTimer();
}

void AGarbageCharacter::SetTimer()
{
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(LogHandle, this, &AGarbageCharacter::LogTimerDelegate, 2.f, true);
	UE_LOG(LogTemp, Warning, TEXT("Timers set"));
}

void AGarbageCharacter::CreateGarbageObjects()
{
	GarbageRawPointer = NewObject<UGarbageObject>();
	GarbageTObjectPtr = NewObject<UGarbageObject>();
	GarbageTArray.Add(NewObject<UGarbageObject>());
	GarbageUProperty = NewObject<UGarbageObject>();
	GarbageUPropertyWeakPtr = NewObject<UGarbageObject>();

	IsValid(GarbageRawPointer);
	IsValid(GarbageTObjectPtr);
	GarbageRawPointer->IsValidLowLevel();
}

void AGarbageCharacter::LogTimerDelegate() const
{
	UE_LOG(LogTemp, Warning, TEXT("GarbageRawPointer: %p, %d"), GarbageRawPointer, GarbageRawPointer->IsValidLowLevel());
	UE_LOG(LogTemp, Warning, TEXT("GarbageTObjectPtr: %p, %d"), GarbageTObjectPtr.Get(), GarbageTObjectPtr->IsValidLowLevel());
	UE_LOG(LogTemp, Warning, TEXT("GarbageTArray: %p, %d"), GarbageTArray[0], GarbageTArray[0]->IsValidLowLevel());
	UE_LOG(LogTemp, Warning, TEXT("GarbageUProperty: %p, %d"), GarbageUProperty.Get(), GarbageUProperty->IsValidLowLevel());
	UE_LOG(LogTemp, Warning, TEXT("GarbageUPropertyWeakPtr: %p, %d"), GarbageUPropertyWeakPtr.Get(), GarbageUPropertyWeakPtr->IsValidLowLevel());

	GEngine->ForceGarbageCollection(true);
}

void AGarbageCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGarbageCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

