#include "TD2020.h"
#include "TD2020SelectableComponent.h"


void UTD2020SelectableComponent::SelectActor()
{
	if (bSelected)
	{
		return;
	}

	bSelected = true;

	// Notify listeners.
	OnSelected.Broadcast();
}

void UTD2020SelectableComponent::DeselectActor()
{
	if (!bSelected)
	{
		return;
	}

	bSelected = false;

	// Notify listeners.
	OnDeselected.Broadcast();
}

bool UTD2020SelectableComponent::IsSelected()
{
	return bSelected;
}
