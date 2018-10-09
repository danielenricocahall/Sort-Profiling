#pragma once
#include "Sorter.h"

class MergeSorter : public Sorter
{
public:
	MergeSorter(const std::deque<unsigned int>& collection, unsigned int threshold);
	MergeSorter(unsigned int threshold);
	MergeSorter() : MergeSorter(1){};
	virtual ~MergeSorter();
	virtual void sort();
	void setThreshold(const unsigned int threshold);
	void merge(std::deque<unsigned int>& left, std::deque<unsigned int>& right);

private:
	unsigned int m_threshold;


};
