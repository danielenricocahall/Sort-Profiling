#pragma once
#include "Sorter.h"

class HeapSorter : public Sorter
{
public:
	HeapSorter();
	virtual ~HeapSorter();
	virtual void sort();

};
