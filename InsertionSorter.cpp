#include "InsertionSorter.h"

InsertionSorter::InsertionSorter()
{
	m_sort_name = "Insertion";
}

InsertionSorter::~InsertionSorter()
{

}

void InsertionSorter::sort()
{
	for (unsigned int ii = 1; ii < m_vec.size(); ++ii)
	{
		unsigned int jj = ii;
		while (jj > 0 && m_vec[jj - 1] > m_vec[jj])
		{
			std::swap(m_vec[jj], m_vec[jj-1]);
			--jj;
		}
	}
}
