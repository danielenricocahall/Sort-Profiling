#pragma once
#include "Sorter.h"

class SelectionSorter : public Sorter
{
public:
	SelectionSorter();
	~SelectionSorter() override;
	void sort() override;
};
