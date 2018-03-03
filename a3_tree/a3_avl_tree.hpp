#ifndef A3_AVL_TREE_HPP
#define A3_AVL_TREE_HPP

#include "a3_binary_search_tree.hpp"

class AVLTree: public BinarySearchTree
{
public:
	// Overriden insert and remove functions 
	// Do not modify these definitions
    bool insert(DataType val);
    bool remove(DataType val);

	// Define additional functions and attributes that you need below
	void balanceAVLTree(Node* T);
	Node* node;
	void left_rotation(Node* T);
	void right_rotation(Node* T);
	void left_right_rotation(Node* T);
	void right_left_rotation(Node* T);
	void insert_rotation(DataType val);
	void remove_rotation(DataType val);
	bool exists(Node* node_, DataType val) const;
	int depth_helper(Node* T) const;
};

#endif

