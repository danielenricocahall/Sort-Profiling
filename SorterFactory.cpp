/*
 * SorterFactory.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: daniel
 */
#include "SorterFactory.h"
#include "BubbleSorter.h"
#include "MergeSorter.h"
#include "HeapSorter.h"
#include "SelectionSorter.h"
#include "InsertionSorter.h"


SorterFactory::SorterFactory()
{

}

SorterFactory::~SorterFactory()
{

}


Sorter * SorterFactory::createSorter(const SortType& type) const
{
	switch(type)
	{
	case SortType::BUBBLE:
		return new BubbleSorter();
	case SortType::MERGE:
		return new MergeSorter();
	case SortType::HEAP:
		return new HeapSorter();
	case SortType::INSERTION:
		return new InsertionSorter();
	case SortType::SELECTION:
		return new SelectionSorter();
	}
	return nullptr; // because I'm perfect and this should never happen
}
