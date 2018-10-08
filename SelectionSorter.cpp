#include "SelectionSorter.h"

SelectionSorter::SelectionSorter()
{
	m_sort_name = "Selection";
}

SelectionSorter::~SelectionSorter()
{

}

void SelectionSorter::sort()
{
	for (unsigned int ii = 0; ii < m_vec.size(); ++ii)
	{
		unsigned int minIndex = ii;
		for (unsigned int jj = ii + 1; jj < m_vec.size(); ++jj)
		{
			if (m_vec[jj] < m_vec[minIndex])
			{
				minIndex = jj;
			}
		}
		if (minIndex != ii)
		{
			swap(minIndex, ii);
		}
	}
}
