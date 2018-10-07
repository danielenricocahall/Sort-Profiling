#pragma once
#include "Sorter.h"

class MergeSorter : public Sorter
{
public:
	MergeSorter();
	MergeSorter(std::deque<unsigned int>& vec) : Sorter(vec) {};
	virtual ~MergeSorter();
	virtual void sort();
	void merge(std::deque<unsigned int>& left, std::deque<unsigned int>& right);


};