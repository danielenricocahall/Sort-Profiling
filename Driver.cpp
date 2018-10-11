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

void runProfilingTest(const SorterFactory::SortType& type, const std::string& mode)
{

	Sorter * sorter =
			SorterFactory::getInstance().createSorter(type);

	// define element sweep
	const std::vector<unsigned int> N = {1000, 10000, 100000, 1000000, 10000000};
	//const std::vector<unsigned int> N = {1000, 10000, 100000};

	// create file
    std::ofstream myfile;
	myfile.open (sorter->getName() + "_" + mode + ".csv");
    myfile << "N, Average Time (s), Current/Preceding \n";

    // number of Monte Carlo runs
	const unsigned int M = 20;
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
			const auto t_start = std::chrono::high_resolution_clock::now();
			sorter->sort();
			const auto t_end = std::chrono::high_resolution_clock::now();
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
    std::cout << "Finished running the " + sorter->getName() << " profiling test!" << std::endl;
    std::cout << "Feel free to check the results in " << sorter->getName() + "_" + mode + ".csv" << std::endl;

	delete sorter;
}

int main()
{

	const std::string mode = "sorted";



	// yay multithreading

	std::thread t1(runProfilingTest, SorterFactory::SortType::HEAP, mode);
	std::thread t2(runProfilingTest, SorterFactory::SortType::MERGE1, mode);
	std::thread t3(runProfilingTest, SorterFactory::SortType::MERGE8, mode);
	std::thread t4(runProfilingTest, SorterFactory::SortType::MERGE16, mode);
	std::thread t5(runProfilingTest,SorterFactory::SortType::MERGE32, mode);
	std::thread t6(runProfilingTest,SorterFactory::SortType::MERGE64, mode);
	std::thread t7(runProfilingTest,SorterFactory::SortType::BST, mode);
	std::thread t8(runProfilingTest, SorterFactory::SortType::BUBBLE, mode);
	std::thread t9(runProfilingTest,SorterFactory::SortType::SELECTION, mode);
	std::thread t10(runProfilingTest,SorterFactory::SortType::INSERTION, mode);


	t1.join();
	t2.join();
	t3.join();

	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();





	return 0;


}

