#pragma once
#include "Sorter.h"

class HeapSorter : public Sorter
{
public:
	HeapSorter();
	~HeapSorter() override;
	void sort() override;

};
