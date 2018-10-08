#include "SorterFactory.h"

#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>
#include <functional>
#include <ctime>
#include <chrono>
#include <numeric>
#include <iostream>
#include <thread>
#include "BinarySearchTree.h"


std::deque<unsigned int> generateRandomDeque(unsigned int NumberCount, unsigned int minimum, unsigned int maximum) {
	std::random_device rd;
	std::mt19937 gen(rd()); // these can be global and/or static, depending on how you use random elsewhere
	std::deque<unsigned int> values(NumberCount);
	std::uniform_int_distribution<> dis(minimum, maximum);
	std::generate(values.begin(), values.end(), [&]() { return dis(gen); });
	return values;
}

void runProfilingTest(const SorterFactory::SortType& type, const std::string mode)
{

	Sorter * sorter =
			SorterFactory::getInstance().createSorter(type);

	// define element sweep
	std::vector<unsigned int> N = {1000, 10000, 100000};

	// create file
    std::ofstream myfile;
	myfile.open (sorter->getName() + "_" + mode + ".csv");
    myfile << "N, Average Time (s), Ratio \n";

    // number of Monte Carlo runs
	unsigned int M = 20;
	double previous_value = -1;
	for(unsigned int ii = 0; ii < N.size(); ++ii)
	{
		std::vector<double> times_elapsed;
		for(unsigned int jj = 0; jj < M; ++jj)
		{
			std::deque<unsigned int> collection = generateRandomDeque(N[ii], 0, N[ii]);
			if(mode == "sorted")
			{
				std::sort(collection.begin(), collection.end());
			}
			else if(mode == "half-sorted")
			{
				std::sort(collection.begin(), collection.begin() + collection.size()/2);
			}
			sorter->setCollection(collection);
			auto t_start = std::chrono::high_resolution_clock::now();
			sorter->sort();
			auto t_end = std::chrono::high_resolution_clock::now();
			times_elapsed.push_back(
					std::chrono::duration<double, std::milli>(t_end-t_start).count());
		}
		double average = std::accumulate( times_elapsed.begin(), times_elapsed.end(), 0.0)/times_elapsed.size();
		average /= 1000;
		if(previous_value > -1)
		{
			myfile << N[ii] << "," << average << "," << average/previous_value <<  "\n";
		}
		else
		{
			myfile << N[ii] << "," << average <<  "\n";

		}
		previous_value = average;
	}

    myfile.close();

	delete sorter;
}

int main()
{


	runProfilingTest(SorterFactory::SortType::BUBBLE, "unsorted");
	runProfilingTest(SorterFactory::SortType::SELECTION, "unsorted");
	runProfilingTest(SorterFactory::SortType::INSERTION, "unsorted");
	runProfilingTest(SorterFactory::SortType::HEAP, "unsorted");
	runProfilingTest(SorterFactory::SortType::MERGE1, "unsorted");
	runProfilingTest(SorterFactory::SortType::MERGE8, "unsorted");
	runProfilingTest(SorterFactory::SortType::MERGE16, "unsorted");
	runProfilingTest(SorterFactory::SortType::MERGE32, "unsorted");
	runProfilingTest(SorterFactory::SortType::MERGE64, "unsorted");
	runProfilingTest(SorterFactory::SortType::BST, "unsorted");


	runProfilingTest(SorterFactory::SortType::BUBBLE, "sorted");
	runProfilingTest(SorterFactory::SortType::SELECTION, "sorted");
	runProfilingTest(SorterFactory::SortType::INSERTION, "sorted");
	runProfilingTest(SorterFactory::SortType::HEAP, "sorted");
	runProfilingTest(SorterFactory::SortType::MERGE1, "sorted");
	runProfilingTest(SorterFactory::SortType::MERGE8, "sorted");
	runProfilingTest(SorterFactory::SortType::MERGE16, "sorted");
	runProfilingTest(SorterFactory::SortType::MERGE32, "sorted");
	runProfilingTest(SorterFactory::SortType::MERGE64, "sorted");
	runProfilingTest(SorterFactory::SortType::BST, "sorted");

	runProfilingTest(SorterFactory::SortType::BUBBLE, "half-sorted");
	runProfilingTest(SorterFactory::SortType::SELECTION, "half-sorted");
	runProfilingTest(SorterFactory::SortType::INSERTION, "half-sorted");
	runProfilingTest(SorterFactory::SortType::HEAP, "half-sorted");
	runProfilingTest(SorterFactory::SortType::MERGE1, "half-sorted");
	runProfilingTest(SorterFactory::SortType::MERGE8, "half-sorted");
	runProfilingTest(SorterFactory::SortType::MERGE16, "half-sorted");
	runProfilingTest(SorterFactory::SortType::MERGE32, "half-sorted");
	runProfilingTest(SorterFactory::SortType::MERGE64, "half-sorted");
	runProfilingTest(SorterFactory::SortType::BST, "half-sorted");

	return 0;


}

