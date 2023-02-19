/*
 * BinarySearchTree.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: daniel
 */
#include "BinarySearchTree.h"
#include <iostream>


BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	delete root;
	m_ordered_collection.clear();
}

void BinarySearchTree::insert(const unsigned int value)
{
	auto * node = new BSTNode();
	node->value = value;
	if(root == nullptr)
	{
		root = node;
	}
	else
	{
		insertionHelper(root, node);
	}
}

void BinarySearchTree::insert(const std::deque<unsigned int>& values)
{
	for(unsigned int value : values)
	{
		insert(value);
	}
}

void BinarySearchTree::insertionHelper(BSTNode * current_node, BSTNode * inserting_node) const
{
	if(inserting_node->value <= current_node->value)
	{
		if(current_node->left == nullptr)
		{
			current_node->left = inserting_node;
		}
		else
		{
			insertionHelper(current_node->left, inserting_node);
		}
	}
	else
	{
		if(current_node->right == nullptr)
		{
			current_node->right = inserting_node;
		}
		else
		{
			insertionHelper(current_node->right, inserting_node);
		}
	}
}

void BinarySearchTree::traverseTreePreOrder()
{
	if(!m_ordered_collection.empty())
	{
		m_ordered_collection.clear();
	}
	preOrderTraversalHelper(root);
}

void BinarySearchTree::preOrderTraversalHelper(BSTNode * current_node)
{
	if(current_node == nullptr)
	{
		return;
	}
	m_ordered_collection.push_back(current_node->value);

	preOrderTraversalHelper(current_node->left);

	preOrderTraversalHelper(current_node->right);
}

void BinarySearchTree::traverseTreeInOrder()
{
	if(!m_ordered_collection.empty())
	{
		m_ordered_collection.clear();
	}
	inOrderTraversalHelper(root);
}

void BinarySearchTree::inOrderTraversalHelper(BSTNode * current_node)
{
	if(current_node == nullptr)
	{
		return;
	}
	inOrderTraversalHelper(current_node->left);

	m_ordered_collection.push_back(current_node->value);

	inOrderTraversalHelper(current_node->right);
}

void BinarySearchTree::traverseTreePostOrder()
{
	if(!m_ordered_collection.empty())
	{
		m_ordered_collection.clear();
	}
	postOrderTraversalHelper(root);
}

void BinarySearchTree::postOrderTraversalHelper(BSTNode * current_node)
{
	if(current_node == nullptr)
	{
		return;
	}
	postOrderTraversalHelper(current_node->left);
	postOrderTraversalHelper(current_node->right);

	m_ordered_collection.push_back(current_node->value);

}

std::deque<unsigned int> BinarySearchTree::getOrderedCollection() const
{
	return m_ordered_collection;
}


