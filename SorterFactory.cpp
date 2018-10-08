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
#include "BSTSorter.h"


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
	case SortType::MERGE1:
		return new MergeSorter(1);
	case SortType::MERGE8:
		return new MergeSorter(8);
	case SortType::MERGE16:
		return new MergeSorter(16);
	case SortType::MERGE32:
		return new MergeSorter(32);
	case SortType::MERGE64:
		return new MergeSorter(64);
	case SortType::HEAP:
		return new HeapSorter();
	case SortType::INSERTION:
		return new InsertionSorter();
	case SortType::SELECTION:
		return new SelectionSorter();
	case SortType::BST:
		return new BSTSorter();
	}
	return nullptr; // because I'm perfect and this should never happen
}
