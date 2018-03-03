#include <iostream>
#include "a3_avl_tree.hpp"

bool AVLTree::insert(DataType val)
{
	if(!BinarySearchTree::insert(val))
		return false;
	insert_rotation(val);
	return true;
}

bool AVLTree::remove(DataType val)
{
	if(!BinarySearchTree::remove(val))
		return false;
	remove_rotation(val);
	return true;
}

void AVLTree::balanceAVLTree(BinarySearchTree::Node* T)
{
	if(T == NULL)
		return;
	if(T->avlBalance > 1 || T->avlBalance < -1)
		node = T;
	balanceAVLTree(T->left);
	balanceAVLTree(T->right);
}

void AVLTree::right_rotation(BinarySearchTree::Node* node_)
{
	Node* T = new Node(node_->val);
	T->right = node_->right;
	T->left = node_->left->right;
	node_->val = node_->left->val;
	node_->right = T;
	node_->left = node_->left->left;
}

void AVLTree::left_rotation(BinarySearchTree::Node* node_)
{
	Node* T = new Node(node_->val);
	T->left = node_->left;
	T->right = node_->right->left;
	node_->val = node_->right->val;
	node_->left = T;
	node_->right = node_->right->right;
}

void AVLTree::left_right_rotation(BinarySearchTree::Node* root_)
{
	left_rotation(root_->left);
	right_rotation(root_);
}
void AVLTree::right_left_rotation(BinarySearchTree::Node* root_)
{
	right_rotation(root_->right);
	left_rotation(root_);
}

void AVLTree::insert_rotation(BinarySearchTree::DataType val)
{
	node = NULL;
	balanceAVLTree(getRootNode());
	if(node == NULL)
		return;
	if(node->left != NULL && node->left->left != NULL && exists(node->left->left, val))
		right_rotation(node);
	else if(node->right != NULL && node->right->right != NULL && exists(node->right->right, val))
		left_rotation(node);
	else if(node->left != NULL && node->left->right != NULL && exists(node->left->right, val))
		left_right_rotation(node);
	else
		right_left_rotation(node);
}

void AVLTree::remove_rotation(BinarySearchTree::DataType val)
{
	node = NULL;
	balanceAVLTree(getRootNode());
	if(node == NULL)
		return;
	if(node->left != NULL && depth_helper(node->left->left) == (depth_helper(node) - 2))
		right_rotation(node);
	else if(node->left != NULL && depth_helper(node->left->right) == (depth_helper(node) - 2))
		left_right_rotation(node);
	else if(node->right != NULL && depth_helper(node->right->right) == (depth_helper(node) - 2))
		left_rotation(node);
	else
		left_right_rotation(node);
	
}

bool AVLTree::exists(BinarySearchTree::Node* node_, BinarySearchTree::DataType val) const
{
	Node* temp = node_;
	while(temp != NULL)
	{
		if(val == temp->val)
			return true;
		else if(val < temp->val)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return false;
}

int AVLTree::depth_helper(Node* n) const
{
	if(n == NULL)
		return -1;
	return 1 + std::max(depth_helper(n->left), depth_helper(n->right));
}

