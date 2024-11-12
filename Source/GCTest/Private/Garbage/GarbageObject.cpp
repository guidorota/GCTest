#include "GarbageObject.h"

void UGarbageObject::FinishDestroy()
{
	UE_LOG(LogTemp, Warning, TEXT("Finishing destroying GarbageObject"));
	UObject::FinishDestroy();
}
