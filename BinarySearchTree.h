#pragma once
#include <queue>

class BinarySearchTree
{
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void insert(const unsigned int value);
	void insert(const std::deque<unsigned int>& values);
	void traverseTreePreOrder() const;
	void traverseTreePostOrder() const;
	void traverseTreeInOrder() const;

private:

	struct BSTNode
	{
		unsigned int value;
		BSTNode * left = nullptr;
		BSTNode * right = nullptr;
	};
	BSTNode * root;
	void insertionHelper(BSTNode * current_node, BSTNode * inserting_node) const;
	void preOrderTraversalHelper(BSTNode * current_node) const;
	void postOrderTraversalHelper(BSTNode * current_node) const;
	void inOrderTraversalHelper(BSTNode * current_node) const;


};
