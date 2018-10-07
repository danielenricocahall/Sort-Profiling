#include "MergeSorter.h"

MergeSorter::MergeSorter()
{
	m_sort_name = "Merge";
}

MergeSorter::~MergeSorter()
{

}

void MergeSorter::sort()
{
	if (m_vec.size() > 1)
	{
		std::size_t const half_size = m_vec.size() / 2;
		std::deque<unsigned int> left_half(m_vec.begin(), m_vec.begin() + half_size);
		std::deque<unsigned int> right_half(m_vec.begin() + half_size, m_vec.end());
		MergeSorter left_sorter = MergeSorter(left_half);
		MergeSorter right_sorter = MergeSorter(right_half);
		left_sorter.sort();
		right_sorter.sort();
		left_half = left_sorter.getSortedCollection();
		right_half = right_sorter.getSortedCollection();
		merge(left_half, right_half);
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
