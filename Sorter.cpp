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

/*
//
void Sorter::swap(const unsigned int ii, const unsigned int jj)
{
	// ensure we're not doing anything stupid
	if (ii < m_vec.size() && jj < m_vec.size())
	{
		// who needs temporary variables? Not this guy!
		m_vec[ii] = m_vec[ii] + m_vec[jj];
		m_vec[jj] = m_vec[ii] - m_vec[jj];
		m_vec[ii] = m_vec[ii] - m_vec[jj];
	}
}*/

std::deque<unsigned int> Sorter::getSortedCollection() const
{
	return m_vec;
}

void Sorter::setCollection(const std::deque<unsigned int>& collection)
{
	m_vec = collection;
}

std::string Sorter::getName()
{
	return m_sort_name;
}
