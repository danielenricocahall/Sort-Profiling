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
		// assume you're at the index of the minimum value
		unsigned int minIndex = ii;
		// look at all values to the right of you, and check if there are any lower values
		for (unsigned int jj = ii + 1; jj < m_vec.size(); ++jj)
		{
			if (m_vec[jj] < m_vec[minIndex])
			{
				// looks like you were wrong - update the minimum index with the index of the lower value
				minIndex = jj;
			}
		}
		// if there was at least one update (meaning the minimum index assumption was wrong), swap the current index with
		// the index of the lowest value
		if (minIndex != ii)
		{
			swap(minIndex, ii);
		}
	}
}
