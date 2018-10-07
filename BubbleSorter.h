#pragma once
#include "Sorter.h"

class BubbleSorter : public Sorter
{
public:
	BubbleSorter();
	BubbleSorter(std::deque<unsigned int>& vec) : Sorter(vec) {};
	virtual ~BubbleSorter();
	virtual void sort();
};