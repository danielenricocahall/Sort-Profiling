#include "BubbleSorter.h"
#include "InsertionSorter.h"
#include "SelectionSorter.h"
#include "MergeSorter.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>


std::deque<unsigned int> generateRandomdeque(int NumberCount, int minimum, int maximum) {
	std::random_device rd;
	std::mt19937 gen(rd()); // these can be global and/or static, depending on how you use random elsewhere

	std::deque<unsigned int> values(NumberCount);
	std::uniform_int_distribution<> dis(minimum, maximum);
	std::generate(values.begin(), values.end(), [&]() { return dis(gen); });
	return values;
}

int main()
{
	std::deque<unsigned int> foo = generateRandomdeque(10, 0, 1000);
	Sorter * sorter = new MergeSorter(foo);
	sorter->sort();
	std::deque<unsigned int> bar = sorter->getSortedCollection();
	for (auto it = bar.begin(); it != bar.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	delete sorter;
	return 0;

}

