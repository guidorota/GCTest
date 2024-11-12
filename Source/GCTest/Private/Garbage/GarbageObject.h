#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GarbageObject.generated.h"

UCLASS()
class UGarbageObject : public UObject
{
	GENERATED_BODY()

	virtual void FinishDestroy() override;
};
