#pragma once
#include "Sorter.h"
#include <string>

class SorterFactory
{
public:

	enum SortType
	{
		BUBBLE,
		HEAP,
		MERGE1,
		MERGE8,
		MERGE16,
		MERGE32,
		MERGE64,
		INSERTION,
		SELECTION,
		BST
	};


	static SorterFactory& getInstance()
	{
		static SorterFactory factory;
		return factory;
	}

	static Sorter * createSorter(const SortType& type) ;


private:
	SorterFactory();
	virtual ~SorterFactory();


};
