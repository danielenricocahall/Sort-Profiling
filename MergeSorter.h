#pragma once
#include "Sorter.h"

class MergeSorter : public Sorter
{
public:
	MergeSorter();
	MergeSorter(const std::deque<unsigned int>& collection, const unsigned int threshold = 1);
	MergeSorter(const unsigned int threshold = 1);
	virtual ~MergeSorter();
	virtual void sort();
	void setThreshold(const unsigned int threshold);
	void merge(std::deque<unsigned int>& left, std::deque<unsigned int>& right);

private:
	unsigned int m_threshold;


};
