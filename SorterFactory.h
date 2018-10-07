#pragma once
#include "Sorter.h"
#include <string>

class SorterFactory
{
public:

	enum SortType
	{
		BUBBLE, HEAP, MERGE, INSERTION, SELECTION
	};

	static SorterFactory& getInstance()
	{
		static SorterFactory factory;
		return factory;
	}

	Sorter * createSorter(const SortType& type) const;


private:
	SorterFactory();
	virtual ~SorterFactory();


};
