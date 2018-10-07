#include "BubbleSorter.h"


BubbleSorter::BubbleSorter()
{

}
BubbleSorter::~BubbleSorter()
{

}
void BubbleSorter::sort()
{
	for (unsigned int ii = 0; ii < m_vec.size()-1; ++ii)
	{
		for (unsigned jj = 0; jj < m_vec.size() - ii - 1; ++jj)
		{
			if (m_vec[jj] > m_vec[jj + 1])
			{
				swap(jj, jj + 1);
			}
		}
		
	}
}