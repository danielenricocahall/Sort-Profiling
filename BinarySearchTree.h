#pragma once
#include <queue>

class BinarySearchTree
{
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void insert(const unsigned int value);
	void insert(const std::deque<unsigned int>& values);
	void traverseTreePreOrder();
	void traverseTreePostOrder();
	void traverseTreeInOrder();
	std::deque<unsigned int> getOrderedCollection() const;

private:

	struct BSTNode
	{
		unsigned int value;
		BSTNode * left = nullptr;
		BSTNode * right = nullptr;
	};
	BSTNode * root;
	std::deque<unsigned int> m_ordered_collection;

	void insertionHelper(BSTNode * current_node, BSTNode * inserting_node) const;
	void preOrderTraversalHelper(BSTNode * current_node);
	void postOrderTraversalHelper(BSTNode * current_node);
	void inOrderTraversalHelper(BSTNode * current_node);


};
