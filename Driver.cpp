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



std::deque<unsigned int> generateRandomDeque(unsigned int NumberCount, unsigned int minimum, unsigned int maximum) {
	std::random_device rd;
	std::mt19937 gen(rd()); // these can be global and/or static, depending on how you use random elsewhere
	std::deque<unsigned int> values(NumberCount);
	std::uniform_int_distribution<> dis(minimum, maximum);
	std::generate(values.begin(), values.end(), [&]() { return dis(gen); });
	return values;
}

int main()
{
	Sorter * sorter =
			SorterFactory::getInstance().createSorter(SorterFactory::SortType::BUBBLE);

	// define element sweep
	std::vector<unsigned int> N = {10, 100, 1000};

	// create file
    std::ofstream myfile;
	myfile.open (sorter->getName() + ".csv");
    myfile << "N, Average Time (s)\n";

    // number of Monte Carlo runs
	unsigned int M = 10;

	for(unsigned int ii = 0; ii < N.size(); ++ii)
	{
		std::vector<double> times_elapsed;
		for(unsigned int jj = 0; jj < M; ++jj)
		{
			std::deque<unsigned int> collection = generateRandomDeque(N[ii], 0, N[ii]);
			sorter->setCollection(collection);
			auto t_start = std::chrono::high_resolution_clock::now();
			sorter->sort();
			auto t_end = std::chrono::high_resolution_clock::now();
			times_elapsed.push_back(
					std::chrono::duration<double, std::milli>(t_end-t_start).count());
		}
		double average = std::accumulate( times_elapsed.begin(), times_elapsed.end(), 0.0)/times_elapsed.size();
		average /= 1000;

	    myfile << N[ii] << "," << average <<  "\n";

	}

    myfile.close();

	delete sorter;
	return 0;

}

