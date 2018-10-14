#include "Sorter.h"


Sorter::Sorter()
{
	m_vec = std::deque<unsigned int>();
}

Sorter::Sorter(std::deque<unsigned int>& vec)
{
	m_vec = vec;
}

Sorter::~Sorter()
{
	m_vec.clear();
}

std::deque<unsigned int> Sorter::getSortedCollection() const
{
	return m_vec;
}

void Sorter::setCollection(const std::deque<unsigned int>& collection)
{
	m_vec = collection;
}

std::string Sorter::getName() const
{
	return m_sort_name;
}
