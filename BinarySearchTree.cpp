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
}

void BinarySearchTree::insert(const unsigned int value)
{
	BSTNode * node = new BSTNode();
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
	for(auto it = values.begin(); it != values.end(); ++it)
	{
		insert((*it));
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

void BinarySearchTree::traverseTreePreOrder() const
{
	preOrderTraversalHelper(root);
}

void BinarySearchTree::preOrderTraversalHelper(BSTNode * current_node) const
{
	if(current_node == nullptr)
	{
		return;
	}
	std::cout << current_node->value << std::endl;

	preOrderTraversalHelper(current_node->left);

	preOrderTraversalHelper(current_node->right);
}

void BinarySearchTree::traverseTreeInOrder() const
{
	inOrderTraversalHelper(root);
}

void BinarySearchTree::inOrderTraversalHelper(BSTNode * current_node) const
{
	if(current_node == nullptr)
	{
		return;
	}
	inOrderTraversalHelper(current_node->left);

	std::cout << current_node->value << std::endl;

	inOrderTraversalHelper(current_node->right);
}

void BinarySearchTree::traverseTreePostOrder() const
{
	postOrderTraversalHelper(root);
}

void BinarySearchTree::postOrderTraversalHelper(BSTNode * current_node) const
{
	if(current_node == nullptr)
	{
		return;
	}
	inOrderTraversalHelper(current_node->left);
	inOrderTraversalHelper(current_node->right);


	std::cout << current_node->value << std::endl;

}

