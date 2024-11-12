#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GarbageCharacter.generated.h"

class UGarbageObject;

UCLASS()
class AGarbageCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGarbageCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:

	UGarbageObject* GarbageRawPointer;
	TObjectPtr<UGarbageObject> GarbageTObjectPtr;
	TArray<UGarbageObject*> GarbageTArray;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UGarbageObject> GarbageUProperty;

	UPROPERTY(VisibleAnywhere)
	TWeakObjectPtr<UGarbageObject> GarbageUPropertyWeakPtr;
	
	FTimerHandle LogHandle;

	void SetTimer();
	void CreateGarbageObjects();
	void LogTimerDelegate() const;

};
