/*
 * BSTSorter.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: daniel
 */


#include "BSTSorter.h"

BSTSorter::BSTSorter()
{

}
BSTSorter::~BSTSorter()
{

}

void BSTSorter::sort()
{
	BinarySearchTree * bst = new BinarySearchTree();
	bst->insert(m_vec);
}
