#include "MergeSorter.h"
#include "SorterFactory.h"
#include <iostream>


MergeSorter::MergeSorter(unsigned int threshold)
{
	m_threshold = threshold;
	m_sort_name = std::string("Merge_" + std::to_string(m_threshold));

}

MergeSorter::MergeSorter(const std::deque<unsigned int>& collection, unsigned int threshold)
{
	m_vec = collection;
	m_threshold = threshold;
	m_sort_name = std::string("Merge_" + std::to_string(m_threshold));
}

MergeSorter::~MergeSorter()
{

}

void MergeSorter::sort()
{
	if (m_vec.size() > m_threshold)
	{
		std::size_t const half_size = m_vec.size() / 2;
		std::deque<unsigned int> left_half(m_vec.begin(), m_vec.begin() + half_size);
		std::deque<unsigned int> right_half(m_vec.begin() + half_size, m_vec.end());
		MergeSorter left_sorter = MergeSorter(left_half, m_threshold);
		MergeSorter right_sorter = MergeSorter(right_half, m_threshold);
		left_sorter.sort();
		right_sorter.sort();
		left_half = left_sorter.getSortedCollection();
		right_half = right_sorter.getSortedCollection();
		merge(left_half, right_half);
	}
	else
	{
		Sorter * sorter = SorterFactory::getInstance().createSorter(SorterFactory::SortType::SELECTION);
		sorter->setCollection(m_vec);
		sorter->sort();
		m_vec = sorter->getSortedCollection();
		delete sorter;

	}

}

void MergeSorter::merge(std::deque<unsigned int>& left, std::deque<unsigned int>& right)
{
	m_vec.clear();
	while (!left.empty() && !right.empty())
	{
		if (left.front() > right.front())
		{
			m_vec.push_back(right.front());
			right.pop_front();
		}
		else
		{
			m_vec.push_back(left.front());
			left.pop_front();
		}
	}
	while (!left.empty())
	{
		m_vec.push_back(left.front());
		left.pop_front();
	}
	while (!right.empty())
	{
		m_vec.push_back(right.front());
		right.pop_front();
	}
}
