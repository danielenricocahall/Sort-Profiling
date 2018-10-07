#pragma once
#include <deque>
#include <algorithm>
#include <string>

class Sorter
{
public:
	Sorter();
	Sorter(std::deque<unsigned int>& vec);
	virtual ~Sorter();
	virtual void sort() = 0;
	virtual void setCollection(const std::deque<unsigned int>& collection);
	virtual void swap(const unsigned int ii, const unsigned int jj);
	virtual std::deque<unsigned int> getSortedCollection() const;
	std::string getName();

protected:
	std::deque<unsigned int> m_vec;
	std::string m_sort_name;
};
