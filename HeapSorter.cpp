#include "HeapSorter.h"
#include <queue>
#include <algorithm>
HeapSorter::HeapSorter()
{
	m_sort_name = "Heap";
}
HeapSorter::~HeapSorter()
{

}
void HeapSorter::sort()
{
	// I love the std library
	std::make_heap(m_vec.begin(), m_vec.end());
	std::sort_heap(m_vec.begin(), m_vec.end());
}
