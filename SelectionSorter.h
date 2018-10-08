#pragma once
#include "Sorter.h"

class SelectionSorter : public Sorter
{
public:
	SelectionSorter();
	virtual ~SelectionSorter();
	virtual void sort();
};
