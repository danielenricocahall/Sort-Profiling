#pragma once
#include <deque>
#include <algorithm>

class Sorter
{
public:
	Sorter();
	Sorter(std::deque<unsigned int>& vec);
	virtual ~Sorter();
	virtual void sort() = 0;
	virtual void swap(const unsigned int ii, const unsigned int jj);
	virtual std::deque<unsigned int> getSortedCollection() const;

protected:
	std::deque<unsigned int> m_vec;
};