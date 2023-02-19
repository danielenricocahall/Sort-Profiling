#include "BubbleSorter.h"


BubbleSorter::BubbleSorter()
{
	m_sort_name = "Bubble";
}
BubbleSorter::~BubbleSorter()
= default;
void BubbleSorter::sort()
{
	bool sorted = false;
	while(!sorted)
	{
		sorted = true;
		for (unsigned int ii = 0; ii < m_vec.size()-1; ++ii)
		{
			if (m_vec[ii] > m_vec[ii + 1])
			{
				std::swap(m_vec[ii], m_vec[ii+1]);
				sorted = false;
			}

		}
	}
}
