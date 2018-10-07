#pragma once
#include "Sorter.h"

class HeapSorter : public Sorter
{
public:
	HeapSorter();
	HeapSorter(std::deque<unsigned int>&vec) : Sorter(vec) {};
	virtual ~HeapSorter();
	virtual void sort();

};