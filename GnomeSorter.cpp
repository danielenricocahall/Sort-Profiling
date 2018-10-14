#include "GnomeSorter.h"
#include <algorithm>


GnomeSorter::GnomeSorter()
{
	m_sort_name = "Gnome";
}

GnomeSorter::~GnomeSorter()
{

}


// Gnome sort is just the poor man's Insertion Sort
// But look ma, no nested loops!
void GnomeSorter::sort()
{
	for(int ii = 0; ii < m_vec.size(); )
	{
		if(m_vec[ii] > m_vec[ii+1])
		{
			std::swap(m_vec[ii], m_vec[ii+1]);
			ii = std::max(0, ii-1); // decrement but enforce boundary condition
		}
		else
		{
			++ii;

		}
	}
}
