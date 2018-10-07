#pragma once
#include "Sorter.h"

class InsertionSorter : public Sorter
{
public:
	InsertionSorter();
	InsertionSorter(std::deque<unsigned int>& vec) : Sorter(vec) {};
	virtual ~InsertionSorter();
	virtual void sort();
};
