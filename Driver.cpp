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
#include <stdlib.h>     /* srand, rand */

#include "BinarySearchTree.h"


std::deque<unsigned int> generateRandomDeque(const unsigned int num, const unsigned int minimum, const unsigned int maximum) {
	std::deque<unsigned int> random_values;
	for(unsigned int ii = 0; ii < num; ++ii)
	{
		random_values.push_back(rand() % maximum + minimum);
	}
	std::random_shuffle(random_values.begin(), random_values.end());
	return random_values;
}

void runProfilingTest(const SorterFactory::SortType& type, const std::string mode)
{

	Sorter * sorter =
			SorterFactory::getInstance().createSorter(type);

	// define element sweep
	std::vector<unsigned int> N = {1000, 10000, 100000, 1000000, 10000000};

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


	std::thread t1(runProfilingTest, SorterFactory::SortType::HEAP, "unsorted");
	std::thread t2(runProfilingTest, SorterFactory::SortType::MERGE1, "unsorted");
	std::thread t3(runProfilingTest, SorterFactory::SortType::MERGE8, "unsorted");
	std::thread t4(runProfilingTest, SorterFactory::SortType::MERGE16, "unsorted");
	std::thread t5(runProfilingTest,SorterFactory::SortType::MERGE32, "unsorted");
	std::thread t6(runProfilingTest,SorterFactory::SortType::MERGE64, "unsorted");
	std::thread t7(runProfilingTest,SorterFactory::SortType::BST, "unsorted");
	/*
	runProfilingTest(SorterFactory::SortType::BUBBLE, "unsorted");
	runProfilingTest(SorterFactory::SortType::SELECTION, "unsorted");
	runProfilingTest(SorterFactory::SortType::INSERTION, "unsorted");
	*/
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();


	/*

	runProfilingTest(SorterFactory::SortType::HEAP, "sorted");
	runProfilingTest(SorterFactory::SortType::MERGE1, "sorted");
	runProfilingTest(SorterFactory::SortType::MERGE8, "sorted");
	runProfilingTest(SorterFactory::SortType::MERGE16, "sorted");
	runProfilingTest(SorterFactory::SortType::MERGE32, "sorted");
	runProfilingTest(SorterFactory::SortType::MERGE64, "sorted");
	runProfilingTest(SorterFactory::SortType::BST, "sorted");
	runProfilingTest(SorterFactory::SortType::BUBBLE, "sorted");
	runProfilingTest(SorterFactory::SortType::SELECTION, "sorted");
	runProfilingTest(SorterFactory::SortType::INSERTION, "sorted");

	runProfilingTest(SorterFactory::SortType::HEAP, "half-sorted");
	runProfilingTest(SorterFactory::SortType::MERGE1, "half-sorted");
	runProfilingTest(SorterFactory::SortType::MERGE8, "half-sorted");
	runProfilingTest(SorterFactory::SortType::MERGE16, "half-sorted");
	runProfilingTest(SorterFactory::SortType::MERGE32, "half-sorted");
	runProfilingTest(SorterFactory::SortType::MERGE64, "half-sorted");
	runProfilingTest(SorterFactory::SortType::BST, "half-sorted");
	runProfilingTest(SorterFactory::SortType::BUBBLE, "half-sorted");
	runProfilingTest(SorterFactory::SortType::SELECTION, "half-sorted");
	runProfilingTest(SorterFactory::SortType::INSERTION, "half-sorted");
	*/

	return 0;


}

