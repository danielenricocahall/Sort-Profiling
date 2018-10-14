/*
 * BSTSorter.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: daniel
 */


#include "BSTSorter.h"

BSTSorter::BSTSorter()
{
	m_sort_name = "BST";
}
BSTSorter::~BSTSorter()
{

}

void BSTSorter::sort()
{
	BinarySearchTree * bst = new BinarySearchTree();
	bst->insert(m_vec);
	bst->traverseTreeInOrder();
	m_vec = bst->getOrderedCollection();
	delete bst;
}
