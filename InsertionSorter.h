#pragma once
#include "Sorter.h"

class InsertionSorter : public Sorter
{
public:
	InsertionSorter();
	virtual ~InsertionSorter();
	virtual void sort();
};
