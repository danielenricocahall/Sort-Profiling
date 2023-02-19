/*
 * BSTSorter.h
 *
 *  Created on: Oct 7, 2018
 *      Author: daniel
 */

#pragma once
#include "Sorter.h"
#include "BinarySearchTree.h"
class BSTSorter : public Sorter
{
public:
	BSTSorter();
	explicit BSTSorter(std::deque<unsigned int>&vec) : Sorter(vec) {};

	~BSTSorter() override;
	void sort() override;
private:
};
