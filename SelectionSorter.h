#pragma once
#include "Sorter.h"

class SelectionSorter : public Sorter
{
public:
	SelectionSorter();
	SelectionSorter(std::deque<unsigned int>& vec) : Sorter(vec) {};
	virtual ~SelectionSorter();
	virtual void sort();
};