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
	std::make_heap(m_vec.begin(), m_vec.end());
	std::deque<unsigned int> sorted_collection;
	while(!m_vec.empty())
	{
		std::pop_heap (m_vec.begin(),m_vec.end());
		m_vec.pop_back();
		sorted_collection.push_front(m_vec.front());
	}
	m_vec = sorted_collection;

}
