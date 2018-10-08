#pragma once
#include "Sorter.h"

class BubbleSorter : public Sorter
{
public:
	BubbleSorter();
	virtual ~BubbleSorter();
	virtual void sort();
};
