#include "TD2020.h"
#include "TD2020ProductionQueue.h"


TSubclassOf<AActor> FTD2020ProductionQueue::operator[](int32 Index) const
{
	return Queue[Index];
}

void FTD2020ProductionQueue::Add(TSubclassOf<AActor> Product)
{
	Queue.Add(Product);
}

int32 FTD2020ProductionQueue::Num() const
{
	return Queue.Num();
}

void FTD2020ProductionQueue::RemoveAt(int32 Index)
{
	// Advance all products.
	int32 Slots = Queue.Num();

	for (int32 SlotToUpdate = Index; SlotToUpdate < Slots - 1; ++SlotToUpdate)
	{
		Queue[SlotToUpdate] = Queue[SlotToUpdate + 1];
	}

	Queue.RemoveAt(Slots - 1);
}
