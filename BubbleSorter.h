#pragma once
#include "Sorter.h"

class BubbleSorter : public Sorter
{
public:
	BubbleSorter();
	~BubbleSorter() override;
	void sort() override;
};
