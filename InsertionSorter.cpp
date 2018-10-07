#include "InsertionSorter.h"

InsertionSorter::InsertionSorter()
{

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
			swap(jj, jj - 1);
			--jj;
		}
	}
}