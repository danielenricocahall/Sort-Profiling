#pragma once
#include "Sorter.h"

class InsertionSorter : public Sorter
{
public:
	InsertionSorter();
	~InsertionSorter() override;
	void sort() override;
};
